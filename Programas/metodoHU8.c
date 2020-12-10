#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void extraer(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por);
void escrituraDestino(char *cad, char *dest);
char *palabra_cambio(char *cadena);

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
            escrituraDestino(reemplazar_por, dest);
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

int main()
{
    //char *aux = palabra_cambio("Nuevo nombre jm asdasdasd");
    char *probando = "nuevo"; 
    char res[100] = "[";
    strcat(res,probando);
    strcat(res, "]\n");
    printf(res);
    extraer("smb.conf", "probando.txt", "[archivos]", res);
    //printf(palabra_cambio("Nuevo nombre jm asdasdasd"));
    //printf(aux);
}