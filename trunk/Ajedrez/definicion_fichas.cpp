
#ifndef fichas
#undef fichas

#include <cstdlib>
#include <iostream>

#include "fichas_movimiento.h"
#include "funciones_jugadas.h"

using namespace std;

char movimiento(char TABLA[TAM][TAM],int fila,int fila2,int col,int col2)
{                            
        char valor;
           
           valor= TABLA[fila][col];
           
           if(TABLA[fila2][col2]==' ')
           {
                     TABLA[fila2][col2]=valor;
                     TABLA[fila][col]=' ';      
           }
                                                 
}




#endif
