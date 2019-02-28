
#include <stdio.h>
#include <stdlib.h>

struct AVL{
    int valor, FE;
    AVL *izq, *der;
};

void preorden(AVL *p){
    if(p){
        printf(" %i ", p->valor);
        preorden(p->izq);
        preorden(p->der);
    }	
}
void inorden(AVL *p){
    if(p){
        inorden(p->izq);
        printf(" %i ", p->valor);
        inorden(p->der);
    }	
}
void postorden(AVL *p){
    if(p){
        postorden(p->izq);
        postorden(p->der);
        printf(" %i ", p->valor);
    }	
}

AVL *crear(int x){
    AVL *aux = new AVL;
    aux->valor = x;
    aux->der = NULL;
    aux->izq = NULL;
    return aux;
}

void insertar(AVL **p, int x){
    if(!*p)
        *p = crear(x);
    else if((*p)->valor > x)
        insertar(&((*p)->izq), x);
    else if((*p)->valor < x)
        insertar(&((*p)->der), x);	
}

int buscar(AVL *p, int x){
    if(p){
        if(p->valor > x) return buscar(p->izq,x);
        else if(p->valor < x) return buscar(p->der,x);
        else return 1;
    }
    return 0;
}

int menorMayores(AVL **p, AVL **t){
    if((*p)->izq) return menorMayores(&(*p)->izq,t);
    else {
        *t = *p;
        *p = (*p)->der;
        return (*t)->valor;	
    }	
}

void eliminar(AVL **p, int x){
    AVL *t = *p;
    if(p){
        if((*p)->valor > x)
            eliminar(&(*p)->izq, x);
        else if((*p)->valor < x)
            eliminar(&(*p)->der, x);
        else{
            if(!t->izq && !t->der)
                *p = NULL;
            else if (!t->izq)
                *p = t->der;
            else if(!t->der)
                *p = t->izq;
            else (*p)->valor = menorMayores(&(*p)->der,&t);	
            delete t;
        }	
    }
}

int contarNodos(AVL *p) {
    if(p) {

        return 1+contarNodos(p->der)+ contarNodos(p->izq);
    }

    return 0;
}

int contarHojas(AVL *p) {
    if(p){
        if(!(p->der) && !(p->izq)) return 1;
        return contarHojas(p->der) + contarHojas(p->izq);
    }
    
    return 0;
}

int alturaArbol(AVL *p) {
int der, izq, altura;
    if(p){
        if(!(p->der) && !(p->izq)) return 0;

        der=alturaArbol(p->der);
        izq=alturaArbol(p->izq);

        der>izq?altura=der:altura=izq;
        altura++;
        return altura;
    }
}

int profundidadArbol(AVL *p) {
int der, izq, profun;
    if(p){
        if(!(p->der) && !(p->izq)) return 1;

        der=profundidadArbol(p->der);
        izq=profundidadArbol(p->izq);

        der>izq?profun=der:profun=izq;
        profun++;
        return profun;
    }
}

void  imprimirNivelArbol(AVL *p, int nivel){
    if(p){
        if(nivel == 0) printf(" %i ", p->valor);
        else {
            imprimirNivelArbol(p->izq, nivel-1);
            imprimirNivelArbol(p->der, nivel-1);
        }
    }
}

void imprimir(AVL *p) {
    int altura,nivel;

    if (p){
        altura = alturaArbol(p);

        printf("\n");
        for(nivel=0; nivel<=altura; nivel++){
            imprimirNivelArbol(p,nivel);
            printf("\n");
        }
    }
}

int contarHojasHijoDer(AVL *p){
    if(p)
        return contarHojas(p->der);
}

void eliminarParesInternos(AVL **p){
    AVL *t=*p;
    if(*p){
        eliminarParesInternos(&((*p)->izq));
        eliminarParesInternos(&((*p)->der));
        if(((*p)->der)|| ((*p)->izq)){
            if((*p)->valor % 2 ==0){
                (*p)->valor = menorMayores(&(*p)->der,&t);	
                delete t;
            }
        }
    }
}


int main() {
    int op = -1, x=0, y=0;
    AVL *p=NULL;
    while ( op ){
    //system("cls");	
        printf( "\n\n\t\tMENU DE MANEJO DE ARBOLES \n\n ");
        printf( "1.\tInsertar en orden\n ");
        printf( "2.\tMostrar (preorden/inorden/postorden)\n ");
        printf( "3.\tEliminar dato\n ");
        printf( "4.\tBuscar\n ");
        printf( "5.\tContar hojas y nodos\n ");
        printf( "6.\tAltura y profundidad del arbol\n ");
        printf( "7.\tImprimir arbol\n ");
        printf( "8.\tContar hojas hijo derecho PREGUNTAR\n ");
        printf( "9.\tEliminar pares que no sean hojas\n ");
        printf( "\n\n0.\tSALIR del sistema\n\n ");

        scanf("%i", &op);

        switch (op){

            case 1: printf("\n\nIndique dato a Insertar ");
                scanf( "%i", &x);
                insertar (&p, x);
            break;

            case 3: printf("\n\nIndique dato a Eliminar ");
                scanf( "%i", &x);
                eliminar (&p, x);
            break;

            case 2:	//system("cls");
                printf("\n preorden="); preorden(p);printf("\n");
                printf("\n inorden="); inorden(p);printf("\n");
                printf("\n postorden="); postorden(p);printf("\n");
            break;

            case 4: printf("\n\nIndique dato a buscar ");
                scanf( "%i", &x);
                buscar(p,x) ? printf("Si esta\n"):printf("No esta\n") ;
            break;

            case 5: //system("cls");
                x=contarNodos(p);
                y=contarHojas(p);
                printf( "\n Tiene %i hojas y %i nodos\n ", y,x);
            break;

            case 6: //system("cls");
                x=alturaArbol(p);
                y=profundidadArbol(p);
                printf( "\n El arbol tiene altura %i y profundidad %i\n ",x,y);
            break;

            case 7:	imprimir(p);
            break;

            case 8: x=contarHojasHijoDer(p);
                    printf( "\n El arbol tiene %i hojas en sus hijo derecho\n ",x);
                    break;
            case 9: eliminarParesInternos(&p);
                    break;
        }

    //system("pause");
    };

    return 0;


}

