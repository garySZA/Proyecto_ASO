#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *quitaespacios(char cadena [100], char cadenasin[100]);
char *procederAQuitar(char *ruta);
int main()
{
    /*
 char cad[100],cadsin[100],vaciar;
 
 quitaespacios("/etc/ ",cadsin);
 
 //Imprimimos el resultado
 printf("La cadena es %s",cadsin); 
 printf(cadsin);
 return 0;
 */

    printf(procederAQuitar("/home/garys/Desktop/ "));
}

char *procederAQuitar(char *ruta){
    char cad[100],cadsin[50],vaciar;
    
    quitaespacios(ruta,cadsin);
    
    //Imprimimos el resultado
    printf("La cadena es %s",cadsin); 
    printf(cadsin);
    char *aux = "";
    char algo[50] = "";
    strcpy(algo, cadsin);
    aux = algo;
    return aux;
}

//Función que devuelve la misma cadena que se le pasa como argumento pero sin espacios
char *quitaespacios(char cadena [100], char cadenasin[100])
{
 int i,j;
 i=0;
 j=0;
 while (cadena[i]!='\0') 
 {
  if(cadena[i]!=' ')
  {
   cadenasin[j]=cadena[i];
   j++;
  }
  i++;
 }

 return cadenasin;

}


