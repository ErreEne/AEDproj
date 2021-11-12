#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

typedef struct grafo Grafo;
Grafo *criargarph(int salas, Grafo *estr);
void montargraph(Grafo *estr, int salas, int vertice1, int vertice2);
void grafonightmare(Grafo *estr, int salas, int **tabuleiro, int li, int ci);
void criarligacao(Grafo *estr, int vertice1, int vertice2, int custo, int linha, int coluna);
int compareItems(int it1, int it2);
void GRAPHpfs(Grafo *G, int salachegada, FILE *fpOut);
void grafotime(int salas, int **tabuleiro, int li, int ci, int salachegada, FILE *fpOut);

#endif /* HEADER_H_INCLUDED */