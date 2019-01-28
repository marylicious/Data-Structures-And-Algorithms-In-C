#include <stdio.h>

int main () {
    
    //Inicializacion array
    int array[4] = {1,2,3,4};
    printf("La posicion 0 es %i \n", array[0]);

    //llenar un array
    printf("Llenado de array:\n");
    
    int array2[4];
    int x;
    for (x=0; x<4; x++) {
        array2[x]=x*2;
        printf(" %i \n", array2[x]);
    }

    //matrices en c

    // int array [cantidad de elementos] [cantidad de elementos de cada elemento]

    //inicializacion

    int matriz [4][6]= {
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24}
    };

    printf("El 16 es => %i \n", matriz[2][3]);

}