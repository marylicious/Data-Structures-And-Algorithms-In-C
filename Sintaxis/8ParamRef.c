#include <stdio.h>

/* en C no existe el tradicional paso de parametros por referencia
en su lugar, se tiene que hacer eso con la ayuda de punteros
 */

int triple (int *$x) {
    //$x es un puntero
    printf("Se accede dentro del valor de x asi => %i \n",*$x);
    return *$x = *$x * 3;
}

int main () {

    int x=12;
    
    printf("Valor de x es %i\n",x);
    printf("El triple de x es %d \n", triple(&x));//pendiente, se hace primero la funcion!
    printf("Valor de x es %i\n",x);
    return 1;
}