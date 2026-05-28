#include <stdio.h>
#include <string.h>
#include <stdlib.h>


class Led{
    public:
    enum color_t {
        ROJO,
        AMARILLO,
        VERDE,
        BLANCO
    };
    enum estado_t{
        OFF,
        ON
    };
    
    // Atributos
    private:
    color_t color;
    estado_t estadoLogico;
    double umbralEncendido; //en volts
    double cteMaxima; // en mA

    // Constructor
    public:
    Led(){
        this->color = BLANCO;
        this->estadoLogico = OFF;
        this->umbralEncendido = 2.0; 
        this->cteMaxima = 20;

    }

    public:
    // Acciones
    void prenderlo(){
        //
    }

    void apagarlo(){

    }

};

int main(int argc, char* argv[]) {

    Led* led0 = new Led();
    Led* led1 = new Led();

    printf("Corriente máxima led0: %f mA\n",  led0->cteMaxima);
    printf("Corriente máxima led1: %f mA\n",  led1->cteMaxima);

    led1->cteMaxima = -89816.7;
    led0->color = Led::AMARILLO;

    printf("Corriente máxima led0: %f mA\n",  led0->cteMaxima);
    printf("Corriente máxima led1: %f mA\n",  led1->cteMaxima);

    printf("Color led0: %i\n",  led1->color);
    printf("Color led1: %i\n",  led1->color);

    return EXIT_SUCCESS;
}