#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void extraer(char *doc, char *nombre, char *comentario, char *ruta, char *permiso);


void extraer(char *doc, char *nombre, char *comentario, char *ruta, char *permiso)
{

    char nombreRecurso[100] = "\n[";
    strcat(nombreRecurso,nombre);
    strcat(nombreRecurso,"]\n");

    char comment[100] = "\tcomment = ";
    strcat(comment, comentario);
    strcat(comment,"\n");

    char path[100] = "\tpath = ";
    strcat(path, ruta);
    strcat(path, nombre);
    strcat(path, "\n");

    char browseable[100] = "\tbrowseable = Yes\n";

    char permisos[100] = "\tread only = ";
    strcat(permisos, permiso);
    strcat(permisos, "\n");

    char valid[100] = "\t#valid users = publica\n";
    char mask[100] = "\tcreate mask = 0664\n";
    char directory[100] = "\tdirectory mask = 0755\n";


    FILE *fp;
    //char cadena[] = "Mostrando el uso de fputs en un fichero.\n";
    fp = fopen ( doc, "a" );
    fputs( nombreRecurso, fp );
    fputs( comment, fp );
    fputs( path, fp );
    fputs( browseable, fp );
    fputs( permisos, fp );
    fputs( valid, fp );
    fputs( mask, fp );
    fputs( directory, fp );
    fclose ( fp );
}

int main()
{
    // archivo, nombre del recurso, comentario, ruta, permisos
    extraer("smb.conf", "Especial", "archivos especiales", "/home/garys/Desktop/", "Yes");
}