#include <stdio.h>
void PrintArray (int a[], int dim) {
    int i;
    
    printf("Array => |");
    for (i=0;i<dim; i++){
        printf("%i|", a[i]);
    }
    printf("\n");
}

void quickSort (int *$a, int inicio, int final) {
    
    //Selecting pivot---middle
    int pivot =  *( $a + ( (inicio+final)/2 ));
    
    //Inicializing variables
    int i = inicio;
    int f = final;
    int aux;

   do {
        
        while ((*($a + i)< pivot) && (i<=final)){
            i++;
        }

        while((pivot < *($a+f)) && (f>=inicio)){
            f--;
        }

        if(i<=f){
            aux= *($a+i);
            *($a+i)= *($a+f);
            *($a+f)= aux;
            i++; f--;
        }

    } while (i<=f);

    //Recursive triggering
   
    if(inicio<f){
       quickSort($a,inicio,f);
    }

    if(i<final){
       quickSort($a,i,final);
    }

 }


int main () {
    
    int dim = 8;
    int array[8] = {2,6,5,3,8,7,1,0};
    
    printf("Initial "); PrintArray(array,dim);
    quickSort(array,0,dim-1);
    printf("Ordered with Quick Sort "); PrintArray(array,dim);
    
    return 0;
}