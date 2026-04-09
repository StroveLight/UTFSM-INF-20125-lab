# Primer programa en C
## Proceso de programación:

### Editores de texto
Usaremos VSCode


### Compiladores y flags de compilación
Para C: `gcc`

Para C++: `g++`

`g++` acepta la mayoría de los parámetros que acepta `gcc`

Documentación gcc: https://gcc.gnu.org/onlinedocs/gcc/

#### Flags más comunes
Optimizar:
* `-O0`, comportamiento por defecto, no optimiza, pero facilita debuggeo.
* `-O`/`O1`, optimización simple.
* `-O2`, optimizar aún más.
* `-O3`, optimizar aún más que `-O2`.
* `-Og`, optimizar, pero tener en mente que se desea debuggear.
* `-Os`, optimizar tamaño del ejecutable. `-Oz`, hacer sacrificios para reducir lo más posible el tamaño del ejecutable

Debuggear:
* `-g`, para debuggeo general compatible con diversos debuggers
* `-ggdb` para debuggeo usando `gdb`


Para ver mas información, se puede usar `man gcc` , o `gcc --help`


### Entornos de desarrollo y herramientas típicas
* makefile/make, permite manejar el código de forma mas simple. Makefile simple:
```
main: main.c
	gcc -o main main.c
```
Luego, en la carpeta ejecutar `make` para usarlo.
* Valgrind, permite medir memoria. Basta con anteceder `valgrind` al comando de ejecutar código.
* VSCode, permite debuggear. Se puede abrir en la carpeta actual usando `code .`
	* Se puede usar la extensión de C/C++ de vscode: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
* `gdb`, una herramienta para debuggear código, es una alternativa al uso de debuggeo de vscode.


## Hola mundo

### En C
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n"); 
    return 0;
}
```

Compilar: `gcc -o main main.c`
* ¿Cómo se lee? El `-o` indica el archivo en el que se entrega el resultado

### En C++

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Compilar: `g++ -o main main.c`

¿Qué es "std"? ¿Por qué se ve a veces un `using namespace std`?


## Uso de sizeof() para determinar tamaños de tipos de datos y variables en el sistema.
* Probar uso de sizeof con tipos de datos y structs

### Ejemplo struct
```c
// Declarar
struct Info {
    char data[31];
    int id;
};

// Instanciar
struct Info info1;
```
