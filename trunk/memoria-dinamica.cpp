#include <cstdlib>
#include <iostream>

using namespace std;

int **crearEscalera(int numEscalones);
void imprimirEscalera(int**escalera,int numEscalones);
void eliminarEscalera(int**escalera,int numEscalones);

int main(int argc, char *argv[])
{
    int a;
        
    cout<<"Ingerese el numero de escalones que desee:\n";
    cin>>a;
    
    **crearEscalera(a);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


int**crearEscalera(int numEscalones)
{
    int**matriz;
    int m=1;
    
    matriz=new int *[numEscalones];
    
    for(int i=0;i<numEscalones;i++)
    {
            matriz[i]=new int[i+1];
    }
    
    for(int i=0;i<numEscalones;i++)
    {
            m=1;
            
            for(int j=0;j<(i+1);j++)
            {
                    matriz[i][j]=m;
                    m++;
            }
    }
    
    imprimirEscalera(matriz,numEscalones);              
}

void imprimirEscalera(int**escalera,int numEscalones)
{
     for(int i=0;i<numEscalones;i++)
     {
             for(int j=0;j<(i+1);j++)
             {
                     cout<<escalera[i][j]<<" ";
             }
             cout<<endl;
     }
     
}

void eliminarEscalera(int**escalera,int numEscalones)
{
     for(int i=0;i<numEscalones;i++)
     {
             delete []escalera[i];
     }
     delete[]escalera;
}
