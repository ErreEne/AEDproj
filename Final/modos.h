#ifndef FUNCAUX_HEADER
#define FUNCAUX_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "defs.h"

int vertipo(int **tabuleiro, int l1i, int c1i, int li, int ci);
int procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3]);
int *soupintor(int **tabela, int li, int ci, int *id);
int quebravel(int **tabuleiro, int l1i, int c1i, int li, int ci);
int salascounters(int **tabuleiro, int *id, int li, int ci);

#endif /* HEADER_H_INCLUDED */