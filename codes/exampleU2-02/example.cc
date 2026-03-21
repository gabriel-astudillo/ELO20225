#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    char varExample01 = 'A';
    char varExample02 = 38;
    int16_t varExample03 = 666;

    int size_varExample01;
    int size_varExample02;
    int size_varExample03;

    size_varExample01 = sizeof(varExample01);
    size_varExample02 = sizeof(varExample02);
    size_varExample03 = sizeof(varExample03);

    printf("varExample01\n");
    printf("Contenido mostrado como caracter: %c\n", varExample01);
    printf("Contenidf mostrado como entero  : %i\n", varExample01);
    printf("Tamaño en memoria               : %i Bytes\n", size_varExample01);
    printf("\n");
    printf("varExample02\n");
    printf("Contenido mostrado como caracter: %c\n", varExample02);
    printf("Contenido mostrado como entero  : %i\n", varExample02);
    printf("Tamaño en memoria               : %i Bytes\n", size_varExample02);
    printf("\n");
    printf("varExample03\n");
    printf("Contenido          : %i\n", varExample03);
    printf("Tamaño en memoria  : %i Bytes\n", size_varExample03);


    exit(EXIT_SUCCESS);
}

