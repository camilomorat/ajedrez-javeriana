#include <iostream>
#include "programas.h"


using namespace std;

void imprimirTablero(arreglo[TAM][TAM])
{
     char l=72, m=177,a=1;
     int h=0,n=0;
     for(int i=0;i<8;i++)
     {
             cout<<h<<" ";
             
             if(i%2==0)
             {
                       for(int j=0;j<8;j++)
                       {
                                                              
                               if(j%2==0)                 
                               cout<<m<<m<<m;                               
                               
                               else
                               cout<<"   ";
                       }
                       cout<<endl;        
             }
             else
             {
                       for(int j=0;j<8;j++)
                       {
                               if(j%2!=0)
                               cout<<m<<m<<m;
                               
                               else
                               cout<<"   ";
                       }
                       cout<<endl;                  
             }
             h++;
     }
     cout<<"   "<<l;
     
     while(n<7)
     {
               l--;
               cout<<"  "<<l;
               n++;
     }
     cout<<endl;
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

