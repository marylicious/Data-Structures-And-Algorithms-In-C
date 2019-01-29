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
int main () {
    
    int dim = 10;
    int array[] = {10,7,1,4,8,8,7,5,3,9};
    
    printf("Initial "); PrintArray(array,dim);
    Bubble(array,dim);
    printf("Ordered "); PrintArray(array,dim);
    
    return 0;
}