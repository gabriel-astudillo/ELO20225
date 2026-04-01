#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    float  temperatura = -25.6;
    int16_t nivel = 90;

    char mensaje[] = "Hola mundo!!!!";

    printf("La temperatura es %f y el nivel es %i, %s\n", temperatura, nivel, mensaje);


    exit(EXIT_SUCCESS);
}

