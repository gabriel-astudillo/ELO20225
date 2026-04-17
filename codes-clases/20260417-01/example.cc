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

void prueba02(){
    int a = 10;
    printf("&a = %p\n", &a);

    int* ptr_a = &a;
    printf("ptr_a  = %p\n", ptr_a);
    printf("*ptr_a = %i\n", *ptr_a);

    *ptr_a = 51;
    printf("a      = %i\n", a);
    printf("*ptr_a = %i\n", *ptr_a);

    int a0 = 20;
    int b0 = 30;
    double res;
    f02(a0, b0, &res);

    printf("res=%f\n", res);


}

int main()
{
    //prueba01();
    prueba02();

    exit(EXIT_SUCCESS);
}
