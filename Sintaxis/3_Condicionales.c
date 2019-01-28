//condicionales
#include <stdio.h>
#include <string.h> //para operar con strings

//COMPARADORES

//xor -> no existe
//or ||
//and &&
// not !
// == igual
//!= diferente

void main () {

    if (1==1) {
        printf("if");
    } else if (2>1) {
        printf("else if");
    } else {
        printf("else");
    }

    printf("\n");

    //Ternary operator

    int x = (1==1)? 5:6;

    printf("x es %i \n", x);

    //switch statement

    int y = 12; //variable guia del switch
    char aux[22]; //si no le asigno valor, tengo que poner el tama#o de la string

    switch(y) {
        case 12: 
            strcpy(aux, "y es 12"); //asigna valor a la string
        break;
        case 16:
            strcpy(aux, "y es 16");
        break;
        default:        
            strcpy(aux, "y no es ni 12 ni 16");
        break;
    }

    printf("aux es  => %s", aux);
}
