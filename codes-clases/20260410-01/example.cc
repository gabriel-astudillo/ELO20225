#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen
#include <time.h>

/*
Descripción:
    Función que dado dos número enteros, retorna el valor
    decimal de la fracción que representan
Entradas:
    num: entero numerador
    den: entero denominador
Salida:
    División entre num y den. Flotante en doble precisión 
*/
double f01(int a, int b){
    double resultado;

    a = a + 10;
    b = b + 10;

    resultado = a / b;
    return resultado;
}


int main(){
	
    int a = 10;
    int b = 30;

    double resultado;
    resultado = f01(a,b);

    printf("resultado=%f\n", resultado);


    exit(EXIT_SUCCESS);
}
