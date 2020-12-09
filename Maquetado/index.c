#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Metodos utilizados para la generacion de la lista de recursos
void extraer(char *doc, char *dest, char *cadena_a_Buscar);
void escrituraDestino(char *cad, char *dest);
void quitarCorchetes();
char *removerCaracteres(char *cadena, char *caracteres);
void leerRecursosParaMostrar();
//

int main(){
    /*
            BLOQUE ENCARGADO DE MOSTRAR LISTA DE RECURSOS
    */

    //con este metodo extraigo los nombres de los recursos compartidos(por defecto en el siguiente formato>[nombreRecurso])
    //como primer parametro esta el origen de donde se va obtener
    //segundo parametro es donde se va almacenar los nombres
    //tercer parametro: hace la busqueda fila por fila al que contenda '['
    extraer("/etc/samba/smb.conf", "listaSucia.txt", "[");

    //luego empezamos a quitar los corchetes con el sig metodo
    //este metodo emplea al metodo remover caracteres que se encarga de quitar los corchetes y almacenar los nombres en un archivo llamado limpio.txt
    quitarCorchetes();

    //una vez que se tienen los nombres de los recursos listos para mostrar procedemos a ponerlos en formato html con el sig metodo.
    //leerRecursosParaMostrar();

    /*
            BLOQUE HTML
    */

    printf ("Content-type:text/html\n\n");
    printf("<!DOCTYPE html>\n");
    printf("<html lang=\"en\">\n");
    printf("<head>\n");
    printf("<meta charset=\"UTF-8\">\n");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    printf("<title>Administrador Samba</title>\n");
    printf("<link rel=\"stylesheet\" href=\"Styles.css\">\n");
    printf("<link rel=\"preconnect\" href=\"https://fonts.gstatic.com\">\n");
    printf("<link href=\"https://fonts.googleapis.com/css2?family=Play&family=Source+Sans+Pro:ital,wght@0,400;1,300&display=swap\" rel=\"stylesheet\">\n");
    printf("</head>\n");
    printf("<body>");
    printf("<form action=\"/cgi-bin/leerform\" method=\"POST\">");
    printf("<div class=\"container\">");
    printf("<div class=\"container-renombrar\">");
    printf("<div class=\"container-titulo\">");
    printf("<h3> Renombrar Recurso compartido </h3>");
    printf("</div>");
    printf("<div class=\"container-elementos\">");
    printf("<div class=\"campo\">");
    printf("<h3> Seleccionar recurso compartido: </h3>");
    printf("</div>");
    printf("<div class=\"campo opcion\">");
    printf("<select name=\"recursos\" id=\"combo\">");
    printf("<option value="" selected=\"selected\"> -Selecciona-</option>");
    leerRecursosParaMostrar();
    printf("</select>");
    printf("</div>");
    printf("<div class=\"campo\">");
    printf("<h3> Seleccionar recurso compartido: </h3>");
    printf("</div>");
    printf("<div class=\"campo opcion\">");
    printf(" <input class=\"input\" type=\"text\" name=\"nombre\" value=\"\" placeholder=\"Ingrese un nuevo nombre\"/>");
    printf("</div>");
    printf("</div>");
    printf(" <div class=\"campo bton\">");
    printf("<input type=\"submit\" name=\"enviar\" value=\"Cambiar nombre\" class=\"boton\"/>");
    printf("</div>");
    printf("</div>");
    printf("</div>");
    printf("</form>");
    printf("</body>");
    printf("</html>");
    
    return 0;
}

void extraer(char *doc, char *dest, char *cadena_a_Buscar)

{
    unlink(dest);

    char temp[1024];
    char temp2[1024];

    FILE *f;
    f = fopen(doc, "r");
    if (f == NULL)
    {
        printf("No se ha podido encontrar el archivo... \n");
        exit(1);
    }

    int cant = 0;

    while (fgets(temp, 1024, (FILE *)f))
    {
        char *aux = temp;

        if (strstr(aux, cadena_a_Buscar) && strstr(aux, "#") == NULL && strstr(aux, "global") == NULL && strstr(aux, "homes") == NULL)
        {
            escrituraDestino(aux, dest);
        }
    }
    fclose(f);
}

void escrituraDestino(char *cad, char *dest)
{
    FILE *f = fopen(dest, "a");

    if (f == NULL)
    {
        perror("Error");
    }
    fputs(cad, f);
    fclose(f);
}

void quitarCorchetes(){

    char temp[1024];
    char temp2[1024];

    FILE *f;
    f = fopen("listaSucia.txt", "r");
    if (f == NULL)
    {
        printf("No se ha podido encontrar el archivo... \n");
        exit(1);
    }

    int cant = 0;
    unlink("limpio.txt");
    while (fgets(temp, 1024, (FILE *)f))
    {
        //char *aux = temp;
        removerCaracteres(temp, "[]");
    }
    fclose(f);
}

char *removerCaracteres(char *cadena, char *caracteres){
    int indiceCadena = 0;
    int indiceCadenaLimpia = 0;
    int deberiaAgregarCaracter = 1;

    while(cadena[indiceCadena]){
        deberiaAgregarCaracter = 1;
        int indiceCaracteres = 0;
        
        while(caracteres[indiceCaracteres]){
            if(cadena[indiceCadena] == caracteres[indiceCaracteres]){
                deberiaAgregarCaracter = 0;
            }
            indiceCaracteres++;
        }

        if(deberiaAgregarCaracter){
            cadena[indiceCadenaLimpia] = cadena[indiceCadena];
            indiceCadenaLimpia++;
        }
        indiceCadena++;
    }
    cadena[indiceCadenaLimpia] = 0;

    escrituraDestino(cadena, "limpio.txt");

    return cadena;
}

void leerRecursosParaMostrar(){
    
    char temp[1024];
        FILE *f;
        f = fopen("limpio.txt", "r");
        if(f == NULL){
                printf("No se ha podido abrir el fichero...\n");
                exit(1);
        }

        while(fgets(temp, 1024, (FILE*) f)) {
        printf("<option value=\"opcion1\">\n");
        printf(temp);
        printf("</option>\n");
    }
        fclose(f);
}
