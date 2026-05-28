#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    // 1) y 2) Determine la cantidad de memoria (en Bytes) utilizada por las variables.
    int32_t cantidadPasos;
    double  potencia; 
    int16_t rpm;
    
    cantidadPasos = 25;
    potencia = 800.25904;

    int totalBytes = sizeof(cantidadPasos) + sizeof(potencia) + sizeof(rpm);
    printf("Cantidad de memoria utilizada por las variables: %d Bytes\n", totalBytes);


    exit(EXIT_SUCCESS);
}

