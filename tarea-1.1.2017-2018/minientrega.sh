# /bin/bash
#comprobar el numero de argumentos
if [ $# -ne "1" ]; then
    echo "$0: Error (EX_USAGE), uso incorrecto del mandato. \"Succes\"" >&2
    echo "$0+ El numero de argumentos recibidos no es el esperado" >&2
    exit 64
fi

# comprobar si pide ayuda

    if [ $1 == '-h' -o $1 == '--help' ]; then
        echo "$0:-h/--help para la ayuda" 
        echo "$0+ Copia archivos los ficheros de un directorio de usuario a otro" 
        exit 0
    fi

# Comprobar que existe MINIENTREGA_CONF

if test -z ${MINIENTREGA_CONF}; then
echo "$0 : Error, no se pudo realizar la entrega">&2
echo "$0 + No es accesible el directorio ">&2
exit 64;
fi

# comprobar la variable MINIENTREGA_CONF es un directorio

if  test ! -d ${MINIENTREGA_CONF}; then
echo "$0 : Error, no se pudo realizar la entrega">&2
echo "$0+ No es un directorio directorio ">&2
exit 64;
fi

#Comprobar que la variable MINIENTREGA_CONF tiene permiso de lectura

if test ! -r ${MINIENTREGA_CONF}; then
echo "$0 : Error, no se pudo realizar la entrega" >&2
echo "$0+ no se puede leer el directorio ">&2
exit 64;
fi

#Comprobar que se puede escribir en dicho directorio
if test ! -w ${MINIENTREGA_CONF}; then
echo "$0 : Error, no se pudo realizar la entrega">&2
echo "$0+ no se puede escribir en el directorio ">&2
exit 64;
fi

#Comprueba que se puede leer el argumento 
if test ! -r ${MINIENTREGA_CONF}/$1; then
echo "$0 : Error, no se pudo realizar la entrega">&2
echo "$0+ no se puede acceder al fichero $1 ">&2
exit 66;
fi 

source ${MINIENTREGA_CONF}/$1

#Comprobacion de que la fecha este en el formato correcto

if [ ${#MINIENTREGA_FECHALIMITE} -ne 10 ]; then
 echo "$0: Error, no se puedo realizar la entrega">&2
 echo "$0: Fecha incorrecta ${MINIENREGA_FECHALIMITE}">&2
exit 65;
fi

if ! [[  ${MINIENTREGA_FECHALIMITE:4:1} == '-'  && ${MINIENTREGA_FECHALIMITE:7:1} == '-' ]]; then 
 echo "$0: Error, no se puedo realizar la entrega">&2
 echo "$0: Fecha incorrecta ${MINIENTREGA_FECHALIMITE}">&2
exit 65;
fi

if [ ${MINIENTREGA_FECHALIMITE:0:4} -gt 2100 ]; then
 echo " $0: Error, no se puedo realizar la entrega">&2
 echo "$0: Entrega fuera de plazo">&2
exit 65;
fi

if [ ${MINIENTREGA_FECHALIMITE:0:4} -gt 2100 -a ${MINIENTREGA_FECHALIMITE:5:2} -ne 01 ]; then
echo " $0: Error, no se puedo realizar la entrega">&2
echo "$0: Entrega fuera de plazo">&2
exit 65;
fi

if [ ${MINIENTREGA_FECHALIMITE:0:4} -gt 2100 -a ${MINIENTREGA_FECHALIMITE:7:2} -ne 01 ]; then
echo " $0: Error, no se puedo realizar la entrega">&2
echo "$0: Entrega fuera de plazo">&2
exit 65;
fi

#Comprobamos los archivos 
for fichero in ${MINIENTREGA_FICHEROS[0]}; do
if !(test -r $fichero) || !(test -e $fichero); then
 echo " $0: Error, no se puedo realizar la entrega">&2
 echo "$0: No es accesible el fichero $fichero">&2
exit 66;
fi
done

#Existe el directorio de destino
if test ! -d ${MINIENTREGA_DESTINO} || test ! -w ${MINIENTREGA_DESTINO};then
 echo " $0: Error, no se puedo realizar la entrega">&2
 echo "$0: No se pudo crear el subdirectorio de entrega en ${MINIENTREGA_DESTINO} ">&2
exit 73;
fi

#copiar archivos
cp ${MINIENTREGA_FICHEROS}/* ${MINIENTREGA_DESTINO}/${USER} 
exit 0
