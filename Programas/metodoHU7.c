#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void extraer(char *doc, char *dest, char *cadena_a_Buscar);
void escrituraDestino(char *cad, char *dest);

void extraer(char *doc, char *dest, char *cadena_a_Buscar)
{
    unlink(dest);

    char temp[1024];
    char temp2[1024];

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
        char *aux = temp;

        if (strstr(aux, cadena_a_Buscar))
        {
            if(strstr(temp, "groups")){
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);    
            }else if(strstr(temp, "users")){
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
            }else if(strstr(temp, "profiles")){
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                
            }else{
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);
                fgets(temp2, 1024, (FILE *)f);    
            }
            
            /*
            */
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
    extraer("smb.conf", "pruebaCopia.txt", "[documentos]");
}