#include <stdio.h>

//constantes
#define true 1
#define false 0
#define max_array 30


typedef struct {
    short int tope; //ultimo elemento que entra.
    short int vector[max_array];
} stack;

void crearPila(stack *Pila){
    Pila->tope=-1;
}

int estaVacia(stack *Pila){
    if(Pila->tope == -1){
        return true;
    } else {
        return false;
    }
}

int estaLlena(stack *Pila){

    if(Pila->tope ==max_array-1){
        return true;
    } else {
        return false;
    }
}

void agregarAPila(stack *Pila, int n){
    if(!estaLlena(Pila)){
        Pila->tope++;
        Pila->vector[Pila->tope] = n;

    } else {
        printf("La pila esta llena\n");
    }
}

void borrarDePila(stack *Pila){
    if(!estaVacia(Pila)){
        int temp = Pila->tope;
        Pila->tope--;

        printf("Si se extrajo el elemento %i |");
    } else {
        printf("La pila esta vacia\n");
    }
}
int main () {

    stack Pila;
    crearPila(&Pila);

    return 1;
}