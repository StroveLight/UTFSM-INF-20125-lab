# Medición

## Breve introducción a complejidad computacional
La complejidad computacional consiste en cuanto llega a ser la cantidad de algo dependiendo de el tamaño del input. Ese algo puede ser, por ejemplo, tiempo o memoria. Se usa la notación `O` para indicar la cota máxima, y se asume que el tamaño de input es `n`, por lo que `O(n*n)` sería algo que crece exponencialmente con el input.

A continuación se dan unos ejemplos:

|operación 	| uso de tiempo | uso de memoria |
|-|-|-|
| Encontrar el valor máximo | `O(n)`, al recorrer todos los valores una vez (un `for`) | `O(1)`, ya que solo requiere saber el máximo actual |
| Ver si hay un par de valores en los datos sin usar ordenamiento ni memoria extra | `O(n*n)`, al probar todos los pares posibles (doble `for`) | `O(1)`, ya que solo se comparan valores |
| Dado `n` valores que van entre `1` y `m` contar la cantidad de veces que cada valor es tomado, recorriendo una vez sobre los datos | `O(n + m)`, al recorrer una vez los datos iniciales y luego recorrer todos los valores | `O(m)` al guardar la cantidad de veces en cada casilla |

En general el tiempo y memoria necesario para resolver depende de cómo uno se enfrente a un problema, y ocasionalmente qué es lo que uno desea priorizar, si menor tiempo o memoria. Hoy en día, usualmente lo que se desea priorizar es el tiempo.

## Tiempo

### Flags que ayudan
Mejor optimización: `-O3`

### Fuera del programa: time

Entrega tres valores:
| Nombre | Descripción |
|-|-|
| `real` | Tiempo real transcurrido (ver un reloj) |
| `user` | Uso de CPU del programa del lado del usuario |
| `sys` | Uso de CPU del programa del lado del sistema operativo |

¿Por qué se pasa por CPU del sistema operativo? Porque hay cosas que solo se encarga el sistema operativo, como manejar archivos abiertos y conexión a internet.

### Dentro del programa
#### clock_gettime
Hay veces que uno desea calcular el tiempo de una operación dentro de una sección del programa, en ese caso se puede usar. A continuaciones se proveen dos relojes monotónicos (el valor que cuentan nunca disminuye).

| reloj | descripción |
|-|-|
| `CLOCK_PROCESS_CPUTIME_ID` | Mide el tiempo que usa el proceso (programa) en la CPU |
| `CLOCK_MONOTONIC` |	 Mide el tiempo del computador, pero puede ser modificado (teniendo un valor mayor al esperado) por sincronización de relojes (La alternativa que no es modificada por la sincronización es `CLOCK_MONOTONIC_RAW`, que es exclusiva de linux) |

Dado que el reloj del computador no es monotónico, usar `CLOCK_REALTIME` puede obtener un segundo tiempo mayor al primero.

Uso:
```c
#include <time.h>
#include <stdio.h>
int main(){
	struct timespec tiempo;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tiempo);
    printf("tiempo: %ld\n", tiempo.tv_sec);
}
```

#### times
También existe [times](https://linux.die.net/man/2/times), que provee información similar al de `time` de consola.


## Memoria
La próxima semana (perfilado) entraremos en medición fuera del programa. Por esta semana, usaremos lo mas simple de `valgrind --tool=massif` para ver la memoria.

### flags que ayudan
Las flags ayudan solo al tamaño de código resultante, pero esto ayuda a que use menos memoria.
|flag| descripción |
|-|-|
|`-Os`| Optimizar tamaño, pero también tiempo|
|`-Oz`| Optimizar tamaño sacrificando tiempo|

### Dentro del programa: punteros + sizeof







## Códigos de ejemplo

### Tiempo O(m*n)
```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	if (argc != 4){
		printf("Uso: main <n> <m> <valor_buscar>");
		return -1;
	}
	int n = atoi(argv[1]), m = atoi(argv[2]);
	int cantidad_encontrado = 0, valor_buscar = atoi(argv[3]);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (i*j == valor_buscar)
				cantidad_encontrado++;
		}
	}
  printf("Valor %d encontrado %d vece(s)\n", valor_buscar, cantidad_encontrado);
}
```

### tiempo O(m + n) espacio O(m)
Generar los datos con `script.sh` y luego correr `./main 100 30 < test.txt`
```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	if (argc != 3){
		printf("Uso: main <n> <m>");
		return -1;
	}
	int n = atoi(argv[1]), m = atoi(argv[2]);

	int* cantidades = malloc(m*sizeof(int));
	int valor;
	while(n--){
		scanf("%d", &valor);
		cantidades[valor]++;
	}
	for (int i=0; i<m; i++){
		printf("%d: %d veces\n", i, cantidades[i]);
	}
	free(cantidades);
}
```

### Uso sizeof

```c
#include <stdlib.h>
#include <stdio.h>

int main(){
    int memoria_a_memoria[2][40] = {0};
    printf("tamaño memoria_a_memoria directo: %ld\n", sizeof(memoria_a_memoria));
    printf("tamaño memoria_a_memoria calculado: %ld\n", 2*40*sizeof(int));
}
```