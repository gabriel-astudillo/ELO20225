#include <Arduino.h>
#include "Arduino_LED_Matrix.h"  

class DisplayBase{
  private:
  ArduinoLEDMatrix* matrix;      

  const byte FILAS = 8;
  const byte COLUMNAS = 12;
  

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
  DisplayBase(){
    matrix = new ArduinoLEDMatrix();
    // Inicializar la matriz de led de la placa R4
    matrix->begin();
  }

  void clear(){
    for(int x = 0; x < this->COLUMNAS; x++){
      for(int y = 0; y < this->FILAS; y++){
        frame[y][x] = 0;
      }
    }
  }

  void setPoint(byte x, byte y){
    frame[y][x] = 1;
  }

  void deletePoint(byte x, byte y){
    frame[y][x] = 0;
  }

  void randomPoint(){
    byte x;
    byte y;

    x = random(COLUMNAS);
    y = random(FILAS);

    frame[y][x] = 1;
  }

  void update(){
    matrix->renderBitmap(frame, 8, 12);
  }

  byte getCols(){
    return this->COLUMNAS;
  }

  byte getRows(){
    return this->FILAS;
  }
};

DisplayBase* m0;

void setup() {
  m0 = new DisplayBase();
}

void loop() {
  m0->clear();
  m0->randomPoint();

  m0->update();
}