#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    // Por qué:
    //      (Objetivo) Almacenar el valor de 50 sensores de temperatura.
    // Cómo:
    //      (Análisis) Se debe utilizar un arreglo de 50 enteros de 16 bits.
    // Qué:
    //      (Implementación):
    //      Declaración

    int16_t estadoSensor[50];

    // Pruebas de uso:
    //
    // Inicialización:
    //      Para el caso de la inicialización, se utiliza utiliza
    //      un ciclo para colocar todos los sensores a cero
    for(int idSensor=0; idSensor < 50; idSensor += 1){
        estadoSensor[idSensor] = 0;
    }

    // Guardar datos:
    //      Para el caso de guardar datos, se utiliza un ciclo
    //      para simular la adquisión de datos de todos los sensores.
    //      El dato simulado es aleatorio.
    int tempMin = 0;
    int tempMax = 300;
    srand(time(nullptr));
    for(int idSensor=0; idSensor < 50; idSensor += 1){
        int temp;
        
        temp = tempMin + rand() % (tempMax - tempMin + 1);
        estadoSensor[idSensor] = temp;
    }

    // Mostrar datos
    //  Para este caso, se mostrará el dato almacenado de tres sensores
    int sensorA;
    int sensorB;
    int sensorC;

    sensorA = 28;
    sensorB = 23;
    sensorC = 48;

    printf("Temperatura Sensor %i : %i[°C]\n", sensorA, estadoSensor[sensorA]);
    printf("Temperatura Sensor %i : %i[°C]\n", sensorB, estadoSensor[sensorB]);
    printf("Temperatura Sensor %i : %i[°C]\n", sensorC, estadoSensor[sensorC]);



    exit(EXIT_SUCCESS);
}

