#include <stdio.h>

int main(){
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
    printf("<option value=\"opcion1\"> opcion1 </option>");
    printf("<option value=\"opcion1\"> opcion2 </option>");
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