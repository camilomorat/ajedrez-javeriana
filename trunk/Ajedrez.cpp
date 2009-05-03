#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    using namespace std;
const int TAM_TABLERO=9;
char casillas[TAM_TABLERO];

bool VerificarSudoku ( char Tablero[][TAM_TABLERO], char valor[]);
bool VerificarHorizontal(char Tablero[][TAM_TABLERO], char valor[]);
bool VerificarVertical (char Tablero[][TAM_TABLERO], char valor[]);
bool VerificarCuadro(char Tablero[][TAM_TABLERO], char valor[]);
bool VerificarCasillas (char casillas[], char valor[]);


	char fila, columna;
	char dato;
	char valor[3], Fin[3];
	bool Salir= true;
	char opcion;
	Fin[0]='F';
	Fin[1]='i';
	Fin[2]='n';
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
	
if (opcion=='s')
	{
	   for (int i=0;i<TAM_TABLERO;i++)
	   {
		   for (int j=0;j<TAM_TABLERO;j++)
		   {
			   TABLERO[i][j]= ' ';
		   }
	   }
	}
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
    	
    system("PAUSE");
    return EXIT_SUCCESS;
}
