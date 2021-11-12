#ifndef ALGORITMO_HEADER
#define ALGORITMO_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

typedef struct grafo Grafo;
typedef struct LinkedListStruct LinkedList;
void Dijkstra(Grafo *G, int salachegada, FILE *fpOut);
int retirarsolucao(int salachegada, int *wt, int *st);
void caminho(Grafo *G, int salachegada, int *wt, int *st, FILE *fpOut);

#endif /* HEADER_H_INCLUDED */