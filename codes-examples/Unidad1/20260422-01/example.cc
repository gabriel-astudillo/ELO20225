#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen


enum estadosPosibles_t{
    APROBADO,
    REPROBADO,
    NOSESABE,
    QUIZAS
};


int main() {
    

    estadosPosibles_t estadoEstudiante;

    estadoEstudiante = APROBADO;

    if(estadoEstudiante == REPROBADO){
        printf("El estudiante está reprobado");
    }
    else if(estadoEstudiante == APROBADO){
        printf("El estudiante está aprobado");
    }
    else if(estadoEstudiante == NOSESABE){
        printf("El estudiante dara examen en marzo");
    }
    

    return EXIT_SUCCESS;
}

/*
 

*/