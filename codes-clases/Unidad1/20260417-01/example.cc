#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen


double f01(double a, double b)
{
    double resultado;
    resultado = a + b;

    return resultado;
}

void f02(double a, double b, double* resultado){
    *resultado = a + b;
}

/*
Esta es una prueba de funcionamiento para:
   1) paso de argumentos por valor.
   2) conversión implícita de tipo de tipos.
*/
void prueba01(){
    int a, b;
    float resultado;

    a = 4;
    b = 5;

    printf("=Antes de f01()=\n");
    printf("main: a = %i\n", a);
    printf("main: b = %i\n", b);
    resultado = f01(a, b);
    printf("=Después de f01()=\n");
    printf("main: a = %i\n", a);
    printf("main: b = %i\n", b);
    printf("resultado = %f\n", resultado);
}
/*
    Funcionamiento básico de punteros
*/
void prueba02(){
    int a = 10;

    // Mostrar la dirección de memoria de la variable a
    printf("&a = %p\n", &a);

    // guardar la dirección de memoria de una variable.
    // Para esto, se necesita un tipo especial de variable
    // que se llama puntero. La sintaxis de declaración
    // para estas variables es que el símbolo '*' está al lado
    // izquierdo del nombre de la variable.
    // Además, para acceder al dato que es referenciado por 
    // dicha dirección, se debe agrega el tipo de contenido
    // que guarda dicha dirección.

    // Pr ejemplo, la dirección de la variable 'a' se guarda en el
    // puntero 'ptr_a'. Además, se informa al lenguaje que el dato 
    // de la variable 'a' es de tipo entero.
    int* ptr_a = &a;

    // Se muestra el contenido de la variable 'ptr_a':
    printf("ptr_a  = %p\n", ptr_a);

    // Con el operador '*', se puede acceder al dato que es referenciado
    // por la dirección guardada en el puntero 'ptr_a':
    printf("*ptr_a = %i\n", *ptr_a);

    // También se puede modificar el contenido de la dirección de memoria
    // almacenada en el puntero:
    *ptr_a = 51;
    printf("a      = %i\n", a);
    printf("*ptr_a = %i\n", *ptr_a);
}

/*
    Prueba de concepto de paso de referencia 
*/
void prueba03(){
    int a0 = 20;
    int b0 = 30;
    double res;
    f02(a0, b0, &res);

    printf("res=%f\n", res);

}

int main()
{
    //prueba01();
    //prueba02();
    prueba03();

    exit(EXIT_SUCCESS);
}
