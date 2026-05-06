#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen
#include <time.h>

int pinEntrada = 0;
int ciclosRealizados = 0;
int resultado = 100;

void funcion01(){
	int ciclosRealizados = 0;
	int resultado = 0;
	for(int i=0; i<10; i++){
		resultado = resultado + i*2;
		ciclosRealizados += 1;
	}
} 

int main(){
	printf("1) ciclosRealizados=%i\n", ciclosRealizados);
	funcion01();
	printf("2) ciclosRealizados=%i\n", ciclosRealizados);
    int suma = 0;
	for(int j=0; j<10; j++){
		suma = suma + j*2;
		ciclosRealizados += 1;
	}
	printf("3) ciclosRealizados=%i\n", ciclosRealizados);
	funcion01();
	printf("4) ciclosRealizados=%i\n", ciclosRealizados);
    exit(EXIT_SUCCESS);
}


 

//char msg[] = "ELO20225"; // 45 4c 4f 32 30 32 32 35 00
//printf("%s\n", msg);