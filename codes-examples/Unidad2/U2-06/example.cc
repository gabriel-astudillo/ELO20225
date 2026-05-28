#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void casoConversion01(){
    int n0;
    int n1;
    float res0;
    
    /*
        la división de dos enteros da un resultado entero.
    */
    n0 = 10;
    n1 = 3;
    res0 = n0 / n1;
    printf("=== División de enteros ===\n");
    printf("res0=%f\n", res0); // Muestra 3.0000

    /*
        Para obtener el valor fraccionario, se debe forzar
        la conversión de n0 ó n1 a float.
    */
    n0 = 10;
    n1 = 3;
    res0 = (float)n0 / n1;
    printf("=== División de enteros convertidos a float ===\n");
    printf("res0=%f\n", res0); // Muestra 3.33333

    res0 = n0 / (float)n1;
    printf("res0=%f\n", res0); // Muestra 3.33333

}

/*
    Caso conversión de tipo de datos en forma implícita.
    En este caso, se muestra la conversión implícita entre el contenido
    de la variable 'a' y la variable de destino 'b'. 
    Esta es una prueba de conversión de tipo de datos con pérdida de datos.
    Lo anterior se debe a que la variable origen es un entero de 32 bits, 
    que posee un cierto rango de representación numérica y la variable destino es un entero de 8 bits,
    que tiene un rango menor de representación.
*/
void casoConcersion02(){
    int32_t a;
    int8_t b;

    a = 49153;
    b = a;

    printf("a=%i\n", a);
    printf("b=%i\n", b);

    // Debe justificar el valor de la variable 'b'.
}

void casoConversion03(){
    /*
        Si se realiza la conversión entre, por ejemplo,
        un entero de 32 bits a un de 8 bits, se perderán
        los bits más significativos del número. Algunas veces
        se visualizará esta pérdida. Esto depende del valor que 
        tenga la variable orignal y el tipo de dato de la variable
        destino.
    */
   int n0;
   int n1;
   

    //Caso pérdida visible
    n0 = 65535;

    // Debido a que el valor de t0 utiliza más de 8 bits,
    // la siguiente conversión va a producir pérdida de datos
    n1 = (int8_t)n0;

    printf("=== Caso pérdida visible ===\n");
    printf("n0=%i\n", n0);
    printf("n1=%i\n", n1);


    //Caso pérdida oculta
    n0 = 65;

    // Debido a que el valor de t0 utiliza más de 8 bits,
    // la siguiente conversión va a producir pérdida de datos
    n1 = (int8_t)n0;

    printf("=== Caso pérdida oculta ===\n");
    printf("n0=%i\n", n0);
    printf("n1=%i\n", n1);

    uint32_t test01 = (uint8_t)0x0FAABBCC;
    printf("test01=0x%X\n", test01);
}



int main(int argc, char* argv[]) {
    
    casoConversion03();


    exit(EXIT_SUCCESS);
}

