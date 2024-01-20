# Get Next Line

![Proyecto](https://img.shields.io/badge/Proyecto-GNL-blue)
![Licencia](https://img.shields.io/badge/Licencia-MIT-orange)
[![Language](https://img.shields.io/badge/Language-English-purple)](https://github.com/MiMendiola/Get_Next_Line#get-next-line)
![Versión](https://img.shields.io/badge/Versión-1.0-green)

El objetivo de este proyecto es crear una funcion muy practica que podremos usar mas adelante y poder aprender el concepto de las `variables estaticas` en C.

Tambien empezaremos a tocar los `files descriptors, (fd)` y a aprender como funcionan y como podremos recorrerlo independientemente de los caracteres que podamos leer, terminando leyendo todo el archivo. Y en mi resolucion aprenderemos a gestionarlas y beneficiarnos de las `referencias a punteros` para usar directamente la memoria de nuestros strings.

Deberemos entregar 3 archivos, y cada uno deberea tener la informacion especifica para cada uno con un maximo de 5 funciones por archivo.

Estas funciones deberan estar en nuestro archivo de `utils`. En mi caso utilize funciones de el proyecto libft pero estas funciones estan modificadas y utilize `ft_strlen`, `ft_strchr`, `ft_strjoin` y `ft_substr`. 

En nuestro archivo `get_next_line.h` tendremos que añadir todos los `prototipos de las funciones` utilizadas, a parte incluiremos las `librerias` que necesitaremos y `definiremos un BUFFER_SIZE` para que se pueda elegir el tamaño de los caracteres que leeremos manualmente para cuando compilemos el archivo, si no le dan un valor se ejecutara directamente con el tamaño que hayamos definido en nuestro archivo.

Proseguimos con nuestro archivo mas importante `get_next_line.c` en el que tendremos en mi caso 4 funciones.

- **void    free_all(char** ****to_free):** `limpiaremos desde la referencia del puntero` que pasemos como parametro y igualaremos el `puntero a NULL` para no tener errores.

- **char	*get_next_line(int fd)**: tendremos nuestra `variable estatica` y la variable que guardara nuestra `linea a mostrar`. Realizaremos la comprobacion de que nada de lo que usamos da error y ejecutaremos nuestras demas funciones ahi y devolveremos la variable que tendremos que imprimir.

- **char**	***read_till_find(int fd, char** ***str_static):** como parametros tendremos nuestra `estatica` y el `fd`. Crearemos una `variable que contendra los bytes leidos` y un `str con el tamaño del BUFFER_SIZE + 1`, comprobaremos que el `'\n’` no este en la lectura del buffer y que la `lectura de bytes sea distinta de cero`. Y comprobaremos que si `bytes < 0`, abra un error y limpiaremos la estatica y devolveremos NULL y si `bytes == 0` saldremos del bucle para devolver nuestra linea leida.
    
    Proseguiremos añadiendo el `\0 a nuestra linea` y añadiendo a nuestra estatica toda la linea leida y finalizamos `retornando nuestra estatica` con todo lo leido.
    
- **void relocate_line(char** ****str_static, char** ****front):** como parametros tendremos nuestra `referencia a estatica` y `referencia a linea a imprimir`. Con esto podremos modificar directamente desde la memoria de nuestros punteros y poder modificarlos en la misma funcion. Comprobaremos que nuestra estatica no sea NULL y que exista, si no la inicializaremos a NULL.  Despues buscaremos la primera linea hasta que encontremos `\0 o \n` y proseguiremos añadiendo 1 posicion mas a nuestro iterador para conseguir el salto de linea o null.
    
    Sabiendo esto podremos conseguir la primera linea aplicando `ft_substr` a `*front` desde la primera posicion hasta el tamaño que encontramos. Seguiremos diciendo que `back` sera igual a la direccion de memoria de la estatica para poder `freezearla` . Continuamos aplicando `ft_substr` a `*estatica` desde que encontramos el salto de linea hasta la `longuitud total - el encuentro del salto`, esto nos creara una nueva direccion de memoria de nuestra estatica con la nueva informacion necesaria y seremos libres de poder freezear nuestra back.
    

---

## Tabla de Contenidos

[GET_NEXT_LINE.C](../get_next_line.c)

[GET_NEXT_LINE_UTILS.C](../get_next_line_utils.c)

[GET_NEXT_LINE.H](../get_next_line.h)

[BONUS](../bonus/)

---

## Recomendaciones

Podremos usar funciones que anteriormente hemos realizado en uno de nuestros anteriores proyectos `Libft` o tambien podriamos realizarlas nuevamente segun nuestras necesidades.

Usar el compilador de VSC el cual nos ayudara a revisar que nuestra creacion de variables se hagan limpiamente y sin ningun problema, y nos ayudara a entender mucho mejor nuestro codigo.

Antes de comenzar deberemos tener claro si queremos realizarlo con la parte bonus o no, en caso de querer hacerlo con bonuses deberemos tener claro estas 2 condiciones:

- Desarrolla get_next_line() con una sola variable estática.
- Tu get_next_line tiene que ser capaz de gestionar múltiples fd a la vez, pudiendo ser de forma alterna y no deberemos perder el hilo de lectura de cada uno de los fd.

A parte deberemos añadir `_bonus` en los archivos bonuses.

Otra cosa a tener en cuenta es que hay que ser observador y saber donde tendremos que hacer `free`, y esto lo realizaremos cada vez que reservemos memoria en nuestro programa.

---

## Contacto

If you have any questions, suggestions, or comments about Get_Next_Line, feel free to contact me:

- Email: <a href="mailto:mglmendiol@gmail.com" style="text-decoration: none; color:#fff">mglmendiol@gmail.com</a>
- LinkedIn: <a href="https://www.linkedin.com/in/mimendiola/" style="text-decoration: none; color:#fff !important;">https://www.linkedin.com/in/mimendiola/</a>