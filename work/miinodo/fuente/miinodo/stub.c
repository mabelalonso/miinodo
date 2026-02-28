#include "miinodo.h"
#include "tipo_archivo.h"

int main(int argc,char **argv)
{
    ino_t inodo;
    /* Validar argumentos */
    if(argc!=3)
    {
        fprintf(stderr,"Uso:\n");
        fprintf(stderr,"%s directorio archivo\n", argv[0]);
        exit(1);
    }

    /* Buscar inodo en el directorio */
    if((inodo=miinodo(argv[1],argv[2]))==-1)
    {
        fprintf(stderr,"Fallo miinodo\n");
        exit(2);
    }
    else if(inodo)
    {
        printf("El inodo de ");
        // Usamos el nuevo módulo para imprimir el nombre con su indicador
        imprimir_nombre_con_tipo(argv[1], argv[2]);
        printf(" es %lu\n", (unsigned long)inodo);
    }
    else
        printf("El archivo %s no se encuentra en el directorio %s\n",argv[2],argv[1]);

    return(0);
}