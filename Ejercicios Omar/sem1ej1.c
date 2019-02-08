#include <stdio.h>
#include <stdlib.h>

//comando no validos para linux comentados


void llenavector( int *p, int *k){
/*   El vector p es pasado por referencia     */
	int i;
	printf ("¿Cuantos elementos (1-20)?  ");
	scanf ("%d",k);
	if ((*k>0) && (*k<21))
	for( i = 0 ; i< *k; i++, p++){
		printf("\tA [%i] = ",i);
        		scanf ("%d", p);
	}
};

void muestravector (int *p, int n){
/*  No se modifica el contenido del vector */
 int i;
 printf("\n\nMuestra datos por pantalla\n\n");
 for(  i = 0 ; i< n; i++){
		printf("\tA[%i] = %i \n",i, *(p+i));
 };
 printf("\n");
};

int calcVolteado(int num) {
    int volteado=0,digito;

    while(num>0) {
        digito = num%10;
        volteado = (volteado*10)+ digito;
        num= num/10;
    }

    return volteado;
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

int esCapicua(int num) {
    int volteado;
    volteado = calcVolteado(num);

    if(volteado== num){
        return 1;
    } else {
        return 0;
    }
}

void mostrarPrimosOCapicuas(int *p, int n) {
    int i,primo,capicua;

    for (i=0; i<n; i++, p++){
        primo = esPrimo(*p);
        capicua= esCapicua(*p);

        if((primo) || (capicua)){
            printf("A[%i] de valor %i es ", i, *p);

            if(primo) { 
                printf("primo ");
            }
            if(capicua){
                printf("capicua");
            }

            printf("\n");
        }
    }
}

void sumaDeDigitos(int *p, int n) {
    int i,suma,aux,digito;
    
    for (i=0; i<n; i++){
       
       suma = 0;
       aux =*(p+i);

       while(aux>0){
           digito= aux%10;
           suma+=digito;
           aux/=10;
       }

       *(p+i)=suma;
    }

    muestravector(p,n);
    
}

void voltearDigitos(int *p, int n){
    int i;
    for (i=0; i<n; i++){
        *(p+i)= calcVolteado(*(p+i));
    }
    muestravector(p,n);
}

/*    programa principal */
void main ( )
{
 int A[20], n =0,  op= -1;

 while (op!=0){
        printf("\n\n\t\tManejo de vectores \n\n");
	printf ("\t1. Llenar vector desde pantalla\n");
	printf ("\t2. Mostrar vector en pantalla\n");
    printf ("\t3. Mostrar primos o capicuas de un vector\n");
    printf ("\t4. Sumar digitos\n");
    printf ("\t5. Voltear digitos\n");
	printf ("\t0. Salir\n");

	scanf ("%d", &op);
	//system("cls");
	switch (op){
		case 1: llenavector( &A[0], &n );
	            break;
		case 2: muestravector( &A[0], n);
		        break;
        case 3: mostrarPrimosOCapicuas( &A[0], n);
		        break;
        case 4: sumaDeDigitos( &A[0], n);
		        break; 
        case 5: voltearDigitos(&A[0], n);
		        //break;     
	};

	//system("pause");
    //system("cls"); 
 };
}
