#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    double a0 = 10.0;
    double a1 = 20.0; 
    float  a2 = 30.0;
    int    a3 = 40;
   
    // Acceso a las direcciones de memoria de cada variable 
    // con el operador &
    printf("=== Direcciones de memoria ===\n");
    printf("a0: %p\n", &a0);
    printf("a1: %p\n", &a1);
    printf("a2: %p\n", &a2);
    printf("a3: %p\n", &a3);

    // Guardar direcciones de memoria de cada variable en
    // un puntero.
    double* p0 = &a0;
    double* p1 = &a1;
    float*  p2 = &a2;
    int*    p3 = &a3;
    printf("=== Direcciones de memoria ===\n");
    printf("a0: %p\n", p0);
    printf("a1: %p\n", p1);
    printf("a2: %p\n", p2);
    printf("a3: %p\n", p3);

    /*
        Direcciones de memoria en un arreglo
        En un arreglo, se mantiene la idea que la variable es una etiqueta
        de una dirección de memoria, la que es el inicio de un especio continuo
        de registros de 1 Byte, cuya cantidad depende exclusivamente del tipo de
        datos de la variable.
        Esto significa, que el nombre del arreglo es también una dirección de memoria.
        El tamaño delespacio continuo de datos depende no sólo del tipo de datos, si no 
        que, además, de la cantidad total registros solicitados 
    */
    double arr0[] = {10.0, 20.0, 30.0, 40.0};
    printf("=== Tamaño del arreglo arr0 ===\n");
    printf("sizeof(arr0): %lu Bytes\n", sizeof(arr0));
    printf("=== Tamaño de un elemento del arreglo arr0 ===\n");
    printf("sizeof(arr0[0]): %lu Bytes\n", sizeof(arr0[0]));  

    printf("=== Direcciones de memoria del arreglo arr0 ===\n");
    printf("arr0   : %p\n", arr0);
    printf("arr0[0]: %p\n", &arr0[0]);
    printf("arr0[1]: %p\n", &arr0[1]);
    printf("arr0[2]: %p\n", &arr0[2]);
    printf("arr0[3]: %p\n", &arr0[3]);

    // Una dirección de memoria de un elemento de un arreglo se puede guardar, como
    // de costrumbre, en un puntero, ya que este tipo de variables almacenan direcciones
    // de memoria.
    double* prt_test = &arr0[2];

    // Como se tiene la dirección del elemento 2 de arr0, entonces se puede modificar a través
    // de ella:
    *prt_test = 300.0;
    printf("arr0[2]= %f\n", arr0[2]);

    


    exit(EXIT_SUCCESS);
}

