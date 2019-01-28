#include <stdio.h>

void main () {
    
    //Incremento y decremento
    
    // int x = 1
    //x++; suma 1 --- equivalente x= x+1;
    //x--; resta 1

    //For loop
    //for (valorinicial;valordesalida;incremento/decremento)

    int x;

    printf("For loop \n");
    for (x=0;x<=10;x++) {
       
        printf("x es %i \n",x);
        //Importante: no se deben declarar variables dentro de un bucle
    }

    printf("While loop \n");
    while (x<=30) {
        printf("x es %i \n",x);

        //rompe el ciclo cuando llega a 20 --- no estoy segura si es buena practica
    
        if (x==20) {
            break;
        }
        x++;
    }

    printf("Do while loop \n");
    //a diferencia del repeat until se repite siempre que la condicion sea verdadera
    do {
       
        printf("x es %i \n",x);
         x++;
    } while (x<=30);

}