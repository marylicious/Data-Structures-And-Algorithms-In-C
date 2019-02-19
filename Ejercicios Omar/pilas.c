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

void eliminarElemento(pila **p, int num){
    int x;

    if(!vacio(*p)){
        if(tope(*p)==num) desapilar(p);
        else{
            x=tope(*p);
            desapilar(p);
            eliminarElemento(p,num);
            apilar(p,x);
        }
    }

}

void eliminarElementoTodasOcurr(pila **p, int num){
    int x;
    if(!vacio(*p)){
        x=tope(*p);
        desapilar(p);
        eliminarElementoTodasOcurr(p,num);
        if(x!=num){
            apilar(p,x);
        }
    }
}

int eliminarUltOcurr(pila **p, int num){
    int x, eliminar;
    if(!vacio(*p)){
        x=tope(*p);
        desapilar(p);
        eliminar = eliminarUltOcurr(p,num);
        
        if(x==num && eliminar){
            return 0;
        }  else {
            apilar(p,x);
            return eliminar;
        }
    }

    return 1;
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

void eliminarRepetidos(pila**p){
    int x, repetido;

    if(!vacio(*p)){
        x=tope(*p);
        desapilar(p);

        repetido=buscarYEliminar(p,x);

        eliminarRepetidos(p);

        if(!repetido){
            apilar(p,x);
        }
    }

}

int insertar_fondo(pila **p, int x){
    int z,res;
    if(!vacio(*p)){
        z=tope(*p);
        
        desapilar(p);
        
        res=insertar_fondo(p,x);
        
        if(!res){
            apilar(p,x);
        }

        apilar(p,z); return 1;

    }

    return 0;
}

void voltear(pila **p){
int z, res;
    if(!vacio(*p)){
        z=tope(*p);
        desapilar(p);
        voltear(p);
        res=insertar_fondo(p,z);
        if(!res){
            apilar(p,z);
        }
    }
}

int dejarParesSup(pila **p){
    int z, res;
    
    if(!vacio(*p)){
        
        z=tope(*p);
        desapilar(p);
        res=dejarParesSup(p);

        if(!res){//siempre apila el ultimo
            apilar(p,z);
        
        } else {
            
            if(z%2==0){
                apilar(p,z);
            } else {
                insertar_fondo(p,z);
            }
        }

        return 1;
    }

    return 0;
}



void main () {
    int op = -1, x=0, y=0;
	pila *p=NULL; 
	while ( op ){
        
        printf( "\n\n\t\tMENU DE MANEJO DE PILAS n\n");
      
        printf( "1.\tApilar elemento\n");
        printf( "2.\tDesapilar\n");
        printf( "3.\tMostrar pila a\n");
        printf( "4.\tEliminar elemento la primera vez que aparece\n");
        printf( "5.\tEliminar elemento todas las veces que aparece\n");
        printf( "6.\tEliminar elemento ultima vez que aparece\n");
        printf( "7.\tEliminar repetidos\n");
        printf( "8.\tVoltear una pila\n");
        printf( "9.\tDejar pares en la parte superior\n");
    
		printf( "0.\tSALIR del sistema\n\n ");
        scanf("%i", &op);
		
		switch (op){
		case 3: mostrar (p);
		        break;
        case 1: printf("\n\nIndique dato a apilar ");
		        scanf( "%i", &x);
		        apilar (&p, x);
		        break;
        case 2: desapilar (&p);
		        break;
        case 4: printf("\n\nIndique elemento a eliminar ");
		        scanf( "%i", &x);
                eliminarElemento(&p,x);
                break;
        case 5: printf("\n\nIndique elemento a eliminar ");
		        scanf( "%i", &x);
                eliminarElementoTodasOcurr(&p,x);
                break;
        case 6: printf("\n\nIndique elemento a eliminar ");
		        scanf( "%i", &x);
                y= eliminarUltOcurr(&p,x);
                break;
        case 7:eliminarRepetidos(&p);
                break;
        case 8:voltear(&p);
                break;
        case 9: y=dejarParesSup(&p);
                break;
       
     
        }
    }
}

