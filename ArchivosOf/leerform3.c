#include <stdio.h>
#include <stdlib.h>
#include "./Libreria/milibreria.h"
#include "./Libreria/miLibreria.c"
#define MAXLEN 1024

//  BLOQUE METODOS PARA HU3

int longitud(char rec[]){
	int res= 0;
	int p1= 0;

	while(rec[p1]!='\0'){
		res=res+1;
		p1= p1+1;
	}

	return res;
}

//  FIN BLOQUE METODOS PARA HU3

// Separar: separa datos del formulario

void separar(char *cadena, char *linea, char separador)
{
    int x, y;
    
    x = 0; y = 0;
    
    while ((linea[x]) && (linea[x] != separador))
    {
	cadena[x] = linea[x];
	x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    
    y = 0;
    
    while (linea[y] = linea[x])
    {
	linea[y] = linea[x];
	y++;
	x++;
    }

}

int main(void)
{
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char mensaje[80];
    char usuario[80];
    char clave[80];
    char shell[80];


    printf ("Content-type:text/html\n\n");
    printf("<head>\n");
    printf("<TITLE>Response</TITLE>\n");

    printf("<link href=\"https://fonts.googleapis.com/css2?family=Play&family=Source+Sans+Pro:ital,wght@0,400;1,300&display=swap\" rel=\"stylesheet\">\n");
    printf("<style>\n");
    printf("body{background: #355C7D;  /* fallback for old browsers */background: -webkit-linear-gradient(to right, #C06C84, #6C5B7B, #355C7D);  /* Chrome 10-25, Safari 5.1-6 */background: linear-gradient(to right, #C06C84, #6C5B7B, #355C7D); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */color: silver;font-family: 'Play', sans-serif;}\n");
    printf(".container { display: flex;justify-content: center;background: transparent;margin: 15px;}\n");
    printf(".container-renombrar {width: 800px;border: solid silver;display: flex;flex-direction: column;justify-content: center;align-items: center;}\n");
    printf(".boton {border: #0096c7 solid;width: 200px;height: 40px;border-radius: 10px;transition: .8s;margin: 15px;}\n");
    printf(".boton:hover {background-color: #0096c7;color: cornsilk;}\n");
    printf("</style>\n");
    printf("</head>\n");
    lenstr = getenv("CONTENT_LENGTH");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
    if (lenstr!= NULL)
    {
	contentLength = atoi(lenstr);   
    }
    else contentLength = 0;

    if (contentLength > sizeof(inputBuffer)-1)
	contentLength = sizeof(inputBuffer)-1;

    i = 0;

    while (i < contentLength){

	x = fgetc(stdin);
	if (x==EOF) break;
	inputBuffer[i] = x;
	i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;


    separar(mensaje, inputBuffer, '=');
    separar(mensaje, inputBuffer, '&');
    
    printf("<div class=\"container\">\n");
    printf("<div class=\"container-renombrar\">\n");
    
    printf("<br>Cambio realizado:");
    printf("<p> Nuevo grupo de trabajo: %s",mensaje);
    printf("<br/>");

    printf("<div class=\"position-fixed\">\n");
    printf("<button class=\"boton\" onclick=\"location.href='./index'\">Volver</button>\n");
    printf("</div>\n");

    printf("</div>\n");
    printf("</div>\n");
    
    //  BLOQUE MAIN METODO PARA HU3

    FILE * flujo = fopen("smb.conf", "r");
	if(flujo == NULL){
		
		perror("Error en la apertura del archivo");
		return 1;
		
	}
	
	char ng[20]= "DIEGO";
	char grup[20];
	char car;
	char cad1[2048];
	int pos1= 0;
	int tam1= 0;
	int enc= 0;
	int bcar1= 1;
	int enc2= 0;
	int bfin= 0;
	int bcat= 0;
	char nueGrup[20]= " ";

	strcat(nueGrup,ng);

	while (feof(flujo)==0){	
		car= fgetc(flujo);

		//cadena1
		if(bcar1==1){
		cad1[pos1]= car;

		if(car=='='){
			enc= 1;
			bcat= 1;
		}

		if(bcat==1){
			strcat(cad1,nueGrup);
			bcat=0;
			bcar1= 0;
			bfin= 1;
			}

		pos1= pos1+1;
		tam1= tam1+1;
		//fin cadena1

		}else{
		//cadena1
		    
			if(car=='p' && bfin==1){
				enc2= 1;
				char salto[3]= "\n	";
				strcat(cad1,salto);
				pos1= pos1+2+longitud(nueGrup);
				bfin= 0;

			}

			if(enc2==1){
				cad1[pos1]= car;
				tam1= tam1+1;
				pos1= pos1+1;
			}
		}


	}
	
	fclose(flujo);

	cad1[tam1+7]= '\0';

	printf("\n%s\n",cad1);


	//Escribimos en el archivo de configuración
	
	FILE * escrito = fopen("smb.conf", "w");
        if(escrito == NULL){

                perror("Error en la apertura del archivo");
                return 1;

        }

	fputs(cad1,escrito);

	fflush(escrito);
	fclose(escrito);

    //  FIN BLOQUE MAIN METODO PARA HU3
    
    return 0;
}