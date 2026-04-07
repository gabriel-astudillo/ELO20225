#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
const int NUM_SENSORES = 10;

enum Accion {
    //Completar código
};

double lecturaSensor(){
    double lecturaAleatoria;

    // número aleatorio entero entre 0 y 255
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}


/*
Entradas:
    sensores[]: arreglo de enteros
    acciones  : enum Accion {INIT, READ, SHOW}

*/
void usarSensores(int sensores[], Accion acc) {
    switch(acc){
        // Completar código
        default:  break;
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int sensores[NUM_SENSORES];

    // Inicializar los sensores
    for (int i = 0; i < NUM_SENSORES; i++) {
        sensores[i] = 0;
    }

    // Realizar lectura de los sensores
    for (int i = 0; i < NUM_SENSORES; i++) {
        sensores[i] = lecturaSensor();
    }

    // Mostrar los resultados
    for (int i = 0; i < NUM_SENSORES; i++) {
        printf("Sensor %i: %i [mV]\n", i, sensores[i]);
    }

    //usarSensores(sensores, INIT);
    //usarSensores(sensores, READ);
    //usarSensores(sensores, SHOW);


    exit(EXIT_SUCCESS);
}

