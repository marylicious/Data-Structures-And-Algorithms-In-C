#include <stdio.h>

//Sintaxis tipodedato FuncionNombre (tipodatoparam param1, tipodato param2) {}

//FUNCION
int Doble (int n) {
    return n*2;
}

//void = sin dato, no retorna nada.

//PROCEDIMIENTO
void Imprimir (int n) {
    printf("El doble de %i es %i\n", n, Doble(n));
}

int main () {
    Imprimir(16);
    return 1;
}