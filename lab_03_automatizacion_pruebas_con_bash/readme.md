# Entregar valores a un programa

## Automatización de pruebas con bash

Algoritmo que recibe el primer parámetro del script de bash (`$i`), y crea archivos de tests de `$i*10` elementos, indicando en la primera línea la cantidad de elementos. 
```bash
#!/bin/bash
MOD=26
for ((i=1; i<=$1; i++)); do
    FILENAME="input/test$i.txt";
    echo "$(($i*10))" > $FILENAME
    for ((j=1; j<=$i*10; j++)); do
        echo "$(( RANDOM % $MOD )) $(( RANDOM % $MOD )) $(( RANDOM % $MOD ))" >> $FILENAME
    done
done
```

* `$(())` corresponde al reemplazo aritmético
* `"$(( RANDOM % $MOD ))` Es usado para crear un número aleatóreo entre `0` y `MOD-1`, ya que se aplica el módulo.
* `>>` Se usa para añadir elementos a un archivo existente (*append*)

## Entrega de parámetros por terminal a un programa en C

* `argc` cantidad de parámetros. Hay que considerar que el nombre del archivo ejecutable es el primer parámetro.
* `argv` Los parámetros en sí. Hay que considerar que el nombre del archivo ejecutable es el primer parámetro.

Programa que lee tres parámetros adicionales, si son menos imprime en consola que no son los suficientes.
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("parámetros insuficientes. Formato: <operación> <número1> <número2>\n");
        exit(-1);
    }
    int cantidad = atoi(argv[2]), cantidad2 = atoi(argv[2]);
    char operacion = argv[1][0];
    switch (operacion)
    {
    case '+':
        break;
    case 's':
        printf("%d\n", cantidad + cantidad2);
        break;
    case '-':
    case 'm':
        printf("%d\n", cantidad - cantidad2);
        break;
    default:
        printf("operación no válida\n");
        break;
    }
    return 0;
}
```

* Usamos `atoi` para convertir el `char*` a `int`. Como alternativa, se puede usar `strtol` para poder distinguir si se leyó algo que no era un `long`.


