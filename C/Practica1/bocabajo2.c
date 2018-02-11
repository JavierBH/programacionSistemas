#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

#define maximo 2049

int main ( int argc, char *argv[]){
    	int i,j,t, nlineas;
        char buffer [maximo];
        FILE *file;
    	char **ptr;
    	
	if (argc == 1){
   		i = 0;
            	nlineas = 1;
            	ptr = (char **)malloc(sizeof (char *)*nlineas);
                while(fgets(buffer, maximo, stdin)){   
                	ptr = (char**)realloc(ptr,sizeof(char *)*nlineas);
			if(ptr == NULL) {
				fprintf (stderr,"%s: Error(EX_OSERR), uso incorrecto del mandato. \"Success\" \n", argv[0]);
               			fprintf(stderr,"%s+.*Error en la asignacion de memoría.\n", argv[0]);
              			return EX_OSERR;
			}
                	ptr[i] = strdup (buffer);   
                	i++;
                	nlineas++;
            	}
            	for(j = 0; j < i; j++){
               		fputs(ptr[i-j-1], stdout);
            	}
		for(j = 0; j < i; j++){
			free(ptr[j]);
		}
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
               			fprintf(stderr,"%s+.*no se pudo leer el archivo o no existe.\n", argv[0]);
                		return EX_NOINPUT;
            		}
            		i = 0;
            		nlineas = 1;
            		ptr = (char **)malloc(sizeof (char *));
                	while(fgets(buffer, maximo, file)){   
                		ptr = (char**)realloc(ptr,sizeof(char *)*nlineas);
				if(ptr == NULL){ 
              		  		fprintf (stderr,"%s: Error(EX_OSERR), uso incorrecto del mandato. \"Success\" \n", argv[0]);
               				fprintf(stderr,"%s+.*Error en la asignacion de memoría.\n", argv[0]);
              				return EX_OSERR;
				}
                		ptr[i] = strdup (buffer);   
                		i++;
                		nlineas++;
            		}
            		fclose(file);
            		for(j = 0; j < i; j++){
            	   		fputs(ptr[i-j-1], stdout);
            		}
			for(j = 0; j <= i; j++){
				free(ptr[j]);
			}   

            	}
		return EX_OK;
	}
}
