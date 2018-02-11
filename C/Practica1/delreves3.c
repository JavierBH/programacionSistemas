#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#define maximo 2049

int main ( int argc, char *argv[]){
	int i,j,t;
    	char buffer [maximo];
    	char inverso [maximo];
    	FILE *file;

	if (argc == 1){
		fgets(buffer, maximo, stdin);
		j=0;
		for (i=strlen(buffer)-2; i>=0; i--){
        		inverso[j] = buffer[i];
        		j++;
        	}

		fputs(inverso, stdout); 
		fputs("\n", stdout);
		return EX_OK; 	
	}else if(argc == 2 && (strcmp (argv[1], "-h") == 0 || (strcmp (argv[1], "--help") == 0))){
      		printf ("%s: Uso: delreves [fichero...]\n", argv[0]);
      		printf ("%s: Invierte el orden de las l lineas de los ficheros (o de la entrada).\n", argv[0]);
      		return EX_OK;
   	}else{
    		for (t = 1; t < argc ; t++){
        		file = fopen(argv[t], "r");
			if(file == NULL){
				fprintf(stderr,"%s: Error(EX_NOINPUT), uso incorrecto del mandato. \"Success\" \n", argv[0]);
				fprintf(stderr,"delreves+ no se pudo leer el archivo o no existe.\n");
				return EX_NOINPUT;
			}

			memset(buffer, 0, maximo);
    			while(fgets(buffer, maximo, file)!=NULL){
				memset(inverso, 0, maximo);
				j=0;
    				for (i=strlen(buffer)-2; i>=0; i--){
        				inverso[j] = buffer[i];
        				j++;
        			}  
				fputs(inverso, stdout);
				fputs("\n",stdout);			  	
    			}
			fclose(file); 			
    		}		
    	return EX_OK;
	}   
}
