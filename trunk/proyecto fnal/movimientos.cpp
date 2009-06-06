/*
  Name: MOVIMIENTOS DEL AJEDREZ
  Copyright: JOSE DAVID RENGIFO FUENTES /2009
  Author: JOSE DAVID RENGIFO FUENTES
  Date: 01/06/09 18:47
*/

#include <iostream>
#include <windows.h>
#include "header.h"

using namespace std;

//------------------------------------------------------------------------------------------
char imprimirTablero(char TABLERO[TAM][TAM])
{    
     HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE); 
     system("cls");
     cout<<endl;
     
     for (int i = 0; i < TAM; i++)
	{
         if(i==8)
         {                   
                    for(int m=0;m<TAM;m++)//coloca color a fila de los numeros guias
                    {                            
                            SetConsoleTextAttribute (hConsoleHandle,14);
                            cout<<TABLERO[i][m];
                            SetConsoleTextAttribute (hConsoleHandle,7 ); 
                            
                            if (m+1 < TAM)//imprime la division de los numeros guias
                            cout << " | ";        
                    }                    
         }
         else
         {
                    for(int m=0;m<1;m++)//coloca color a la columna de las letras guias
                    {                            
                          SetConsoleTextAttribute (hConsoleHandle,14);
                          cout<<TABLERO[i][m];
                          SetConsoleTextAttribute (hConsoleHandle,7 );
                          
                          if (m+1 < TAM)//imprime la division de las letras guias
                          cout << " | ";  
                    } 
         }         
         
        for (int j = 1; j < TAM; j++)
		{
            if(i<8)//imprime el contenido de la tabla
            cout << TABLERO [i][j];
            
            if(i<8)
            {
                   if (j+1 < TAM)//coloca las divisiones en forma de columnas
                   cout << " | ";
            }
        }
		cout << endl;
        if (i+1 < TAM)
        {
                for (int cont = 0 ; cont < 34; cont++)//coloca las rayas que dividen las filas
                {
					cout << '-';
                }
        }
        cout << endl;
    } 
}
//------------------------------------------------------------------------------------------
void imprimirMuertas(char tabla[2][17])//imprime la matriz de fichas muertas
{
     HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
     
     SetConsoleTextAttribute (hConsoleHandle,14);
     cout<<"TABLA DE FICHAS ELIMINADAS DE C/A JUGADOR\n\n";                           
     SetConsoleTextAttribute (hConsoleHandle,7 );
        
     for(int i=0;i<2;i++)
     {
             for(int m=0;m<1;m++)//coloca color a la columna de los jugadores
             {                            
                     SetConsoleTextAttribute (hConsoleHandle,14);
                     cout<<tabla[i][m];                           
                     SetConsoleTextAttribute (hConsoleHandle,7 );
                                                     
                     if (m+1 < 2)//imprime la division
                     cout << "|";  
             }
             for(int j=1;j<17;j++)
             {
                     cout<<tabla[i][j];
                     cout<<" |";
             }
             cout<<endl;
             for (int cont = 0 ; cont < 50; cont++)//coloca las rayas que dividen las filas
             {
                     cout << '-';
             }
             cout<<endl;
     }
}
//------------------------------------------------------------------------------------------
char iniciarFichas(char matriz[2][17])//inicia la matriz de fichas eliminadas
{
     int a=49;
     for(int i=0;i<2;i++)
     {
             for(int g=0;g<1;g++)
             {
                     matriz[i][g]=a;
                     a++;
             }
             for(int j=1;j<17;j++)
             {
                     matriz[i][j]=' ';
             }
     }
}
//------------------------------------------------------------------------------------------
void eliminarArreglo(int**escalera,int numPosiciones)
{
     for(int i=0;i<numPosiciones;i++)
     {
             delete []escalera[i];
     }
     delete[]escalera;
}
//------------------------------------------------------------------------------------------
int cambio(char numero)//realiza el respectivo cambio de letra a numero
{
    int cambio;
    if(numero=='A')
       cambio=0;
    if(numero=='B')
       cambio=1;
    if(numero=='C')
       cambio=2;
    if(numero=='D')
       cambio=3;
    if(numero=='E')
       cambio=4;
    if(numero=='F')
       cambio=5;
    if(numero=='G')
       cambio=6;
    if(numero=='H')
       cambio=7;
    
    return cambio;
}
//------------------------------------------------------------------------------------------
char cambio2(int numero)//realiza el respectivo cambio de numero a letra
{
    char cambio;
    if(numero==0)
       cambio='A';
    if(numero==1)
       cambio='B';
    if(numero==2)
       cambio='C';
    if(numero==3)
       cambio='D';
    if(numero==4)
       cambio='E';
    if(numero==5)
       cambio='F';
    if(numero==6)
       cambio='G';
    if(numero==7)
       cambio='H';
    
    return cambio;
}
//------------------------------------------------------------------------------------------
char movimiento(char TABLA[TAM][TAM],int fila2,int col2,Jugada posicion)//Hace el cambio cuando la posicion indicada esta vacia
{                           
        int fila,col;
        
        fila=posicion.fila;
        col=posicion.columna; 
                            
        char valor;
           
        valor= TABLA[fila][col];
           
        if(TABLA[fila2][col2]==' ')
        {
                 TABLA[fila2][col2]=valor;
                 TABLA[fila][col]=' ';      
        }                           
}
//------------------------------------------------------------------------------------------
char movimientoMata(char tablero[TAM][TAM],Jugada posicion,Movidas jugada)//Esta funcion retorna las jugadas posibles para algunas fichas y ademas da la posibilidad de matar fichas contrarias 
{
     HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
     
     int col;
     int fila;
     int *recorrido1,*recorrido2;
     bool movimiento=0;
         
     col=posicion.columna;
     fila=posicion.fila;
     
     if(jugada.tipo=='T'||jugada.tipo=='A'||jugada.tipo=='D')//decide si las fichas se pueden mover
     {
              int avance;                    
              int limite,limite2;
              int cont=1;
              int cont2=1;
              bool impresion=0;
              
              avance=jugada.contador;
              for(int i=0;i<avance;i++)
              {
                      if(jugada.tipo=='T')//decide si la torre se puede mover
                      {
                              limite=jugada.fichas[0][i];
                              limite2=jugada.fichas2[0][i];
                      }
                      else if(jugada.tipo=='A')//decide si el alfil se puede mover
                      {
                              limite=jugada.fichas[1][i];
                              limite2=jugada.fichas2[1][i];
                      }
                      else if(jugada.tipo=='D')//decide si la reyna se puede mover
                      {
                              limite=jugada.fichas[2][i];
                              limite2=jugada.fichas2[2][i];
                      }      
                      if(tablero[limite][limite2]==' ')
                      {
                                 movimiento=1;
                                 if(movimiento==1)
                                 {
                                            if(impresion==0)
                                            {
                                                    SetConsoleTextAttribute (hConsoleHandle,14 );
                                                    cout<<"\nLa ficha que eligio se puede mover a:\n\n";
                                                    SetConsoleTextAttribute (hConsoleHandle,7 );    
                                                    impresion=1;
                                            }       
                                            cout<<cont<<". "<<(cambio2(limite))<<(limite2)<<endl; 
                                            cont++;               
                                 }
                      }
                      if(tablero[limite][limite2]!=' ')
                      { 
                                 if(posicion.jugador==1)
                                 {
                                         if(tablero[limite][limite2]!='P'&&tablero[limite][limite2]!='C'
                                         &&tablero[limite][limite2]!='D'&&tablero[limite][limite2]!='R'&&
                                         tablero[limite][limite2]!='A'&&tablero[limite][limite2]!='T') 
                                         {
                                                     if(impresion==1||impresion==0)
                                                     {
                                                            SetConsoleTextAttribute (hConsoleHandle,14 );
                                                            cout<<"\nPuede atacar en la posicion:\n\n";
                                                            SetConsoleTextAttribute (hConsoleHandle,7 );    
                                                            impresion=1;
                                                     } 
                                                     cout<<cont2<<". "<<(cambio2(jugada.fila[i]))<<(jugada.columna[i])<<endl; 
                                                     cont2++;                                                                                
                                         } 
                                 }
                                 else
                                 {
                                         if(tablero[limite][limite2]!='p'&&tablero[limite][limite2]!='c'
                                         &&tablero[limite][limite2]!='a'||tablero[limite][limite2]!='r'&&
                                         tablero[limite][limite2]!='d'&&tablero[limite][limite2]!='t')  
                                         {
                                                     if(impresion==1||impresion==0)
                                                     {
                                                            SetConsoleTextAttribute (hConsoleHandle,14 );
                                                            cout<<"\nPuede atacar en la posicion:\n\n";
                                                            SetConsoleTextAttribute (hConsoleHandle,7 );    
                                                            impresion=0;
                                                     } 
                                                     cout<<cont2<<". "<<(cambio2(jugada.fila[i]))<<(jugada.columna[i])<<endl; 
                                                     cont2++;                                                                                
                                         } 
                                 }
                      }
                      
              } 
     }     
     else//aqui van todas las entradas diferentes de los mencionados anteriormente(caballo,peon,rey)
     {
                int paso,paso2;
                paso=jugada.contador;
                paso2=paso;
                
                if(paso==paso2)
                {
                          int cont=1;
                          int cont2=1;
                          int movida;
                          int movida2;
                          bool impresion=0;
                          
                          
                          
                          for(int i=0;i<paso;i++)
                          {
                                   movida=jugada.fila[i];
                                   movida2=jugada.columna[i];
                                   if(tablero[movida][movida2]==' ')
                                   {
                                           movimiento=1;
                                           if(movimiento==1)
                                           {
                                                     if(impresion==0)
                                                     {
                                                           SetConsoleTextAttribute (hConsoleHandle,14 );
                                                           cout<<"\nLa ficha que eligio se puede mover a:\n\n";
                                                           SetConsoleTextAttribute (hConsoleHandle,7 );    
                                                           impresion=1;
                                                     }       
                                                     cout<<cont<<". "<<(cambio2(jugada.fila[i]))<<(jugada.columna[i])<<endl; 
                                                     cont++;               
                                           }
                                   }
                                   if(tablero[jugada.fila[i]][jugada.columna[i]]!=' ')
                                   { 
                                            if(posicion.jugador==1)
                                            {
                                                      if(tablero[movida][movida2]!='P'&&tablero[movida][movida2]!='c'
                                                      &&tablero[movida][movida2]!='A'&&tablero[movida][movida2]!='R'&&
                                                      tablero[movida][movida2]!='D'&&tablero[movida][movida2]!='T') 
                                                      {
                                                             if(impresion==1||impresion==0)
                                                             {
                                                                     SetConsoleTextAttribute (hConsoleHandle,14 );
                                                                     cout<<"\nPuede atacar en la posicion:\n\n";
                                                                     SetConsoleTextAttribute (hConsoleHandle,7 );    
                                                                     impresion=0;
                                                             } 
                                                             cout<<cont2<<". "<<(cambio2(jugada.fila[i]))<<(jugada.columna[i])<<endl; 
                                                             cont2++;                                                                                
                                                      } 
                                            }
                                            else
                                            {
                                                      if(tablero[movida][movida2]!='p'&&tablero[movida][movida2]!='c'
                                                      &&tablero[movida][movida2]!='a'&&tablero[movida][movida2]!='r'&&
                                                      tablero[movida][movida2]!='d'&&tablero[movida][movida2]!='t') 
                                                      {
                                                             if(impresion==1||impresion==0)
                                                             {
                                                                     SetConsoleTextAttribute (hConsoleHandle,14 );
                                                                     cout<<"\nPuede atacar en la posicion:\n\n";
                                                                     SetConsoleTextAttribute (hConsoleHandle,7 );    
                                                                     impresion=0;
                                                             } 
                                                             cout<<cont2<<". "<<(cambio2(jugada.fila[i]))<<(jugada.columna[i])<<endl; 
                                                             cont2++;                                                                                
                                                      } 
                                            }
                                              
                                   }
                          }
                          cout<<endl;     
                }
     }
}
//------------------------------------------------------------------------------------------



