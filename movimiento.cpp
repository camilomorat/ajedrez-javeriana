#include <iostream>
#include "programas.h"

using namespace std;

int jug=2,x=4,y=4,ax=4,ay=4,j;

int vpeon(int ax,int ay,int x,int y)
{   int b=0;
    if (jug==1)
    {   if (y>ay)//Si avanzo algunas casillas
	{  if (x==ax)//Si avanzo en linea recta
	   {  if (ay==2)//Si fue el primer movimiento
	      {  if (y==3&&pos[ay][x-1]==0)
		    b++;
		 else
		    if (y==4&&pos[ay][x-1]==0&&pos[ay+1][x-1]==0)//Puede avanzar 2 casillas
		       b++;
	      }
	      else
		 if (ay+1==y&&pos[y-1][x-1]==0)//Nada mas puede avanzar una casilla
		    b++;
	   }
	   else//Si avanzo en diagonal
	      if (x>ax)
	      {  if (ax+1==x&&ay+1==y&&pos[y-1][x-1]!=0)//Pero solo una casilla adelante y hacia la derecha o izquierda
		     b++;
	      }
	      else
		 if (x<ax)
		    if (x+1==ax&&ay+1==y&&pos[y-1][x-1]!=0)//Pero solo una casilla adelante y hacia la derecha o izquierda
		       b++;
	}
    }
    else//Jugador 2
    {	if (y<ay)//Si avanzo algunas casillas
	{  if (x==ax)//Si avanzo en linea recta
	   {  if (ay==7)//Si fue el primer movimiento
	      {  if (y==6&&pos[y-1][x-1]==0)
		    b++;
		 else
		    if (y==5&&pos[y][x-1]==0&&pos[y-1][x-1]==0)//Puede avanzar 2 casillas
		       b++;
	      }
	      else
		 if (ay-1==y&&pos[y-1][x-1]==0)//Nada mas puede avanzar una casilla
		    b++;
	   }
	   else//Si avanzo en diagonal
	      if (x>ax)
	      {  if (ax+1==x&&ay-1==y&&pos[y-1][x-1]!=0)//Pero solo una casilla adelante y hacia la derecha o izquierda
		     b++;
	      }
	      else
		 if (x<ax)
		    if (x+1==ax&&ay-1==y&&pos[y-1][x-1]!=0)//Pero solo una casilla adelante y hacia la derecha o izquierda
		       b++;
	}
    }
    if (b)
       return 1;
    else
       return 0;
}

int vtorre(int ax,int ay,int x,int y)//Me valida el movimiento de una torre Se le manda el jugador, y las coordenadas
{       int aux,s=0,c;
	if (ax<x&&ay==y)//se movio derecha
	{ 	aux=x-ax-1;
		for (c=ax; c<x-1; c++)
		{	if (pos[y-1][c]==0)
				s++;
		}
	}
	else
		if (ax>x&&ay==y)//Se movio a la izquierda
		{	aux=ax-x-1;
			for (c=x; c<ax-1; c++)
			{	if (pos[y-1][c]==0)
					s++;
			}
		}
		else
			if (ay>y&&x==ax)//Hacia arriba
			{       aux=ay-y-1;
				for (c=y; c<ay-1; c++)
				{	if (pos[c][x-1]==0)
						s++;
				}
			}
			else
				if (ay<y&&ax==x)//Hacia abajo
				{       aux=y-ay-1;
					for (c=ay; c<y-1; c++)
					{	if (pos[c][x-1]==0)
							s++;
					}
				}
				else
					s=-1;
	if (aux==s)
		return 1;
	else
		return 0;
}

int vcaballo (int ax,int ay,int x,int y)//Me valida el movimiento de un caballo.Se le manda el jugador, y las coordenadas
{   int b=0;
    if (x>ax)//Si brinca hacia la derecha
    {   if (y>ay)//Hacia abajo
	{  if (x-ax==1&&y-ay==2)
	      b++;
	   else
	      if (x-ax==2&&y-ay==1)
		 b++;
	}
	else
	   if (y<ay)//Hacia arriba
	   {  if (x-ax==1&&ay-y==2)
		 b++;
	      else
		 if (x-ax==2&&ay-y==1)
		    b++;
	   }
    }
    else
    {   if (x<ax)//Si brinca hacia la izquierda
	{  if (y>ay)//Hacia abajo
	   {  if (ax-x==1&&y-ay==2)
		 b++;
	      else
		 if (ax-x==2&&y-ay==1)
		    b++;
	   }
	   else
	      if (y<ay)//Hacia arriba
	      {  if (ax-x==1&&ay-y==2)
		    b++;
		 else
		    if (ax-x==2&&ay-y==1)
		       b++;
	      }
	}
    }
    if (b)
       return 1;
    else
       return 0;
}

