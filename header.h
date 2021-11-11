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
void criartabuleiro(FILE *fpIn, FILE *fpOut);
int **criarmatriz(int **tabuleiro, int li, int ci, int *verticecounter, int **matrizadj, int salas, int l1i, int c1i);
int salascounters(int **tabuleiro, int *id, int li, int ci);

/*Funções do socorro.c*/
typedef struct grafo Grafo;
Grafo *criargarph(int salas, Grafo *estr);
void montargraph(Grafo *estr, int salas, int vertice1, int vertice2);
void grafonightmare(Grafo *estr, int salas, int **tabuleiro, int li, int ci);
void criarligacao(Grafo *estr, int vertice1, int vertice2, int custo, int linha, int coluna);
int compareItems(int it1, int it2);
void GRAPHpfs(Grafo *G, int salachegada, FILE *fpOut);
void grafotime(int salas, int **tabuleiro, int li, int ci, int salachegada, FILE *fpOut);

/*Funções da fila*/
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
