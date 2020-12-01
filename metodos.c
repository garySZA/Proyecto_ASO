#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void extraer(char *doc, char *dest, char *cadena_a_Buscar, char *reemplazar_por);
void escrituraDestino(char *cad, char *dest);
char *palabra_cambio(char *cadena);

int main()
{
    char *aux = palabra_cambio("Nuevo nombre jm asdasdasd");
    extraer("smb.conf", "probando.txt", "comment = Archivos varios", "\tcomment = Archivos varios2\n");
    //printf(palabra_cambio("nueva palabra 5"));
    printf(aux);
}

char *palabra_cambio(char *cadena)
{
    char buscar[1024] = "\tcomment = ";
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
