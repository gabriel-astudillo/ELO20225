# ELO20225 Tarea 1
## Parte 1

### Objetivo

Realizar mediciones de tiempo de ejecución en un código sencillo con el fin de evidenciar
las diferencias que existe entre usar la memoria del sistema y un sistema de Entrada/Salida.

### Descripción

El trabajo a realizar en esta parte, consta de N hitos:

#### Hito 1

Analizar la función `cicloEjemplo()`:

```
double cicloEjemplo(){
    int64_t cantidadIteraciones;
    double tiempoTotal;
    uint64_t inicio, fin;

    cantidadIteraciones = 1e6;
    tiempoTotal = 0.0;

    inicio = clock(); 
    for(int64_t i=0; i<cantidadIteraciones; i++){
        printf("*");
    }
    fin = clock(); 
    printf("\n");

    tiempoTotal = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;

    double tiempoPromedio = tiempoTotal / (double)cantidadIteraciones;

    return tiempoPromedio;
}
```

Para evidenciar su análisis, debe responder las siguientes preguntas:

1) Qué es lo que retorna la función `clock()`.
2) Qué unidades tienen las variables `inicio` y `fin`.
3) Por qué para obtener el tiempo total de duración del ciclo `for` se debe dividir la diferencia entre `fin` e `inicio` con el valor constante `CLOCKS_PER_SEC`.
4) Explicar que hace `(double)` como prefijo de  `(fin - inicio))`
5) Explicar para que sirve utilizar `(double)` como prefijo de `(fin - inicio))`


#### Hito 2

Utilizando como base la función `cicloEjemplo()`, crear otra función, llamada `cicloPrueba(caso_t caso)`. La variable `caso` es un enum que tiene los valores `{VACIO, ESPACIO, ASTERISCO, NEWLINE}`.

La función `cicloPrueba(caso_t caso)` permitirá medir el tiempo promedio que toma el procesador en realizar un ciclo vacío, mostrar un espacio, un asterisco y un salto de línea.

Un ejemplo de ciclo de 10 iteraciones vacío es:

```
for(int t=0; t<10; i++){
    ;
}
```

Un ejemplo de ciclo de 10 iteraciones que muestra un letra 'a' es:

```
for(int t=0; t<10; i++){
    printf("a");
}
```

Para evidenciar el trabajo de este hito, es necesario que en su informe presente y explique su implementación en base a un diagrama de flujo. Cada parte del código de la función implementada debe estar explicada tanto en el diagrama como en lenguaje natural.

#### Hito 3

Una vez realizado la implementación anterior, deberá ejecutar 10 veces el programa compilado, tabular los resultados y determinar promedios y desviación estándar de los tiempos obtenidos en cada caso. Un ejemplo de datos tabulados se muestra en la siguiente tabla.

| Caso      	| tprom 1 	| tprom2 	| ... 	| tprom10 	| Promedio 	| Desv. Estandar 	|
|-----------	|---------	|--------	|-----	|---------	|----------	|----------------	|
| NADA      	| 3.6     	| 9.8    	| ... 	| 7.5     	| 6.78     	| 1.27           	|
| ESPACIO   	| 172.71  	| 132.79 	| ... 	| 196.25  	| 154.89   	| 1.53           	|
| ASTERISCO 	| 132.79  	| 196.25 	| ... 	| 172.71  	| 156.32   	| 1.67           	|
| NEWLINE   	| 696.25  	| 796.95 	| ... 	| 876.59  	| 789.45   	| 2.34           	|


En base a los datos agregados (promedio y desviación estándar), explique las diferencias que se obtienen entre los distintos casos.

