#include "miinodo.h"
#include <string.h>

int miinodo(char *nombre,char *archivo)
{
	struct dirent *entradadirectorio;
	DIR *directorio;
	/* El directorio se abre */
	if((directorio=opendir(nombre))==NULL)
	{
		fprintf(stderr,"\a No pude abrir el directorio %s ",nombre);
		perror("\n");
		return(-1); /* Error y salir */
	}
	/* Se recorre el directorio */
	while(entradadirectorio=readdir(directorio))
		if(entradadirectorio->d_ino!=0)
			if(!strncmp(archivo,entradadirectorio->d_name,strlen(archivo)))
				return(entradadirectorio->d_ino);
	if(closedir(directorio)==-1)
	{
		fprintf(stderr,"\a No pude cerrar el directorio %s ",nombre);
		perror("\n");
		return(-1); /* Error y salir */
	}
	return(0); /* Salida normal */
}

