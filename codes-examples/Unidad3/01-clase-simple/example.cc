#include <cstdio>
#include <cstdlib>
#include <cstring>

class A{
    private:
    int a0;
    int a1;

    public:

    // Constructor por omisión
    A(){
        // Configurar los valores por omisión de los atributos
        // En este caso, como ejemplo, se opta por los valores 0 y -1
        this->a0 = 0;
        this->a1 = -1;
    }

    // Constructor adicional
    A(int a0, int a1){
        this->a0 = a0;
        this->a1 = a1;
    }

    // Se asume que se necesitan todos los setter y getters de todos los atributos.
    void setA0(int a0){
        this->a0 = a0;
    }

    void setA1(int a1){
        this->a1 = a1;
    }

    int getA0(){
        return this->a0;
    }

    int getA1(){
        return this->a1;
    }

};

void mostrarAtributos(A* clase){
    // Mostrar el valor del atributo a0:
    printf("a0 : %i\n", clase->getA0() );

    // Mostrar el valor del atributo a1:
    printf("a1 : %i\n", clase->getA1() );
}

int main(int argc, char* argv[]) {
    // Códigos de prueba de la clase A

    // Prueba unitaria 1: 
    //   Crear objeto de la clase A con 
    //   el constructor por omisión
    // Resultado esperado:
    //    Los valores de los atributos del objeto
    //    creado deben ser los por omisión.
    printf("====prueba 1=====\n");
    A* test01 = new A();
    mostrarAtributos(test01);


    // Prueba unitaria 2: 
    //   Crear objeto de la clase A con 
    //   el constructor con parámetros
    // Resultado esperado:
    //    Los valores de los atributos del objeto
    //    creado deben ser los ingresados en el constructor.
    printf("====prueba 2=====\n");
    A* test02 = new A(19, 74);
    mostrarAtributos(test02);

    // Prueba unitaria 3:
    //   Con el objeto test02, cambiar el valor del atributo a0
    // Resultado esperado:
    //   se debe observar un cambio en el valor sólo del atributo a0.
    printf("====prueba 3=====\n");
    test02->setA0(-73);
    mostrarAtributos(test02);

    exit(EXIT_SUCCESS);
}

