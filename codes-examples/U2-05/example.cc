#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    /*
        Se declaran algunas variables. Se utilizan enteros sólo por 
        que la cantidad de bits que utilizan es evidente según el tipo
        de datos
    */

    double a0;
    double a1; 
    float  a2;
    int    a3;
   
    printf("=== Direcciones de memoria ===\n");
    printf("a0: %p\n", &a0);
    printf("a1: %p\n", &a1);
    printf("a2: %p\n", &a2);
    printf("a3: %p\n", &a3);



    exit(EXIT_SUCCESS);
}

