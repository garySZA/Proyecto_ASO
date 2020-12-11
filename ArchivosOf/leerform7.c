#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#define MAXLEN 1024


char *removerCaracteres(char *cadena, char *caracteres);

//      METODOS PARA ELIMINAR RECURSO
void extraer(char *doc, char *dest, char *cadena_a_Buscar);
void escrituraDestino(char *cad, char *dest);

// Separar: separa datos del formulario

void separar(char *cadena, char *linea, char separador)
{
    int x, y;

    x = 0; y = 0;

    while ((linea[x]) && (linea[x] != separador))
    {
        cadena[x] = linea[x];
        x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;

    y = 0;

    while (linea[y] = linea[x])
    {
        linea[y] = linea[x];
        y++;
        x++;
    }

}
//  METODO PARA REMOVER CUALQUIER CARACTER DE UNA CADENA
char *removerCaracteres(char *cadena, char *caracteres){
    int indiceCadena = 0;
    int indiceCadenaLimpia = 0;
    int deberiaAgregarCaracter = 1;

    while(cadena[indiceCadena]){
        deberiaAgregarCaracter = 1;
        int indiceCaracteres = 0;
        
        while(caracteres[indiceCaracteres]){
            if(cadena[indiceCadena] == caracteres[indiceCaracteres]){
                deberiaAgregarCaracter = 0;
            }
            indiceCaracteres++;
        }

        if(deberiaAgregarCaracter){
            cadena[indiceCadenaLimpia] = cadena[indiceCadena];
            indiceCadenaLimpia++;
        }
        indiceCadena++;
    }
    cadena[indiceCadenaLimpia] = 0;

    return cadena;
}

//      INICIO BLOQUE DE METODOS PARA ELIMINAR UN RECURSO 

void extraer(char *doc, char *dest, char *cadena_a_Buscar)
{
    unlink(dest);

    char temp[1024];
    char temp2[1024];

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
        char *aux = temp;

        if (strstr(aux, cadena_a_Buscar))
        {
            if(strstr(temp, "groups")){
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);    
            }else if(strstr(temp, "users")){
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
            }else if(strstr(temp, "profiles")){
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                
            }else{
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);    
            }
            
            /*
            */
        }
        else
        {
            escrituraDestino(aux, dest);
        }
    }
    fclose(f);
}

void escrituraDestino(char *cad, char *dest)
{
    FILE *f = fopen(dest, "a");

    if (f == NULL)
    {
        perror("Error");
    }
    fputs(cad, f);
    fclose(f);
}

//      FIN BLOQUE DE METODOS PARA ELIMINAR UN RECURSO

int main(void)
{
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char mensaje[80];
    char usuario[80];
    char clave[80];
    char shell[80];
    char sig[80];

    printf ("Content-type:text/html\n\n");
    printf("<TITLE>Response</TITLE>\n");
    lenstr = getenv("CONTENT_LENGTH");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
    if (lenstr!= NULL)
    {
        contentLength = atoi(lenstr);
    }
    else contentLength = 0;

    if (contentLength > sizeof(inputBuffer)-1)
        contentLength = sizeof(inputBuffer)-1;

    i = 0;

    while (i < contentLength){

        x = fgetc(stdin);
        if (x==EOF) break;
        inputBuffer[i] = x;
        i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;


    separar(mensaje, inputBuffer, '=');
    separar(mensaje, inputBuffer, '&');

    //      REMUEVE CARACTERES ESPECIALES DEL NOMBRE DE RECURSO
    removerCaracteres(mensaje, "%AD0");

    //      LLAMADA A LOS METODOS PARA LA ELIMINACION...
    extraer("smb.conf", "pruebaEliminado.txt", mensaje);


    if(buscador("smb.conf",mensaje)){
        //      REEMPLAZO DEL ARCHIVO SMB.CONF  
        lanzador("pruebaEliminado.txt","smb.conf");
        printf("<br>Cambio Realizado: ");
        printf("Exitoso<br/>");
        printf("<p> Recurso eliminado: %s",mensaje);
    }else{
        printf("<br>Cambio Realizado: ");
        printf("Fallido<br/>");
        printf("<p> Recurso compartido no encontrado");
    }
    printf("<br/>");
    printf("<a href=\"./index\">Volver a pagina principal</a>");
    return 0;
}