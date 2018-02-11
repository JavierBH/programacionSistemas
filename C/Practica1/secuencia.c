#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#define MAX_OUTPUT 100


int main ( int argc, char *argv[] )
{
   double hasta = 10, desde = 1, paso = 1, output; 
   char *ptr;

//Comprobación del numero de argumentos
if (argc >4 ){
fprintf(stderr,"%s: Error(EX_NOINPUT), uso incorrecto del mandato. \"Success\" \n", argv[0]);
fprintf(stderr,"%s: El número de argumentos no es correcto.\n", argv[0]);
 return EX_USAGE; 
}

//Comprobación del mandato de ayuda
if(argc == 2 && (strcmp (argv[1], "-h") == 0 || (strcmp (argv[1], "--help") == 0))){
      		printf ("%s: Uso: secuencia[ hasta [ desde [ paso ]]]\n", argv[0]);
      		printf ("%s: Genera la secuencia de números en el intervalo y paso indicados.\n", argv[0]);
      		return EX_OK;
   	}

   if (argc == 1){

// Imprimir Numeros
       while (desde<=hasta){
           printf("\t%g\n",desde);
           desde++;
       }
       return EX_OK;
   }

 
   if (argc == 2){

//Declarar variables
hasta = strtod(argv[1], &ptr);

// Imprimir Numeros       
	 while (desde<=hasta){
//Comprobación de errores
if (desde > MAX_OUTPUT){
fprintf(stderr,"%s: Error(EX_NOPERM), uso incorrecto del mandato. \"Success\" \n", argv[0]);
fprintf(stderr,"%s+ Se intento superar el limite de la salida.\n", argv[0]); 
return EX_NOPERM;
}
           printf("\t%g\n",desde);
           desde++;
       }
return EX_OK;
   }




if (argc == 3){

//Declarar variables

       hasta = strtod(argv[1], &ptr);
	desde = strtod(argv[2], &ptr);


// Imprimir Numeros
	 while (desde<=hasta){

//Comprobación de errores
if (desde > MAX_OUTPUT){
fprintf(stderr,"%s: Error(EX_NOPERM), uso incorrecto del mandato. \"Success\" \n", argv[0]);
fprintf(stderr,"%s+ Se intento superar el limite de la salida.\n", argv[0]); 
return EX_NOPERM;
}
           printf("\t%g\n",desde);
           desde++;
       }
return EX_OK;
   }



	if(argc == 4){
//Declarar variables
	hasta = strtod(argv[1], &ptr);
	 desde = strtod(argv[2], &ptr);	
	  paso = strtod(argv[3], &ptr);
/*
fprintf (stderr,"%s: Error(EX_OSERR), uso incorrecto del mandato. \"Success\" \n", argv[0]);
               				fprintf(stderr,"%s+.*Error en la asignacion de memoría.\n", argv[0]);
*/

//Comprobación de errores
if (paso == 0){
fprintf(stderr,"%s+.* Error(EX_USAGE), uso incorrecto del mandato. \"Success\" \n", argv[0]);
fprintf(stderr,"%s+ El valor del paso es 0.\n", argv[0]); 
 return EX_USAGE;
}
if ((desde < hasta) && (paso<0)){
fprintf(stderr,"%s+.* Error(EX_USAGE), uso incorrecto del mandato. \"Success\" \n", argv[0]);
fprintf(stderr,"%s+ El signo de paso no permite recorrer el itervalo.\n", argv[0]); 
return EX_USAGE;
}

if ((desde > hasta)&& (paso>0)){
fprintf(stderr,"%s+.* Error(EX_USAGE), uso incorrecto del mandato. \"Success\" \n", argv[0]);
fprintf(stderr,"%s+ El signo de paso no permite recorrer el itervalo.\n", argv[0]); 
return EX_USAGE;
}

// Imprimir Numeros
	
	   if (desde <= hasta){

	  while (desde<= hasta){

//Comprobación de errores
	if (desde > MAX_OUTPUT){
	fprintf(stderr,"%s: Error(EX_NOPERM), uso incorrecto del mandato. \"Success\" \n", argv[0]);
	fprintf(stderr,"%s+ Se intento superar el limite de la salida .\n", argv[0]); 
	return EX_NOPERM;
	}
           printf("\t%g\n", desde);
           desde = desde + paso;
	}
}

else{

  while (desde>=hasta){

//Comprobación de errores
if (desde > MAX_OUTPUT){
fprintf(stderr,"%s: Error(EX_NOPERM), uso incorrecto del mandato. \"Success\" \n", argv[0]);
fprintf(stderr,"%s+ Se intento superar el limite de la salida .\n", argv[0]); 
return EX_NOPERM;
}
           printf("\t%g\n", desde);
           desde = desde + paso;

       }

}
    return EX_OK;
}
}
