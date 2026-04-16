# Depuración Ⅱ: gdb

## Hexadecimales

También llamados como `base 16`, representan números que van del `0` a la `f`. Debido a que los computadores funcionan con bits (base 2), es mas cómodo mostrar direcciones de memoria en base 16 que en base 10. Un número base 16 se encuentra en código como un número que empieza con `0x`, por ejemplo `0xff`.

En C, se puede mostrar un valor como hexadecimal usando `%x` (solo que en este caso no muestra el `0x` al inicio e intenta de convertit el valor a `unsigned int`).


## gdb
Permite debuggear código compilado. Flags de compilación para debugueo es `-g` para el general y `-ggdb` para debugueo con gdb.

Al abrirlo puede preguntar por `debuginfod` es una opción que permite descargar información de internet que facilita el debugueo.

`breakpoint` corresponde a los puntos en los que uno desea que el programa se detenga para obtener mayor información

### En consola:
basta con usar `gdb` antes del nombre del programa a probar, por ejemplo `gdb ./main`, esto abrirá `gdb` con el contexto del programa compilado.

Comandos dentro de gdb (se reconoce porque indica `(gdb)` la consola)

| Comando | Descripción |
|-|-|
| `q` o `quit` | Salir de gdb |
| `r` o `run` | corre el programa |
| `print <variable>` | Muestra el valor que posee la variable |
| `b` o `break` `<linea/funcion>` | Indica el número de línea o nombre de función en donde detener el programa, ej: `b 6` es la línea 6 |
| `i` o `info` | Muestra los subcomandos de información. Dentro se puede oprimir Enter para mas información, `q` para no tener más información, o `c` para continuar |
| `i b`| muestra información de los breakpoints existentes |
| `d` o `delete` `<id>` | Elimina el breakpoint usando el id del mismo |
| `c` o `continue` | Avanza hasta el siguiente breakpoint o hasta que termine el programa |
| `l` o `list` | Muestra el código alrededor de la línea actual |
| `s` o `step` | Ejecuta el siguiente paso considerando dentro de llamadas a funciones |
| `n` o `next` | Ejecuta el siguiente paso sin entrar en llamadas a funciones |
| `bt` o `backtrace` | Permite ver la secuencia de funciones que llamaron al programa |

### En Vscode
Se recomienda usarlo donde esté instalado `gcc` ya que compila el código.

Se requiere del uso de una extensión: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools




### Código de ejemplo 1

```c
#include <stdio.h>

int main(){
    float j = 0;
    for (char i=100; i != 20; i++)
        j += 1.0 / (float)i;
    printf("%f\n", j);
    printf("%x\n", j);
		assert j
    return 0;
}
```

### Código de ejemplo 2
```c
#include <stdio.h>

int dividir(int a, int b){
    if (b == 3)
        return a;
    return dividir( a/b, b);
}

int main(){
    int a = 1048576;
    int b = 2;
    int j = dividir(a, b);
    return 0;
}
```
