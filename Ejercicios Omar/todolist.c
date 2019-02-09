#include <stdio.h>
#include <stdlib.h>
#define true 1 
#define false 0 

typedef struct lista {
    int valor;
    struct lista *sig;
} lista; 

void main () {
    int op = -1, x=0, y=0;
	lista *p=NULL;
	while ( op ){
        scanf("%i", &op);
        printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n ");
		printf( "x.\t\n Insertar al final de la lista sin permitir repetidos\n ");
        printf( "x.\t\n Eliminar numeros repetidos dejando la primera ocurrencia\n ");
        printf( "x.\t\n Eliminar numeros repetidos dejando la ultima ocurrencia\n ");
        printf( "x.\t\n Dejar un elemento impar y uno par mientras sea posible\n ");
        printf( "x.\t\n Determinar si la lista es simetrica\n ");
        printf( "x.\t\n Voltear la lista\n ");
        printf( "x.\tEliminar un numero todas las veces que lo encuentre\n\n");
		printf( "0.\tSALIR del sistema\n\n ");
		
		switch (op){
		case 1: printf("\n\nIndique dato a Insertar ");
		        scanf( "%i", &x);
		        insertar (&p, x);
		        break;
        }
    }
}