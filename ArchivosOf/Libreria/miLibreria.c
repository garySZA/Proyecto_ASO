#include "milibreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


void lanzador(char *origen, char *destino){
    char *doc = origen;
    char *dest = destino;
    int veces = 1;
    int contador = 1;
    int aux = veces;

    while(veces >= contador){
        unlink(dest);
        extraerDeDoc(doc, dest);
        printf("\ncopiando: %d", contador);
        contador = contador +1;
        aux = aux - 1;
        if(aux > 1)
            unlink(dest);
    }
}

void extraerDeDoc(char *doc, char *dest){
        char temp[1024];

        FILE *f;
        f = fopen(doc, "r");
        if (f == NULL)
        {
            printf("No se ha podido encontrar el archivo... \n");
            exit(1);
        }
        while(fgets(temp, 1024, (FILE*) f)) {
            char *aux = temp;

            escrituraDestinoDeDoc(aux, dest);
        }
        fclose(f);    
}

void escrituraDestinoDeDoc(char *cad, char *dest){
    
    FILE *f = fopen(dest, "a");

	if(f == NULL){
		perror("Error");
	}
    fputs(cad,f);          
    fclose(f);
}

//      METODO PARA BUSCAR PALABRA EN ARCHIVO
bool buscador(char *doc, char *cadena_a_Buscar)
{
    char temp[1024];

    FILE *f;
    f = fopen(doc, "r");
    if (f == NULL)
    {
        printf("No se ha podido encontrar el archivo... \n");
        exit(1);
    }
    while (fgets(temp, 1024, (FILE *)f))
    {
        if(strstr(temp, cadena_a_Buscar)){
            return true;
        }
    }
    fclose(f);
}

//Metodos HU6
void extraerHU6(char *doc, char *dest, char *cadena_a_Buscar)

{
    unlink(dest);

    char temp[1024];
    char temp2[1024];
    char nuevo[100];

    FILE *f;
    f = fopen(doc, "r");
    if (f == NULL)
    {
        printf("No se ha podido encontrar el archivo... \n");
        exit(1);
    }

    int cant = 0;

    while (fgets(temp, 1024, (FILE *)f))
    {
        if (strstr(temp, cadena_a_Buscar) && strstr(temp, "#") == NULL && strstr(temp, "global") == NULL && strstr(temp, "homes") == NULL && strstr(temp, "logon") == NULL)
        {
            if(strstr(temp,cadena_a_Buscar)){
                escrituraDestinoHU6(temp, dest);
            }
        }
        cant+1;
    }
    fclose(f);
}

void escrituraDestinoHU6(char *cad, char *dest)
{
    FILE *f = fopen(dest, "a");

    if (f == NULL)
    {
        perror("Error");
    }
    fputs(cad, f);
    fclose(f);
}

//      REEMPLAZADOR DE PALABRAS
char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  //buffer[p-str] = '\0'; NO HACE FALTA
  
char aux[strlen(p+strlen(orig))+1]; 
strcpy(aux, p+strlen(orig)); //Lo guardamos para que sprintf no lo machaque si rep es más largo que orig

sprintf(buffer+(p-str), "%s%s", rep, aux);
  
  return replace_str(buffer, orig, rep);
}

//  METODO QUE VERIFICA LA EXISTENCIA DE UN DIRECTORIO
int verifPath(char *directorio)
{
   int esCorrecto;
    char ruta[100];
    strcpy(ruta, directorio);
    strcat(ruta, "exp.txt");

	FILE *archivo;
	char caracter;
	
	archivo = fopen(ruta,"a");
	
	if (archivo == NULL){

            esCorrecto = 0;
    }
    else{
            esCorrecto = 1;
        }
        
        unlink(ruta);
	
    return esCorrecto;
}