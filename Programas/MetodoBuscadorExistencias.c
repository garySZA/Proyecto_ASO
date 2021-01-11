#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

bool buscador(char *doc, char *cadena_a_Buscar);

bool buscador(char *doc, char *cadena_a_Buscar)
{
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
        if(strstr(temp, cadena_a_Buscar)){
            return true;
        }
    }
    fclose(f);
}

int main()
{
    if(buscador("smb.conf", "documentos")){
        printf("funciona");
    }else{
        printf("No funciona :(");
    }
}