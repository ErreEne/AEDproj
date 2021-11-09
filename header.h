#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

/* Funções no modos.c */
int A1(int **tabuleiro, int l1i, int c1i, int li, int ci);
int procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3]);
int *soupintor(int **tabela, int li, int ci, int *id);
int quebravel(int **tabuleiro, int l1i, int c1i, int li, int ci);
int contarsalas(int *id, int li, int ci, int **tabela);

/*Funções no tabuleiro.c*/
void modosDeJogo(FILE *fpIn, FILE *fpOut);
int **criarmatriz(int **tabuleiro, int li, int ci, int *verticecounter, int **matrizadj, int salas, int l1i, int c1i);

/*Funções do socorro.c*/
typedef struct grafo Grafo;
Grafo *criargarph(int salas, Grafo *estr);
void montargraph(Grafo *estr, int salas, int vertice1, int vertice2);
void grafonightmare(Grafo *estr, int salas, int **tabuleiro, int li, int ci);
void criarligacao(Grafo *estr, int vertice1, int vertice2, int custo);
int compareItems(int it1, int it2);

/*Funções Algoritmo Dijkstra*/
void GRAPHpfs(Grafo *G, int s, int st[], int wt[], int *queue, int espaco);

/*Funções da fila*/
void PQinit(int sala);
void PQinsert(int vertice, int *queue, int espaco, int *wt);
int IsEmpty();
int PQdelmin(int *queue, int espaco, int *wt);
void FixUp(int Heap[], int Idx, int *wt);

#endif /* HEADER_H_INCLUDED */
