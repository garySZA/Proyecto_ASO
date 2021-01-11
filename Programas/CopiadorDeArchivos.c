#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void extraer(char *doc, char *dest);
void escrituraDestino(char *cad, char *dest);
void lanzador(char *origen, char *destino);

int main(){
    lanzador("notas.txt", "sondaBB.txt");
}

void lanzador(char *origen, char *destino){
    char *doc = origen;
    char *dest = destino;
    int veces = 1;
    int contador = 1;
    int aux = veces;

    while(veces >= contador){
        unlink(dest);
        extraer(doc, dest);
        printf("\ncopiando: %d", contador);
        contador = contador +1;
        aux = aux - 1;
        if(aux > 1)
            unlink(dest);
    }
}

void extraer(char *doc, char *dest){
        char temp[1024];

        FILE *f;
        f = fopen(doc, "r");
        if (f == NULL)
        {
            printf("No se ha podido encontrar el archivo... \n");
            exit(1);
        }
        while(fgets(temp, 1024, (FILE*) f)) {
            char *aux = temp;

            escrituraDestino(aux, dest);
        }
        fclose(f);    
}

void escrituraDestino(char *cad, char *dest){
    
    FILE *f = fopen(dest, "a");

	if(f == NULL){
		perror("Error");
	}
    fputs(cad,f);          
    fclose(f);
}
