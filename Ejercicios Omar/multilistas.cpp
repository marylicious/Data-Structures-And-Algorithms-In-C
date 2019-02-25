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
        printf("\n [%i]-->", t->valor);

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

void imprimirSiEncuentraX(multi *p, int x){
    multi *aux=p; int imprimir;
    lista *auxSub;
    while(aux){
        auxSub=aux->aba;
        imprimir=0; 

        while(auxSub){
            if(auxSub->valor == x){
                imprimir=1;
                break;
            } 

            auxSub=auxSub->sig;
        }

        if(imprimir) printf("\n%i\n", aux->valor);

        aux=aux->sig;
    }
}

void eliminarRepetidosSublista(multi **p){
    
    multi *aux=*p; 
    lista *auxSub, *auxAba; 
    int num;

    while(aux){
        
        auxAba=aux->aba;

        while(auxAba){
            num = auxAba->valor;
            auxSub=auxAba;
            
            while(auxSub && auxSub->sig){

                if(auxSub->sig->valor == num){
                    lista *t= auxSub->sig;
                    auxSub->sig=auxSub->sig->sig;
                    delete(t);
                }   
                else auxSub = auxSub->sig;

            }

            auxAba=auxAba->sig;
        }

        aux=aux->sig;
    }
}

int buscarMayor(multi *p){
    int mayor=0;
    multi *aux=p;

    while(aux){
        if(aux->valor>mayor) mayor=aux->valor;
        aux=aux->sig;
    }

    return mayor; 
}

void imprimirRepeticiones(multi *p, int menor){
 multi *aux=p;
 while(aux){
     if(aux->valor == menor) printf("\n%i\n", menor);
     aux=aux->sig;
 }
}

 
void imprimirOrdenados(multi *p, int rep){
    
    int ultMenor=-1, menor, mayor = buscarMayor(p);
    multi *aux=p;

    if(aux){
        
        while(ultMenor!=mayor){ aux=p; menor=mayor;
            while(aux){
                
                if(aux->valor<menor && aux->valor>ultMenor){
                    menor=aux->valor;
                }

                aux=aux->sig;
            }
      

            if(rep){
                imprimirRepeticiones(p,menor);
            } else {
                 printf("\n%i\n", menor);
            }

            ultMenor=menor;
        }
    }

}

int main() {
	int op = -1, x=0, y=0;
	multi *p=NULL;
	while ( op ){
			
		printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n ");
		printf( "1.\tInsertar a multilista por cabeza\n ");
        printf( "2.\tInsertar a sublista por cabeza\n ");
		printf( "3.\tMostrar multilista\n ");
        printf( "4.\tImprimir los valores que tengan el num x en la sublista\n ");
        printf( "5.\tEliminar repetidos en la sublista dejando primera ocurrencia\n ");
        printf( "6.\tImprimir los valores de la lista principal ordenados(sin rep)\n ");
        printf( "7.\tImprimir los valores de la lista principal ordenados(con rep)\n ");
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

            case 4: printf("\n\nIndique X ");
                    scanf( "%i", &x);
                    imprimirSiEncuentraX(p,x);
                    break;
            case 5: eliminarRepetidosSublista(&p);
                    break;

            case 6: imprimirOrdenados(p, 0);
                    break;
            case 7: imprimirOrdenados(p, 1);
                    break;
        }

             
		        
    }

    return 0;
	
}
	
	

