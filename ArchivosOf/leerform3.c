#include <stdio.h>
#include <stdlib.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#define MAXLEN 1024

void buscaYReemplaza(char *doc, char *dest, char *name);
void escritor(char *cad, char *dest);

//  BLOQUE METODOS PARA HU3

int longitud(char rec[]){
	int res= 0;
	int p1= 0;

	while(rec[p1]!='\0'){
		res=res+1;
		p1= p1+1;
	}

	return res;
}

//	METODOS OF
/*
//Metodo que se encarga de realizar una busqueda fila por fila la cadena "workgroup",
si la fila que agarra no contiene la cadena entonces lo pasa al siguiente metodo que se encarga
de escribir lo que el primer metodo le pase en un archivo auxiliar llamado "work.txt"
*/
/*
Una vez que encuentra la fila que contenga la cadena, la reemplaza por otra cadena
concatenada con el nuevo nombre que ingresa como parametro al primer metodo.
*/
void buscaYReemplaza(char *doc, char *dest, char *name){
        unlink(dest);
        char temp[1024];

        //concatenando el nuevo nombre del grupo de trabajo
        char nuevo[100] = "\tworkgroup = ";
        strcat(nuevo, name);
        strcat(nuevo,"\n");

        FILE *f;
        f = fopen(doc, "r");
        if (f == NULL)
        {
            printf("No se ha podido encontrar el archivo... \n");
            exit(1);
        }
        while(fgets(temp, 1024, (FILE*) f)) {
            char *aux = temp;
            
            if(strstr(temp, "workgroup")){
                escritor(nuevo, dest);
            }else{
                escritor(aux, dest);
            }
        }
        fclose(f);    
}

void escritor(char *cad, char *dest){
    
    FILE *f = fopen(dest, "a");

	if(f == NULL){
		perror("Error");
	}
    fputs(cad,f);          
    fclose(f);
}

//  FIN BLOQUE METODOS PARA HU3

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

	char *archSamba = "smb.conf";

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
    
    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");
    
    printf("<br>Cambio realizado: Exitoso");
    printf("<p> Nuevo grupo de trabajo: %s",mensaje);
    printf("<br/>");

	//Llamada al metodo para realizar el cambio
	buscaYReemplaza(archSamba, "work.txt", mensaje);

	//Llamando al metodo para reemplazar el archivo smb por el auxiliar que contiene los cambios
	lanzador("work.txt", archSamba);

	//Eliminando el archivo auxiliar
	unlink("work.txt");

    printf("<div class=\"position-fixed\">\n");
    printf("<button class=\"boton\" onclick=\"location.href='./index'\">Volver</button>\n");
    printf("</div>\n");

    printf("</div>\n");
    printf("</div>\n");
    
    
    return 0;
}