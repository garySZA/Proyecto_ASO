#include <stdio.h>
#include <sys/stat.h>

void darPermisos(char *ruta){
    chmod(ruta,0777);
}

int main(){
    darPermisos("./directorio");
}