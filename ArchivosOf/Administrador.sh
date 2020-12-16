#!/bin/bash

#      BLOQUE DE COMPILACION

gcc index.c -o index
gcc leerform5.c -o leerform5
gcc leerform6.c -o leerform6
gcc leerform7.c -o leerform7
gcc leerform8.c -o leerform8

#      BLOQUE QUE OTORGA PERMISOS A LOS EJECUTABLES

chmod ugo+s index
chmod ugo+s leerform5
chmod ugo+s leerform6
chmod ugo+s leerform7
chmod ugo+s leerform8

#      BLOQUE ENCARGADO DE MOVER LOS EJECUTABLES A DESTINO YA CON PERMISOS LISTOS PARA SER UTILIZADOS 

mv index /srv/www/cgi-bin/
mv leerform5 /srv/www/cgi-bin/
mv leerform6 /srv/www/cgi-bin/
mv leerform7 /srv/www/cgi-bin/
mv leerform8 /srv/www/cgi-bin/

#       COPIADO DE LA LIBRERIA

cp -r Libreria/ /srv/www/cgi-bin/

#       despues de ejecutarse ese script con permisos "chmod ugo+x" deberia dejar todo listo para utilizar desde el navegador