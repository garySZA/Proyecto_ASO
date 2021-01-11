#include <stdio.h>
#include <string.h>

void leerRecursosParaMostrarHTML(char *documento){
    char temp[1024];
        FILE *f;
        f = fopen(documento, "r");
        if(f == NULL){
                printf("No se ha podido abrir el fichero...\n");
                exit(1);
        }

        while(fgets(temp, 1024, (FILE*) f)) {
            char res[100] = " <p class=\"parrafo\">";
            strcat(res,temp);
            strcat(res, "</option>\n");
            //printf("</option>\n");
            printf(res);

        //printf("<option value=\"opcion1\">\n");
    }
        fclose(f);
}

int main(){
    leerRecursosParaMostrarHTML("limpio.txt");
}