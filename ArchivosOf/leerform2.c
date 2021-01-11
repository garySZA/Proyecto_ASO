#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#define MAXLEN 1024

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

//Metodo activador de servicio

void procederA(char *accion){
    if(strcmp(accion, "activar") == 0){
        system("service smb start");
    }else{
        system("service smb stop");
    }
}

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

    char *archSamba = "smb.conf";

    setuid(0);
    setgid(0);

    printf ("Content-type:text/html\n\n");
    printf("<head>\n");
    printf("<TITLE>Response</TITLE>\n");

    printf("<link href=\"https://fonts.googleapis.com/css2?family=Play&family=Source+Sans+Pro:ital,wght@0,400;1,300&display=swap\" rel=\"stylesheet\">\n");
    printf("<style>\n");
    printf("body{background: #355C7D;  /* fallback for old browsers */background: -webkit-linear-gradient(to right, #C06C84, #6C5B7B, #355C7D);  /* Chrome 10-25, Safari 5.1-6 */background: linear-gradient(to right, #C06C84, #6C5B7B, #355C7D); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */color: silver;font-family: 'Play', sans-serif;}\n");
    printf(".container { display: flex;justify-content: center;background: transparent;margin: 15px;}\n");
    printf(".container-renombrar {width: 800px;border: solid silver;display: flex;flex-direction: column;justify-content: center;align-items: center;}\n");
    printf(".boton {border: #0096c7 solid;width: 200px;height: 40px;border-radius: 10px;transition: .8s;margin: 15px;}\n");
    printf(".boton:hover {background-color: #0096c7;color: cornsilk;}\n");
    printf("</style>\n");
    printf("</head>\n");

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

    //Llamando al metodo activador
    procederA(mensaje);

    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");

    if(strstr(mensaje, "selected")){
        printf("Error, debe elegir una opcion para poder continuar.");
    }else{
        if(strcmp(mensaje, "activar") == 0){
            printf("El servidor Samba ha sido activado.");
        }else{
            printf("El servidor Samba ha sido desactivado.");
        }
    }
    
    printf("<br/>");

    printf("<div class=\"position-fixed\">\n");
    printf("<button class=\"boton\" onclick=\"location.href='./index'\">Volver</button>\n");
    printf("</div>\n");

    printf("</div>\n");
    printf("</div>\n");
    
    return 0;
}