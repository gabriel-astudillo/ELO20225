#include <stdio.h>

/*
tipos de ventanas de analisis
0 => RECTANGULAR
1 => HANNING
2 => HAMMING
*/

enum ventana_t{
    RECTANGULAR,
    HANNING,
    HAMMING
};

/*
tipo de banda de análisis
0 COMPONENTE_DC
1 FUNDAMENTAL
2 ARMONICOS
3 RUIDO_BASE
*/

enum banda_t{
    COMPONENTE_DC,
    FUNDAMENTAL,
    ARMONICOS,
    RUIDO_BASE
};

void analizarEspectro(float *datos, int N, ventana_t ventana, banda_t banda) {
    printf("--- Análisis de Señal ---\n");
    
    // Selección de ventana mediante enum
    switch (ventana) {
        case RECTANGULAR:// 
            printf("Ventana: Rectangular (Lóbulos laterales altos)\n"); 
            break;
        case HANNING://    
            printf("Ventana: Hanning (Buen compromiso de resolución)\n"); 
            break;
        case HAMMING: //    
            printf("Ventana: Hamming (Optimizada para cancelación de lóbulos)\n"); 
            break;
        default:          
            printf("Ventana no soportada.\n"); 
            return;
            break;
    }

    // Lógica de análisis basada en la banda (Simulación)
    printf("Extrayendo: ");
    switch (banda) {
        case COMPONENTE_DC: //
            printf("Nivel de offset (0 Hz).\n");
            break;
        case FUNDAMENTAL:// 
            printf("Frecuencia principal de la señal.\n");
            break;
        case ARMONICOS:// :
            printf("Múltiplos enteros de la fundamental (Distorsión).\n");
            break;
        case RUIDO_BASE://:
            printf("Piso de ruido térmico del ADC.\n");
            break;
    }
    
    // Aquí iría el algoritmo de FFT o filtrado digital
    printf("Resultado: Procesamiento completado para %d muestras.\n\n", N);
}

int main() {
    float bufferSenal[1024]; // Buffer de muestras del ADC

    //¿Qué se quiere analizar con la siguiente intrucción?
    analizarEspectro(bufferSenal, 1024, HANNING, COMPONENTE_DC);
    
    //¿Qué se quiere analizar con la siguiente intrucción?
    //analizarEspectro(bufferSenal, 1024, 0, 1);

    return 0;
}