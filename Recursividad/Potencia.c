#include <stdio.h>


int Potencia (int exp, int base) {
    
    //Caso Base >> exp = 0
    if (exp == 0) {
        return 1;
    } else {
        return base * Potencia(exp-1,base);
    }
}

int main (){
    
    int base;
    int exp;

    printf("Introduzca la base:");
    scanf("%d", &base);
    printf("Introduzca el exponente:");
    scanf("%d", &exp);

    printf("%i a la %i es = %i \n",base,exp,Potencia(exp,base));

    return 1;
}