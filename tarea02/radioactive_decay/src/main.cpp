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


// Include the LED_Matrix library
#include "Arduino_LED_Matrix.h"  

ArduinoLEDMatrix* matrix;        

const byte FILAS = 8;
const byte COLUMNAS = 12;

// Representación matricial de la matriz
// de led del ArduinoR4
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

uint32_t deltaT_Actualizacion = 1; //ms
uint32_t ultimoTick = 0;

// Variables to track the current positions
uint8_t pointX = 0;
uint8_t pointY = 0;
uint8_t pixelValue;


int contarLedsEncendidos(){
  int total = 0;
  for(int x=0; x<COLUMNAS; x++){
    for(int y=0; y<FILAS; y++){
      total = total + frame[y][x];
    }
  }
  return total;
}

void setup() {
  // Initialize the LED matrix
  matrix = new ArduinoLEDMatrix();
  matrix->begin();
}

void loop() {
  // Track the current time
  uint32_t actualTick = millis();

  // Actualizar la matriz de led
  // Esta estructura es una forma de implementar un delay no bloqueante.
  if (actualTick - ultimoTick > deltaT_Actualizacion) {
    
    // Generate random positions and pixel value
    pointX = random(COLUMNAS);
    pointY = random(FILAS);

    uint8_t cantidadLedEncendidos = contarLedsEncendidos();

    if (cantidadLedEncendidos == 96){
      pixelValue = 0;
    }
    else if(cantidadLedEncendidos == 0){
      pixelValue = 1;
    }
    

    // Actualizar el valor X,Y de la matriz lógica
    frame[pointY][pointX] = pixelValue;

    // En base a los datos de la matriz lógica, 
    // actualizar la matriz física
    matrix->renderBitmap(frame, 8, 12);

    // Actualizar el instante de tiempo de actualización
    ultimoTick = actualTick;
  }
}