#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
            printf("funciona");
            printf(aux);
            printf(reemplazar_por);
            escrituraDestino(reemplazar_por, dest);
        }
        else
        {
            escrituraDestino(aux, dest);
            printf("no encuentra");
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

    printf("<br>Cambio Realizado: ");

    separar(mensaje, inputBuffer, '=');
    separar(mensaje, inputBuffer, '&');
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');

    removerCaracteres(mensaje, "%AD0");

    //  PROCEDIENDO A CAMBIAR NOMBRE
    char res[100] = "[";
    strcat(res,usuario);
    strcat(res, "]\n");

    //  CONCATENANDO [] PARA SU BUSQUEDA EN EL DOCUMENTO
    char palabraABuscar[100] = "[";
    strcat(palabraABuscar,mensaje);
    strcat(palabraABuscar,"]");

    //extraer("smb.conf", "probando.txt", palabraABuscar, res);
    //

    printf("<p> Recurso eliminado: %s",mensaje);
    printf("<a href=\"./index\">Volver a pagina principal</a>");
    return 0;
}