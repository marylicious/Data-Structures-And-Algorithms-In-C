#include <stdio.h>
#include <stdlib.h>
#define true 1 
#define false 0 

typedef struct lista {
    int valor;
    struct lista *sig;
} lista; 

void insertar( lista **cab, int x){
	/* inserta x por el comienzo de la lista p */
	lista *t;
	t= malloc(sizeof(lista));
	t->valor = x;
	t->sig  = *cab;
	*cab = t;
}

void eliminar ( lista **p, int x){
	/* elimina la primera ocurrencia del valor x en la lista p */
	lista *t=*p;
	if (t)
	   if (t->valor==x){
	   	   *p=(*p)->sig;
	   	   free( t);
	   }
	   else {
	   	   while ((t->sig)&&(t->sig->valor != x)) t=t->sig;
	   	   if (t->sig){
	   	   	   lista *aux= t->sig;
	   	   	   t->sig = t->sig->sig;
	   	   	   free( aux );
			  }
	   }
}

void mostrar ( lista *cab){
	/* muestra por pantalla la lista enlazada */
	lista *t = cab;
	//agregar system("cls"); 

	printf( " Cab ");
	while (t){
		printf("->[%i]", t->valor);
		t= t->sig;
	}
	printf("->NULL\n\n");
}

void intercalarCasillas(lista **cabb, lista **caba){
	lista *auxA = *caba, *auxB = *cabb, *previo;
	
	if(!cabb){
		*cabb= *caba;
		*caba = NULL;
	}

	while (auxA && auxB) {
		*caba=(*caba)->sig;
		previo=auxA;
		auxA->sig = auxB->sig;
		auxB->sig = auxA;
		auxB = auxA->sig;
		auxA=*caba;
	}

	if(!auxB && auxA) {
		previo->sig=*caba;
		*caba=NULL;
	}
}


void parImpar(lista **ca, lista **cb){
	
	//Enlazo pares de A en B

	lista *auxB=*cb, *auxA = *ca;


	while(auxB && auxB->sig) auxB=auxB->sig;

	//Enlazo pares del cuerpo de A

	while(auxA && auxA->sig) {

		if((auxA->sig->valor) % 2 == 0) {
			auxB->sig = auxA->sig;
			auxA->sig = auxA->sig->sig;
			auxB->sig->sig=NULL;
			auxB= auxB->sig;
		}
		else {
			auxA=auxA->sig;
		}
	}

	//Enlazo cabeza de A si es par 

	if((*ca)->valor%2== 0){
		auxB->sig= *ca;
		*ca = (*ca)->sig;
		auxB->sig->sig= NULL;
	}

	//Enlazo impares de B al final de A

	auxB=*cb; auxA=*ca;

	while(auxA && auxA->sig) auxA=auxA->sig;

	while(auxB && auxB->sig) {

		if((auxB->sig->valor) % 2 != 0) {
			auxA->sig = auxB->sig;
			auxB->sig = auxB->sig->sig;
			auxA->sig->sig=NULL;
			auxA= auxA->sig;
		}
		else {
			auxB=auxB->sig;
		}
	}

	if((*cb)->valor%2!= 0){
		auxA->sig= *cb;
		*cb = (*cb)->sig;
		auxA->sig->sig= NULL;
	}
}

void eliminarComunes(lista **ca, lista **cb){
	
	lista *auxA,*auxB, *recorrido=*ca;
	int num,repetido;

	while(recorrido){

		repetido = 0;
		num = recorrido->valor;
		auxB = *cb;

		while(auxB && auxB->sig){
			
			if(auxB->sig->valor == num) {
				lista *eliminar = auxB->sig;
				auxB->sig = auxB->sig->sig;
				free(eliminar);
				repetido=1;
			} else {
				auxB=auxB->sig;
			}
		}


		if((*cb)->valor == num){
			lista *eliminar = *cb;
			*cb= (*cb)->sig;
			free(eliminar);
			repetido=1;
		}

		if(repetido){

			auxA=*ca;
			//elimino posibles repeticiones en A
			while(auxA && auxA->sig) {
			
				if(auxA->sig->valor == num) {
					lista *eliminar = auxA->sig;
					auxA->sig = auxA->sig->sig;
					free(eliminar);
				} else {
				auxA=auxA->sig;
				}
			}

			if((*ca)->valor == num){
				lista *eliminar = *ca;
				*ca= (*ca)->sig;
				free(eliminar);
			}
		}

		recorrido=recorrido->sig;
	}
}

