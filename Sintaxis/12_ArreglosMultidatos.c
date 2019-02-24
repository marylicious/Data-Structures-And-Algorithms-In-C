#include <stdio.h>
//Creando el tipo carro
typedef struct {
        unsigned short int ruedas;
        char *modelo;
        char *carro;
} Carro; 
     
int main () {

    //Matriz de tipo carro.
    Carro MiCarro[2];

    //Llenado de datos
    MiCarro[0].ruedas = 4;
    MiCarro[0].modelo = "911";
    
    //Punteros a Structs 
    Carro Car, *P; //puntero tipo Carro
    

    Car.ruedas = 4;

    //Pasamos la direccion de memoria de Car a P
    P= &Car;

    //Acceder desde el puntero a la propiedad ruedas
    P -> ruedas = 16;
    //otra manera
    (*P).ruedas = 16;

    //Punteros a arreglos de structs
    Carro Arreglo[2];
    Arreglo[1].ruedas=5;

    P = Arreglo; //no se utiliza el &

    //imprimir las ruedas en el segundo elemento de arreglo desde el puntero
    printf(" las ruedas son => %i \n", (P+1)-> ruedas);

    return 1;
}
