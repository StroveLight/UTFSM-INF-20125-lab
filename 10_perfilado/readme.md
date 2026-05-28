# Medición


## massif
Massif sirve para medir uso de memoria durante un programa.

Uso: `valgrind --tool=massif`

Crea un archivo de la forma `massif.out.<pid>` con la información del uso de memoria. Para ver el archivo de mejor forma, se usa `ms_print <nombre_archivo>`:

Ejemplo de tabla:
```
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  5        213,790            5,136            5,120            16            0
  6        216,965            1,032            1,024             8            0
  7        216,999                0                0             0            0
```

Significado columnas:
|nombre | significado |
|-|-|
| `time` | Momento de la snapshot, usualmente es tiempo `(i)` |
| `total` | Uso de memoria total en ese momento |
| `useful-heap` | Parte del heap que se ha usado hasta el momento |
| `extra-heap` | Memoria adicional que se requiere para manejar la memoria pedida (por parte del SO) |
| `stacks` | Es 0, a menos a que se use massif con `--stacks=yes`, en cuyo caso muestra el tamaño del stack |

Para programas cortos se recomienda usar `--time-unit=B` al usar massif para así usar bytes en vez de tiempo.


# perf
`perf stat` sirve para mostrar información de un programa, usualmente se envían mas valores para poseer mayor información de la forma:
`perf stat -e instructions,cycles,cache-references,cache-misses`

Donde:
| nombre | significado |
|-|-|
| instructions | Instrucciones realizadas por el computador |
| cycles 	|  Ciclos de CPU usados |
| cache-references | Veces que se usó la caché |
| cache-misses | Veces que no se encontró algo en la caché |

## otros
También existe `callgrind` para ver uso mediante llamadas de funciones. Y `perf` que permite medir el performance de un programa.




## códigos

Mínimo recursivo:
```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // INT_MAX

int recursive_min(int* position, int curr_min){
    if (!*position)
        return curr_min;
    if (*position < curr_min)
        curr_min = *position;
    return recursive_min(position + 1, curr_min);
}
 
void main()
{
    int *valores, cantidad, minimo;
    printf("\nNúmero elementos:");
    scanf("%d", &cantidad);
    valores = calloc((cantidad+1), sizeof(int));
    printf("\nNúmeros:");
    for (int i = 0; i < cantidad; i++)
       scanf("%d", &valores[i]);

    minimo = recursive_min(valores, INT_MAX);
    
    printf("\nMínimo: %d", minimo);
    
    free(valores);
    printf("\n");
}
```
