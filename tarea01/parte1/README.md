# ELO20225 Tarea 1
## Parte 1

### Objetivo

Implementar código modular a partir de una solución monolítica. Utilizar tipos de datos `enum` para mejorar la legibilidad del código.

### Descripción

A partir del código inicial en la función `main()`:

```
int main(int argc, char* argv[]) {
    int sensores[NUM_SENSORES];

    // Inicializar los sensores
    for (int i = 0; i < NUM_SENSORES; i++) {
        sensores[i] = 0;
    }

    // Realizar lectura de los sensores
    for (int i = 0; i < NUM_SENSORES; i++) {
        sensores[i] = lecturaSensor();
    }

    // Mostrar los resultados
    for (int i = 0; i < NUM_SENSORES; i++) {
        printf("Sensor %i: %i [mV]\n", i, sensores[i]); 
    }
    
    exit(EXIT_SUCCESS);
}
```
Se debe implementar la función `lecturaSensor()`. Se debe considerar la descripción de dicha función. Sus parámetros no deben ser alterados. Una vez realizado la implementación, el código anterior debe ser reemplazado por el siguiente:

```
int main(int argc, char* argv[]) {
    int sensores[NUM_SENSORES];
    
    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}
```

La ejecución del nuevo programa debe ser similar al original. Obviamente, sólo cambiarán los valores simulados ya que son aleatorios.

Para evidenciar el trabajo de esta parte, es necesario que en su informe presente y explique su implementación en base a un diagrama de flujo. Cada parte del código de la función implementada debe estar explicada tanto en el diagrama como en lenguaje natural.

