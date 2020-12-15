#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#define MAXLEN 1024

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
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');

    printf("<br>Cambio Realizado: Exitoso");
    printf("<p>Permisos del recurso: %s",mensaje);

    char *aux = replace_str(usuario, "%2F", "/");

    if(strcmp(usuario,"") ==0){
        printf("<p> probando ruta: %s",usuario);
    }else{
        printf("<p> Nueva ruta: %s",aux);
    }

    printf("<br/>");
    printf("<a href=\"./index\">Volver a pagina principal</a>");
    return 0;
}