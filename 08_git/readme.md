# git

Git es un sistema de control de versiones, es decir, sirve para actualizar archivos (usualmente de un programa) de a poco.

Al ser un sistema de control de versiones, la información de versiones previas sigue disponible incluso cuando se cambian todos los datos, por esto hay que asegurarse de no introducir información indeseada (como claves).

## Definiciones
Repositorio Local: El computador en el que uno trabaja.

repositorio remoto: El lugar en el que se sirven los cambios, por ejemplo, `github`.

*commit*: Los cambios de los archivos que se le asigna un mensaje. Por ejemplo el commit de mensaje `fix suma` tiene los cambios del archivo `main.c` y el archivo `suma.c` para arreglar la suma.

*staging area*: Los *commit* que están localmente, pero que aún no se han subido al servidor.


## Acciones
`git` permite una variedad de acciones usando `git <accion>`, a continuación se detallan las mas simples:
| acción | descripción |
|-|-|
| `clone <repositorio>` | Crea un repositorio local a partir de un repositorio remoto	|
| `pull` | Trae los cambios del repositiorio remoto al repositorio local	|
| `add <archivo>` | Le indica a git que considere los cambios del archivo	local |
| `commit -m <mensaje>` | Le indica a git que los cambios locales considerados los agrupe con cierto mensaje	|
| `push` | Envia los cambios del repositiorio local a los que se le ha hecho commit al repositorio remoto	|
| `status` | Indica el estado de los arhcivos locales |
| `stash` | (Usar con cuidado) Guarda los cambios locales temporalmente, y deja el repositorio sin los cambios. Hacer dos veces seguidas `git stash` puede hacer que los primeros cambios se pierdan |
| `stash pop` | (Usar con cuidado) Aplica los cambios locales guardados en el uso de `git stash` en el repositorio local |

Hay operaciones más complejas como el uso de ramas, pero estas se escapan de lo abordable en el módulo.

# github
[github](https://github.com/StroveLight/UTFSM-INF-20125-lab) es una interfaz con la que usar acciones de `git`

## Repositorio
Un repositiorio es un lugar en el que uno puede subir sus cambios, puede ser de una persona o compartido.
* Ejemplo: https://github.com/StroveLight/UTFSM-INF-20125-lab

Uno puede crear un repositorio propio usando https://github.com/new
* Un repositorio puede ser público o privado, si es público puede ser visto por todos los de la internet


## Repositorio de perfil: 
Para crear este repositorio se necesita crear un nombre de repositorio con el mismo nombre que se tiene uno de usuario (tener cuidado con no usar el apodo en vez del nombre de usuario).
* Ejemplo: https://github.com/StroveLight/StroveLight

El archivo que se muestra es el `README.md` y está en formato `.md` al igual que este archivo. Para incluir una imagen se puede usar `![](imagen.png)`, asumiendo que la imágen está en la mismma carpeta que la actual.

Ejemplo imagen incluida:

![](metaton.png)

