#include <stdio.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#include <string.h>

int main(){
    //lanzador("notas.txt", "vamooooss.txt");
    //      PRUEBA BUSCADOR
    //if(buscador("/home/garys/Desktop/Carps/ASO2-2020/smb.conf", "nelsi")){
    //    printf("bien");
    //}

 char cadena[50];
    int i, j, s;
    printf("inserta tu frase plox: ");
    gets(cadena);
    s=strlen(cadena);
    j=' ';
    for(i=s;i>=0;i--){
        if(i == 0){
            cadena[i]=j;
        }
    }
    printf("%s\n\n", cadena);
    printf("ya elimine todas las vocales, ahora dame mi titulo >:v");
    return 0;
    
}