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
    printf("Personas Casona:");
    for (int i=0; i < lugar.cantidad_personas; i++)
        printf(" %c", lugar.personas[i].nombre);
    printf("\n");    
}
