#include <stdio.h>
#include <stdlib.h>

typedef struct pila {
    int valor;
    struct pila *sig;
} pila; 


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
    pila *t= malloc(sizeof(pila));
    t->valor = x;
    t->sig= *p;
    *p=t;
}

void desapilar(pila **p){

    if(!vacio(*p)){
        pila *t= *p;
        *p= (*p)->sig;
        free(t);
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


int buscarYEliminar(pila **p, int x){
    
    int rep,z;
    if(!vacio(*p)){
        z=tope(*p);
        desapilar(p);
        rep=buscarYEliminar(p,x);

        if(z!=x){
            apilar(p,z);
        } else {
            rep=1;
        }
        return rep;
    }

    return 0;
}

void eliminarRecurrencias(pila **p, int x){
    int z; 
    if(!vacio(*p)){
        z=tope(*p);
        desapilar(p);
        eliminarRecurrencias(p,x);
        if(z!= x){
            apilar(p,z);
        }

    }
}


void eliminarComunes(pila **A, pila **B){
    int z, comun;
    if(!vacio(*A)){
        z=tope(*A);
        desapilar(A);
        comun = buscarYEliminar(B,z);
        
        if(comun){
            eliminarRecurrencias(A,z);
        }

        eliminarComunes(A,B);

        if(!comun){
            apilar(A,z);
        }
    }
}


int Buscar(pila **p, int x){
int res,z;
    if(!vacio(*p)){
        
        if(tope(*p)== x) return 1;
        z=tope(*p);
        desapilar(p);
        res=Buscar(p,x);
        apilar(p,z);
        return res;
    }

    return 0;

}



void eliminarDeAComunesAAmbas(pila **A, pila **B){
    int z, comun=0;
    if(!vacio(*A)){
        z=tope(*A);
        desapilar(A);

        comun=Buscar(B,z);

        if(comun){
            eliminarRecurrencias(A,z);
        }

        eliminarDeAComunesAAmbas(A,B);

        if(!comun){
            apilar(A,z);
        }
    }
}

int contar(pila **p){

    int z, res;

    if(!vacio(*p)){
        z=tope(*p);
        desapilar(p);
        res=contar(p);
        apilar(p,z);
        res++;
        return res;
    }

    return 0;
}

int sumaDesdeFondoIgualLongitud(pila **a, pila **b, pila **c){
    int topA,topB,res,suma;
    if(!vacio(*a) && !vacio(*b)){
        topA=tope(*a);
        topB=tope(*b);
        desapilar(a);
        desapilar(b);
        res=sumaDesdeFondoIgualLongitud(a,b,c);
        suma=topA+topB+res;

    
        if(suma>9){
            res=suma/10;
            suma=suma%10;    
        } else{
            res=0;
        }

        apilar(c,suma);
        apilar(a,topA);
        apilar(b,topB);
        return res;

    }

    return 0;
}
void sumaDesdeFondo(pila **a, pila **b, pila **c){

    int la, lb, cerosAgg,i, suma;
   
    //igualamos la longitud de ambas pilas
   
    la= contar(a);
    lb= contar(b);

    if(la>lb){
        cerosAgg=la-lb; 
            
        for(i=0; i<cerosAgg; i++){
            apilar(b,0); 
        }

    } else {
        cerosAgg=lb-la; 
            
        for(i=0; i<cerosAgg; i++){
            apilar(a,0); 
        }
    }

    //Se llama una funcion que suma desde el fondo pilas de igual longitud

    suma = sumaDesdeFondoIgualLongitud(a,b,c);

    if(suma){
        apilar(c,1);
    }

    //eliminar 0 de mas
    if(la>lb){
        while(cerosAgg>0){
            desapilar(b);
            cerosAgg--;
        }
    } else {
        while(cerosAgg>0){
            desapilar(a);
            cerosAgg--;
        }
    }
    
}

void main () {
    int op = -1, x=0, y=0;
	pila *a=NULL, *b=NULL, *c=NULL; 
	while ( op ){
        
        printf( "\n\n\t\tMENU DE MANEJO DE PILAS n\n");
      
        printf( "1.\tApilar elemento en a\n");
        printf( "2.\tApilar elemento en b\n");
        printf( "3.\tMostrar pilas \n");
        printf( "4.\tEliminar comunes a ambas pilas \n");
        printf( "5.\tEliminar de A comunes a ambas \n");
        printf( "6.\t Suma de pilas desde el fondo \n");
		printf( "0.\tSALIR del sistema\n\n ");
        scanf("%i", &op);
		
		switch (op){
		
        case 1: printf("\n\nIndique dato a apilar en a ");
		        scanf( "%i", &x);
		        apilar (&a, x);
		        break;
        case 2: printf("\n\nIndique dato a apilar en b");
		        scanf( "%i", &x);
		        apilar (&b, x);
		        break;
        case 3: printf("Pila a es => ");mostrar (a);
                printf("Pila b es => ");mostrar (b);
                printf("Pila c es => ");mostrar (c);
		        break;
        case 4: eliminarComunes(&a,&b);
                break;
        case 5: eliminarDeAComunesAAmbas(&a,&b);
                break;
        case 6: sumaDesdeFondo(&a,&b,&c);
                break;
     
        }
    }
}


