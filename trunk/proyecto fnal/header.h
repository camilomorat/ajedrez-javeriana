/*
  Name: HEADER DEL AJEDREZ(ESTAN LOS PROTOTIPOS/CONSTANTES/ESTRUCTURAS)
  Copyright: JOSE DAVID RENGIFO FUENTES /2009
  Author: JOSE DAVID RENGIFO FUENTES
  Date: 01/06/09 18:46
*/
#ifndef HEADER_H
#define HEADER_H

//-------------------------------------------------------------------------------------------
const int TAM=9;
//-------------------------------------------------------------------------------------------
struct Jugada
{
       char ficha[3];
       char fichasMuertas[2][17];
       int columna;
       int fila;
       int jugador;
       int partida;
};
struct Movidas
{
       char tipo;
       int fila[8];
       int columna[8];
       int *fichas[3];
       int *fichas2[3];
       int contador;
       int alfil;
       int reyna;
       int torre;
};
//-------------------------------------------------------------------------------------------
int cambio(char numero);
char cambio2(int numero);
char imprimirTablero( char TABLERO[TAM][TAM]);
char movimiento(char TABLA[TAM][TAM],int fila2,int col2,Jugada posicion);
char movimientoMata(char tablero[TAM][TAM],Jugada posicion,Movidas jugada);
void imprimirMuertas(char tabla[2][17]);
char iniciarFichas(char matriz[2][17]);
void eliminarArreglo(int**escalera,int numPosiciones);
//-------------------------------------------------------------------------------------------
char peon(char tablero[TAM][TAM],Jugada posicion,Movidas jugada);
char caballo(char tablero[TAM][TAM],Jugada posicion,Movidas jugada);
char rey(char tablero[TAM][TAM],Jugada posicion,Movidas jugada);
char torre(char tablero[TAM][TAM],Jugada posicion,Movidas jugada);
char alfil(char tablero[TAM][TAM],Jugada posicion,Movidas jugada);
char reyna(char tablero[TAM][TAM],Jugada posicion,Movidas jugada);
//-------------------------------------------------------------------------------------------

#endif
