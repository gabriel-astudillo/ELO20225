#include <Arduino.h>

/*
  Esta biblioteca ya viene incluida.
  Docs Arduino:
      https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/
   código fuente:
      https://github.com/arduino/ArduinoCore-renesas/tree/main/libraries/Arduino_LED_Matrix/src

   Para dibujar frames:
      https://ledmatrix-editor.arduino.cc/

  Estructura para crear animaciones:
      const uint32_t animacion[][4] = {
        { <uint32_t>, <uint32_t>, <uint32_t>, dt }, // Frame (dt ms)
        ...
      };

  Los bits se leen de izquierda a derecha y de arriba a abajo. 
  El primer número <uint32_t> contiene los primeros 32 LEDs, el segundo los siguientes 32, y así sucesivamente.

  Para cargar y reproducir:
      matrix.loadSequence(animacion);
      matrix.play(true); // true para repetir en bucle
*/

/*
  Matrix Frame Buffer
  
  This Arduino sketch demonstrates the creation and manipulation of 
  a frame buffer for the LED matrix. The frame buffer is used to control 
  the lighting of individual LEDs on the matrix, turning them randomly on and off.
  
  See the full documentation here:
  https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix
*/


#include "Arduino_LED_Matrix.h"  

class MatrixRadioActive{
  private:
  ArduinoLEDMatrix* matrix;      

  uint32_t intervaloActualizacion; //ms
  const byte FILAS = 8;
  const byte COLUMNAS = 12;

  // Variables to track the current positions
  uint8_t pointX;
  uint8_t pointY;
  uint8_t pixelValue;
  uint8_t cantidadLedEncendidos;

  uint8_t frame[8][12] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };


  public:
  MatrixRadioActive(){
    matrix = new ArduinoLEDMatrix();
    this->cantidadLedEncendidos = 0;
    this->intervaloActualizacion = 1000;
    // Initialize the LED matrix
    matrix->begin();
  }

  void actualizarCantidadledEncendidos(){

    int total = 0;
    for(int x = 0; x < this->COLUMNAS; x++){
      for(int y = 0; y < this->FILAS; y++){
        total = total + this->frame[y][x];
      }
    }
    this->cantidadLedEncendidos =  total;
  }

  void update(){
    uint32_t actualTick = millis();

    delay(intervaloActualizacion);  
    
    // Genera coordenadas aleatorias
    // dentro del display
    pointX = random(COLUMNAS);
    pointY = random(FILAS);


    this->actualizarCantidadledEncendidos();

    if (cantidadLedEncendidos == 96){
      pixelValue = 0;
    }
    else if (cantidadLedEncendidos == 0){
      pixelValue = 1;
    }
    

    // Actualizar el valor X,Y de la matriz lógica
    frame[pointY][pointX] = pixelValue;

    // En base a los datos de la matriz lógica, 
    // actualizar la matriz física
    // Este método es propio de la biblioteca
    // Arduino_LED_Matrix.h
    matrix->renderBitmap(frame, 8, 12);


    // Enviar datos por el puerto serie
    this->sendData();

  }

  /*
    Enviar datos por el puerto serie en el siguiente formato:
    <intervalo de actualización>:<cantidad de leds encendidos>
  */
  void sendData(){
    Serial.print(this->intervaloActualizacion);
    Serial.print(":");
    Serial.println(this->cantidadLedEncendidos);
  }

  uint8_t getCantidadLedEncendidos(){
    return this->cantidadLedEncendidos;
  }

  void setIntervaloActualizacion(int ia){
    this->intervaloActualizacion = ia;
  }

  int getIntervaloActualizacion(){
    return this->intervaloActualizacion;
  }

};

MatrixRadioActive* m0;

void setup() {
  Serial.begin(115200);
  m0 = new MatrixRadioActive();
  m0->setIntervaloActualizacion(0);
}

void loop() {
  m0->update();
}