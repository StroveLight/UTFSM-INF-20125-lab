#include <stdio.h>
#include "utils/int_a_char.h"
#include "lugar.h"
#include "persona.h"


int main(){
    const int personas_agregar = 21;
    struct Persona personas[personas_agregar];
    for (int i = 0; i < personas_agregar; i++){
        personas[i] = (struct Persona){.nombre = int_a_char(i), .id = i};
    }

    struct Lugar lugar = asignar_personas_a_lugar((struct Persona *) personas, personas_agregar);
    mostrar_personas(lugar);
}
