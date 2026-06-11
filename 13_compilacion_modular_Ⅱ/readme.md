# Compilación modular Ⅱ: makefile

## Uso de un makefile
El uso principal de un makefile es permitir una forma más simple de ingresar los comandos para compilar el código. El uso más común es usar `make` a secas para compilar lo primero del archivo.


## Estructura de un makefile

### Estructura simple
```make
objetivo: prerrequisitos
	comando
```

| Nombre | Descripción |
|-|-|
| objetivo (`target`) | Nombre del archivo final |
| prerrequisitos (`dependencies`) | Archivos que se necesitan para el archivo final (se utiliza para verificar si hubieron cambios) |
| comando (`recipe`) | El comando que uno utiliza para generar el archivo compilado |
Para correr el programa basta con correr `make objetivo`

El comando debe estar separado por un `tab` y no por espacio.

### clean
Este comando se utiliza para eliminar los archivos que no sean parte del código. Por ejemplo, los `.o` y el ejecutable.

Un ejemplo:
```make
clean:
	rm ./*.o main
```
Nota: En general se usa `rm -f` para que no se levante error si es que no hay archivos por eliminar, ya que al levantar un error se detiene el makefile.

Ojo que si el nombre de algún archivo es `clean`, el makefile se confundirá, por lo que en general se usa `.PHONY: clean` en la línea anterior a declarar el `clean` para indicar que no se refiere a un archivo.

### Variables
Para evitar repetir texto en un makefile se pueden usar variables, lo más común son las flags a usar:
```
CFLAGS = -g -Wall -Wextra

independiente: independiente.o
	gcc $(CFLAGS) independiente.o -o independiente

independiente.o: independiente.c
	gcc $(CFLAGS) -c independiente.c

.PHONY: clean
clean:
	rm independiente.o independiente
```
* El `=` se usa para asignar valor cuando se use
* El `=:` se usa para asignar el valor inmediatamente 


### Ejemplo completo
En general uno puede necesitar compilar más de un archivo, pero para compilarlos todos se tiende a usar `all` y luego indicar qué objetivos correr al llamar `all`.

```
CFLAGS = -g -Wall -Wextra
COMMON_COMMAND = -I./utils main.c ./utils/int_a_char.c

all: casona edificio

edificio:
	gcc $(CFLAGS) -I./lugar/edificio -o edificio ./lugar/edificio/lugar.c $(COMMON_COMMAND)

casona:
	gcc $(CFLAGS) -I./lugar/casona -o casona ./lugar/casona/lugar.c $(COMMON_COMMAND)

clean:
	rm ./casona ./edificio

```

### Argumentos `make`
* `-n` Permite ver qué archivos cambiarían sin cambiarlos

### Variables automáticas
Para evitar repetir texto, se pueden usar "shortcuts":
* `$@` Indica el `target`
* `$^` Indica todas las dependencias
* `$<` Indica la primera dependencia

```make
CFLAGS = -g -Wall -Wextra

enumerar: enumerar.o numeros/primero.o numeros/segundo.o numeros/tercero.o
	gcc $(CFLAGS) -o $@ $^

enumerar.o: enumerar.c
	gcc $(CFLAGS) -c -o $@ $<

numeros/%.o: numeros/%.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm enumerar enumerar.o numeros/*.o
```
