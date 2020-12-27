#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void extraer2(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por);
void escrituraDestino(char *cad, char *dest);

//  PARA REEMPLAZAR LOS PERMISOS DEL RECURSO
void extraer2(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por);

//  buscan el nombre del recurso y luego reemplazando la ruta

void extraer(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por)
{
    unlink(dest);

    char ruta[100] = "\tpath = ";
    strcat(ruta, reemplazar_por);

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

int main()
{
    

    //  PRUEBAS PARA CAMBIAR RUTA
    //char *probando = "/etc/Desktop\n";
    //extraer("smb.conf", "probando.txt", "[archivos]", probando);
    

    //  PRUEBAS PARA CAMBIAR PERMISOS
    char *probando = "Yes";
    char *aux = "No";
    extraer2("smb.conf", "probando.txt", "[archivos]", probando);
    extraer2("smb.conf", "probando.txt", "[archivos]", aux);
    extraer2("smb.conf", "probando.txt", "[archivos]", probando);
    extraer2("smb.conf", "probando.txt", "[archivos]", aux);
    extraer2("smb.conf", "probando.txt", "[archivos]", probando);
    extraer2("smb.conf", "probando.txt", "[archivos]", aux);
    extraer2("smb.conf", "probando.txt", "[archivos]", probando);
    extraer2("smb.conf", "probando.txt", "[archivos]", aux);
    extraer2("smb.conf", "probando.txt", "[archivos]", probando);
    extraer2("smb.conf", "probando.txt", "[archivos]", aux);
    extraer2("smb.conf", "probando.txt", "[archivos]", probando);
    extraer2("smb.conf", "probando.txt", "[archivos]", aux);
    extraer2("smb.conf", "probando.txt", "[archivos]", probando);
    extraer2("smb.conf", "probando.txt", "[archivos]", aux);
    
}