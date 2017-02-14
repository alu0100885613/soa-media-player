# Media Player

Reproductor multimedia, que carga y reproduce videos, permitiendo pausarlos, pararlos, verlos en velocidad rápidad, normal e inversa. También permite acceder a la webcam, activándola y parándola cuando sea necesario.

## Cómo compilar

1. Abrir una terminal :black_small_square:
2. Situarse en el directorio del proyecto :u6e80:
3. Ejecutar `qmake`. Esto generará en la carpeta un [Makefile](http://www.cprogramming.com/tutorial/makefiles.html). :page_facing_up:
4. Ejecutar `make`. Esto genererá archivos .o, el ejecutable y los archivos moc y qrc. :package: :poop:
5. Listo, ejecutar el reproductor.app (doble click en carpeta) para abrir la aplicación. :vhs:
6. Al terminar la ejecución y uso, usar `make clean` y `make distclean`. Las cosas bien recogidas. :mailbox_closed:


## Requisitos para compilar y ejecutar

1. Que la bash conozco el comando `qmake`. :mag:
    
    1.1. Para esto, hará falta editar el fichero **~/profile** en Linux :penguin: y **~/.bash_profile** en            MAC :green_apple:.Podemos usar `vi ~/.bash_profile`, para añadir la ruta en la que se encuentra `qmake`
         al PATH, la cuál será de esta forma: 
        `PATH=$PATH:/Users/<tu usuario>/Qt/<versión (5.8 recomendada) >/clang_64/bin`.

2. Tener el compilador g++.



## Características del reproductor

Se han implementado los siguientes elementos:

 * Botón **Play / Pause**, para iniciar o pausar la reproducción de una película. :arrow_forward:
   * Si no se está reproduciendo nada o se está viendo la webcam, al pulsar este control se abre un cuadro de diálogo para seleccionar el archivo de vídeo y después comenzar la reproducción.
   * Si se estaba reproduciendo un archivo, esta se pondrá en pausa.
 * Botón **Webcam**, para iniciar la captura de la webcam.:camera:
 * Botón **Stop**, para detener la reproducción del archivo o la captura de la webcam. :no_entry:
 * Botón radio **Rewind**, para reproducir la película hacia atrás. Solo actúa y tiene efectos sobre vídeos. :rewind:
 * Botón radio **Forward**, para reproducir la película hacia adelante de forma acelerada. Solo actúa y tiene efectos sobre vídeos. :fast_forward:
 * Botón radio **Normal**, para reproducir la película de manera normal (opción por defecto). Solo actúa y tiene efectos sobre vídeos. 

La ruta del video con el nombre y el nombre de la webcam se refleja en la barra de estado.
Los botones tienen iconos. :new_moon_with_face:
Los videos que reproduce son .mp4 y .amv. :neckbeard:
Existen ventanas de advertencia para avisar al usuario. :warning:
El botón Play / Pause es el mismo pero cambia de nombre dependiendo del estado del vídeo.
Manejo de errores del reproductor y la cámara.


 **Eduardo Borges Fernández** (alu0100885613@ull.edu.es)
 Sistemas Operativos Avanzados. Universidad de La Laguna (ULL) :mortar_board:
