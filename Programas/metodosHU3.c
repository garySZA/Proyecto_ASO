#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void buscaYReemplaza(char *doc, char *dest, char *name);
void escritor(char *cad, char *dest);

/*
//Metodo que se encarga de realizar una busqueda fila por fila la cadena "workgroup",
si la fila que agarra no contiene la cadena entonces lo pasa al siguiente metodo que se encarga
de escribir lo que el primer metodo le pase en un archivo auxiliar llamado "work.txt"
*/
/*
Una vez que encuentra la fila que contenga la cadena, la reemplaza por otra cadena
concatenada con el nuevo nombre que ingresa como parametro al primer metodo.
*/
void buscaYReemplaza(char *doc, char *dest, char *name){
        unlink(dest);
        char temp[1024];

        //concatenando el nuevo nombre del grupo de trabajo
        char nuevo[100] = "\tworkgroup = ";
        strcat(nuevo, name);
        strcat(nuevo,"\n");

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
                escritor(nuevo, dest);
                printf("hecho");
            }else{
                escritor(aux, dest);
            }
        }
        fclose(f);    
}

void escritor(char *cad, char *dest){
    
    FILE *f = fopen(dest, "a");

	if(f == NULL){
		perror("Error");
	}
    fputs(cad,f);          
    fclose(f);
}

int main(){
    buscaYReemplaza("smb.conf", "work.txt", "Admin");
}