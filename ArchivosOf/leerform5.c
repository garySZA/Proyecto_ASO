#include <stdio.h>
#include <stdlib.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#define MAXLEN 1024

//  METODOS PARA LA HU5
void extraer(char *doc, char *nombre, char *comentario, char *ruta, char *permiso);

//  BLOQUE DE METODOS PARA LA HU5

void extraer(char *doc, char *nombre, char *comentario, char *ruta, char *permiso)
{

    char nombreRecurso[100] = "\n[";
    strcat(nombreRecurso,nombre);
    strcat(nombreRecurso,"]\n");

    char comment[100] = "\tcomment = ";
    strcat(comment, comentario);
    strcat(comment,"\n");

    char path[100] = "\tpath = ";
    strcat(path, ruta);
    strcat(path, "\n");

    char browseable[100] = "\tbrowseable = Yes\n";

    char permisos[100] = "\tread only = ";
    strcat(permisos, permiso);
    strcat(permisos, "\n");

    char valid[100] = "\t#valid users = publica\n";
    char mask[100] = "\tcreate mask = 0664\n";
    char directory[100] = "\tdirectory mask = 0755\n";

    FILE *fp;
    //char cadena[] = "Mostrando el uso de fputs en un fichero.\n";
    fp = fopen ( doc, "a" );
    fputs( nombreRecurso, fp );
    fputs( comment, fp );
    fputs( path, fp );
    fputs( browseable, fp );
    fputs( permisos, fp );
    fputs( valid, fp );
    fputs( mask, fp );
    fputs( directory, fp );
    fclose ( fp );
}

//  FIN BLOQUE METODOS HU5

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
    separar(shell, inputBuffer, '=');
    separar(shell, inputBuffer, '&');

    char *aux = replace_str(clave, "%2F", "/");
    
    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");


    printf("<br>Cambio realizado:");

    
    //  INVOCANDO AL METOODO>
    //  primer if verifica si existe algun recurso con el nombre ingresado
    //  implementar if para controlar ruta
    if(buscador(archivoSmb, mensaje)){
        printf(" Fallido, ya existe un recurso con el nombre ingresado");
    }else
    {
        printf(" Exitoso\n");
        char *shellLimpio = replace_str(shell, "%2F", "/");
        printf("<p> Ruta: %s",shellLimpio);
        printf("<br/>");
        printf("<p> Nombre del recurso: %s",mensaje);
        printf("<p> Comentario: %s",replace_str(usuario, "+", " "));
        if(strcmp(aux,"ambos") == 0){
            printf("<p> Permisos: Lectura y escritura");

            //  CAMBIADO DE PERMISO
            
            extraer(archivoSmb, mensaje, replace_str(usuario, "+", " "), shellLimpio, "No");
        }else if (strcmp(aux,"lectura") == 0)
        {
            printf("<p> Permisos: Lectura");
            //  CAMBIADO DE PERMISO
            extraer(archivoSmb, mensaje, replace_str(usuario, "+", " "), shellLimpio, "Yes");
        }
    }
    

    printf("<div class=\"position-fixed\">\n");
    printf("<button class=\"boton\" onclick=\"location.href='./index'\">Volver</button>\n");
    printf("</div>\n");

    printf("</div>\n");
    printf("</div>\n");

    return 0;
}