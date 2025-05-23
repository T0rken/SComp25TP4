# Trabajo Práctico N°4: Módulos de kernel

## Cátedra de Sistemas de Computación, FCEFyN, UNC. 2025

### Grupo: Los puntos flotantes

### Alumnos: Bernaus, Julieta; Di Pasquo, Franco; Viccini, Carlos Patricio

### Profesor: Jorge, Javier

## Introducción

Un módulo de kernel es un fragmento de código que puede ser cargado y descargado del kernel, y que sirve para extender su funcionalidad sin reiniciar el sistema. En este laboratorio, se exploran esas propiedades de los módulos y conceptos relacionados.

## Desarrollo


### Consigna

La consigna para este trabajo consta de los siguiente puntos:

- Clonar un [repositorio](https://gitlab.com/sistemas-de-computacion-unc/kenel-modules.git) 
- Instalar los paquetes "build-essential", "checkinstall", "kernel-package" y "linux-source".
- Resolver dos desafíos y una serie de once pasos.

Los desafíos son los siguientes:

- ¿Qué es checkinstall y para qué sirve? ¿Se animan a usarlo para empaquetar un hello world ? Revisar la bibliografía para impulsar acciones que permitan mejorar la seguridad del kernel, concretamente: evitando cargar módulos que no estén firmados. rootkits ? 

- Debe tener respuestas precisas a las siguientes preguntas y sentencias:
    - ¿ Qué funciones tiene disponible un programa y un módulo ?
    - Espacio de usuario o espacio del kernel.
    - Espacio de datos.
    - Drivers. Investigar contenido de /dev.

Por su parte, la serie de consignas es:
1. ¿Qué diferencias se pueden observar entre los dos modinfo ? 
2. ¿Qué divers/modulos estan cargados en sus propias pc? comparar las salidas con las computadoras de cada integrante del grupo. Expliquen las diferencias. Carguen un txt con la salida de cada integrante en el repo y pongan un diff en el informe.
3. ¿cuales no están cargados pero están disponibles? que pasa cuando el driver de un dispositivo no está disponible. 
4. Correr hwinfo en una pc real con hw real y agregar la url de la información de hw en el reporte. 
5. ¿Qué diferencia existe entre un módulo y un programa  ? 
6. ¿Cómo puede ver una lista de las llamadas al sistema que realiza un simple helloworld en c?
7. ¿Qué es un segmentation fault? ¿Cómo lo maneja el kernel y como lo hace un programa?
8. ¿Se animan a intentar firmar un módulo de kernel ? y documentar el proceso ?  https://askubuntu.com/questions/770205/how-to-sign-kernel-modules-with-sign-file
9. Agregar evidencia de la compilación, carga y descarga de su propio módulo imprimiendo el nombre del equipo en los registros del kernel. 
10. ¿Que pasa si mi compañero con secure boot habilitado intenta cargar un módulo firmado por mi? 
11. Dada la siguiente nota https://arstechnica.com/security/2024/08/a-patch-microsoft-spent-2-years-preparing-is-making-a-mess-for-some-linux-users/ 
    - ¿Cuál fue la consecuencia principal del parche de Microsoft sobre GRUB en sistemas con arranque dual (Linux y Windows)?
    - ¿Qué implicancia tiene desactivar Secure Boot como solución al problema descrito en el artículo?
    - ¿Cuál es el propósito principal del Secure Boot en el proceso de arranque de un sistema?

### Desafío #1

Estas preguntas fueron contestadas en clase pero se recopila la información aquí también.

1. ¿Qué es checkinstall y para qué sirve?

Checkinstall es una herramienta que se utiliza en sistemas Linux para crear paquetes instalables (por ejemplo, .deb en Debian/Ubuntu) a partir de programas que se compilan e instalan desde el código fuente. Un paquete instalable es un archivo que contiene todo lo necesario para instalar un programa en un sistema operativo.

Cuando instalas un programa manualmente con `make install`, los archivos se copian al sistema sin un registro claro, lo que dificulta su desinstalación.
Con `checkinstall`, en vez de ejecutar `make install`, ejecutás sudo `checkinstall`. Esto crea un paquete instalable que se puede gestionar fácilmente con el sistema de paquetes (instalar, actualizar o desinstalar).

De esta manera, se consigue tener un sistema ordenado y se facilita la gestion de software instalado desde el codigo fuente

2. ¿Se animan a usarlo para empaquetar un hello world ? 
<!-- Revisar la bibliografía para impulsar acciones que permitan mejorar la seguridad del kernel, concretamente: evitando cargar módulos que no estén firmados. rootkits ?  -->

### Desafío #2

1. ¿Qué funciones tiene disponible un programa y un módulo?

    Funciones de un programa:
    - funciones de librerías externas y estándar,
    - llamadas al sistema,
    - funciones definidas por el usuario.
    Funciones de un módulo:
    - funciones externas provistas por el kernel solamente,
    - funciones definidas por el usuario.       

2. Espacio de usuario o espacio del kernel.

    Existen dos niveles de privilegio utilizados por Unix: kernel y usuario. Cada uno tiene su espacio, en el cual está permitido realizar ciertas acciones. Esto permite ordenar las acciones y proteger el acceso a los recursos.

3. Espacio de datos.

    El espacio de datos es la parte de la memoria donde se almacenan los datos, incluyendo todas las variables y segmentos de datos. Cualquier módulo de kernel se linkea a todo el kernel, por lo cual es importante mantener un espacio de datos ordenado. Se recomienda utilizar prefijos y convenciones de código bien definidas, y variables estáticas.

4. Drivers. Investigar contenido de /dev.

    En Unix, cada pieza de hardware está representada por un archivo en /dev, que le permite comunicarse con el hardware. Ese archivo es una interfaz que se comunica con lo conocido como un driver, que es un módulo de kernel también y maneja la comunicación real.

### Resolución de pasos
1. ¿Qué diferencias se pueden observar entre los dos modinfo?

2. ¿Qué divers/módulos están cargados en sus propias pc? comparar las salidas con las computadoras de cada integrante del grupo. Expliquen las diferencias. Carguen un txt con la salida de cada integrante en el repo y pongan un diff en el informe.

Las salidas de nuestras tres máquinas se encuentran en: [lsmod Franco.txt](./lsmod%20Franco.txt), [lsmod Julieta](./lsmod%20Julieta.txt) y .

Pendiente: Patricio, diff.

3. ¿Cuáles no están cargados pero están disponibles? ¿Qué pasa cuando el driver de un dispositivo no está disponible?

Los módulos disponibles son los que están en `/lib/modules/$(uname -r)/`, mientras que los cargados son aquellos que encuentra `lsmod`. Se puede comparar las salidas de imprimir esos dos comandos (un `ls` de los módulos del kernel) y ahí se obtendrán los módulos no cargados pero disponibles. 

Por otro lado, si no existe ningún driver para un hardware, no se lo puede utilizar y no hay nada en "Kernel driver in use:" cuando se utiliza el comando `lspci -k`.

4. Correr hwinfo en una pc real con hw real y agregar la url de la información de hw en el reporte. 

El reporte de `hwinfo` se encuentra en [hwinfo.txt](./hwinfo.txt).

5. ¿Qué diferencia existe entre un módulo y un programa? 
6. ¿Cómo puede ver una lista de las llamadas al sistema que realiza un simple helloworld en c?
7. ¿Qué es un segmentation fault? ¿Cómo lo maneja el kernel y como lo hace un programa?
8. ¿Se animan a intentar firmar un módulo de kernel ? y documentar el proceso ?  https://askubuntu.com/questions/770205/how-to-sign-kernel-modules-with-sign-file
9. Agregar evidencia de la compilación, carga y descarga de su propio módulo imprimiendo el nombre del equipo en los registros del kernel. 
10. ¿Que pasa si mi compañero con secure boot habilitado intenta cargar un módulo firmado por mi? 
11. Dada la siguiente nota https://arstechnica.com/security/2024/08/a-patch-microsoft-spent-2-years-preparing-is-making-a-mess-for-some-linux-users/ 
    - ¿Cuál fue la consecuencia principal del parche de Microsoft sobre GRUB en sistemas con arranque dual (Linux y Windows)?
    - ¿Qué implicancia tiene desactivar Secure Boot como solución al problema descrito en el artículo?
    - ¿Cuál es el propósito principal del Secure Boot en el proceso de arranque de un sistema?

## Conclusión

## Bibliografía

https://sysprog21.github.io/lkmpg/#how-modules-begin-and-end

