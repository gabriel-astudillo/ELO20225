import asyncio
import serial
import random
import time
from nicegui import ui

# =============================================================================
# CONFIGURACIÓN CENTRALIZADA
# =============================================================================

# --- Puerto serie ---
PORT       = '/dev/cu.usbmodem907069208A9C2'
BAUD_RATE  = 115200

# --- Parámetros de escala (lo que se ve en los ejes) ---
RANGO_X_VISTA = 180      # segundos visibles en el eje X (ventana deslizante)
Y_MIN         = -0.1       # límite inferior del eje Y
Y_MAX         = 100.1     # límite superior del eje Y
TOTAL_LEDS    = 96

# --- Parámetros de geometría (tamaño físico del gráfico) ---
FIG_ANCHO  = 12         # ancho de la figura en pulgadas
FIG_ALTO   = 4          # alto  de la figura en pulgadas

# --- Parámetros del gráfico ---
MAX_PUNTOS    = 3000    # máximo de puntos en memoria
COLOR_LINEA   = '#1f77b4'
TAMAÑO_PUNTO  = 2

CANTIDAD_LEDS_ON = 0
PORCENTAJE_LED_ON = 0

# =============================================================================


def configurar_axes(ax):
    """Aplica la escala fija y la apariencia al axes de Matplotlib."""
    ax.set_autoscalex_on(False)
    ax.set_autoscaley_on(False)
    ax.set_xlim(0, RANGO_X_VISTA)
    ax.set_ylim(Y_MIN, Y_MAX)
    ax.set_xlabel('Tiempo (s)')
    ax.set_ylabel('Porcentaje')

    ax.set_title('Porcentaje de Leds encendidos en el tiempo')
    
    ax.grid(True, linestyle='--', alpha=0.5)

def calcular_xlim(t: float) -> tuple[float, float]:
    """Calcula los límites X de la ventana deslizante para el tiempo actual."""
    if t > RANGO_X_VISTA:
        return (round(t - RANGO_X_VISTA,2), t)
    return (0.0, float(RANGO_X_VISTA))


def actualizar_ventana_x(ax, t: float):
    #ax.set_autoscalex_on(False)
    #ax.set_autoscaley_on(False)
    """Mantiene la ventana deslizante en X sin tocar Y."""
    if t > RANGO_X_VISTA:
        ax.set_xlim(t - RANGO_X_VISTA, t)
    else:
        ax.set_xlim(0, RANGO_X_VISTA)

async def actualizar_cantidad_leds(ui_label):
    #global CANTIDAD_LEDS_ON
    while(True):
        ui_label.text = f"Cantidad de leds encendidos: {CANTIDAD_LEDS_ON} ({PORCENTAJE_LED_ON}%)"
        await asyncio.sleep(0.1)

async def escuchar_puerto(plot):
    global CANTIDAD_LEDS_ON, PORCENTAJE_LED_ON
    print(f"Intentando conectar al puerto {PORT}...")
    inicio = time.time()

    # Configurar marcadores de la línea una sola vez
    ax = plot.fig.gca()
    linea = ax.lines[0]
    linea.set_marker('o')
    linea.set_markersize(TAMAÑO_PUNTO)
    linea.set_color(COLOR_LINEA)
    
    # Aplicar escala y apariencia inicial
    configurar_axes(ax)
    #puntos = 0
    t = 0.0
    try:
        ser = serial.Serial(PORT, BAUD_RATE, timeout=0.05)
        print(f"Conectado exitosamente a {PORT}")
        
        while True:
            if ser.in_waiting > 0:
                linea_raw = ser.readline().decode('utf-8').strip()
                if ':' in linea_raw:
                    try:
                        tiempo_str, dato_str = linea_raw.split(':', 1)
                        dt, CANTIDAD_LEDS_ON = float(tiempo_str), int(dato_str)
                        t += dt/1000
                        t = round(t,ndigits=3)

                        porcentaje = (CANTIDAD_LEDS_ON / TOTAL_LEDS) * 100
                        PORCENTAJE_LED_ON = round(porcentaje, 2)
                        print(f"raw='{linea_raw}'  t={t}  dato={CANTIDAD_LEDS_ON} porcentaje={PORCENTAJE_LED_ON} xlim={calcular_xlim(t)}")
                        plot.push(
                            [t], [[PORCENTAJE_LED_ON]],
                            x_limits=calcular_xlim(t),       # ventana deslizante
                            y_limits=(Y_MIN, Y_MAX),          # eje Y fijo
                        )
                        actualizar_ventana_x(ax, t)
                        #puntos += 1
                        #print(f"Puntos: {puntos}")
                    except ValueError:
                        pass
            await asyncio.sleep(0.02)
            #t += 0.02
            #actualizar_ventana_x(ax, t)

    except Exception as e:
        print(f"Modo simulación activo (Puerto no encontrado: {e})")

        while True:
            await asyncio.sleep(0.2)
            t = time.time() - inicio
            d = random.uniform(Y_MIN + 10, Y_MAX - 10)   # datos dentro del rango configurado

            plot.push([t], [[d]],
                      x_limits=calcular_xlim(t),
                      y_limits=(Y_MIN, Y_MAX),
                      )
            actualizar_ventana_x(ax, t)
            # El eje Y ya está fijo desde configurar_axes(); no hay que tocarlo aquí


@ui.page('/')
def principal():
    ui.label('Monitoreo en tiempo real').classes('text-2xl font-bold m-4')
    
    '''
    ui.label(
        f'Ventana X: {RANGO_X_VISTA} s  |  '
        f'Eje Y: [{Y_MIN}, {Y_MAX}]  |  '
        f'Figura: {FIG_ANCHO}×{FIG_ALTO} in'
    ).classes('text-sm text-gray-500 mx-4')
    '''
    cantidad_leds = ui.label('').classes('text-sm text-gray-500 mx-4')
    
    plot = ui.line_plot(
        n=1,
        limit=MAX_PUNTOS,
        figsize=(FIG_ANCHO, FIG_ALTO),   # geometría parametrizada
    ).with_legend(['Leds ON'], loc='upper left')


    asyncio.create_task(escuchar_puerto(plot))
    asyncio.create_task(actualizar_cantidad_leds(cantidad_leds))


ui.run(title='Visualizador', port=8080)