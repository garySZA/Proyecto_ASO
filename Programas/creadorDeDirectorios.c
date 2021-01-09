#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

void crearDir(char *ruta){
    //mkdir(ruta, O_CREAT);
    char aux[100] = "mkdir ";
    strcat(aux, ruta);
    char *algo = aux;

    system(algo);
}

int main(){
    char *ruta = "/home/garys/Desktop/";
    char *nombre = "probando";
    char direc[100] = "";
    strcpy(direc, ruta);
    strcat(direc,nombre);
    printf(direc);
    printf("\n");

    crearDir(direc);
}