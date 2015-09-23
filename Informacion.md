# **AJEDREZ** #

### _**PLANEAMIENTOS & REQUERIMIENTOS DEL PROFESOR**_ ###
Para que el ajedrez tenga un buen desarrollo, hay que realizar ciertas funciones para saber el movimiento de cada pieza, teniendo en cuenta que cada ficha se mueve de una forma diferente, dandole prevalencia al color blanco que es el que predomina al inicio de cada partida.

Dentro de los requerimientos exiguidos estan:

  * Para cualquier movida, indicar al usuario las posibles posiciones en donde puede ubicar la pieza, teniendo en cuenta el tipo de pieza y su movimiento.

  * El juego debe ejecutarse con otra persona, con el fin interactuar y asi asegurando un juego placentero

### _**METODOS PARA ABORDAR EL PROBLEMA**_ ###
**1.** Matriz de posiciones(8x8) aparece con las 16 fichas en pocision inicial

**2.** Funcion de turno(PARA DOS JUGADORES)

  * Antes de: si desea terminar el juego digite "FIN".

  * El primer turno es para el jugador de las fichas blancas o (jugador 1)

> jugador uno: ¿que ficha desea mover?


**3.** Movimientos por fichas(una funcion por cada ficha)

Recorrido por la matriz de posiciones de acuerdo a la ficha que se desea mover y se imprime las opciones que tiene la ficha para la nueva ubicacion, y tambien se examina si en las opciones que tiene la ficha de posicionarse existe otra ficha del jugador contrario.

  * si existe que la ficha de turno ocupe su lugar.

  * si se elimina una  ficha que se guarde en un lugar donde se identifiquen las fichas eliminadas de cada jugador

  * si existe una ficha del equipo contrario ubicada en la primera fila del equipo enemigo que se le muestre al jugador que fichas perdio y que escoja una y esa ficha se ubica en la posicion original.