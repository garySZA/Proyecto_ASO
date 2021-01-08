#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#define MAXLEN 1024

//      Metodos para cambiar nombre de recurso

void extraer(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por);
void escrituraDestino(char *cad, char *dest);
char *palabra_cambio(char *cadena);
//

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

    //escrituraDestino(cadena, "limpio.txt");

    return cadena;
}

//      BLOQUE ENCARGADO DE CAMBIAR NOMBRE DE RECURSO

char *palabra_cambio(char *cadena)
{
    char buscar[100];
    strcat(buscar, "\tcomment = ");
    strcat(buscar, cadena);
    strcat(buscar,"\n");
    char *res = buscar;
    return res;
}

void extraer(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por)
{
    unlink(dest);

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
            //printf("funciona");
            //printf(aux);
            //printf(reemplazar_por);
            escrituraDestino(reemplazar_por, dest);
        }
        else
        {
            escrituraDestino(aux, dest);
            //printf("no encuentra");
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

//      FIN DE BLOQUE ENCARGADO DE CAMBIAR NOMBRE DE RECURSO

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

    char *inputs = usuario;

    //removerCaracteres(mensaje, "%D0A");
    char *name = replace_str(mensaje, "%0D%0A", "");

    //  PROCEDIENDO A CAMBIAR NOMBRE
    char res[100] = "[";
    strcat(res,usuario);
    strcat(res, "]\n");

    //  CONCATENANDO [] PARA SU BUSQUEDA EN EL DOCUMENTO
    char palabraABuscar[100] = "[";
    strcat(palabraABuscar,name);
    strcat(palabraABuscar,"]");

    //

    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");

    if(strstr(name, "selected")){
        printf("recurso no seleccionado");
    }else{
        if(strcmp(inputs, "") == 0){
            printf("Debe ingresar un nuevo nombre valido, intente otra vez");
        }else{
            if(buscador(archSamba, name)){
                //      PROCEDIENDO AL CAMBIO DE NOMBRE DEL RECURSO
                //      REEMPLAZAR RUTA PARA EL ARCHIVO ORIGINAL AQUI
                extraer(archSamba, "probandoHU8.txt", palabraABuscar, res);

                //      REEMPLAZO DEL ARCHIVO SMB.CONF  
                lanzador("probandoHU8.txt",archSamba);

                printf("<br>Cambio Realizado: Exitoso");
                printf("<p> Nombre anterior: %s",name);
                printf("<p> Nuevo nombre: %s",usuario);

                //      ELIMINACION DE ARCHIVO AUXILIAR     
                unlink("probandoHU8.txt");
            }else{
                printf("<br>Cambio Realizado: Fallido");
                printf("<p> Nombre del recurso: %s",name);
                printf("<p> nombre de recurso no existe...");
            }
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