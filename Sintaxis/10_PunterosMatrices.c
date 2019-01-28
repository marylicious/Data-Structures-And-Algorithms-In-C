#include <stdio.h>
int main () {
    
    int a[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int *$p;
    
    $p = &a[0][0];
    //Importante: no es valido colocar $p = a como sucedia con los vectores.

    //las matrices se trabajan como si fueran un arreglo estirado

    printf("Imprimir 5 => %i \n", *($p+4));

    return 1;
}