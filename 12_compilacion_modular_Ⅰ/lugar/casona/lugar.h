#ifndef CASAH
#define CASAH
#include "../../persona.h"

#define CAPACIDAD_LUGAR 30

struct Lugar
{
    struct Persona personas[CAPACIDAD_LUGAR];
    int cantidad_personas;
};

struct Lugar asignar_personas_a_lugar(struct Persona *, int cantidad);
void mostrar_personas(struct Lugar);

#endif