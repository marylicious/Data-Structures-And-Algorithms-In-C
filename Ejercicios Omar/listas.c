#include <stdio.h>
#include <stdlib.h>
#define true 1 //eliminar
#define false 0 //eliminar

typedef struct lista {
    int valor;
    struct lista *sig;
} lista; //eliminar typedef

//FUNCIONES AUXILIAREs

int calcVolteado(int num) {
    int volteado=0,digito;

    while(num>0) {
        digito = num%10;
        volteado = (volteado*10)+ digito;
        num= num/10;
	}

    return volteado;
}

int calcSumaDigitos(int num){
	
	int suma =0,digito;

	while(num>0){
		digito = num%10;
		suma +=digito;
		num/=10;
	}
	
	return suma;
}

int esPrimo(int num){
   
    if ((num == 2) || (num == 3) || (num == 5) || (num == 7)) {
        return 1;
    }


    if ( (num%2 == 0) || (num%3==0) || (num%5==0) || (num%7==0)){
        return 0;
    } else {
        return 1;
    }
  
}

int esPar(int num){
	if(num%2==0){
		return 1;
	} else {
		return 0;
	}
}

//FUNCIONES PRINCIPAlES
void insertar( lista **cab, int x){
	/* inserta x por el comienzo de la lista p */
	lista *t;
	t= malloc(sizeof(lista));
	t->valor = x;
	t->sig  = *cab;
	*cab = t;
}

