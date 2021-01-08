#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// Comando para generar estado del servidor cada cierto tiempo
//  watch -n 300 "rpm -qa | grep samba > estadoSamba.txt"

void lector();
char *verifInstalado();

char *verifInstalado(){
        lector();
        char temp[100];
        FILE *f;
        f = fopen("estadoSamba.txt", "r");
        if(f == NULL){
                printf("No se ha podido abrir el fichero...2\n");
                exit(1);
        }

        while(!feof(f)){
                char *instalado = "samba";
                fgets(temp, 50, f);
                if(strstr(temp, instalado) > 0){
                       // printf("Instalado");
			return "Instalado";
                }else{
                        //printf("No instalado");
			return "No instalado";
                }
        }
	fclose(f);
	//return 0;
}

void lector(){
        system("rpm -qa | grep samba > estadoSamba.txt");
}

int main(){
        printf(verifInstalado());
}