#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor;
    lista *sig;
};

struct multi {
    int valor;
    multi *sig;
    lista *aba;
};


void insertarMultilista(multi **p, int x){
    multi *t= new multi;
    t->valor=x;
    t->sig=*p;
    *p=t;
}

multi *BuscarNodoMulti(multi *p, int x){
    
    multi *aux=p;
    
    while(aux){

        if(aux->valor == x) return aux;
        aux=aux->sig;
    }

    return NULL;
}

void insertarSublista(multi *p, int x, int y){
    //inserto y debajo del primer valor x en la lista principal

    multi *nodo=BuscarNodoMulti(p,x);

    if(nodo){
        lista *t= new lista;
        t->valor = y;
        t->sig = nodo->aba;
        nodo->aba = t;
    }
}


void mostrarMultilista (multi *p){

    multi *t = p; lista *f;
    printf( "\n\nMostrar Multilista\n\n");
    printf( "\n[Cab]\n");
    printf( "\n  | \n");
    printf( "\n  v \n");
    while ( t){
       
        f=NULL;
        printf("\n[%i]-->", t->valor);

        f=t->aba;
        
        
        while (f){
             printf("[%i]->", f->valor);
													
             f=f->sig;
        }

        printf("NULL\n");

        t= t->sig;

        
        printf( "\n  | \n");
        printf( "\n  v \n");
        
    }

    printf("\n NULL\n");

}


int main() {
	int op = -1, x=0, y=0;
	multi *p=NULL;
	while ( op ){
			
		printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n ");
		printf( "1.\tInsertar a multilista por cabeza\n ");
        printf( "2.\tInsertar a sublista por cabeza\n ");
		printf( "3.\tMostrar multilista\n\n");
        printf( "4.\tImprimir los valores que tengan el num x en la sublista\n\n");
		printf( "0.\tSALIR del sistema\n\n ");
		
		scanf("%i", &op);
		
		switch (op){
		case 1: printf("\n\nIndique dato a Insertar ");
		        scanf( "%i", &x);
                insertarMultilista(&p,x);
		        break;
        case 2: printf("\n\nIndique dato de la multilista sobre cual va a insertar");
		        scanf( "%i", &x);
                printf("\n\nIndique dato de la sublista ");
		        scanf( "%i", &y);
                insertarSublista(p,x,y);
                break;
        case 3: mostrarMultilista(p);
                break;
        }     
		        
    }

    return 0;
	
}
	
	

