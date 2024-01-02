#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tateti.h"

void iniciarTablero(char ta[][TAMANIO])
{
    ta[0][0] = '1';
    ta[0][1] = '2';
    ta[0][2] = '3';
    ta[1][0] = '4';
    ta[1][1] = '5';
    ta[1][2] = '6';
    ta[2][0] = '7';
    ta[2][1] = '8';
    ta[2][2] = '9';
}

void mostrarTablero(char ta[][TAMANIO])
{
    printf("\nTablero:\n\n");
    for (int i = 0; i < TAMANIO; i++)
    {
        for (int j = 0; j < TAMANIO; j++)
        {
            if ((ta[i][j] == 'X') || (ta[i][j] == 'O')) //Se muestra la posición del tablero solo si
            {                                           //está cargada con una de las "fichas"
                printf(" |%c| ", ta[i][j]);
            }
            else
            {
                printf(" | | ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int sortearJugadorComienzo()
{
    return 1 + rand () % 2;
}

int pedirPosicion(int jugConTurno)
{
    int pos;
    do
    {
        printf("Jugador %d, ingrese en que posicion quiere jugar: #", jugConTurno);
        scanf("%d", &pos);
    }
    while((pos < 1) || (pos > 9));
    return pos;
}

int verificarEstadoPosicionElegida(char ta[][TAMANIO], int posElegida)
{
    int estado = 0; //Significa que la posición elegida está libre
    switch(posElegida)
    {
        case 1:
        {
            if ((ta[0][0] == 'X') || (ta[0][0] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 2:
        {
            if ((ta[0][1] == 'X') || (ta[0][1] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 3:
        {
            if ((ta[0][2] == 'X') || (ta[0][2] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 4:
        {
            if ((ta[1][0] == 'X') || (ta[1][0] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 5:
        {
            if ((ta[1][1] == 'X') || (ta[1][1] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 6:
        {
            if ((ta[1][2] == 'X') || (ta[1][2] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 7:
        {
            if ((ta[2][0] == 'X') || (ta[2][0] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 8:
        {
            if ((ta[2][1] == 'X') || (ta[2][1] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
        break;
        case 9:
        {
            if ((ta[2][2] == 'X') || (ta[2][2] == 'O'))
            {
                estado = 1; //Significa que la posición está ocupada
                return estado;
            }
        }
    }
    return estado;
}

void modificarPosicionTablero(char ta[][TAMANIO], int posElegida, char caracAEscribir)
{
    if (posElegida == 1)
    {
        ta[0][0] = caracAEscribir;
    }
    else if (posElegida == 2)
    {
        ta[0][1] = caracAEscribir;
    }
    else if (posElegida == 3)
    {
        ta[0][2] = caracAEscribir;
    }
    else if (posElegida == 4)
    {
        ta[1][0] = caracAEscribir;
    }
    else if (posElegida == 5)
    {
        ta[1][1] = caracAEscribir;
    }
    else if (posElegida == 6)
    {
        ta[1][2] = caracAEscribir;
    }
    else if (posElegida == 7)
    {
        ta[2][0] = caracAEscribir;
    }
    else if (posElegida == 8)
    {
        ta[2][1] = caracAEscribir;
    }
    else
    {
        ta[2][2] = caracAEscribir;
    }
}

void jugar(char ta[][TAMANIO], int jugConTurno)
{
    int posicionElegida;
    int estadoDeLaPosicion;
    do
    {
        posicionElegida = pedirPosicion(jugConTurno);
        estadoDeLaPosicion = verificarEstadoPosicionElegida(ta, posicionElegida);
        if (estadoDeLaPosicion == 0)
        {
            if (jugConTurno == 1)
            {
                modificarPosicionTablero(ta, posicionElegida, 'X'); //Escribimos una 'X' en la posicion elegida
            }
            else
            {
                modificarPosicionTablero(ta, posicionElegida, 'O'); //Escribimos una 'O' en la posicion elegida
            }
        }
        else
        {
            printf("\nJugador %d, la posicion %d esta ocupada, ingrese otra\n", jugConTurno, posicionElegida);
        }
    }
    while(estadoDeLaPosicion == 1);
}

int siguienteJugador(int jugActual)
{
    if (jugActual == 1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int comprobarGanador(char ta[][TAMANIO])
{
    int jugadorGanador = 0; //No hay ganador
    ///Verificaciones en filas
    for (int i = 0; i < TAMANIO; i++)
    {
        if ((ta[i][0] == 'X') && (ta[i][1] == 'X') && (ta[i][2] == 'X'))
        {
            printf("\nFelicitaciones jugador 1! Gano el juego\n");
            jugadorGanador = 1;
            return jugadorGanador;
        }
        if ((ta[i][0] == 'O') && (ta[i][1] == 'O') && (ta[i][2] == 'O'))
        {
            printf("\nFelicitaciones jugador 2! Gano el juego\n");
            jugadorGanador = 2;
            return jugadorGanador;
        }
    }
    ///Verificaciones en columnas
    for (int i = 0; i < TAMANIO; i++)
    {
        if ((ta[0][i] == 'X') && (ta[1][i] == 'X') && (ta[2][i] == 'X'))
        {
            jugadorGanador = 1;
            return jugadorGanador;
        }
        if ((ta[0][i] == 'O') && (ta[1][i] == 'O') && (ta[2][i] == 'O'))
        {
            jugadorGanador = 2;
            return jugadorGanador;
        }
    }
    ///Verificaciones en diagonales
    //Jugador 1
    if ((ta[0][0] == 'X') && (ta[1][1] == 'X') && (ta[2][2] == 'X'))
    {
        jugadorGanador = 1;
        return jugadorGanador;
    }
    if ((ta[2][0] == 'X') && (ta[1][1] == 'X') && (ta[0][2] == 'X'))
    {
        jugadorGanador = 1;
        return jugadorGanador;
    }
    //Jugador 2
    if ((ta[0][0] == 'O') && (ta[1][1] == 'O') && (ta[2][2] == 'O'))
    {
        jugadorGanador = 2;
        return jugadorGanador;
    }
    if ((ta[2][0] == 'O') && (ta[1][1] == 'O') && (ta[0][2] == 'O'))
    {
        jugadorGanador = 2;
        return jugadorGanador;
    }
    return jugadorGanador;
}

void darResultados(int gan)
{
    if (gan == 0)
    {
       printf("\nHubo empate!\n");
    }
    else if (gan == 1)
    {
        printf("\nFelicitaciones jugador 1! Gano el juego\n");
    }
    else if (gan == 2)
    {
        printf("\nFelicitaciones jugador 2! Gano el juego\n");
    }
}

void repetirJuego(char tabl[][TAMANIO])
{
    int opcionElegida;
    do
    {
        iniciarTablero(tabl);
        mostrarTablero(tabl); //Mostramos el tablero vacío antes de comenzar
        int jugadorConTurno = sortearJugadorComienzo(); //Se sortea quién comienza
        int jugadas = 0; //Contador de jugadas: cuando llega a 9 corta el juego porque ya no quedan posiciones libres
        int ganador = 0; //No hay ganador
        while ((ganador == 0) && (jugadas < 9))
        {
            jugar(tabl, jugadorConTurno); //Se realiza una jugada
            jugadas++;
            mostrarTablero(tabl); //Se muestra el tablero con los cambios
            jugadorConTurno = siguienteJugador(jugadorConTurno); //Cambiamos el turno
            ganador = comprobarGanador(tabl); //Verificamos si hay un ganador
        }
        darResultados(ganador);
        opcionElegida = seguirJugando();
    }
    while (opcionElegida == 1);
    printf("\nGracias por jugar!");
}

int seguirJugando()
{
    int opcionElegida;
    do
    {
        printf("\nIngrese 1 para seguir jugando.\n");
        printf("Ingrese 0 para terminar el juego.\n");
        printf("Su opcion: #");
        scanf("%d", &opcionElegida);
    }
    while(opcionElegida != 0 && opcionElegida != 1);
    return opcionElegida;
}
