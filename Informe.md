# Trabajo Práctico N°4: Módulos de kernel

## Cátedra de Sistemas de Computación, FCEFyN, UNC. 2025

### Grupo: Los puntos flotantes

### Alumnos: Bernaus, Julieta; Di Pasquo, Franco; Viccini, Carlos Patricio

### Profesor: Jorge, Javier

## Introducción
En el siguiente informe, se desarrollarán las consignas propuestas en clase acerca de los modulos de Kernel. Se explorara estos segmentos de código, los cuales pueden cargarse y descargarse dinámicamente en el kernel según sea necesario, y que permiten añadir o eliminar funcionalidades sin necesidad de reiniciar el sistema. 


## Desarrollo


### Consigna

La consigna para este trabajo consta de los siguiente puntos:

- Clonar un [repositorio](https://gitlab.com/sistemas-de-computacion-unc/kenel-modules.git) 
- Instalar los paquetes "build-essential", "checkinstall", "kernel-package" y "linux-source".
- Resolver los desafios #1 y #2 propuestos:

### Desafio #1

Estas preguntas fueron contestadas en clase pero se recopila la información aquí también.

1. ¿Qué es checkinstall y para qué sirve?

Checkinstall es una herramienta que se utiliza en sistemas Linux para crear paquetes instalables (por ejemplo, .deb en Debian/Ubuntu) a partir de programas que se compilan e instalan desde el código fuente. Un paquete instalable es un archivo que contiene todo lo necesario para instalar un programa en un sistema operativo.

Cuando instalas un programa manualmente con `make install`, los archivos se copian al sistema sin un registro claro, lo que dificulta su desinstalación.
Con `checkinstall`, en vez de ejecutar `make install`, ejecutás sudo `checkinstall`. Esto crea un paquete instalable que se puede gestionar fácilmente con el sistema de paquetes (instalar, actualizar o desinstalar).

De esta manera, se consigue tener un sistema ordenado y se facilita la gestion de software instalado desde el codigo fuente

2. ¿Se animan a usarlo para empaquetar un hello world ? 
<!-- Revisar la bibliografía para impulsar acciones que permitan mejorar la seguridad del kernel, concretamente: evitando cargar módulos que no estén firmados. rootkits ?  -->

### Desafio #2

1. ¿Qué funciones tiene disponible un programa y un módulo?

2. Espacio de usuario o espacio del kernel.

3. Espacio de datos.

4. Drivers. Investigar contenido de /dev.

## Conclusión

