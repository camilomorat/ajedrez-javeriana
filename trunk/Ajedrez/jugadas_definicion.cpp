
#ifndef funciones
#undef funciones
#include <cstdlib>
#include <iostream>
#include "fichas_movimiento.h"
#include "funciones_jugadas.h"

char imprimirTablero(char TABLERO[TAM][TAM])
{     
     cout<<endl; 
     for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
            cout << TABLERO [i][j];
            if (j+1 < TAM)
               cout << " | ";
        }
		cout << endl;
        if (i+1 < TAM)
        {
                for (int cont = 0 ; cont < 34; cont++)
                {
					cout << '-';
                }
        }
        cout << endl;
    }    
}

int cambio(char numero)
{
    int cambio;
    if(numero=='A')
       cambio=7;
    if(numero=='B')
       cambio=6;
    if(numero=='C')
       cambio=5;
    if(numero=='D')
       cambio=4;
    if(numero=='E')
       cambio=3;
    if(numero=='F')
       cambio=2;
    if(numero=='G')
       cambio=1;
    if(numero=='H')
       cambio=0;
    
    return cambio;
}


#endif
