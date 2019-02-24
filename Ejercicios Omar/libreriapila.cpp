#include <stdio.h>
#include <stdlib.h>

 struct pila {
    int valor;
    pila *sig;
} ; 


int vacio(pila *p) {
    //Retorna 1 en vacio
    return (p==NULL);
}

int tope(pila *p){
    //devuelve el valor de tope su p no esta vacia
    if(!vacio(p)) return p->valor;
    return 0;
}

void apilar(pila **p, int x){
    //agrega x como tope de p
    pila *t= new pila;
    t->valor = x;
    t->sig= *p;
    *p=t;
}

void desapilar(pila **p){

    if(!vacio(*p)){
        pila *t= *p;
        *p= (*p)->sig;
        delete(t);
    }
}


void mostrar ( pila *p){
	/* muestra por pantalla la lista enlazada */
	pila *t = p;
	
	printf( " Tope ");
	while (t){
		printf("->[%i]", t->valor);
		t= t->sig;
	}
	printf("->NULL\n\n");
}

int main (){
return 0;
}
