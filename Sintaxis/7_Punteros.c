#include <stdio.h>

int main () {
    
    int x=16;
    int *$puntero; //declaracion de un puntero con *
    //PD> el $ no es necesario, el del curso utiliza $ identificar variables punteros de variables normales
    
    //& > operador de direccion
    // * > operador de indireccion 
    //nos permite declarar un tipo de dato puntero, también nos permite ver el
    // VALOR que está en la dirección asignada.

    //Importante> los punteros deben ser del mismo tipo a la variable a la que van a apuntar.


    $puntero = &x; //le asigno a puntero la direccion de memoria de x;

    printf("El valor de x es %i \n", x);

    //Direccion en la memoria ram de esa variable
    printf("La direccion de memoria de x es %p \n",&x);

    printf("La direccion de memoria de x desde puntero es %p \n", $puntero);

    printf("El valor de la direccion de memoria alojada en el puntero es %d \n", *$puntero);

    printf("La direccion de memoria del puntero como tal %p \n", &$puntero);

    //Importante no podemos buscar el valor en una direccion de memoria de un puntero que no tiene guardado una direccion de memoria

    return 1;
}