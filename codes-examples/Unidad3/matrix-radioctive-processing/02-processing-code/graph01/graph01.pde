import processing.serial.*;

Serial port;
int xActual;
int xAnterior;

String input; //Dato crudo recibido por el puerto Serie

int valorActual = 0;
int valorAnterior = 0;

void setup(){
  size(1200,400);
  frameRate(30);
  pixelDensity(1);
  smooth();
  
  printArray(Serial.list());
  String arduinoPort = Serial.list()[3];
  println(arduinoPort);
  port = new Serial(this, arduinoPort, 115200);
 
  xActual=0;
  xAnterior = 0;
  background(200);
}

void draw(){
  
  // Dibujar ejes
  stroke(#FF0000);
  line(0, 19, width,  19);
  line(0, height-19, width,  height-19);
  
  if (port.available() > 0) {
    //print(">");
    String inBuffer = new String("");
    //println(inBuffer);
    inBuffer = port.readString(); 
    //println(inBuffer);
    if (inBuffer != null) {    
      String[] buff = splitTokens(inBuffer, ":");
      
      if( buff.length == 2){
        buff[1] = trim(buff[1]);
        valorActual = int(buff[1]);  
      }
      
    }
   
    //Dibujar el dato
    stroke(200);
    line(xActual, 0, xActual, height);
    stroke(0);
    line(xActual+1, 0, xActual+1, height); //linea blanca
    
    int valorEscaladoAnterior = (int)map(valorAnterior, 1, 96, 20, height-20);
    int valorEscaladoActual    = (int)map(valorActual  , 1, 96, 20, height-20);
    
    // No graficar cuando se llegue al borde de la pantalla.
    if(abs(xAnterior - xActual) == 1){
      line(xAnterior, height-valorEscaladoAnterior, xActual,  height-valorEscaladoActual );
    }
    
    xAnterior = xActual % width;
    xActual   = (xActual + 1) % width;   
 
    valorAnterior = valorActual;

  }

}
