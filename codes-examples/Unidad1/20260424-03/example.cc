#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int CANTIDAD_ELEMENTOS = 10;

void f01() {
    int j = 0;
    float m;
    for (int k = 0; k < 5; k++){
        m = m + 1;
        printf("k=%i\n", k);
    }
    printf("j=%i\n", j);
    printf("m=%f\n", m);
}

/*
    Implementación de
    \sum_{it=1}^N \frac{1}{N}

    La sumatoria debe dar siempre 1 \forall N

    Preguntas: 
        * ¿Por qué la implementación no calcula el valor teórico?
        * Si se cambia 1.0/iteraciones por 1/iteraciones, el resultado
          es total=0. ¿Por qué ocurre esto?
        * Cambie tipo de dato de la variable delta a double. Compile y ejecute el programa.
          Explique el nuevo valor que se obtiene en la variable total.

*/
void f02(){
 
    int iteraciones = 100;

    float delta = 1.0/iteraciones;

    float total = 0;
    for(int it = 0; it < iteraciones; it++){
        total = total + delta;
    }

    printf("total=%f\n", total);
}

/*
    Ejemplos de función con parámetro que es un arreglo.
    El arreglo, ¿se pasa por valor o por referencia?. Explique
    en base a la definición de lo que es un arreglo en C.
*/
void mostrarArreglo(int a[]) {
    for (int i = 0; i < CANTIDAD_ELEMENTOS; i++) {
        printf("a[%i]=%i\n", i, a[i]);
    }
}

void modificarArreglo(int z[]) {
    for (int w = 0; w < CANTIDAD_ELEMENTOS; w++) {
        z[w] = 200 + w;
    }
}

void driveArreglos() {

    int arr0[] = { 100, 101, 102, 103, 104 };

    mostrarArreglo(arr0);
    modificarArreglo(arr0);
    mostrarArreglo(arr0);

}


void f03(){

}


int main()
{
    //driveArreglos();
    //f01();
    //f02();

    return 0;
}