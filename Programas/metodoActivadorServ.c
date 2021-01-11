#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

void procederA(char *accion){
    if(strcmp(accion, "activar")){
        system("service smb start");
    }else{
        system("service smb stop");
    }
}