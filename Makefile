# compilador a utilizar
CC=gcc
# flags para compilar, -g para fazermos testes, O3 para otimização e O3 é o que temos de submeter
CFLAGS= -Wall -std=c11 -O3

%.o: %.c 

#Pontos .c .h
SOURCES = main.c #acrescentar o resto

OBJECTS = main.o

: prog 
prog: $(OBJECTS)
	$(CC) $(CFLAGS) -o roap $(PROJOBJECTS)

# fileManipulation.o: fileManipulation.h fileManipulation.c gameAnalisys.h
#	$(CC) -g -c fileManipulation.c

#gameAnalisys.o: defs.h gameAnalisys.h gameAnalisys.c
#	$(CC) -g -c gameAnalisys.c

#main.o: defs.h fileManipulation.h gameAnalisys.h main.c
#	$(CC) -g -c main.c

clean:
	rm -f $(OBJECTS) core roap

depend::
	makedepend $(SOURCES)




