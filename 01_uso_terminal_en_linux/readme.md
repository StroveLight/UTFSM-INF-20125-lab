# Lab 1: Uso terminal en Linux

## Comandos comunes

| Nombre | acción |
|-|-|
| touch | Crea archivo |
| mkdir | Crea carpeta |
| cd | Cambiar directorio |
| ls | Listar archivos en directorios |
| rm | Remover archivos |
| help | Muestra los comandos más comunes, y permite consultar sobre ellos |
| man | Muestra el manual de un comando. Hacer click en la techa "Q" para salir |
| grep | Buscar texto en archivos |
| echo | Mostrar en pantalla |
| cat | Mostrar contenido de archivo |
| time | Mide el tiempo de ejecución  |
| head | Muestra las primeras líneas de un archivo |
| mv | Mover archivo |
| cp | Copiar archivo |

## Operadores

| Operador | Nombre | Descripción |
|-|-|-|
| `\|` | Pipe | Permite enviar el output de un programa a otro
| `>` | Output redirection | Crea archivo con el output del comando
| `<` | Input redirection | Ejecuta un comando con el output de un archivo


### Ejemplos
1. Enviar ls a archivo: `ls -alt > ls.txt`
2. Mostrar en consola información ordenada `echo | sort < 123.txt`
