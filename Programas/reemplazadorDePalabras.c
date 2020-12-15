#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  //buffer[p-str] = '\0'; NO HACE FALTA
  
char aux[strlen(p+strlen(orig))+1]; 
strcpy(aux, p+strlen(orig)); //Lo guardamos para que sprintf no lo machaque si rep es más largo que orig

sprintf(buffer+(p-str), "%s%s", rep, aux);
  
  return replace_str(buffer, orig, rep);
}

int main(void)
{
  puts(replace_str("hola%2Fcd", "%2F", "/"));
  char *aux = replace_str("hola%2Fcd", "%2F", "/");
  printf(aux);
  return 0;
}