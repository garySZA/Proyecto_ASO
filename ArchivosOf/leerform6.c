#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"

#define MAXLEN 1024

//  LISTA DE METODOS PARA HU6
void extraer1(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por);
void escrituraDestino(char *cad, char *dest);

//  PARA REEMPLAZAR LOS PERMISOS DEL RECURSO
void extraer2(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por);


//  BLOQUE METODOS PARA HU6

void extraer1(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por)
{
    unlink(dest);

    char ruta[100] = "\tpath = ";
    strcat(ruta, reemplazar_por);
    strcat(ruta, "\n");

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
        char *aux = temp;
        if (strstr(aux, cadena_a_Buscar))
        {
            escrituraDestino(aux, dest);
            fgets(temp, 1024, (FILE *)f);
            escrituraDestino(aux, dest);
            escrituraDestino(ruta, dest);
            fgets(temp, 1024, (FILE *)f);
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

//  PARA REEMPLAZAR LOS PERMISOS DEL RECURSO
void extraer2(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por)
{
    unlink(dest);

    char ruta[100] = "\tread only = ";
    strcat(ruta, reemplazar_por);
    strcat(ruta, "\n");

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
        char *aux = temp;
        if (strstr(aux, cadena_a_Buscar))
        {
            escrituraDestino(aux, dest);
            fgets(temp, 1024, (FILE *)f);
            escrituraDestino(aux, dest);
            //
            fgets(temp, 1024, (FILE *)f);
            escrituraDestino(aux, dest);
            fgets(temp, 1024, (FILE *)f);
            escrituraDestino(aux, dest);
            //
            escrituraDestino(ruta, dest);
            fgets(temp, 1024, (FILE *)f);
        }
        else
        {
            escrituraDestino(aux, dest);
        }
    }
    fclose(f);
}

//  FIN BLOQUE METODOS PARA HU6

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

char *quitar(char *archivo, char *aBorrar, char *reemplazo){
    char *res = replace_str(archivo, aBorrar, reemplazo);
    return res;
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

    char *archivoSmb = "smb.conf";

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
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');
    separar(clave, inputBuffer, '=');
    separar(clave, inputBuffer, '&');

    //char *aux = replace_str(usuario, "%2F", "/");
    char *mensajeLimpio = quitar(mensaje, "%0D%0A", "");
    char reco[100] = "[";
    strcat(reco, mensajeLimpio);
    strcat(reco,"]");

    //char *ruta = quitar(clave,"%2F","/");

    char *ruta2 = replace_str(clave, "%2F", "/");

    //  INVOCANDO METODOS

    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");

    //  ANIADIR EN ESTA LINEA UN IF QUE VERIFIQUE LA RUTA INGRESADA...
            if(verifPath(ruta2) == 1){
                if(strcmp(usuario,"ambos") == 0){
                    printf("<p> Permisos: Lectura y escritura");

                    //  CAMBIADO DE PERMISO
                    extraer2(archivoSmb, "probando.txt", reco, "No");

                    //  CAMBIAR RUTA
                    extraer1("probando.txt", "probando2.txt",reco, ruta2);

                    printf("<br>Cambio Realizado: Exitoso");
                    printf("<p>Recurso modificado: %s", quitar(mensaje, "%0D%0A", ""));
                    printf("<p>Nueva ruta: %s",quitar(clave,"%2F","/"));

                    //Reemplazando el archivo original por el auxiliar que contiene los cambios
                    lanzador("probando2.txt", archivoSmb);

                    //Eliminando los archivos auxiliares
                    unlink("probando.txt");
                    unlink("probando2.txt");

                }else if (strcmp(usuario,"lectura") == 0)
                {
                    printf("<p> Permisos: Lectura");
                    //  CAMBIADO DE PERMISO
                    extraer2(archivoSmb, "probando.txt", reco, "Yes");

                    //  CAMBIAR RUTA
                    extraer1("probando.txt", "probando2.txt",reco, ruta2);

                    printf("<br>Cambio Realizado: Exitoso");
                    printf("<p>Recurso modificado: %s", quitar(mensaje, "%0D%0A", ""));
                    printf("<p>Nueva ruta: %s",quitar(clave,"%2F","/"));

                    //Reemplazando el archivo original por el auxiliar que contiene los cambios
                    lanzador("probando2.txt", archivoSmb);

                    //Eliminando los archivos auxiliares
                    unlink("probando.txt");
                    unlink("probando2.txt");

                }
            }else{
                printf("Fallido, Ingrese una ruta valida...");
            }
        
        
    

    printf("<br/>");

    printf("<div class=\"position-fixed\">\n");
    printf("<button class=\"boton\" onclick=\"location.href='./index'\">Volver</button>\n");
    printf("</div>\n");

    printf("</div>\n");
    printf("</div>\n");
    return 0;
}