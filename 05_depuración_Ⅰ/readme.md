# Depuración Ⅰ: printf y assert

## Memoria y punteros
Los tipos de datos en C vistos hasta ahora usan un tamaño fijo en memoria, es por esto que podemos usar `sizeof` para ver cuánto tamaño usan.

Un puntero (ejemplo: `int *`) es la dirección de memoria a la que apunta el valor, es decir, indica dónde está almacenado el dato (ejemplo: `int`).
* El uso de `&` permite saber en qué lugar de memoria está almacenado un valor
* El uso de `*` permite acceder al valor de una referencia

## bits
Un computador representa los valores como 0s y 1s, a esa representación se le llama **representación binaria**, o en **base 2**. En algunos casos es de gran ayuda aprovechar eso para testear cosas cada cierto tiempo. Cabe mencionar que para los números con signo el primer bit determina el signo.

Ejemplo de uso de números binarios:
```c
#include <stdio.h>

int main() {
	char uno = 0b0001;
	char diez = 0b1010;
	printf("dos: %d\n", uno << 1);
	printf("tres: %d\n", uno | (uno << 1));
	printf("cuatro: %d\n", (diez >> 1) ^ uno);
	printf("menos uno: %d\n", ~(uno & diez));
}

```
- Usamos `0b` para indicar que el número que viene a continuación está en binario.
- Usamos `char`, porque usa un byte en memoria.

### Operadores de bits
| | nombre | ejemplo | en bytes |
|-|-|-|-|
| `&` | AND | `2 & 3` es `2` |  `0b10 & 0b11` es `0b10`  |
| `\|` | OR | `2 \| 1` es `3`|  `0b10 \| 0b11` es `0b11` |
| `^` | XOR | `3 ^ 1` es `1` |  `0b11 ^ 0b01` es `0b10`  |
| `<<` | shift left | `2 << 1` es `4` |  `0b010 << 1` es `0b100`  |
| `>>` | shift right | `2 >> 1` es `1` |  `0b010 >> 1` es `0b001`  |
| `~ ` | Negación | `~0` es `-1` |  `~ 0b00000000` es `0b11111111`  |
* `<< 1` equivale a multiplicar por dos
* `>> 1` equivale a división entera por dos.
* `~0` es `-1` para el caso de valores que posean signo, en caso de que no posean signo, la negación de `0` da el valor mas alto posible
  * ¿Por qué da `-1` y no el valor mínimo posible? Es porque los computadores representan los números negativos de una forma poco intuitiva ya que es más eficiente. En ese caso el valor mínimo posible es `0b10000000`, para el caso de un número de un byte.



## Uso de `printf`

Se puede usar el printf para imprimir un valor, pero también para imprimir su ubicación en memoria:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char* hola = "hola";
    int setenta = 70;
    printf("texto: %s\n> memoria: %p\n> 1ra letra: %c\n", hola, hola, *hola);
    printf("> largo: %li\n> espacio_en_memoria: %ld\n", strlen(hola),
            strlen(hola)*sizeof(*hola));

    printf("número: %i\n> memoria: %p\n", setenta, &setenta);
    printf("> letra: %c\n> espacio_en_memoria: %ld\n", setenta, sizeof(setenta));
    return 0;
}
```

El uso de `strlen(hola)*sizeof(*hola)` se usa para calcular el tamaño del `char*`.
* `strlen(hola)` retorna el largo del string.
* `sizeof(*hola)` retorna el espacio que usa el primer carácter.

## Uso de assert

Assert nos permite asegurar (assert) que lo que estamos haciendo siempre será verdad, en caso de que no lo sea, el programa falla y reporta donde falló el assert.

```c
#include <assert.h>

int main(int argc, char *argv[]){
	assert(argc == 1);
	return 0;
}
```

