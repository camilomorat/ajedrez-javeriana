/*
  Name: FICHAS DEL AJEDREZ(MOVIMIENTO)
  Copyright: JOSE DAVID RENGIFO FUENTES /2009
  Author: JOSE DAVID RENGIFO FUENTES
  Date: 01/06/09 18:48
*/

#include <iostream>
#include "header.h"

using namespace std;

//------------------------------------------------------------------------------------------
char peon(char tablero[TAM][TAM],Jugada posicion,Movidas jugada)
{
    int a,b,turno;
    int aux=0;  
    
    turno=posicion.jugador;    
    a=posicion.fila;
    b=posicion.columna;
    
    if(turno==1)
    { 
        if(posicion.partida==0)
        {
                if(tablero[(a+2)][b]==' ')//movimiento doble del peon hacia adelante
                {       
                        jugada.fila[aux]=(a+2);
                        jugada.columna[aux]=b;
                        aux++;
                }                
        } 
        
        if(tablero[(a+1)][b]==' ')//movimiento del peon hacia adelante
        {     
                jugada.fila[aux]=(a+1);
                jugada.columna[aux]=b;
                aux++;
        }
        
        if(tablero[(a+1)][(b+1)]!=' ')//ataque diagonal derecha
        {
                if(b!=8)  
                { 
                        jugada.fila[aux]=(a+1);
                        jugada.columna[aux]=(b+1);
                        aux++;
                }               
        }
        
        if(tablero[(a+1)][(b-1)]!=' ')//ataque diagonal izquierda
        {
                 if(b!=1)
                 {
                        jugada.fila[aux]=(a+1);
                        jugada.columna[aux]=(b-1);
                        aux++;
                 }
        } 
        jugada.contador=aux;
        movimientoMata(tablero,posicion,jugada);        
    }
    else
    {
        aux=0;
        
        if(posicion.partida==0)
        {
                if(tablero[(a-2)][b]==' ')//movimiento doble del peon hacia adelante
                {       
                        jugada.fila[aux]=(a-2);
                        jugada.columna[aux]=b;
                        aux++;                        
                } 
        }
        
        if(tablero[(a-1)][b]==' ')//movimiento del peon hacia adelante
        {        
                 jugada.fila[aux]=(a-1);
                 jugada.columna[aux]=b;
                 aux++;
        }
        
        if(tablero[(a-1)][(b+1)]!=' ')//ataque diagonal derecha
        {
                  jugada.fila[aux]=(a-1);
                  jugada.columna[aux]=(b+1);
                  aux++;
        }
        
        if(tablero[(a-1)][(b-1)]!=' ')//ataque diagonal izquierda
        {
                if(b!=1)
                {
                        jugada.fila[aux]=(a-1);
                        jugada.columna[aux]=(b-1);
                        aux++;
                }  
        }
        jugada.contador=aux;
        movimientoMata(tablero,posicion,jugada); 
    }
}
//------------------------------------------------------------------------------------------
char caballo(char tablero[TAM][TAM],Jugada posicion,Movidas jugada)
{
     int a,b;
     int aux=0; 
     
     a=posicion.fila;
     b=posicion.columna;
                   
     if(tablero[(a-2)][(b-1)]==' '||tablero[(a-2)][(b-1)]!=' ')
     {
                if(0<a)
                {
                       if(b>1)
                       {
                              jugada.fila[aux]=(a-2);
                              jugada.columna[aux]=(b-1);
                              aux++;
                              //cout<<cambio2((a-2))<<(b-1)<<endl;
                       }
                }
     }
      
     if(tablero[(a-2)][(b+1)]==' '||tablero[(a-2)][(b+1)]!=' ')
     {
                if(0<a)
                {       if(b<=7)
                        {
                                jugada.fila[aux]=(a-2);
                                jugada.columna[aux]=(b+1);
                                aux++;
                                //cout<<cambio2((a-2))<<(b+1)<<endl;
                        } 
                }
     }
     
     if(tablero[(a-1)][(b-2)]==' '||tablero[(a-1)][(b-2)]!=' ')
     {
                if(0<a)
                {       if(a<=7)
                        {
                               if(b>2)
                               {
                                      jugada.fila[aux]=(a-1);
                                      jugada.columna[aux]=(b-2);
                                      aux++;
                                      //cout<<cambio2((a-1))<<(b-2)<<endl;
                               } 
                        } 
                }
     }
     
     if(tablero[(a-1)][(b+2)]==' '||tablero[(a-1)][(b+2)]!=' ')
     {
                if(0<a)
                {       if(b<7)
                        {
                               jugada.fila[aux]=(a-1);
                               jugada.columna[aux]=(b+2);
                               aux++;
                               //cout<<cambio2((a-1))<<(b+2)<<endl;
                        } 
                } 
     }
    
     if(tablero[(a+1)][(b-2)]==' '||tablero[(a+1)][(b-2)]!=' ')
     {
                if(b>2)
                {
                       if(a<7)
                       {
                              jugada.fila[aux]=(a+1);
                              jugada.columna[aux]=(b-2);
                              aux++;
                              //cout<<cambio2((a+1))<<(b-2)<<endl;
                       }
                }
     }
      
     if(tablero[(a+1)][(b+2)]==' '||tablero[(a+1)][(b+2)]!=' ')
     {
                if(a<7)
                {
                        if(b<7)
                        {
                               jugada.fila[aux]=(a+1);
                               jugada.columna[aux]=(b+2);
                               aux++;
                               //cout<<cambio2((a+1))<<(b+2)<<endl;
                        }
                }
     }
    
     if(tablero[(a+2)][(b-1)]==' '||tablero[(a+2)][(b-1)]!=' ')
     {
                if(a<7)
                {
                       jugada.fila[aux]=(a+2);
                       jugada.columna[aux]=(b-1);
                       aux++;
                       //cout<<cambio2((a+2))<<(b-1)<<endl;
                } 
     }
    
     if(tablero[(a+2)][(b+1)]==' '||tablero[(a+2)][(b+1)]!=' ')
     {
                if(a<7)
                {
                       jugada.fila[aux]=(a+2);
                       jugada.columna[aux]=(b+1);
                       aux++;
                       //cout<<cambio2((a+2))<<(b+1)<<endl; 
                } 
     }
     jugada.contador=aux;
     movimientoMata(tablero,posicion,jugada); 
}
//------------------------------------------------------------------------------------------
char rey(char tablero[TAM][TAM],Jugada posicion,Movidas jugada)
{
    int a,b,turno;
    int aux=0; 
    
    turno=posicion.jugador;
    a=posicion.fila;
    b=posicion.columna; 
    
    if(turno==1)
    { 
        if(tablero[(a+1)][b]==' ')//movimiento del rey hacia adelante
        {
                 jugada.fila[aux]=(a+1);
                 jugada.columna[aux]=b;
                 aux++;
                 //cout<<cambio2((a+1))<<b<<endl;                        
        }
        
        if(tablero[(a-1)][b]==' ')//movimiento del rey hacia atras
        {
                 if(a!=0)
                 {
                         jugada.fila[aux]=(a-1);
                         jugada.columna[aux]=b;
                         aux++;
                         //cout<<cambio2((a-1))<<b<<endl;
                 }
        }
        if(tablero[(a+1)][(b+1)]==' ')//movimiento diagonal derecha
        {
                 if(b<8) 
                 {
                         jugada.fila[aux]=(a+1);
                         jugada.columna[aux]=(b+1);
                         aux++;
                         //cout<<cambio2((a+1))<<(b+1)<<endl;
                 }   
        }
        if(tablero[(a+1)][(b-1)]==' ')//movimiento diagonal izquierda
        {
                 if(b>1)
                 {
                        jugada.fila[aux]=(a+1);
                        jugada.columna[aux]=(b-1);
                        aux++;
                        //cout<<cambio2((a+1))<<(b-1)<<endl;
                 } 
        }
        jugada.contador=aux;
        movimientoMata(tablero,posicion,jugada); 
    }
    else
    {
        aux=0;
        if(tablero[(a-1)][b]==' ')//movimiento del rey hacia adelante
        { 
                 jugada.fila[aux]=(a-1);
                 jugada.columna[aux]=b;
                 aux++;
                 //cout<<cambio2((a-1))<<b<<endl;                              
        }
        if(tablero[(a+1)][b]==' ')//movimiento del rey hacia atras
        {
                 if(a!=7)
                 {
                         jugada.fila[aux]=(a+1);
                         jugada.columna[aux]=b;
                         aux++;
                         //cout<<cambio2((a+1))<<b<<endl;
                 }
        }
        if(tablero[(a-1)][(b-1)]==' ')//movimiento diagonal izquierda
        {
                 if(b>1)
                 {
                        jugada.fila[aux]=(a-1);
                        jugada.columna[aux]=(b-1);
                        aux++;
                        //cout<<cambio2((a-1))<<(b-1)<<endl;
                 }  
        }
        if(tablero[(a-1)][(b+1)]==' ')//movimiento diagonal derecha
        {
                 if(b<8)
                 {
                        jugada.fila[aux]=(a-1);
                        jugada.columna[aux]=(b+1);
                        aux++;
                        //cout<<cambio2((a-1))<<(b+1)<<endl;
                 }
        }
        jugada.contador=aux;
        movimientoMata(tablero,posicion,jugada); 
    }
}
//------------------------------------------------------------------------------------------
char torre(char tablero[TAM][TAM],Jugada posicion,Movidas jugada)
{
     int a,b;
     
     a=posicion.fila;
     b=posicion.columna;
     jugada.tipo='T';
     
     if(jugada.torre==0)
     {
                jugada.fichas[0]= new int [16];
                jugada.fichas2[0]= new int [16];
     }
    
     int aux=a;
     int aux2=b;
     int cont=0;
     int filas;
     int columnas;
     
     while((7-a)!=0)//movimiento hacia abajo
     {         
                  filas=a+1;
                  columnas=b;
                  jugada.fichas[0][a]=filas;
                  jugada.fichas2[0][a]=columnas;
                  a++;
                  //cout<<cambio2((a+1))<<b<<endl;
     }
     cont=a;
     a=aux;
     cont+=a;
     
     /*while((a-0)!=0)//movimiento hacia arriba
     {
                   filas=a+1;
                   columnas=b;
                   jugada.fichas[0][cont]=filas;
                   jugada.fichas2[0][cont]=columnas; 
                   cont++;
                   a--;
                   //cout<<cambio2((a-1))<<b<<endl;
     }
    
     while((8-b)!=0)//movimiento hacia la derecha
     {
                   filas=aux;
                   columnas=b+1;
                   jugada.fichas[0][cont]=filas;
                   jugada.fichas2[0][cont]=columnas;
                   cont++;      
                   b++;
                   //cout<<cambio2(aux)<<(b+1)<<endl;
     }*/
     b=aux2;
     while((b-1)!=0)//movimiento hacia la izquierda
     {
                   filas=aux;
                   columnas=b-1;
                   jugada.fichas[0][cont]=filas;
                   jugada.fichas2[0][cont]=columnas; 
                   cont++;            
                   b--;
                   //cout<<cambio2(aux)<<(b-1)<<endl;
     }
     jugada.contador=cont;
     //movimientoMata(tablero,posicion,jugada); 
     
}
//------------------------------------------------------------------------------------------
char alfil(char tablero[TAM][TAM],Jugada posicion,Movidas jugada)
{
    int a,b;
     
    a=posicion.fila;
    b=posicion.columna;
    
    if(jugada.alfil==0)
    {
               jugada.fichas[1]= new int [16];
               jugada.fichas2[1]= new int [16];
    }
    
    jugada.tipo='A';
     
    int aux=a;
    int aux2=b;
    
    int cont=0,cont2=1;
     
    int filas;
    int columnas;
    
    cont=0;
   
    if(a<5)
    {
           while((8-b)!=0)//movimiento diagonal derecha hacia abajo
           {
                   filas=(a+1);
                   columnas=(b+1);
                   jugada.fichas[1][cont]=filas;
                   jugada.fichas2[1][cont]=columnas;
                   a++;            
                   b++;
                   cont++;
                   //cout<<cambio2(a+1)<<(b+1)<<endl; 
           }
           
    }
    a=aux;
    b=aux2;
   
    if(a>=5)
    {
            if(a!=7)
            {
                    while((7-a)!=0)//movimiento diagonal derecha hacia abajo
                    {
                                    filas=(a+1);
                                    columnas=(b+1);
                                    jugada.fichas[1][cont]=filas;
                                    jugada.fichas2[1][cont]=columnas;            
                                    a++;
                                    b++;
                                    cont++;
                                    //cout<<cambio2(a+1)<<(b+1)<<endl;
                    }
                    
            }            
    } 
    a=aux;
    b=aux2;
    
    if(a>=3)
    {
            if(a!=7)
            {
                    while((7-a)!=0)//movimiento diagonal izquierda hacia abajo
                    {
                               filas=(a+1);
                               columnas=(b-1);
                               jugada.fichas[1][cont]=filas;
                               jugada.fichas2[1][cont]=columnas;
                               a++;
                               b--;
                               cont++; 
                               //cout<<cambio2(a+1)<<(b-1)<<endl;
                    } 
                                      
            }            
    }
    a=aux;
    b=aux2;
    
    if(a<3)
    {
           while(((b-1)-0)!=0)//movimiento diagonal izquierda hacia abajo
           {
                   filas=(a+1);
                   columnas=(b-1);
                   jugada.fichas[1][cont]=filas;
                   jugada.fichas2[1][cont]=columnas;                   
                   b--;
                   a++;
                   cont++;
                   //cout<<cambio2((a+1))<<(b-1)<<endl;
           }
           
    }
    a=aux;
    b=aux2;
    
    if(b>=5)
    {
            while((a-0)!=0)//movimiento diagonal izquierda hacia arriba
            {  
                   filas=(a-1);
                   columnas=(b-1);
                   jugada.fichas[1][cont]=filas;
                   jugada.fichas2[1][cont]=columnas;  
                   a--;
                   b--;
                   cont++;
                   //cout<<cambio2((a-1))<<(b-1)<<endl;            
            }
    }
    a=aux;
    b=aux2;
       
    /*if(b<5)
    {
           if(a!=0)
           {
                   while(((b-1)-0)!=0)//movimiento diagonal izquierda hacia arriba
                   {
                                 filas=a-1;
                                 columnas=b-1;
                                 
                                 jugada.fichas[1][b]=filas;
                                 jugada.fichas2[1][b]=columnas;
                                 
                                 cout<<cambio2((a-1))<<(b-1)<<endl;
                                 b--;
                                 a--;
                                 
                                cont++;
                                 
                   }
                   //cont+=(b+1);
                   cout<<a<<b<<endl;
                   
           }           
    }*/
    a=aux;
    b=aux2;
    
    /*if(a>5)
    {
           if(a!=0)
           {
                   while((8-b)!=0)//movimiento diagonal derecha hacia arriba
                   {
                              filas=(a-1);
                              columnas=(b+1);
                              jugada.fichas[1][cont]=filas;
                              jugada.fichas2[1][cont]=columnas;
                              a--;            
                              b++;
                              cont++;
                              //cout<<cambio2(a-1)<<(b+1)<<endl; 
                   }
           }
    }*/
    
    a=aux;
    b=aux2;
    
    if(a<=5)
    {
            if(a!=0)
            {
                    while(((a-1)-0)!=0)//movimiento diagonal derecha hacia arriba
                    {            
                                 filas=(a-1);
                                 columnas=(b+1);
                                 jugada.fichas[1][cont]=filas;
                                 jugada.fichas2[1][cont]=columnas;
                                 cout<<cambio2((a-1))<<(b+1)<<endl; 
                                 a--;
                                 b++; 
                                 cont++;
                                           
                    }
            }            
    }
    jugada.contador=cont;
    //movimientoMata(tablero,posicion,jugada); 
}
//------------------------------------------------------------------------------------------
char reyna(char tablero[TAM][TAM],Jugada posicion,Movidas jugada)
{
    int a,b;
     
    a=posicion.fila;
    b=posicion.columna;
     
    int aux=a;
    int aux2=b;
    
    while((7-a)!=0)//movimiento hacia abajo
    {
                   cout<<cambio2((a+1))<<b<<endl;
                   a++;
    }
    
    a=aux;
    while((a-0)!=0)//movimiento hacia arriba
    {
                   cout<<cambio2((a-1))<<b<<endl;
                   a--;
    } 
    
    while((8-b)!=0)//movimiento hacia la derecha
    {
                   cout<<cambio2(aux)<<(b+1)<<endl;             
                   b++;
    }
    
    b=aux2;
    while((b-1)!=0)//movimiento hacia la izquierda
    {
                   cout<<cambio2(aux)<<(b-1)<<endl;              
                   b--;
    }
    
    if(a<5)
    {
           while((8-b)!=0)//movimiento diagonal derecha hacia abajo
           {
                   cout<<cambio2(a+1)<<(b+1)<<endl; 
                   a++;            
                   b++;
           }
    }
    a=aux;
    b=aux2;
    
    if(a>=5)
    {
            if(a!=7)
            {
                    while((7-a)!=0)//movimiento diagonal derecha hacia abajo
                    {
                                    cout<<cambio2(a+1)<<(b+1)<<endl;
                                    a++;
                                    b++;
                    }
            }            
    }
    a=aux;
    b=aux2;
    
    if(a>=3)
    {
            if(a!=7)
            {
                    while((7-a)!=0)//movimiento diagonal izquierda hacia abajo
                    {
                               cout<<cambio2(a+1)<<(b-1)<<endl;
                               a++;
                               b--;
                    }                    
            }            
    }
    a=aux;
    b=aux2;
    
    if(a<3)
    {
           while(((b-1)-0)!=0)//movimiento diagonal izquierda hacia abajo
           {
                   cout<<cambio2((a+1))<<(b-1)<<endl;
                   b--;
                   a++;
           }
    }
    a=aux;
    b=aux2;
    
    if(b>=5)
    {
            while((a-0)!=0)//movimiento diagonal izquierda hacia arriba
            {                               
                   cout<<cambio2((a-1))<<(b-1)<<endl;
                   a--;
                   b--;            
            }
    }
    a=aux;
    b=aux2;
    
    if(b<5)
    {
           if(a!=0)
           {
                   while(((b-1)-0)!=0)//movimiento diagonal izquierda hacia arriba
                   {
                                 cout<<cambio2((a-1))<<(b-1)<<endl;
                                 b--;
                                 a--;
                   }
           }           
    }
    a=aux;
    b=aux2;
    
    if(a>5)
    {
           if(a!=0)
           {
                   while((8-b)!=0)//movimiento diagonal derecha hacia arriba
                   {
                              cout<<cambio2(a-1)<<(b+1)<<endl; 
                              a--;            
                              b++;
                   }
           }
    }
    
    a=aux;
    b=aux2;
    
    if(a<=5)
    {
            if(a!=0)
            {
                    while(((a-1)-0)!=0)//movimiento diagonal derecha hacia arriba
                    {                               
                                 cout<<cambio2((a-1))<<(b+1)<<endl;
                                 a--;
                                 b++;            
                    }
            }            
    }
}
//------------------------------------------------------------------------------------------
/*PROTOTIPO QUE FUNCIONA
char torre(char tablero[TAM][TAM],Jugada posicion)
{
     int a,b;
     
     a=posicion.fila;
     b=posicion.columna;
     
     int aux=a;
     int aux2=b;
     
     int cont=0;
         
    
     while((a-0)!=0)//movimiento hacia arriba
     {
                   cout<<cambio2((a-1))<<b<<endl;
                   a--;
     } 
     
     a=aux;
     while((7-a)!=0)//movimiento hacia abajo
     {
                   cout<<cambio2(a+1)<<b<<endl;
                   a++;
     }
         
     while((8-b)!=0)//movimiento hacia la derecha
     {
                   cout<<cambio2(aux)<<(b+1)<<endl;             
                   b++;
     }
     b=aux2;
     while((b-1)!=0)//movimiento hacia la izquierda
     {
                   cout<<cambio2(aux)<<(b-1)<<endl;              
                   b--;
     }
     
}

char alfil(char tablero[TAM][TAM],Jugada posicion)
{
    int a,b;
     
    a=posicion.fila;
    b=posicion.columna;
     
    int aux=a;
    int aux2=b;
    
    if(a<5)
    {
           while((8-b)!=0)//movimiento diagonal derecha hacia abajo
           {
                   cout<<cambio2(a+1)<<(b+1)<<endl; 
                   a++;            
                   b++;
           }
    }
    a=aux;
    b=aux2;
    
    if(a>=5)
    {
            if(a!=7)
            {
                    while((7-a)!=0)//movimiento diagonal derecha hacia abajo
                    {
                                    cout<<cambio2(a+1)<<(b+1)<<endl;
                                    a++;
                                    b++;
                    }
            }            
    }
    a=aux;
    b=aux2;
    
    if(a>=3)
    {
            if(a!=7)
            {
                    while((7-a)!=0)//movimiento diagonal izquierda hacia abajo
                    {
                               cout<<cambio2(a+1)<<(b-1)<<endl;
                               a++;
                               b--;
                    }                    
            }            
    }
    a=aux;
    b=aux2;
    
    if(a<3)
    {
           while(((b-1)-0)!=0)//movimiento diagonal izquierda hacia abajo
           {
                   cout<<cambio2((a+1))<<(b-1)<<endl;
                   b--;
                   a++;
           }
    }
    a=aux;
    b=aux2;
    
    if(b>=5)
    {
            while((a-0)!=0)//movimiento diagonal izquierda hacia arriba
            {                               
                   cout<<cambio2((a-1))<<(b-1)<<endl;
                   a--;
                   b--;            
            }
    }
    a=aux;
    b=aux2;
    
    if(b<5)
    {
           if(a!=0)
           {
                   while(((b-1)-0)!=0)//movimiento diagonal izquierda hacia arriba
                   {
                                 cout<<cambio2((a-1))<<(b-1)<<endl;
                                 b--;
                                 a--;
                   }
           }           
    }
    a=aux;
    b=aux2;
    
    if(a>5)
    {
           if(a!=0)
           {
                   while((8-b)!=0)//movimiento diagonal derecha hacia arriba
                   {
                              cout<<cambio2(a-1)<<(b+1)<<endl; 
                              a--;            
                              b++;
                   }
           }
    }
    
    a=aux;
    b=aux2;
    
    if(a<=5)
    {
            if(a!=0)
            {
                    while(((a-1)-0)!=0)//movimiento diagonal derecha hacia arriba
                    {                               
                                 cout<<cambio2((a-1))<<(b+1)<<endl;
                                 a--;
                                 b++;            
                    }
            }            
    }
}
*/
