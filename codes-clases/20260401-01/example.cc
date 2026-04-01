#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen
#include <time.h>

int main(int argc, char* argv[]) {

    double d0;
    char c0 = 'a';
    int32_t i0 = 56;
    int tamTotal = sizeof(d0) + sizeof(c0) + sizeof(i0);
    printf("tamTotal=%i Bytes\n", tamTotal);


    // Se declara la variable voltajes
    // como un arreglo ==> []
    // Este arreglo va a almacenar 200
    // datos de tipo double
    double voltajes[200];

    printf("tamaño voltajes= %lu Bytes\n", sizeof(voltajes));
    printf("tamaño voltajes[0]= %lu Bytes\n", sizeof(voltajes[0]));

    char mensaje[] = "holas";
    printf("tamaño mensaje= %lu Bytes\n", sizeof(mensaje));
    printf("largo mensaje= %lu simbolos\n", strlen(mensaje));
    

    
    
    exit(EXIT_SUCCESS);
}
