#include <stdio.h>

int main () {

    char array[] = {'A', 'B', 'C', 'D', 'E'};
    char *$array = array; //<Esta es la manera en la que se apunta a una array
    //Es equivalente a hacer > char *$array = &array[0];
    

    printf("Valor en la direccion de memoria del puntero => %c \n", *$array);
    printf("Valor en la direccion de memoria del puntero mas 1 => %c \n", *($array+1));

    //El puntero puede comenzar desde cualquier punto del array
    $array = &array[3];
    printf("Valor en la direccion de memoria del puntero => %c \n", *$array);
    printf("Valor en la direccion de memoria del puntero menos 1=> %c \n", *($array-1));
    
    $array = array;
    printf("Valor en la direccion de memoria del puntero => %c \n", *$array);
    printf("La direccion de memoria del primer elemento es = %p\n", $array);
    printf("La direccion de memoria del segundo elemento es = %p\n", $array+1);
    printf("La direccion de memoria del tercer elemento es = %p\n", $array+2);

    return 1;
}

//Una array es una secuencia de espacios en memoria, al sumarle uno al puntero que contiene
//la direccion de memoria del primer elemento, se pasa al segundo elemento.