#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

void criartabuleiro(FILE *fpIn, FILE *fpOut);
int **criarmatriz(int **tabuleiro, int li, int ci, int *verticecounter, int **matrizadj, int salas, int l1i, int c1i);
int salascounters(int **tabuleiro, int *id, int li, int ci);

#endif /* HEADER_H_INCLUDED */