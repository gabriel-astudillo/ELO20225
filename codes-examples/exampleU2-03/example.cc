#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    // El arreglo A puede guardar 150 valores int16_t.
    int16_t A[150];

    // El arreglo B puede guardar 2500 valores double (punto flotante en doble precisión)
    double B[2500];

    A[100] = 30;
    B[2000] = 1.5;

    // Mostrar contenidos asignados.
    printf("A[100]=%i\n", A[100]);
    printf("B[2000]=%f\n", B[2000]);

    // Mostrar contenidos de los arreglos que no
    // han sido asignados. Algunas veces el sistema
    // operativo o el compilador no asegura el valor
    // por omisión. Esto puede ocasionar errores de 
    // arrastre.
    printf("A[10]=%i\n", A[10]);
    printf("B[1000]=%f\n", B[1000]);

    int32_t C[] = {3, 10, 78, 70};

    printf("C[0]=%i\n", C[0]);
    printf("C[3]=%i\n", C[3]);

    printf("===Tamaño en memoria de los arreglos===\n");
    int memA = sizeof(A);
    int memB = sizeof(B);
    int memC = sizeof(C);
    printf("Arreglo A: %i Bytes\n", memA);
    printf("Arreglo B: %i Bytes\n", memB);
    printf("Arreglo C: %i Bytes\n", memC);

    // Arreglo de caracteres
    // 
    printf("===Arreglo de caracteres===\n");
    char msg[] = "Ejemplo";
    printf("msg[]=%s\n", msg);

    int largoMensaje = strlen(msg);
    int tamanoMemoria = sizeof(msg);
    printf("largoMensaje=%i\n", largoMensaje);
    printf("tamaño en memoria=%i Bytes\n", tamanoMemoria);



    exit(EXIT_SUCCESS);
}

