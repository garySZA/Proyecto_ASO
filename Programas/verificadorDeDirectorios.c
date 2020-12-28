#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

bool verifDirectorio(char *directorio)
{
    bool esCorrecto = false;
    char ruta[100];
    strcat(ruta, directorio);
    strcat(ruta, "exp.txt");

	FILE *archivo;
	char caracter;
	
	archivo = fopen(ruta,"a");
	
	if (archivo == NULL){

            esCorrecto = false;
    }
    else{
            esCorrecto = true;
        }
        
        unlink("exp.txt");
	
    return esCorrecto;
}

int main(){
    if(verifDirectorio("/home/garys/Desktop/")){
        printf("verdadero");
    }else{
        printf("falso");
    }
}