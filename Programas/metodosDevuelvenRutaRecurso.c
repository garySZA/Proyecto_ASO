#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>


void eliminar(char *ruta);
void crearDir(char *ruta);
void darPermisos(char *ruta);
char *buscador(char *doc, char *cadena_a_Buscar);
void moverDirectorio(char *anterior, char *nuevo, char *nombre);


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

void crearDir(char *ruta){
    //mkdir(ruta, O_CREAT);
    char aux[100] = "mkdir ";
    strcat(aux, ruta);
    char *algo = aux;

    system(algo);
}

void darPermisos(char *ruta){
    chmod(ruta,0777);
}

char *buscador(char *doc, char *cadena_a_Buscar)
{

    char temp[100];
    char temp2[100];

    char *aux = "";

    FILE *f;
    f = fopen(doc, "r");
    if (f == NULL)
    {
        printf("No se ha podido encontrar el archivo... \n");
        exit(1);
    }
    while (fgets(temp, 100, (FILE *)f))
    {

        if (strstr(temp, cadena_a_Buscar))
        {
            fgets(temp2, 100, (FILE *)f);
            fgets(temp2, 100, (FILE *)f);
            aux = temp2;
            return aux;
        }
    }
    fclose(f);

}

// cp -r rudelio/ prueba2/
void moverDirectorio(char *anterior, char *nuevo, char *nombre){

  char *rutaLimpia = replace_str(anterior, "\n", " ");

  char *cp = "cp -r ";
  char comando[50] = "";
  strcpy(comando, cp);
  strcat(comando,anterior);
  strcat(comando, nuevo);
  //strcmp(comando, nuevo);
  //printf(comando);

  //Ejecutando el comando para poder copiar el directorio a la nueva ruta
  system(comando);

  //Ejecutando comando para eliminar el directorio original
  eliminar(anterior);

  //Dando permisos al nuevo directorio
  char *preparando = nuevo;
  char archiNuevo[50] = "";
  strcpy(archiNuevo, preparando);
  strcat(archiNuevo, nombre);
  //printf(archiNuevo);
  darPermisos(archiNuevo);

}

//metodo para eliminar el directorio original
void eliminar(char *ruta){
  //char *comander = replace_str(ruta, "\t", "");
  char *comander = "rm -r ";
  char dir[50] = "";
  strcpy(dir, comander);
  strcat(dir, ruta);

  //printf(dir);

  system(dir);

}

int main()
{
    //char *posible = buscador("smb.conf", "[documentos]");
    char *ruta = replace_str(buscador("smb.conf", "[documentos]"),"path = ", "");
    //strcat(ruta, "/");
    //printf(ruta);

    //eliminar(ruta);

    moverDirectorio(ruta,"/home/garys/Desktop/", "documentos");
    
    //printf(buscador("smb.conf", "[documentos]"));

}