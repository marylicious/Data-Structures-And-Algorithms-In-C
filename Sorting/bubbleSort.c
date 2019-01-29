#include <stdio.h>

//num = num in array.

//Burbuja o Intercambio Directo
void PrintArray (int a[], int dim) {
    int i;
    
    printf("Array => |");
    for (i=0;i<dim; i++){
        printf("%i|", a[i]);
    }
    printf("\n");
}

void Bubble(int *$num, int dim) {
    int fin, i, aux;
    
    for(fin=0; fin<dim-1;fin++){

        for(i=dim-1; i>fin; i--) {
            
            if( (*($num+i)) < (*($num+i-1)) ) {  
                aux = *($num+i);
                *($num+i) = *($num+i-1);
                *($num+i-1) = aux;
            }

        }
    }
}

void InvertedBubble(int *$num, int dim) {
    int fin,i,aux;

    for (fin=dim-1; fin>0; fin--) {
        
        for (i=0; i<fin;i++) {
             
             if( (*($num+i)) > (*($num+i+1)) ) {  
                aux = *($num+i);
                *($num+i) = *($num+i+1);
                *($num+i+1) = aux;
            }
        
        }

    }
}

void InvertedBubble2(int *$num, int dim) {
    int fin,i,aux;

    for(fin=1; fin<dim; fin++){
        
        for(i=0; i< dim-fin; i++) {
             
            if( (*($num+i)) > (*($num+i+1)) ) {  
                aux = *($num+i);
                *($num+i) = *($num+i+1);
                *($num+i+1) = aux;
            }
        }
    }
}

//void InvertedBubble2()
int main () {
    
    int dim = 10;
    int array[] = {10,7,1,4,8,8,7,5,3,9};
    
    printf("Initial "); PrintArray(array,dim);
    //Bubble(array,dim);
    //InvertedBubble(array,dim);
    InvertedBubble2(array,dim);
    //printf("Ordered with Bubble"); PrintArray(array,dim);
    //printf("Ordered with InvertedBubble "); PrintArray(array,dim);
    printf("Ordered with InvertedBubble2 "); PrintArray(array,dim);
    
    return 0;
}