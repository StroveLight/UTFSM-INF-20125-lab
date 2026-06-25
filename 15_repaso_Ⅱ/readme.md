# Repaso Ⅱ

## Ejecución con tests

### Permiso de ejecución para el shell script (.sh)
`chmod +x script.sh`

### RANDOM en .sh

`RANDOM` permite crear un número aleatorio, pero al depender de el valor anterior, los valores que provee a partir de el mismo número es siempre el mismo. Lo anterior se puede aprovechar al asignarse manualmente el valor de `RANDOM`.

### argumentos por consola en .sh

Uno puede pasar argumentos por consola a un script usando el índice del argumento en el script:

```bash
RANDOM="${1:-20125}"
```
* `1`, que en realidad se evalúa como `$1`, es el primer argumento
* `:-` Indica el valor a usar por defecto, en este caso es `20125`

Se recomienda usar valores por defecto para cubrir casos en los que no se pase el argumento al script.

Ejemplo de uso con argumentos:
`script.sh 2`, pasa el valor `2` como primer argumento


### Pasar los tests al ejecutable
Se usa `<`:

`./main < test.txt`


## Problema de hoy
### máximo común divisor (gcd) en C++
Antes tanto para el mínimo común múltiplo (`lcm`) como para el `gcd` se usaba `__gcd()` que estaba en el compilador de `GCC`, sin embargo, desde C++17, está tanto `gcd` como `lcm` en la librería `<numeric>`.

## Problema: Sincronización de relojes
Tres relojes se tardan distinto tiempo en marcar las 12 horas. El objetivo es calcular en qué momento los relojes vuelver a marcar la misma hora a las 12, asumiendo que parten marcando la misma hora a las 12.

### Input:
Primero el número de problemas, luego, por cada uno:
* Tres valores que indican el tiempo que se tarda cada reloj en marcar las 12

Ejemplo
```
4
2 3 6
3 4 5
4 4 1
3 3 3
```


### Output:
Por cada problema, cuántos dias pasarán hasta que los tres marquen la misma hora.

```
6
60
4
3
```
