#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "/home/garys/Desktop/Carps/ASO2-2020/ArchivosOf/Libreria/milibreria.h"
#include "/home/garys/Desktop/Carps/ASO2-2020/ArchivosOf/Libreria/miLibreria.c"

char *buscarNombreGrupo(char *doc){
        char temp[1024];

        char *grupo;
        char *limpio;

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
                grupo = temp;
                limpio = replace_str(grupo, "workgroup =", "");
            }
        }
        fclose(f);    
        return limpio;
}

int main(){
    printf(buscarNombreGrupo("smb.conf"));
}