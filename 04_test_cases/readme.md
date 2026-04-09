# Gestión de casos de prueba (test cases)

## Manejo de texto en C
* `scanf()`, permite leer texto de consola
	* se necesita pasar el valor por referencia (uso de `&`) para que se almacene el valor en una referencia existente.
* `printf()`, permite mostrar texto en consola

### Tipos de datos mas comunes
| sintaxis | tipo de dato |
|-|-|
| `%d` o `%i` | `int` |
| `%ld` o `%li` | `long` |
| `%f` | `float` |
| `%s` | `char*` |
| `%c` | `char` |


## Manejo de test cases en archivos de texto (redirección de entrada/salida).

Ejemplo de archivo para Input/Output:
```c
#include <stdio.h>

int main() {
    int cantidad;
    scanf("%d", &cantidad);
    while (cantidad--){
        int primero, segundo;
        scanf("%d %d", &primero, &segundo);
        printf("%d\n", primero + segundo);
    }
    return 0;
}
```

input.txt
```
4
3 6
109 2
310 452
231 -31
```

comando:
```
./main < ./input/01.txt > ./output/01.txt
```

solución.txt
```
9
111
762
200
```

## Introducción a bash-programming y Automatización básica en bash de la ejecución de códigos para múltiples pruebas.

Cómo dar permisos para correr un archivo llamado `script.sh`: `chmod +x script.sh`
* El `chmod +x` le da permisos de ejecución (`x`) al archivo

### Ejemplo de correr código
Ejemplo básico que corre `./main` dado los archivos de input e imprime en consola cuál está corriendo:
```bash
#!/bin/bash
for INPUTFILEPATH in ./input/*.txt;
do
    FILENAME=$(basename $INPUTFILEPATH);
    echo "running $FILENAME";
    ./main < "$INPUTFILEPATH" > "./output/$FILENAME";
done
```
* El `$()` permite evaluar el interior, para no interpretarlo como texto.
* El `*` de `./input/*.txt` corresponde a un *wildcard*, es decir, que permite cualquier texto entre medio, de esta forma usamos todos los archivos que terminen con `.txt` de la carpeta `input/`


### Ejemplo de comparar respuestas con la solución
Ejemplo que revisa los outputs y los imprime en consola
```bash
#!/bin/bash
for INPUTFILEPATH in ./output/*.txt;
do
    FILENAME=$(basename $INPUTFILEPATH);
	if [ $(diff -rq "$INPUTFILEPATH" "./solution/$FILENAME" | wc -m) -ne 0 ];
    then
        echo "$FILENAME";
    fi
done
```
* `diff -rq` Solo muestra en consola texto cuando 
* `wc -c` Reporta la cantidad de bytes de un texto, si es que es vacío reporta 0.
* `[ ... -ne 0 ]` El `-ne` es el *not equal* (!=), el uso de `[ ]` permite evaluar el interior como fórmula y que funcione el `-ne`.

### Otros
* Fórmula random en bash:
```
$($RANDOM % $MAX)
```

## Ejemplos avanzados de problemas resueltos con el juez virtual.

Mostrado en lab.

