//debug de taller 1 - Ordenar lista en impares primero, pares luego y primos al final

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
    lista *t = malloc(sizeof(lista));
    t->valor = x;
    t->sig = *cab;
    *cab = t;
}

int esPrimo (int num) {

    if(num ==1) {
        return 0; 
    }

    if(num == 2 || num == 3 || num == 5 || num == 7 ) {
        return 1;
    }

    if(num%2==0 || num%3 ==0 || num%5 ==0 || num%7 ==0) {
        return 0;
    } else {
        return 1;
    }
}


void mostrar ( lista *cab){
/* muestra por pantalla la lista enlazada */
    lista *t = cab;
    printf( "Cab ");
    while ( t){
        printf("->[%i]", t->valor);
        t= t->sig;
    }
    printf("->NULL\n\n");
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

int esPar(int num) {

    if(num%2 == 0) return 1;
    else {
        return 0;
    }
}


void eliminarRepetidos(lista *p) {
    lista *recorrido = p, *aux;
    int num;

    while(recorrido && recorrido->sig) {

    num = recorrido ->valor;
    aux = recorrido;

    while (aux && aux->sig) {

        if(aux->sig-> valor == num) {
            lista *t = malloc(sizeof(lista));
            t= aux->sig,
            aux->sig = aux ->sig->sig;
            free (t);
        } else aux=aux->sig;
    }

    recorrido=recorrido->sig;
}

}

lista *BuscarNodo(lista *comienzo, int tipo) {

lista *aux = comienzo;

//comienzo = a partir de donde busco

//tipo 1 impar, tipo 2 par, tipo 3 primo
    if (tipo == 1) {

        while (aux && (esPar(aux->valor) || esPrimo(aux->valor) ) ) {
            aux = aux->sig;
        }
        
        return aux;
    } 

    if (tipo == 2) {

        while (aux && !esPar(aux->valor)) {
        aux = aux->sig;
        }

        return aux;
    }

}

void cambio(int *A, int *B) {
    int aux = *A;
    *A=*B;
    *B= aux;
}


void ordimparparprimo(lista *p) {

lista *aux, *impar, *ultImpar, *ultPar, *par;

    if (p){

        //Elimino repetidos
        eliminarRepetidos(p);

        //inicializo
        aux=p;
        impar=p;
        ultImpar=NULL;
        par=p;

        //Busco todos los impares y los coloco delante
        while(aux && aux->sig) {

            if(esPar(aux->valor) || esPrimo(aux->valor)) {

                impar= BuscarNodo(impar, 1);

                if(impar){ 
                    cambio(&aux->valor, &impar->valor);
                    ultImpar = aux; 
                    mostrar(p);
                }
                else {
                    break;
                }

            } 
            ultImpar=aux;
            aux = aux->sig;
        }

        if(ultImpar && !esPar(ultImpar->valor)){
            aux = ultImpar->sig;
        } else {
            aux = p;
        }

       

        // Y luego coloco los pares

        while(aux && aux->sig) {

        if(!esPar(aux->valor) || esPrimo(aux->valor)) {

            par= BuscarNodo(aux, 2);

            if(par && par != p) {
                cambio(&aux->valor, &par->valor);
                mostrar(p);
            }
            else break;
        } 

            aux = aux->sig;
        }


    }// fin if p


}


void main() {
int op = -1, x=0;
lista *p=NULL;
while ( op ){

printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n ");
printf( "1.\tInsertar por comienzo de lista\n ");
printf( "2.\tEliminar dato\n ");
printf( "3.\tMostrar lista\n\n");
printf( "4.\tOrdenar Impar Par Primos\n\n");
printf( "0.\tSALIR del sistema\n\n ");

scanf("%i", &op);

switch (op){
case 1: printf("\n\nIndique dato a Insertar ");
scanf( "%i", &x);
insertar (&p, x);
break;
case 2: printf("\n\nIndique dato a Eliminar ");
scanf( "%i", &x);
eliminar (&p, x);
break;
case 3: mostrar(p);
break;
case 4: ordimparparprimo(p);
break;

}


};


}

/* FIN de Menu para manejo dinamico de listas en C */