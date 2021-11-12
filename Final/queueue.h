#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

void PQinit(int sala, int *queue, int qsize, int *queueaux);
void PQinsert(int vertice, int *queue, int *wt, int qsize, int *queueaux, int w);
int IsEmpty();
int PQdelmin(int *queue, int *wt, int *queueaux);
void FixUp(int *Heap, int Idx, int *wt, int *queueuaux, int w);
int retirarsolucao(int salachegada, int *wt, int *st);
void caminho(Grafo *G, int salachegada, int *wt, int *st, FILE *fpOut);
void FixDown(int Heap[], int Idx, int N, int *wt, int *queueaux);
void freeGraph(Grafo *G);

#endif /* HEADER_H_INCLUDED */