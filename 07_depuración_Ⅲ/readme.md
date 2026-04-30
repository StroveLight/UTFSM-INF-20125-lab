# Depuración Ⅲ: valgrind

## Manejo de memoria

En C, se puede manejar memoria dinámicamente solicitando al sistema operativo
* `malloc(tamaño)` alloca la cantidad de `tamaño` de bytes. Su nombre proviene de "memory allocation". Retorna un puntero a la ubicación de la memoria.
* `calloc(cantidad, tamaño)`alloca la cantidad de `tamaño*cantidad` de bytes con todos los bits en 0. Su nombre proviene de "clear allocation". Retorna un puntero a la ubicación de la memoria.
* `free(puntero)` libera la memoria pedida


## valgrind
Se usa para debugueo de memoria, en particular cuando se trabaja incorrectamente con la misma. Algunos casos:
* Escribir/Leer fuera de memoria permitida.
* Leer una variable que no se le ha asignado un valor.
* Memoria que no ha sido liberada.
* Trabajar con espacios memoria ya ha sido liberada.

Cabe mencionar que un código puede ser inseguro si posee problemas de memoria.

Para mayor debugueo se recomienda compilar con `-O0` y con `-g`.




### Código de ejemplo 1

```c
#include <stdlib.h>
#include <stdio.h>

int main(){
    int **memoria_a_memoria = malloc(2*sizeof(int));
    int *memoria = malloc(4*sizeof(int));
    memoria_a_memoria[0] = memoria;
    memoria_a_memoria[1] = calloc(4, sizeof(int));
    printf("Es cero: %d\n", memoria_a_memoria[0][1]);
    printf("Puede no ser cero: %d\n", **memoria_a_memoria);
    printf("ubicación int**: %p\n", memoria_a_memoria);
    printf("ubicación int*:  %p\n", &memoria_a_memoria);
}
```

### Código de ejemplo 2

```c
#include <stdlib.h>
#include <stdio.h>

struct Info;

struct Info {
    int valor;
    struct Info* next;
};

int main(){
    struct Info *infoActual = NULL;
    for (int i = 4; i > 0; i--){
        struct Info* informacion = malloc(sizeof (struct Info));
        (*informacion).valor = i;
        informacion->next = infoActual;
        infoActual = informacion;
    }
    for (int i = 1; i < 5; i++){
        printf("id: %d, siguiente: %p\n", infoActual->valor, infoActual->next);
        infoActual = infoActual->next;
    }
}
```

### Código de ejemplo 2 sin leaks
```c
#include <stdlib.h>
#include <stdio.h>

struct Info;

struct Info {
    int valor;
    struct Info* next;
};


int main(){
    struct Info *infoActual = NULL, *info2;
    for (int i = 4; i > 0; i--){
        struct Info* informacion = calloc(1, sizeof (struct Info));
        (*informacion).valor = i;
        informacion->next = infoActual;
        infoActual = informacion;
    }
    for (struct Info *infoMostrar = infoActual; infoMostrar != NULL; infoMostrar = infoMostrar->next){
        printf("id: %d, siguiente: %p\n", infoMostrar->valor, infoMostrar->next);
    }
    for (int i = 1; i < 5; i++){
        info2 = infoActual;
        infoActual = infoActual->next;
        free(info2);
    }
}
```


