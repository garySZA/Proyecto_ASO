#!/bin/bash

#      BLOQUE DE COMPILACION

gcc index.c -o index
gcc leerform7.c -o leerform7
gcc leerform8.c -o leerform8

#      BLOQUE QUE OTORGA PERMISOS A LOS EJECUTABLES

chmod ugo+s index
chmod ugo+s leerform7
chmod ugo+s leerform8

#      BLOQUE ENCARGADO DE MOVER LOS EJECUTABLES A DESTINO YA CON PERMISOS LISTOS PARA SER UTILIZADOS 

mv index /home/garys/Desktop/
mv leerform7 /home/garys/Desktop/
mv leerform8 /home/garys/Desktop/


#       despues de ejecutarse ese script con permisos "chmod ugo+x" deberia dejar todo listo para utilizar desde el navegador