#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){


	int longitud(char arec[]);

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

	//fin escritura

	return 0;

}

int longitud(char rec[]){
	int res= 0;
	int p1= 0;

	while(rec[p1]!='\0'){
		res=res+1;
		p1= p1+1;
	}

	return res;
}

