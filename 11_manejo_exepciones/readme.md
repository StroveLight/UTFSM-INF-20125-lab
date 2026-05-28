# Manejo de excepciones en C++

## Exepciones

Corresponden a cuando el programa encuentra un error durante su ejecución. El uso permite que el código "salte" a donde se maneja el error

### C es sin excepciones: Se pueden usar valores de retorno
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int *memoria = malloc(9223372036854775807L / 2L);
	if(memoria != NULL) {
		printf("Liberando memoria...\n");
		free(memoria);
	}
	else {
		printf("No hay suficiente memoria disponible\n");
	}
	return 0;
}
```

### C++ permite capturar excepciones
```c++
#include <iostream>
#include <new>

int main(void) 
{
	try {
		char *memoria = new char[9223372036854775807L / 2L];
		std::cout << "(C++) Liberando memoria..." << std::endl;
		delete [] memoria;
	}
	catch (const std::bad_alloc& error){
		std::cout << "(C++) No hay suficiente memoria disponible (" <<error.what()<< ')' << std::endl;
	}
	return 0;
}
```

## RAII
En `C++` se aplica el Resource Acquisition Is Initialization, lo que significa que al destruirse un objeto, este libera los recursos apropiadamente. 

Es el RAII el principal motivo por el que no existe el `finally` en `C++`, ya que en vez de tener en mente que debe hacerse algo siempre cuando se maneja una excepción, en `C++` lo que se hace siempre se declara en el objeto.

## Ejemplos

### En base de datos (transacción)
Una transacción en una base de datos corresponde a un grupo de acciones que se hacen todas o ninguna. Usualmente si ocurre un error, uno deshace todas las acciones hechas desde el inicio de la transacción.


