# Trabajo Práctico N°4: Módulos de kernel

## Cátedra de Sistemas de Computación, FCEFyN, UNC. 2025

### Grupo: Los puntos flotantes

### Alumnos: Bernaus, Julieta; Di Pasquo, Franco; Viccini, Carlos Patricio

### Profesor: Jorge, Javier

## Introducción

Un módulo de kernel es un fragmento de código que puede ser cargado y descargado del kernel, y que sirve para extender su funcionalidad sin reiniciar el sistema. En este laboratorio, se exploran esas propiedades de los módulos y conceptos relacionados.

## Desarrollo

### Consigna

La consigna cuenta con dos desafíos y una serie de once preguntas para completar luego de seguir una serie de pasos.

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

### Desafío 1

### Desafío 2

### Resolución de pasos

## Conclusión

