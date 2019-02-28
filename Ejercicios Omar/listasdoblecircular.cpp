#include <stdio.h>
#include <stdlib.h>

struct doble {
    int valor;
    doble *prev, *prox;
};

void insertarAlFinal(doble **p, int x){

    doble *nuevo = new doble;
    nuevo->valor = x;

    if(*p){
        
        (*p)->prev=nuevo;
        doble *aux= *p;
        
        while(aux && aux->prox!= *p) {
            aux=aux->prox;
            
        }

        aux->prox=nuevo;
        nuevo->prev=aux;
        nuevo->prox=*p;
    
    } else {
        nuevo->prev=nuevo;
        nuevo->prox=nuevo;
        *p=nuevo;
    }
}


void mostrar(doble *p){
    doble *aux=p;

    printf("\nVerificando enlace prox\n");

    printf("\n Cab <->");

     while(aux && aux->prox!=p){
        printf("[%i]<->", aux->valor);
        aux=aux->prox;
     }

     if(aux){
         printf("[%i]<->", aux->valor);
     }
            

    printf("Cab \n");

    printf("\nVerificando enlace prev\n");

    printf("\n Cab <->");
    
    
    if(p){
    aux=p->prev;

     while(aux && aux!=p){
        printf("[%i]<->", aux->valor);
        aux=aux->prev;
     }

     if(aux){
         printf("[%i]<->", aux->valor);
     }      
    }

    printf("Cab \n");

}

void insertarLuegoDeValorDado(doble **p, int x, int y){
    //insertar y despues de x o al final
    doble *nuevo= new doble;
    nuevo->valor=y;
    doble *aux=*p;

    while(aux && aux->valor!=x && aux->prox!= *p){
        aux=aux->prox;
    }

    if(*p){
        nuevo->prox=aux->prox;
        nuevo->prev=aux;
        aux->prox->prev=nuevo;
        aux->prox=nuevo;
    } else {
        nuevo->prev=nuevo;
        nuevo->prox=nuevo;
        *p=nuevo;
    }
}

void eliminarRepetidos(doble **p){
    
    doble *aux= *p, *aux2; 
    int num,repetido;

    while(aux && aux->prox!=*p){
        
         
        num=aux->valor;
        aux2=aux;
        repetido=0;
        

        while(aux2 && aux2->prox!=*p && aux2->prox!=aux2){

            printf("bb ");
            if(aux2->prox && aux2->prox->valor == num){
        
                doble *e= aux2->prox;
                printf("pro");
                aux2->prox= aux2->prox->prox;
                printf("ban");
                aux2->prox->prev=aux2;
                printf("do");
                delete(e);
                repetido=1;

            } else aux2=aux2->prox;
        }

        if(repetido){

            if(aux->prev!=aux && aux->prox!=aux){
                doble *e=aux;

                if(*p == aux) *p=(*p)->prox;

                aux->prev->prox=aux->prox;
                aux->prox->prev=aux->prev;
                delete(e);
            } else {
                doble *e=aux;
                *p=NULL;
                delete(e);
            }
        }

        aux=aux->prox;

    } 
}
int main () {

    doble *p=NULL; 
    int x=0, y=0, op=-1;

    while ( op ){
			
		printf( "\n\n\t\tMENU DE MANEJO DE LISTAS DOBLEMENTE ENLAZADAS CIRCULARES n\n ");
		printf( "1.\tInsertar al final\n ");
        printf( "2.\tMostrar\n ");
        printf( "3.\tInsertar luego de un valor dado(o al final)\n ");
        printf( "4.\tEliminar repetidos todas las ocurrencias\n ");
        
		printf( "0.\tSALIR del sistema\n\n ");
		
		scanf("%i", &op);
		
		switch (op){
            case 1: printf("\n Introduzca el valor que desea insertar= ");
                    scanf("%i", &x);
                    insertarAlFinal(&p, x);
                    break;
            case 2: mostrar(p);
                    break;
            case 3: printf("\n Introduzca el valor desde el cual desea insertar= ");
                    scanf("%i", &x);
                    printf("\n Introduzca el valor que desea insertar= ");
                    scanf("%i", &y);
                    insertarLuegoDeValorDado(&p,x,y);
                    break;
            case 4: eliminarRepetidos(&p);
                    break;
            
        }

             
		        
    }

    


    return 0;
}