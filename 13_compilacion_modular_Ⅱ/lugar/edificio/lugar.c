#include "lugar.h"
#include <stdio.h>


struct Lugar asignar_personas_a_lugar(struct Persona *personas, int cantidad){
    struct Lugar lugar = {.cantidad_personas = 0};
    for (int i = 0; i < CAPACIDAD_LUGAR && i < cantidad; i++){
        lugar.personas[i] = personas[i];
        lugar.cantidad_personas++; 
    }
    printf("Lugar creado\n");
    return lugar;
}

void mostrar_personas(struct Lugar lugar){
    printf("Personas Edificio:\n");
    for (int i=0; i < lugar.cantidad_personas; i+=2){
        printf("Depto. %i0%i:", i/2/8 + 1, i/2%8 + 1);
        printf(" %c", lugar.personas[i].nombre);
        if (i +1 < lugar.cantidad_personas)
            printf(" y %c", lugar.personas[i + 1].nombre);
        printf("\n");
    }
}
