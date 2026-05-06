#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen

/*
Estructura de una función:
«tipo de dato que se retorna» «nombre de la función»(«parámetros separados con coma»)

Todas las variables que son declaradas dentro
del ámbito de la función, significa que son variables
locales a la función. Esto incluye los parámetros.
*/

/*
    Ejemplo de función que dos parámetros enteros y retorna un double.
    Se debe recordar que las variables declaras en la función son locales
    a ella: a, b, resultado.

    Por omisión, cuando la función se llama, los argumentos de COPIAN
    en los parámetros en el mismo orden.
*/
double f01(int a, int b)
{
    double resultado;

    printf("f01: &a=%p\n", &a);

    // Para que C puede dividir dos números enteros y realizar
    // la división en el conjunto de los punto flotante, se debe
    // hacer un cast de por lo menos uno de los operandos.
    resultado = a / (double)b;
    return resultado;
}

double f02(double a, double b)
{
    double resultado;

    printf("f02: &a=%p\n", &a);

    resultado = a + b;
    return resultado;
}

int main()
{

    int a = 3;
    int b = 4;

    double resultado;

    resultado = f01(a, b);
    printf("resultado f01()=%f\n", resultado);

    resultado = f02(a, b);
    printf("resultado f02()=%f\n", resultado);

    // Siempre se debe recordar que toda variable
    // es una dirección de memoria. La dirección de memoria
    // de una variable se puede conocer utilizando el operador &.
    // Ejemplo: mostrar la dirección de memoria de la variable a:
    printf("main: &a=%p\n", &a);

    // Una dirección de memoria se puede guardar en una variable especial,
    // llamada puntero. Un puntero se especifica con el símbolo *.
    // Para que el lenguaje pueda determinar cuál es el tamaño del dato
    // que se es referenciado por la dirección de memoria guardada en el puntero,
    // se debe especificar el tipo de dato respectivo.
    // Por ejemplo, la siguiente instrucción significa:
    //      1) Guarde la dirección de la variable a en la variable ptr_a. Esto es factible
    //         ya que ptr_a está definida como un puntero (a su izquierda está el símbolo *)
    //      2) Esa dirección de memoria, hace referencia a un contenido que es un int (4 Bytes)
    int* ptr_a = &a;

    exit(EXIT_SUCCESS);
}
