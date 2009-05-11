#include <cstdlib>
#include <iostream>

using namespace std;

bool esPalindrome(char *frase);
int longitud(char *letras);
const int TAM=101;

int main(int argc, char *argv[])
{
    char letras[TAM];    
    
    cout<<"Digite una frase de max. 100 letras\n";    
    cin.getline(letras,TAM);
    cout<<endl;     
    if(esPalindrome(letras)==true)
    {
              cout<<"**************************\n";                    
              cout<<"* La frase ES Palindrome *\n";
              cout<<"**************************\n";
              cout<<endl;            
    }
    else
    cout<<"La frase NO es Palindrome\n";
    
    cout<<"La longitud de la Cadena es:\n";
    cout<<"** "<<longitud(letras)<<" **"<<endl;
    cout<<endl; 
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
bool esPalindrome(char *frase)
{
     char *principal,*ultimo;
     bool estado=true;
     
     principal=frase;
     ultimo=principal;
     
     
     while((*ultimo)!='\0')
     {
            ultimo++;
     }
     ultimo--;
     while(principal<=ultimo)
     {
               while((*principal)==' ') 
                             
                      principal++;
                      
               while((*ultimo)==' ')                          
               
                      ultimo--;    
                 
               if((*principal)!=(*ultimo))
               {   
                      estado=false;
                      principal=ultimo;
               }   
                                     
               principal++;
               ultimo--;               
     }
     
     return estado;
}         

int longitud(char *letras)
{
    char *lptr;
    int aux=0;
    
    lptr=letras;
    while((*lptr)!='\0')
    {
         lptr++;
         aux++;
    }
    return aux;
}     

