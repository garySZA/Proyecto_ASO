#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Metodos utilizados
void extraerHU6(char *doc, char *dest, char *cadena_a_Buscar);
void escrituraDestinoHU6(char *cad, char *dest);

void extraer(char *doc, char *dest, char *cadena_a_Buscar)

{
    unlink(dest);

    char temp[1024];
    char temp2[1024];
    char nuevo[100];

    FILE *f;
    f = fopen(doc, "r");
    if (f == NULL)
    {
        printf("No se ha podido encontrar el archivo... \n");
        exit(1);
    }

    int cant = 0;

    while (fgets(temp, 1024, (FILE *)f))
    {
        if (strstr(temp, cadena_a_Buscar) && strstr(temp, "#") == NULL && strstr(temp, "global") == NULL && strstr(temp, "homes") == NULL && strstr(temp, "logon") == NULL)
        {
            if(strstr(temp,cadena_a_Buscar)){
                escrituraDestino(temp, dest);
            }
        }
        cant+1;
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
    extraer("smb.conf", "rutas.txt", "path");
}