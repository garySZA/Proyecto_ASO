#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int verifDirectorio(char *directorio)
{
    int esCorrecto;
    char ruta[100];
    strcat(ruta, directorio);
    strcat(ruta, "exp.txt");

	FILE *archivo;
	char caracter;
	
	archivo = fopen(ruta,"a");
	
	if (archivo == NULL){

            esCorrecto = 0;
    }
    else{
            esCorrecto = 1;
        }
        
        unlink("exp.txt");
	
    return esCorrecto;
}

int main(){
    if(verifDirectorio("/home/garys/Desktop/") == 1){
        printf("verdadero");
    }else{
        printf("falso");
    }
}