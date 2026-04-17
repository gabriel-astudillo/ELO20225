#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
    Un enum permite definir un conjunto cerrado de valores relacionados 
    bajo un mismo nombre de tipo.
    El primero valor de un enum siempre está asociado al valor entero 0.

*/    

// Por ejemplo, los valores del tipo de dato diaSemana son: 
// LUNES,...,DOMINGO. 
// No pueden ser otros valores
// Al declara el siguiente enum, también se está crean un nuevo tipo
// de datos: diaSemana_t
// En C, los tipos de datos creados, SIEMPRE se deben terminar en _t.
enum diaSemana_t {
  LUNES,
  MARTES,
  MIERCOLES,
  JUEVES,
  VIERNES,
  SABADO,
  DOMINGO
} ;

enum tipoDia_t{
    HABIL,
    INHABIL
};

tipoDia_t determinarTipoDia(diaSemana_t dia){
    tipoDia_t tipo;
    if(dia >= LUNES && dia <= VIERNES){
        tipo = HABIL;
    }else{
        tipo = INHABIL;
    }

    return tipo;
}

int main(int argc, char* argv[]) {

    diaSemana_t diaPrueba;
    tipoDia_t tipo;

    diaPrueba = MIERCOLES;

    tipo = determinarTipoDia(diaPrueba);

    if (tipo == HABIL){
        printf("El día es hábil\n");
    }else{
        printf("El día es inhábil\n");
    }
    
    
    exit(EXIT_SUCCESS);
}

