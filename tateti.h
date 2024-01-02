#ifndef TATETI_H_INCLUDED
#define TATETI_H_INCLUDED
#define TAMANIO 3

void iniciarTablero(char tablero[][TAMANIO]);
void mostrarTablero(char tablero[][TAMANIO]);
int sortearJugadorComienzo();
int pedirPosicion(int jugadorConTurnoParaJugar);
int verificarEstadoPosicionElegida(char tablero[][TAMANIO], int posicionElegidaPorJugador);
void modificarPosicionTablero(char tablero[][TAMANIO], int posicionElegidaPorJugador, char caracterAEscribir);
void jugar(char tablero[][TAMANIO], int jugadorConTurnoParaJugar);
int siguienteJugador(int jugadorActual);
int comprobarGanador(char tablero[][TAMANIO]);
void darResultados(int ganador);
void repetirJuego(char tablero[][TAMANIO]);
int seguirJugando();

#endif // TATETI_H_INCLUDED
