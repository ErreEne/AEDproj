#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

typedef struct grafo Grafo;
typedef struct LinkedListStruct LinkedList;
void GRAPHpfs(Grafo *G, int salachegada, FILE *fpOut);
int retirarsolucao(int salachegada, int *wt, int *st);
void caminho(Grafo *G, int salachegada, int *wt, int *st, FILE *fpOut);

#endif /* HEADER_H_INCLUDED */