int valfil(int ax,int ay,int x,int y)//Me valida el movimiento de un  Alfil .Se le manda el jugador, y las coordenadas
{   int b=0,s=0,q=0,r=0,aux=-1;
    if (x>ax)//Se avanza hacia la derecha
    {   if (y>ay)//Si se avanza hacia la derecha en diagonal hacia abajo
       {  if (y-ay==x-ax)
	  {  r=ax;
	     aux=x-ax-1;
	     for (q=ay; q<y-1; q++)
	     {   if (pos[q][r]==0)
		     s++;
		 r++;
	     }
	     if (s==aux)
		b++;
	  }
       }
       else
       {  if (y<ay)//Si se avanza hacia la derecha en diagonal hacia arriba
	  {  if (ay-y==x-ax)
	     {  r=ax;
		aux=x-ax-1;
		for (q=ay-2; q>y-1; q--)
		{   if (pos[q][r]==0)
		       s++;
		    r++;
		}
		if (s==aux)
		    b++;
	     }
	  }
       }
    }
    else
    {  if (x<ax)//Si avanzo hacia la izquierda
       {  if (y>ay)//Si se avanza hacia la izquierda en diagonal hacia abajo
	  {  if (y-ay==ax-x)
	     {  r=ax-2;
		aux=ax-x-1;
		for (q=ay; q<y-1; q++)
		{   if (pos[q][r]==0)
		       s++;
		    r--;
		}
		if (s==aux)
		   b++;
	     }
	  }
	  else
	  {  if (y<ay)//Si se avanza hacia la izquierda en diagonal hacia arriba
	     {  if (ay-y==ax-x)
		{  r=x;
		   aux=ax-x-1;
		   for (q=y; q<ay-1; q++)
		   {  if (pos[q][r]==0)
			 s++;
		      r++;
		   }
		   if (s==aux)
		      b++;
		}
	     }
	  }
       }
    }
    if (b)
       return 1;
    else
       return 0;
}

int vrey(int ax,int ay,int x,int y)//Me valida el movimiento de el rey.Se le manda el jugador, y las coordenadas
{  int b=0;
   if (x>ax)//Si se avanzo hacia la derecha
   {   if (y==ay&&ax+1==x)
	  b++;
       else
       {  if (y>ay&&ax+1==x&&ay+1==y)//Hacia abajo
	     b++;
	  else
	     if(y<ay&&ax+1==x&&y+1==ay)//Hacia arriba
		b++;
       }
   }
   else
   {  if (x<ax)//Si se avanzo hacia la izquierda
      {	 if (y==ay&&x+1==ax)
	    b++;
	 else
	 {  if (y>ay&&x+1==ax&&ay+1==y)//Hacia abajo
	       b++;
	    else
	       if(y<ay&&x+1==ax&&y+1==ay)//Hacia arriba
		  b++;
	 }
      }
      else
      {	 if (y>ay)//Si se avanzo hacia abajo
	 {  if (ay+1==y)
	       b++;
	 }
	 else
	 {  if (y<ay)
	       if (y+1==ay)//Si se avanzo hacia arriba
		  b++;
	 }
      }
   }
   if (b)
      return 1;
   else
      return 0;
}

int vreyna(int ax,int ay,int x,int y)//Me valida el movimiento de una reyna.Se le manda el jugador, y las coordenadas
{  int b=0,s=0,q=0,r=0,aux=-1;
   if (x>ax)//Se avanza hacia la derecha
   {   if (y==ay)//Si se avanza hacia la derecha en linea recta
       {   aux=x-ax-1;
	  for (q=ax; q<x-1; q++)
	  {  if (pos[y-1][q]==0)
	      s++;
	  }
	  if (s==aux)
	     b++;
       }
       else
       {  if (y>ay)//Si se avanza hacia la derecha en diagonal hacia abajo
	  {  if (y-ay==x-ax)
	     {  r=ax;
		aux=x-ax-1;
		for (q=ay; q<y-1; q++)
		{   if (pos[q][r]==0)
		       s++;
		    r++;
		}
		if (s==aux)
		   b++;
	     }
	  }
	  else
	  {  if (y<ay)//Si se avanza hacia la derecha en diagonal hacia arriba
	     {  if (ay-y==x-ax)
		{  r=ax;
		   aux=x-ax-1;
		   for (q=ay-2; q>y-1; q--)
		   {   if (pos[q][r]==0)
			  s++;
		       r++;
		   }
		   if (s==aux)
		      b++;
		}
	     }
	  }
       }
    }
    else
    {  if (x<ax)//Si avanzo hacia la izquierda
       {  if (y==ay)//Si se avanza hacia la izquierda en linea recta
	  {  aux=ax-x-1;
	     for (q=x; q<ax-1; q++)
	     {   if (pos[y-1][q]==0)
		    s++;
	     }
	     if (s==aux)
		b++;
	  }
	  else
	  {  if (y>ay)//Si se avanza hacia la izquierda en diagonal hacia abajo
	     {  if (y-ay==ax-x)
		{  r=ax-2;
		   aux=ax-x-1;
		   for (q=ay; q<y-1; q++)
		   {   if (pos[q][r]==0)
			  s++;
		       r--;
		   }
		   if (s==aux)
		      b++;
		}
	     }
	     else
	     {	if (y<ay)//Si se avanza hacia la izquierda en diagonal hacia arriba
		{  if (ay-y==ax-x)
		   {  r=x;
		      aux=ax-x-1;
		      for (q=y; q<ay-1; q++)
		      {  if (pos[q][r]==0)
			    s++;
			 r++;
		      }
		      if (s==aux)
			 b++;
		   }
		}
	     }
	  }
       }
       else//Pudo haberse movido hacia arriba o hacia abajo en linea recta
       {  if (y>ay)//Si se movio hacia abajo
	  {  aux=y-ay-1;
	     for (q=ay; q<y-1; q++)
	     {   if (pos[q][x-1]==0)
		    s++;
	     }
	     if (s==aux)
		b++;
	  }
	  else
	     if (y<ay)//Si se movio hacia arriba
	     {  aux=ay-y-1;
		for (q=y; q<ay-1; q++)
		{   if (pos[q][x-1]==0)
		       s++;
		}
		if (s==aux)
		   b++;
	     }
       }
    }
    if (b)
       return 1;
    else
       return 0;
}