void mostrar ( lista *cab){
	/* muestra por pantalla la lista enlazada */
	lista *t = cab;
	//agregar system("cls"); 
	printf( "\n\nMostrar lista\n\n  Cab ");
	while (t){
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


void voltearNumsEnLista(lista *cab) {
	
	lista *aux= cab;

	while(aux){
		aux->valor = calcVolteado(aux->valor);
		aux=aux->sig;
	}

	mostrar(cab);

}

void sumarDigitos(lista *cab) {
	
	lista *aux = cab;
	while(aux){
		aux->valor = calcSumaDigitos(aux->valor);
		aux=aux->sig;
	}

}

void voltearYSumDig(lista *cab) {
	
	//voltearDigitos
	printf("Los numeros en la lista volteados serian =>");
	voltearNumsEnLista(cab);

	//sumarDigitos
	sumarDigitos(cab);

}

void eliminarPrimos(lista **cab){

	lista *aux = *cab;

	while(aux){
		
		if(esPrimo(aux->valor)){
			eliminar(cab, aux->valor);
		}

		aux = aux->sig;
	}

}


void paresAlFinal(lista **cab) {
	
	lista *impar = *cab;
	lista *par = *cab;
	lista *sigPar, *sigImpar,*ultImpar, *ultPar=NULL, *primerPar=NULL;
	int cont = 0;

	//condicion verifica que hallan nodos
	if(par!=NULL && impar!=NULL) {

		while ((par != NULL) || (impar != NULL)) {

			//buscar el primer par y el primer impar

			while( (impar != NULL) && esPar(impar->valor) ) {
				impar = impar->sig;
			}
			
			//reposiciono cabeza de la lista la primera vez que corre el bucle
			if(cont<=0 && impar != NULL){
				*cab = impar;
			}

			while( (par != NULL) && !esPar(par->valor) ) {
				par = par->sig;
			}

			//guardo el puntero hacia el primer par
			if(cont<=0 && par != NULL){
				primerPar = par;
			}
			
			//Buscar el siguiente par y el siguiente impar
			if(impar!= NULL) {
				sigImpar = impar;
				do {
					sigImpar = sigImpar -> sig;
				} while((sigImpar!=NULL) && esPar(sigImpar->valor));
			} else {
				sigImpar = NULL;
			}

			if(par!= NULL) {
				sigPar = par;
				do {
					sigPar = sigPar -> sig;
				} while((sigPar!=NULL) && !esPar(sigPar->valor));
			} else {
				sigPar = NULL;
			}
			

			//enlazo valores con los siguientes
			if(impar!= NULL) {
				impar->sig = sigImpar;
				ultImpar = impar;
			}

			if(par!= NULL){
				par -> sig = sigPar;
				ultPar=par;
			}

			//reinicio los nodos par e impar para poder hacer bucle
			impar = sigImpar;
			par = sigPar;
			cont++;
		} 
		
		ultImpar->sig = primerPar;//uno los punteros impares con pares
		ultPar->sig = NULL;  
		
		
	}	
	
}

void eliminarUltOcurr(lista **p, int x) {  
	lista *aux = *p, *ocurr=NULL;
	if(aux!=NULL){//verfico que no sea una lista vacia
		
		if(aux->valor == x) {//verifico si el valor esta en el primer nodo
			ocurr = aux; 
		} 

		//recorre la lista hasta el ultimo nodo
		while(aux->sig!=NULL) {
				
			//deja el puntero aux en el puntero anterior de la ocurrencia del valor
			while((aux->sig!=NULL)&& (aux->sig->valor != x)) 
					aux = aux->sig;
					
			if(aux -> sig != NULL) {
					ocurr = aux; //guardo el nodo antes de la ocurrencia del valor en ocurr
					aux= aux ->sig; //sigo recorriendo la lista
				}
		}
		
		if(ocurr!=NULL){
			if(ocurr==*p) { //si la ocurrencia se encuentra en el primer nodo
				*p=(*p)->sig;
				free(ocurr);
			} else {
				lista *t = ocurr->sig;
				ocurr->sig = t->sig;
				free(t);
			}
		}

	} 
}

void insertarLuegoDeValor(lista **p, int x, int y){
	lista *aux = *p;
	lista *nodo_nuevo = malloc(sizeof(lista));

	nodo_nuevo -> valor = x;

	if(aux!=NULL){
		while((aux->sig != NULL)&&(aux->valor != y))
			aux = aux->sig;
		
		if(aux->sig!= NULL)
			nodo_nuevo->sig = aux ->sig;
		 else 
			//no se encontro y
			nodo_nuevo -> sig = NULL;

		aux ->sig = nodo_nuevo;


	} else {
		nodo_nuevo->sig = NULL;
		*p = nodo_nuevo;
	}
}

void insertarOrdenadamente (lista **p, int x) {
	lista *nuevo_nodo = malloc(sizeof(lista));
	nuevo_nodo -> valor = x;
	nuevo_nodo->sig = NULL;

	lista *aux = *p;
	
	if(aux == NULL) {//caso de la lista vacia
		*p= nuevo_nodo;
	} else {
		//caso de que el primer numero de la lista sea el mayor
		if(aux -> valor > x) {
			nuevo_nodo->sig = aux;
			*p=nuevo_nodo;
		} else {
			//caso en el que el numero se deba colocar en el medio  o al final
			while((aux->sig != NULL) && (aux->sig->valor < x))
				aux=aux->sig;
			
			if(aux->sig!=NULL){
				nuevo_nodo->sig = aux->sig;
			}

			aux->sig = nuevo_nodo; 
		}
	}
}

void insertarFinalSinRepetidos(lista **p, int x) {
	
	lista *nuevo_nodo= malloc(sizeof(lista)), *aux=*p;
	nuevo_nodo -> valor = x;
	nuevo_nodo ->sig = NULL;
	
	if(!aux){
		*p = nuevo_nodo;
	} else {
		
		if(aux->valor != x){
			while((aux->sig) && (aux->valor != x))
				aux=aux->sig;
			
			if((!aux->sig) && (aux->valor!=x)){ //se salio porque no consiguio valor
				aux->sig = nuevo_nodo;
			}
		}
		 
	}
}

void eliminarTodasOcurr(lista **p, int x){
	lista *aux = *p;
	
		
		while(aux && aux->sig){
			
			if(aux->sig->valor == x){
				lista *nodo_a_eliminar = aux->sig;
				aux->sig = aux->sig ->sig;
				free(nodo_a_eliminar);
			} else aux=aux->sig;

		}

		if (*p)
			if((*p)->valor == x){
				lista *nodo_a_eliminar = *p;
				*p = (*p)->sig;
				free(nodo_a_eliminar);
			}
}

void eliminarRepetidos(lista **p){
	lista *aux=*p, *recorrido=*p;
	int num;
	while(recorrido){
		num=recorrido->valor;
		aux=recorrido;

		while(aux->sig) {
			while((aux->sig) && (aux->sig->valor != num))
				aux=aux->sig;
			
			if(aux->sig){
				lista *t = aux->sig;
				aux->sig = aux->sig->sig;
				free(t);
			}
		}
		recorrido = recorrido->sig;
	}
}


//buggeado
void eliminarRepetidosUltOcurr(lista **p){
  
  lista *recorrido = *p, *aux, *ultimo = NULL;
  int num;

	while(recorrido) {
		
		num = recorrido ->valor;
		aux = *p;

		//Busco repetidos y guardo la ultima recurrencia en un puntero
		while(aux) {
			
			if(aux->valor == num && aux != recorrido){
				ultimo=aux;
			}
			aux=aux->sig;
		}

		//elimino quien no sea el ultimo
		if(ultimo) {
			
			aux = *p;
			
			while(aux && aux->sig){
				
				if(aux->sig->valor== num && aux->sig != ultimo){
					lista *t=aux->sig;
					aux->sig=aux->sig->sig;
					free(t);
				} else {
					aux=aux->sig;
				}
			}

			if((*p)->valor == num && (*p)!=ultimo){
				lista *t= *p;
				*p= (*p)->sig;
				free(t);
			}

			//reiniciamos ultimo
			ultimo= NULL;
		} 

		recorrido=recorrido->sig;

	}
}

int chequearSiListaSimetrica(lista *p) {
	lista *aux=p, *medio, *m, *t, *izq, *der; int cont=0, i, mitad;
	if(p) {
		//cuento los nodos en la lista
		while(aux){
			aux=aux->sig;
			cont++;
			
		}

		if (cont<=2) mitad=0;
		else mitad = cont/2;

		medio = p;

		for(i=0; i<mitad; i++){
			medio=medio->sig;
		}

	
		m= medio ->sig;

		while(m && m->sig) {
			t= m->sig;
			m->sig = t->sig;
			t->sig = medio->sig;
			medio->sig = t;
		}

		izq =p;
		der = medio ->sig;
				

		while(der) {
			

			if((izq->valor) == (der->valor)) {
				izq=izq->sig;
				der=der->sig;
			} else {
				printf("False\n");
				return 0;
			}
			
		}

		if(!der) {	printf("True\n"); return 1;}
	}

} 

lista *BuscarNodo(lista *p, int res){
	
	if(p)
		if(p->valor %2 == res)
			return p;
		else
			return BuscarNodo(p->sig,res);
	return NULL;
}

void swap(int *A, int *B) {
	int aux = *A;
	*A=*B;
	*B=aux;
}

void ParImpar(lista *p){
	lista *aux=p, *nodo=NULL;
	int cont=0;

	while(aux){
		if((cont%2)!= ((aux->valor)%2)){
			nodo = NULL;
			nodo = BuscarNodo(aux, (cont%2));

			if(nodo)
				swap(&aux->valor, &nodo->valor);
			else
				return;
		}
		aux=aux->sig;
		cont++;
	}
}




void separarDigitos(lista *p) {
	lista *aux=p; int num, digito;

	while(aux){
		num= aux->valor;
		while(num>9){
			lista *t= malloc(sizeof(lista));
			digito= num%10;
			num=num/10;
			t->valor = digito;
			t->sig = aux->sig;
			aux->sig = t;
			aux->valor=num;
		}

		aux=aux->sig;
	}
}


void main () {
    int op = -1, x=0, y=0;
	lista *p=NULL;
	while ( op ){
		// agregar system("cls");	
		printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n ");
		printf( "1.\tInsertar por comienzo de lista\n ");
		printf( "2.\tEliminar dato\n ");
		printf( "3.\tMostrar lista P\n ");
		printf( "4.\tMostrar numeros al reves y hacer suma de los digitos\n ");
		printf( "5.\tEliminar numeros primos de la lista\n ");
		printf( "6.\tDejar los pares al final de la lista\n ");
		printf( "7.\tEliminar ultima ocurrencia de dato\n ");
		printf( "8.\tInsertar luego de un valor dado\n ");
		printf( "9.\tInsertar ordenadamente (menor a mayor)\n ");
		printf( "10.\tEliminar un elemento dado todas las veces que lo encuentre\n ");
		printf( "11.\tEliminar numeros repetidos dejando la primera ocurrencia\n ");
		printf( "12.\tEliminar numeros repetidos dejando la ultima ocurrencia\n ");
		printf( "13.\tChequear si la lista es simetrica\n ");
		printf( "14.\tPar e impar mientras sea posible\n ");
		printf( "15.\tInsertar al final de la lista sin permitir repetidos\n ");
		printf( "16.\tSeparar digitos de la lista\n ");
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
		case 4: voltearYSumDig(p);
				break;
		case 5: eliminarPrimos(&p);
				break;
		case 6: paresAlFinal(&p);
				break;
		case 7: printf("\n\nIndique dato a Eliminar ");
		        scanf( "%i", &x);
				eliminarUltOcurr(&p, x);
				break;
		case 8: printf("\n\nIndique dato a Insertar ");
		        scanf( "%i", &x);
				printf("\n\nIndique valor de nodo previo al dato");
				scanf( "%i", &y);
		        insertarLuegoDeValor(&p, x, y);
		        break;
		case 9: printf("\n\nIndique dato a Insertar ");
		        scanf( "%i", &x);
				insertarOrdenadamente(&p,x);
				break;
		case 10:printf("\n\nIndique dato a Eliminar ");
		        scanf( "%i", &x);
				eliminarTodasOcurr(&p, x);
				break;
		case 11:eliminarRepetidos(&p);
				break;
		case 12:eliminarRepetidosUltOcurr(&p);
				break;
		case 13:chequearSiListaSimetrica(p);
				break;
		case 14:ParImpar(p);
				break;
		case 15: printf("\n\nIndique dato a Insertar ");
		        scanf( "%i", &x);
				insertarFinalSinRepetidos(&p,x);
				break;
		case 16:separarDigitos(p);
				break;
	
        }
    }	
    
    //agregar system("pause");
}