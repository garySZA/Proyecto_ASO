#include <stdbool.h>

void extraerDeDoc(char *doc, char *dest);
void escrituraDestinoDeDoc(char *cad, char *dest);
void lanzador(char *origen, char *destino);

//  Buscador de palabras
bool buscador(char *doc, char *cadena_a_Buscar);

//metodo que extrae cadenas de un archivo dado otra cadena a buscar y lo pasa a uno nuevo
//primer parametro> documento de donde extrae
//segundo parameto> destino donde escribe las filas que contienen la cadena dada a buscar
//tercer parametro> palabra a buscar fila por fila
void extraerHU6(char *doc, char *dest, char *cadena_a_Buscar);
void escrituraDestinoHU6(char *cad, char *dest);

//reemplazador de palabras
char *replace_str(char *str, char *orig, char *rep);

//metodo que verifica un directorio
bool verifDirectorio(char *directorio);