#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* Funções no modos.c */
int A1(int **tabuleiro, int l1i, int c1i, int li, int ci);
int procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3]);
int A6(int **tabela, int li, int ci, int l1i, int c1i, int l2i, int c2i);

/*Funções no tabuleiro.c*/
void modosDeJogo(FILE *fpIn, FILE *fpOut);
int *arrayNSWE(int **tabuleiro, int li, int ci, int c1i, int l1i);

#endif /* HEADER_H_INCLUDED */