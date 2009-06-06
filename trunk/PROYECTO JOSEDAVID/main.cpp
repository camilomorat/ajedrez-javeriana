/*
  Name: MAIN DEL AJEDREZ
  Copyright: JOSE DAVID RENGIFO FUENTES /2009
  Author: JOSE DAVID RENGIFO FUENTES
  Date: 01/06/09 18:45
*/
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "header.h"

using namespace std;

int main(int argc, char *argv[])
{
    HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
    
    Jugada ajedrez;
    Movidas ajedrez2;  
    int opcion;
    int a=1,b=0,c=0,d=1;
       
    char TABLERO[TAM][TAM]={
	{'A','T','C','A','D','R','A','C','T'},
	{'B','P','P','P','P','P','P','P','P'},
	{'C',' ',' ',' ',' ',' ',' ',' ',' '},
	{'D',' ',' ',' ',' ',' ',' ',' ',' '},
	{'E',' ',' ',' ',' ',' ',' ',' ',' '},
	{'F',' ',' ',' ',' ',' ',' ',' ',' '},
	{'G','p','p','p','p','p','p','p','p'},
	{'H','t','c','a','d','r','a','c','t'},
	{'*','1','2','3','4','5','6','7','8'}};
	
	
    cout<<"*************************************************\n";
    cout<<"**                  AJEDREZ                    **\n";
    cout<<"*************************************************\n";
    cout<<endl<<endl;
        
    cout<<"Por favor escoja una de las siguientes opciones:\n";
    cout<<"\n1. Instrucciones y modo de juego\n";
    cout<<"\n2. Jugar Ahora!!!!\n";
    cout<<"\n3. Oprima 3 para salir del juego\n";    
    cout<<endl;
    cin>>opcion;  
    
    switch(opcion)
    {
         case 1:
         {
              cout<<"--*MODO DE JUEGO*--"<<endl<<endl;
              cout<<"Es el mismo esquema de un ajedrez tradicional, consta de 2 jugadores,\n";
              cout<<"uno contra el otro. Para mover una ficha se debe seleccionar la posicion\n";
              cout<<"en la que esta ejem: H6, donde posteriormente se despliega unas opciiones,\n";
              cout<<"con movimientos posibles, enumerados del 1-20.\n"<<endl;
              cout<<"Para terminar el juego se digita FIN.\n";
              cout<<endl<<endl;
              cout<<"Por favor escoja una de las siguientes opciones:\n";
              cin>>opcion;
         }
            
         case 2:        
         {       
              int nturno=0;
              int ficha;
              iniciarFichas(ajedrez.fichasMuertas);
              
              char jugada[3];
              char mov,mov2;
              int fila2;
              int col,col2;
              int ncolumna;
         
              ajedrez.jugador=1;
              imprimirTablero(TABLERO);
              
              SetConsoleTextAttribute (hConsoleHandle,7 );
              cout<<"RECUERDE COLOCAR LAS LETRAS EN MAYUSCULAS Y SIN ESPACIOS\n";
              cout<<endl;
              SetConsoleTextAttribute (hConsoleHandle,6);
              cout<<"JUGADOR 1: (FICHAS EN MAYUSCULAS)\n";
              cout<<"JUGADOR 2: (FICHAS EN MINUSCULAS)\n";
              SetConsoleTextAttribute (hConsoleHandle,7);
              cout<<endl;
                     
              while(ajedrez.jugador!=0)
              {
                      if(ajedrez.jugador%2!=0)
                      {      
                              SetConsoleTextAttribute (hConsoleHandle,14 );
                              cout<<"Jugador 1:\n";
                              SetConsoleTextAttribute (hConsoleHandle,7 );
                                                                       
                              cout<<"Digite la ubicacion de la ficha: \n";
                              cin>>ajedrez.ficha;
                              cout<<endl;
                                                                                            
                              if((ajedrez.ficha[0]=='F')&&(ajedrez.ficha[1]=='I')&&(ajedrez.ficha[2]=='N'))
                              break;
                                                                  
                              mov=ajedrez.ficha[0];
                              ajedrez.fila=cambio(mov);
                              col=(ajedrez.ficha[1]-'0');
                              ajedrez.columna=col;
                              ncolumna=(col-1);     
                              
                              if(nturno<1)//Restringuie la seleccion de la ficha por si el jugador no selecciona sus fichas
                              {
                                     while(TABLERO[ajedrez.fila][ncolumna]=='G'||TABLERO[ajedrez.fila][ncolumna]=='H')
                                     {
                                                     SetConsoleTextAttribute (hConsoleHandle,12 );
                                                     cout<<"POSICION INVALIDA, DIGITE OTRAVEZ LA POSICION DE LA FICHA";
                                                     cout<<endl<<endl;
                                                     SetConsoleTextAttribute (hConsoleHandle,7 );
                                          
                                                     cout<<"Digite la ubicacion de la ficha: \n";
                                                     cin>>ajedrez.ficha;
                                                     cout<<endl;
                                 
                                                     mov=ajedrez.ficha[0];
                                                     ajedrez.fila=cambio(mov);
                                                     col=(ajedrez.ficha[1]-'0');
                                                     ajedrez.columna=col;
                                                     ncolumna=(col-1);                                                                                    
                                     } 
                              }
                              
                              while(TABLERO[ajedrez.fila][ajedrez.columna]==' ')//Restringue cuando un jugador selecciona un espacio vacio
                              {
                                     SetConsoleTextAttribute (hConsoleHandle,12 );
                                     cout<<"POSICION VACIA, DIGITE OTRAVEZ LA POSICION DE LA FICHA";
                                     cout<<endl<<endl;
                                     SetConsoleTextAttribute (hConsoleHandle,7 );
                                          
                                     cout<<"Digite la ubicacion de la ficha: \n";
                                     cin>>ajedrez.ficha;
                                     cout<<endl;
                                 
                                     mov=ajedrez.ficha[0];
                                     ajedrez.fila=cambio(mov);
                                     col=(ajedrez.ficha[1]-'0');
                                     ajedrez.columna=col;
                                     ncolumna=(col-1);                                       
                              }
                              
                                                                                                                                 
                              ajedrez.partida=0;  
                              
                              if(b>0)
                              {
                                        ajedrez.partida=1;
                                        b++;
                              }
                              b++;
                              
                              ajedrez2.alfil=0; 
                              ajedrez2.reyna=0;  
                              ajedrez2.torre=0;
                              
                              if(c>0)
                              {
                                        ajedrez2.alfil=1; 
                                        ajedrez2.reyna=1;  
                                        ajedrez2.torre=1;
                                        c++;
                              }
                              c++;      
                                                            
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='P')
                              {
                                     peon(TABLERO,ajedrez,ajedrez2);
                              }
                              
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='C')
                              {
                                     caballo(TABLERO,ajedrez,ajedrez2);
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='R')
                              {
                                     rey(TABLERO,ajedrez,ajedrez2);
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='T')
                              {
                                     torre(TABLERO,ajedrez,ajedrez2); 
                                     ajedrez2.torre++;
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='A')
                              {
                                     alfil(TABLERO,ajedrez,ajedrez2);
                                     ajedrez2.alfil++; 
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='D')
                              {
                                     reyna(TABLERO,ajedrez,ajedrez2);
                                     ajedrez2.reyna++;
                              }
                                 
                              cout<<"Digite la jugada: \n";                  
                              cin>>jugada;
                              cout<<endl;
                                
                              mov2=jugada[0];
                              fila2=cambio(mov2);
                              col2=(jugada[1]-'0');
                              ajedrez.jugador++;
                              
                              if(TABLERO[fila2][col2]!=' ')
                              {
                                        ficha=TABLERO[fila2][col2];
                                        TABLERO[fila2][col2]=TABLERO[ajedrez.fila][ajedrez.columna];
                                        TABLERO[ajedrez.fila][ajedrez.columna]=' ';
                                        ajedrez.fichasMuertas[1][a]=ficha;
                                        a++;
                              }
                              if(TABLERO[fila2][col2]==' ')
                              {
                                        movimiento(TABLERO,fila2,col2,ajedrez);
                              }
                              
                              imprimirTablero(TABLERO);
                              imprimirMuertas(ajedrez.fichasMuertas);
                          }
                      else
                      {
                              SetConsoleTextAttribute (hConsoleHandle,14 );
                              cout<<"Jugador 2:\n";
                              SetConsoleTextAttribute (hConsoleHandle,7 );
                                                                       
                              cout<<"Digite la ubicacion de la ficha: \n";
                              cin>>ajedrez.ficha;
                              cout<<endl;
                                 
                              if((ajedrez.ficha[0]=='F')&&(ajedrez.ficha[1]=='I')&&(ajedrez.ficha[2]=='N'))
                              break;
                                 
                              mov=ajedrez.ficha[0];
                              ajedrez.fila=cambio(mov);
                              col=(ajedrez.ficha[1]-'0');
                              ajedrez.columna=col;
                              ncolumna=(col-1);
                                                                   
                              if(nturno<1)//Restringuie la seleccion de la ficha por si el jugador no selecciona sus fichas
                              {
                                     while(TABLERO[ajedrez.fila][ncolumna]=='A'||TABLERO[ajedrez.fila][ncolumna]=='B')
                                     {
                                                     SetConsoleTextAttribute (hConsoleHandle,12 );
                                                     cout<<"POSICION INVALIDA, DIGITE OTRAVEZ LA POSICION DE LA FICHA";
                                                     cout<<endl<<endl;
                                                     SetConsoleTextAttribute (hConsoleHandle,7 );
                                          
                                                     cout<<"Digite la ubicacion de la ficha: \n";
                                                     cin>>ajedrez.ficha;
                                                     cout<<endl;
                                 
                                                     mov=ajedrez.ficha[0];
                                                     ajedrez.fila=cambio(mov);
                                                     col=(ajedrez.ficha[1]-'0');
                                                     ajedrez.columna=col;
                                                     ncolumna=(col-1);                                                                                    
                                     } 
                              }
                              
                              while(TABLERO[ajedrez.fila][ajedrez.columna]==' ')
                              {
                                     SetConsoleTextAttribute (hConsoleHandle,12 );
                                     cout<<"POSICION VACIA, DIGITE OTRAVEZ LA POSICION DE LA FICHA";
                                     cout<<endl<<endl;
                                     SetConsoleTextAttribute (hConsoleHandle,7 );
                                          
                                     cout<<"Digite la ubicacion de la ficha: \n";
                                     cin>>ajedrez.ficha;
                                     cout<<endl;
                                 
                                     mov=ajedrez.ficha[0];
                                     ajedrez.fila=cambio(mov);
                                     col=(ajedrez.ficha[1]-'0');
                                     ajedrez.columna=col;
                                     ncolumna=(col-1);                                       
                              }
                              
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='r')
                              {
                                     rey(TABLERO,ajedrez,ajedrez2);
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='p')
                              {
                                     peon(TABLERO,ajedrez,ajedrez2);
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='c')
                              {
                                     caballo(TABLERO,ajedrez,ajedrez2);
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='t')
                              {
                                     torre(TABLERO,ajedrez,ajedrez2);
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='a')
                              {
                                     alfil(TABLERO,ajedrez,ajedrez2);
                              }
                              if(TABLERO[ajedrez.fila][ajedrez.columna]=='d')
                              {
                                     reyna(TABLERO,ajedrez,ajedrez2);
                              }   
                             
                              cout<<"Digite la jugada: \n";                  
                              cin>>jugada;
                              cout<<endl;
                                                                  
                              mov2=jugada[0];
                              fila2=cambio(mov2);
                              col2=(jugada[1]-'0');
                              
                              if(TABLERO[fila2][col2]!=' ')
                              {
                                        ficha=TABLERO[fila2][col2];
                                        TABLERO[fila2][col2]=TABLERO[ajedrez.fila][ajedrez.columna];
                                        TABLERO[ajedrez.fila][ajedrez.columna]=' ';
                                        ajedrez.fichasMuertas[0][d]=ficha;
                                        d++;
                              }
                              if(TABLERO[fila2][col2]==' ')
                              {
                                        movimiento(TABLERO,fila2,col2,ajedrez);
                              }
                                           
                              imprimirMuertas(ajedrez.fichasMuertas);
                              imprimirTablero(TABLERO);
                              
                              ajedrez.jugador=1;
                              nturno++;                                                          
                          }      
                     }  
         }
         
         case 3:
         {
              cout<<endl;
              cout<<"FIN DEL JUEGO\n";
              cout<<endl;
              break;
         }          
    }
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
