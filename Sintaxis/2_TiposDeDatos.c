//identificadores y tipos
#include <stdio.h>

int main () {
    char letra = 'A';
    char letra2 = 'B';
    int entero = 200;
    float flo = 123.1231;
    
    //El tipo string no existe, es un array de chars
    char string[] = "hola soy mary";
    
    //Esto es un string con tama#o, siempre se le agrega un caracter mas de lo que necesita 
    //porque al final de cualquier string hay un caracter \0 nulo. 

    char saludo[5] = "hola";

    printf("Aqui imprimire letra %c, letra2 %c, entero %i,  un float %f \n", letra,letra2,entero,flo);
    printf ("Imprimimos la string aqui => %s \n", string);
    printf ("Aqui imprimiremos el saludo => %s \n", saludo);
}