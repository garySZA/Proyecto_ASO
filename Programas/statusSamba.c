#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

char *statusSamba(){
	system("systemctl is-active smb.service > /etc/Resultado.txt");
	char temp[100];

        char *grupo;
        char *limpio;

        FILE *f;
        f = fopen("/etc/Resultado.txt", "r");
        if (f == NULL)
        {
            printf("No se ha podido encontrar el archivo... \n");
            exit(1);
        }
        while(fgets(temp, 1024, (FILE*) f)) {
            char *aux = temp;
            
            if(strstr(temp, "inactive")){
                grupo = "Inactivo";
            }else{
                grupo = "Activo";
            }
        }
        fclose(f);   
        //unlink("Resultado.txt");
        return grupo;
}

int main(){
        printf(statusSamba());
}

