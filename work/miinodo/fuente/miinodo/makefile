# %W%
COMPILADOR=gcc
# Se agregan los nuevos fuentes y el módulo de tipo de archivo
FUENTE = miinodo.c stub.c tipo_archivo.c
OBJS=$(FUENTE:.c=.o)
# Se incluyen los encabezados necesarios
HEADER=miinodo.h tipo_archivo.h
PROG= $(RUTA_BIN)miinodo

# Objetivo principal que realiza el enlace (link)
CC: $(OBJS)
	$(COMPILADOR) $(OBJS) -lm -o $(PROG)
	@- echo "Compilación terminada"

LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado"

BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado"

# Regla de sufijo: convierte automáticamente cualquier .c en .o
.c.o:
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o

# Dependencias de los objetos respecto a los encabezados
$(OBJS): $(RUTA_INCL)miinodo.h $(RUTA_INCL)tipo_archivo.h