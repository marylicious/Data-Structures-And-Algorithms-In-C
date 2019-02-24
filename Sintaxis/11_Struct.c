#include <stdio.h>
//Struct es como los registros en pascal.

struct Persona {
    unsigned short int edad;
    char *nombre;
};

struct Carro {
    char *dueno;
    unsigned short int year;
};

typedef struct Carro CA; //se define el tipo CA

//Otra manera:
/* typedef struct {
    char *dueno;
    unsigned short int year;
} CA;/ */

int main () {
    
    struct Persona maria;
        
    maria.edad=22;
    maria.nombre = "Maria V";

    printf("%s tiene %i a#os \n",maria.nombre,maria.edad);

    CA carro;
    carro.dueno = maria.nombre;
    carro.year = 96;

    printf("El carro de %s es del %i \n",carro.dueno,carro.year);

    return 0;
}