#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen
#include <time.h>

int main(int argc, char* argv[]) {
    
    // Una estructura simple de agrupación se llama arreglo
    int voltajes[2000];
    
    for(int i=0; i < 200; i++){
        voltajes[i] = 0;
    }
    
    int size = sizeof(voltajes);
    printf("size = %i\n", size);
    
    //caso particular: arreglo de caracteres
    // Analizar: por qué el tamaño en memoria es
    //           distinto que el largo del string.
    char string01[]   = "hola mundo";
    int sizeString01  = sizeof(string01);
    int largoString01 = strlen(string01);
    
    
    printf("string01      = %s\n", string01);
    printf("largoString01 = %i\n", largoString01);
    printf("sizeString01  = %i\n", sizeString01);
    
    
    //caso particular: arreglo de caracteres
    char string02[] = "hola mundo";
    int sizeString02   = sizeof(string02);
    int largoString02  = strlen(string02);
    
    printf("string02      = %s\n", string02);
    printf("largoString02 = %i\n", largoString02);
    printf("sizeString02  = %i\n", sizeString02);
    
    
    
    
    exit(EXIT_SUCCESS);
}

//char msg[] = "ELO20225"; // 45 4c 4f 32 30 32 32 35 00
//printf("%s\n", msg);