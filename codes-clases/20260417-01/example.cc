#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen


double f01(double a, double b)
{
    double resultado;

    printf("f01: &a=%p\n", &a);

    resultado = a + b;
    return resultado;
}

int main()
{

    int a, b;
    int resultado;

    a = 4;
    b = 5;

     // Ejemplo: mostrar la dirección de memoria de la variable a:
    printf("main: &a=%p\n", &a);

    resultado = f01(a, b);
    printf("resultado f01()=%f\n", resultado);

    // Por ejemplo, la siguiente instrucción significa:
    //      1) Guarde la dirección de la variable a en la variable ptr_a. Esto es factible
    //         ya que ptr_a está definida como un puntero (a su izquierda está el símbolo *)
    //      2) Esa dirección de memoria, hace referencia a un contenido que es un int (4 Bytes)
    int* ptr_a = &a;

    exit(EXIT_SUCCESS);
}
