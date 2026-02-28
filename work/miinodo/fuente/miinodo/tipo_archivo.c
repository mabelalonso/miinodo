#include "tipo_archivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void imprimir_nombre_con_tipo(const char *ruta_dir, const char *nombre_archivo) {
    char ruta_completa[1024];
    // Construimos la ruta completa para que lstat pueda encontrar el archivo
    snprintf(ruta_completa, sizeof(ruta_completa), "%s/%s", ruta_dir, nombre_archivo);

    struct stat info_archivo;

    // Si lstat falla, solo imprimimos el nombre normal
    if (lstat(ruta_completa, &info_archivo) == -1) {
        printf("%s", nombre_archivo);
        return;
    }

    printf("%s", nombre_archivo);

    // Evaluamos los macros de sys/stat.h para agregar el sufijo correspondiente
    if (S_ISDIR(info_archivo.st_mode)) {
        printf("/");
    } else if (S_ISLNK(info_archivo.st_mode)) {
        printf("->");
    } else if (S_ISBLK(info_archivo.st_mode)) {
        printf("*b");
    } else if (S_ISCHR(info_archivo.st_mode)) {
        printf("*c");
    } else if (S_ISREG(info_archivo.st_mode) && (info_archivo.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))) {
        printf("*"); // Es un archivo regular y tiene permisos de ejecución
    }
}