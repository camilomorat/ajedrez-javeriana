#include <cstdlib>
#include <iostream>

using namespace std;

const int TAM_TABLERO=9;
char imprimirTablero( char TABLERO[TAM_TABLERO][TAM_TABLERO]);
int cambio(char numero);

int main(int argc, char *argv[])
{
    int opcion;
    char TABLERO[TAM_TABLERO][TAM_TABLERO]={
	{'a', 'T','C','A', 'D','R','A','C','T'},
	{'b', 'P','P','P', 'P','P','P','P','P'},
	{'c', ' ',' ',' ', ' ',' ',' ',' ',' '},
	{'d', ' ',' ',' ', ' ',' ',' ',' ',' '},
	{'e', ' ',' ',' ', ' ',' ',' ',' ',' '},
	{'f', ' ',' ',' ', ' ',' ',' ',' ',' '},
	{'g', 'P','P','P', 'P','P','P','P','P'},
	{'h', 'T','C','A', 'D','R','A','C','T'},
	{'*', '1','2','3', '4','5','6','7','8'}};
    
    cout<<"*****************************\n";
    cout<<"**       AJEDREZ           **\n";
    cout<<"*****************************\n";
    cout<<endl<<endl;
        
    cout<<"Por favor escoja una de las siguientes opciones:\n";
    cout<<"\n1. Instrucciones y modo de juego\n";
    cout<<"\n2. Jugar Ahora!!!!!!\n";
    cout<<"\n3. Oprima 3 para salir del juego\n";    
    cout<<endl;
    cin>>opcion;  
    
    switch(opcion)
    {
         case 1:
         cout<<"Modo de Juego"<<endl;
         cout<<"Es la misma modalidad del ajedrez comun, para seleccionar\n";
         cout<<"una ficha se escribe su posicion ejem: H6, despues aparecen\n";
         cout<<"una serie de movimientos posibles los cuales aparecen indicados\n";
         cout<<"con numeros del 1-20. (TODAS LAS JUGADAS SE DEBEN ESCRIBIRSE EN\n";
         cout<<"MAYUSCULAS). Para terminar el juego se digita FIN.\n";
         cout<<endl;
         cout<<"Por favor escoja una de las siguientes opciones:\n";
         cin>>opcion;
            
         case 2:
         
         imprimirTablero(TABLERO);         
         char jugada[3];
         
         while((jugada[0]!='F')&&(jugada[1]!='I')&&(jugada[2]!='N'))
         {    
                cout<<"Recuerde colocar en mayusculas las letras y sin espacios\n";        
                cout<<"Digite la jugada: \n";
                cout<<endl;
                cin>>jugada;
                cout<<endl;
                
                cambio(jugada[0]);
                imprimirTablero(TABLERO);
         }
              
         case 3:
         break;      
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

char imprimirTablero(char TABLERO[TAM_TABLERO][TAM_TABLERO])
{     
     cout<<endl; 
     for (int i = 0; i < TAM_TABLERO; i++)
	{
		for (int j = 0; j < TAM_TABLERO; j++)
		{
            cout << TABLERO [i][j];
            if (j+1 < TAM_TABLERO)
               cout << " | ";
        }
		cout << endl;
        if (i+1 < TAM_TABLERO)
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

