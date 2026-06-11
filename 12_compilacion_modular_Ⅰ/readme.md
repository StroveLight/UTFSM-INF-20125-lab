# Compilación modular Ⅰ

## Requerir más de una vez un mismo archivo

Para evitar esto, se usan macros de C:

```c
#ifndef ARCHIVOH
#define ARCHIVOH

# código que no queremos que se ejecute más de una vez

#endif
```

Podemos probarlo con el archivo `persona.h`

## Compilación Estática

### Sin pasos intermedio

```bash
gcc -g -I./lugar/casona -I./utils -o main main.c ./lugar/casona/lugar.c ./utils/int_a_char.c
```

Nota: el `-I` Se usa para especificar qué carpetas debe buscar adicionalmente, por motivos históricos, no tiene un espacio después.

### Con pasos intermedios

El archivo poseerá toda la información necesaria. 

Ejemplo casona:
```bash
gcc -g -c ./utils/int_a_char.c
gcc -g -c ./lugar/casona/lugar.c -o casona.o
gcc -g -I./lugar/casona -I./utils -o main main.c casona.o int_a_char.o
```

Ejemplo Edificio:
```bash
gcc -g -c ./utils/int_a_char.c
gcc -g -I./persona -c ./lugar/edificio/lugar.c -o edificio.o
gcc -g -I./lugar/edificio -o main main.c int_a_char.o edificio.o
```

Nota: el `-c` se usa para saltar el paso de enlazar el archivo, lo que permite compilar archivos por separado.


### eliminar .o
```bash
rm ./*.o
```

## Librería Estática

Para esto usaremos `ar` (archivador), que utiliza las siguientes opciones
| opcion | descripción |
|-|-|
|r| Reemplazar o insertar en el archivo |	
|c| No advertir creación |	
|s| Agregar tabla de símbolos al archivo |	
|t| Listar archivos dentro del archivo |
|v| Modo verboso |
|d| eliminar módulo especificado del archivo |

Compilar el main en archivo.o
```bash
gcc -g -I./lugar/casona -c main.c
```

Uso con edificio
```bash
ar rcs lib_lugar.a int_a_char.o edificio.o
gcc -o lib_lugar main.o -L. -l:lib_lugar.a
```

Cambiar edificio por casona
```bash
ar d lib_lugar.a edificio.o
ar r lib_lugar.a casona.o
gcc -o lib_lugar main.o -L. -l:lib_lugar.a
```

### eliminar librerías
```bash
rm ./lib_*
```

## Librería Dinámica

Permite en ejecución resolver lo que se necesita.


Ejemplo casona:
```bash
gcc -g -fPIC -c ./utils/int_a_char.c -o int_a_char.o
gcc -g -fPIC -c ./lugar/casona/lugar.c -o casona.o
gcc -shared -o lib_lugar.so casona.o int_a_char.o
gcc -g -I./lugar/casona -c main.c
gcc -o lib_lugar main.o -L. -l:./lib_lugar.so
```

Descripción:
* 1 y 2: compilar archivos con `-fPIC` (Position Independent Code), permite que el archivo se pueda ejecutar sin importar de dónde esté ubicado en memoria RAM.
* 3: Crear librería compartida
* 4: enlazar librería con archivo main
* 5: crear archivo que use la librería y el main


Usar edificio en vez de casona:
```bash
gcc -g -fPIC -c ./lugar/edificio/lugar.c -o edificio.o
gcc -shared -o lib_lugar.so edificio.o int_a_char.o
```

Nota: para debuggear, se usa `ldd` sobre el archivo de librería creado

### eliminar .so
```bash
rm ./*.so
```
