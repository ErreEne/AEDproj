#ifndef PQFUNC
#define PQFUNC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

void PQinsert(int vertice, int *queue, int *wt, int qsize, int *queueaux, int w, int espaco);
int IsEmpty(int espaco);
int PQdelmin(int *queue, int *wt, int *queueaux, int espaco);
void FixUp(int *Heap, int Idx, int *wt, int *queueuaux, int w);
void FixDown(int Heap[], int Idx, int N, int *wt, int *queueaux);

#endif /* HEADER_H_INCLUDED */