void mezclarAB(lista **cabA, lista **cabB){

	lista *auxA=*cabA, *auxB, *finalB=*cabB;

	if(*cabB){
		while(finalB&&finalB->sig) finalB=finalB->sig;
	}
	

	if(!(*cabA) && *cabB){
		
		if(finalB!=*cabB){
				auxB=*cabB;
				while(finalB!=auxB->sig) auxB=auxB->sig;
		}

		*cabA=finalB;

		if(auxB) auxB->sig = NULL;
	}

	if(*cabA){	

		while(*cabB){
			
			if(finalB!=*cabB){
				auxB=*cabB;
				while(finalB!=auxB->sig) auxB=auxB->sig;
			}

			finalB->sig = auxA->sig;
			auxA->sig = finalB;

			
			if(finalB!=*cabB){
				auxB->sig=NULL;
				finalB=auxB;
			} else {*cabB=NULL;}

			auxA = auxA->sig->sig;
			
			if(!auxA){
				auxA=*cabA;
				while(auxA&&auxA->sig) auxA=auxA->sig;
			}

		}
	}
}

void colocarValorAenPosB(lista **A, lista **B){
	lista *auxA=*A, *auxB=*B;
	int num, cont;

	if(*A && *B){
		while(auxA){
			
			num=auxA->valor;
			
			if(num == 1){
				lista *t=malloc(sizeof(lista));
				t->valor=num;
				t->sig=*B;
				*B=t;
			} else {
				auxB=*B; cont=1;

				while(auxB&& auxB->sig){
					cont++;
					if(cont<num){
						auxB=auxB->sig;
					} else break;
				}

				if(cont>=num){
					lista *t= malloc(sizeof(lista));
					t->valor=num;
					t->sig=auxB->sig;
					auxB->sig=t;		
				}

				
			}

			auxA=auxA->sig;
		}
	}
}


void main () {
    int op = -1, x=0, y=0;
	lista *a=NULL, *b=NULL;
	while ( op ){
        
        printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n");
        /*printf( "1.\tInsertar numero en lista a\n");
        printf( "2.\tInsertar numero en lista b\n");
        printf( "3.\tEliminar numero en lista a\n");
        printf( "4.\tEliminar numero en lista b\n");
        printf( "5.\tMostrar lista a\n");
        printf( "6.\tMostrar lista b\n");
		printf( "7.\tIntercalar listas\n");
		printf( "8.\tDejar pares en A e impares en B(problema borde)\n");
		printf( "9.\tEliminar numeros comunes\n");
		printf( "10.\tMezclar A con B(pero B desde atras) sin voltear B ni estructuras auxiliares\n");*/
		printf( "11.\tMostrar listas b\n");
		printf( "12.\tInserte (mueva) cada valor de A, digamos x, en la posicion x de B \n");
		printf( "0.\tSALIR del sistema\n\n ");
        scanf("%i", &op);
		
		switch (op){
		case 1: printf("\n\nIndique dato a Insertar\n");
		        scanf( "%i", &x);
		        insertar (&a, x);
		        break;
        case 2: printf("\n\nIndique dato a Insertar \n");
		        scanf( "%i", &x);
		        insertar (&b, x);
		        break;
        case 3: printf("\n\nIndique dato a eliminar \n");
		        scanf( "%i", &x);
		        eliminar (&a, x);
		        break;
        case 4: printf("\n\nIndique dato a eliminar\n ");
		        scanf( "%i", &x);
		        eliminar (&b, x);
		        break;
        case 5: printf("Lista a es => ");
		        mostrar(a);
		        break;
        case 6: printf("Lista b es => ");
		        mostrar(b);
		        break;
		case 7: intercalarCasillas(&b,&a);
		        break;
		case 8: parImpar(&a,&b);
				break;
		case 9: eliminarComunes(&a,&b);
				break;
		case 10: mezclarAB(&a,&b);
				break;
		case 11: printf("Lista a es => ");
		        mostrar(a);
				printf("Lista b es => ");
		        mostrar(b);
				break;
		case 12: colocarValorAenPosB(&a, &b);
				break;
        }
    }
}