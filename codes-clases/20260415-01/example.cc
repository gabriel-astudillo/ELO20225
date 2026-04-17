#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen


double f01(int a, int b){
    double resultado;

    printf("f01: &a=%p\n", &a);

    resultado = a / (double)b;
    return resultado;
}

double f02(double a, double b){
    double resultado;

    printf("f02: &a=%p\n", &a);

    resultado = a + b;
    return resultado;
}

int main(){
	
    int a = 3;
    int b = 4;

    double resultado;
    
    resultado = f01(a,b);
    printf("resultado f01()=%f\n", resultado);

    resultado = f02(a,b);
    printf("resultado f02()=%f\n", resultado);

    printf("main: &a=%p\n", &a);

    int* ptr_a = &a;

    

    exit(EXIT_SUCCESS);
}
