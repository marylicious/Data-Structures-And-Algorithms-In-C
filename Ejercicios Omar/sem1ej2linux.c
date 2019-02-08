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

void main () {
    int op = -1, x=0;
	lista *p=NULL;
	while ( op ){
		// agregar system("cls");	
		printf( "\n\n\t\tMENU DE MANEJO DE LISTAS n\n ");
		printf( "1.\tInsertar por comienzo de lista\n ");
		printf( "2.\tEliminar dato\n ");
		printf( "3.\tMostrar lista\n ");
		printf( "4.\tMostrar numeros al reves y hacer suma de los digitos\n ");
		printf( "5.\tEliminar numeros primos de la lista\n ");
		printf( "6.\tDejar los pares al final de la lista\n\n");
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
        }
    }	
    
    //agregar system("pause");
}