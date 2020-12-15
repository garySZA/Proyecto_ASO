#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"

//Metodos utilizados para la generacion de la lista de recursos
void extraer(char *doc, char *dest, char *cadena_a_Buscar);
void escrituraDestino(char *cad, char *dest);
void quitarCorchetes();
char *removerCaracteres(char *cadena, char *caracteres);
void leerRecursosParaMostrar();
//

//      METODOS PARA HU6
void leerRecursosParaMostrarHTML(char *documento);

int main(){
    /*
            BLOQUE ENCARGADO DE MOSTRAR LISTA DE RECURSOS
    */

    //con este metodo extraigo los nombres de los recursos compartidos(por defecto en el siguiente formato>[nombreRecurso])
    //como primer parametro esta el origen de donde se va obtener
    //segundo parametro es donde se va almacenar los nombres
    //tercer parametro: hace la busqueda fila por fila al que contenda '['
    extraer("smb.conf", "listaSucia.txt", "[");

    //luego empezamos a quitar los corchetes con el sig metodo
    //este metodo emplea al metodo remover caracteres que se encarga de quitar los corchetes y almacenar los nombres en un archivo llamado limpio.txt
    quitarCorchetes();

    //una vez que se tienen los nombres de los recursos listos para mostrar procedemos a ponerlos en formato html con el sig metodo.
    //leerRecursosParaMostrar();

    //Generar rutas de los recursos
    //reemplazar ruta smb.conf aqui
    extraerHU6("smb.conf", "rutas.txt","path");

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
    //      BLOQUE ESTILOS
    printf("<style>\n");
    printf("body{background: #355C7D;  /* fallback for old browsers */background: -webkit-linear-gradient(to right, #C06C84, #6C5B7B, #355C7D);  /* Chrome 10-25, Safari 5.1-6 */background: linear-gradient(to right, #C06C84, #6C5B7B, #355C7D); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */color: silver;font-family: 'Play', sans-serif;}\n");
    printf(".container { display: flex;justify-content: center;background: transparent;margin: 15px;}\n");
    printf(".container-elementos {display: grid;grid-template-columns: repeat(2, 1fr);grid-template-rows: repeat(2, 1fr);column-gap: 50px;row-gap: 10px;}\n");
    printf(".container-elementos-reducidos{display: grid;grid-template-columns: repeat(2, 1fr);grid-template-rows: repeat(1, 1fr);column-gap: 50px;row-gap: 10px;}\n");
    printf(".campo {justify-content: center;align-items: center;}\n");
    printf(".bton {display: flex;}\n");
    printf(".opcion {margin-top: 15px;}\n");
    printf("#combo, .input{width: 200px;border: solid #0096c7;}\n");
    printf(".container-titulo {display: flex;justify-content: center;}\n");
    printf(".boton {border: #0096c7 solid;width: 200px;height: 40px;border-radius: 10px;transition: .8s;margin: 15px;}\n");
    printf(".boton:hover {background-color: #0096c7;color: cornsilk;}\n");
    printf(".container-renombrar {width: 800px;border: solid silver;display: flex;flex-direction: column;justify-content: center;align-items: center;}\n");
    printf(".contenedor-ruta, .contenedor-nombre{display: flex;flex-direction: column;width: 200px;}\n");
    printf(".contenedor-nombre-ruta {width: 60%; height: 150px;border: 2px dotted #000;background-color: transparent;overflow: auto;display: flex;}\n");
    printf(".parrafo {height: 15px;margin: 5px;border-bottom: solid silver 2px;padding: 2px;}\n");
    printf("</style>\n");
    //      FIN BLOQUE ESTILOS

    printf("</head>\n");
    printf("<body>");

    //  INICIO FORM HU6

    printf("<form action=\"/cgi-bin/leerform6\" method=\"POST\">\n");
    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");
    printf("<div class=\"container-titulo\">\n");
    printf("<h3> Modificar recurso compartido </h3>\n");
    printf("</div>\n");
    printf("<div class=\"contenedor-nombre-ruta\">\n");
    printf("<div class=\"contenedor-nombre\">\n");

    //aqui entra los nombres de los recursos, llamar a metodo aqui
    leerRecursosParaMostrarHTML("limpio.txt");

    printf("</div>\n");
    printf("<div class=\"contenedor-ruta\">\n");

    //aqui entran las rutas de los recursos, llamar a metodo aqui
    leerRecursosParaMostrarHTML("rutas.txt");
    
    printf("</div>\n");
    printf("</div>\n");
    printf("<div class=\"container-elementos\">\n");
    printf("<div class=\"campo\">\n");
    printf("<h3> Seleccionar recurso compartido: </h3>\n");
    printf("</div>\n");
    printf("<div class=\"campo opcion\">\n");
    printf("<select name=\"recursos\" id=\"combo\">\n");
    printf("<option value="" selected=\"selected\"> -Selecciona-</option>\n");
    printf("<option value=\"lectura\"> Solo lectura </option> </option>\n");
    printf("<option value=\"ambos\"> Lectura y escritura </option>\n");
    printf("</select>\n");
    printf("</div>\n");
    printf("<div class=\"campo\">\n");
    printf("<h3> Ingresar nueva ruta: </h3>\n");
    printf("</div>\n");
    printf("<div class=\"campo opcion\">\n");
    printf("<input class=\"input\" type=\"text\" name=\"nombre\" value=\"\" placeholder=\"Nueva ruta\"/>\n");
    printf("</div>\n");
    printf("</div>\n");
    printf("<div class=\"campo bton\">\n");
    printf("<input type=\"submit\" name=\"enviar\" value=\"Guardar cambios\" class=\"boton\"/>\n");
    printf("</div>\n");
    printf("</div>\n");
    printf("</div>\n");
    printf("</form>\n");

    //  FIN FORM HU6

    //  INICIO FORM HU7

    printf("<form action=\"/cgi-bin/leerform7\" method=\"POST\">\n");
    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");
    printf("<div class=\"container-titulo\">\n");
    printf("<h3> Borrar recurso compartido </h3>\n");
    printf("</div>\n");
    printf("<div class=\"container-elementos container-elementos-reducidos\">\n");
    printf("<div class=\"campo\">\n");
    printf("<h3> Seleccionar recurso compartido: </h3>\n");
    printf("</div>\n");
    printf("<div class=\"campo opcion\">\n");
    printf("<select name=\"recursos\" id=\"combo\">\n");
    printf("<option value="" selected=\"selected\"> -Selecciona-</option>\n");
    leerRecursosParaMostrar();
    printf("</select>\n");
    printf("</div>\n");
    printf("</div>\n");
    printf("<div class=\"campo bton\">\n");
    printf("<input type=\"submit\" name=\"enviar\" value=\"Borrar\" class=\"boton\"/>\n");
    printf("</div>\n");
    printf("</div>\n");
    printf("</div>\n");
    printf("</form>\n");
    

    //  FIN FORM HU7

    // INICIO FORM HU8

    printf("<form action=\"/cgi-bin/leerform8\" method=\"POST\">");
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
    printf("<option value=\"\" selected=\"selected\"> -Selecciona-</option>");
    leerRecursosParaMostrar();
    printf("</select>");
    printf("</div>");
    printf("<div class=\"campo\">");
    printf("<h3> Ingresar nuevo nombre: </h3>");
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

    //  FIN FORM HU8

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
            char res[100] = "<option value=\"";
            strcat(res,temp);
            strcat(res,"\">\n");
            printf(res);
            printf(temp);
            printf("</option>\n");
    }
        fclose(f);
}

//      METODOS PARA HU6
void leerRecursosParaMostrarHTML(char *documento){
    char temp[1024];
        FILE *f;
        f = fopen(documento, "r");
        if(f == NULL){
                printf("No se ha podido abrir el fichero...\n");
                exit(1);
        }

        while(fgets(temp, 1024, (FILE*) f)) {
            char res[100] = " <p class=\"parrafo\">";
            strcat(res,temp);
            strcat(res, "</option>\n");
            //printf("</option>\n");
            printf(res);

        //printf("<option value=\"opcion1\">\n");
    }
        fclose(f);
}