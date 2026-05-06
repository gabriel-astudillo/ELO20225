#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen


int determinarTipoDia(int dia){
    int tipo;
    if(dia >= 0 && dia <= 4){
        tipo = 0;
    }else{
        tipo = 1;
    }

    return tipo;
}

int main(int argc, char* argv[]) {

    int diaPrueba;
    int tipo;

    diaPrueba = 2;

    tipo = determinarTipoDia(diaPrueba);


    if (tipo == 0){
        printf("El día es hábil\n");
    }
    else if(tipo == 1){
        printf("El día es inhábil\n");
    }
    
    exit(EXIT_SUCCESS);
}

