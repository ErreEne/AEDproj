#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "defs.h"

static int *queuevertice;
static int espaco; /* primeira posição livre */
static int qsize;
static int *queuecusto;

/* tamanho da tabela */

void PQinit(int sala, int *queuevertice, int *queuecusto, int qsize, int espaco)
{

    queuevertice = (int *)calloc(sala, sizeof(int));
    queuecusto = (int *)calloc(sala, sizeof(int));
    if (queuevertice == NULL || queuecusto == NULL)
        exit(-1);
    qsize = sala;
    espaco = 0;
}

void PQinsert(int vertice, int *queue, int espaco, int *wt)
{
    /* insere novo elemento no fim e restabelece ordenação com FixUp */
    if ((espaco + 1) < qsize)
    {
        queue[espaco] = vertice;
        FixUp(queue, espaco, wt);
        espaco++;
    }
}

int IsEmpty(int espaco)
{

    if (espaco == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*int PQdelmin()
{
    int Idx, Min, aux;

    for (Idx = 1, Min = 0; Idx < espaco; Idx++)
        if (queue[Min] > queue[Idx])
            Min = Idx;

    aux = queue[Min];
    queue[Min] = queue[espaco - 1];
    queue[espaco - 1] = aux;
    return (queue[--espaco]);
}
*/

void FixUp(int Heap[], int Idx, int *wt)
{
    int aux;
    while (Idx > 0 && wt[Heap[(Idx - 1) / 2]] > wt[Heap[Idx]])
    {
        aux = Heap[Idx];
        Heap[Idx] = Heap[(Idx - 1) / 2];
        Heap[(Idx - 1) / 2] = aux;
        Idx = (Idx - 1) / 2;
    }
}

void FixDown(int Heap[], int Idx, int N, int *wt)
{
    int Child, aux; /* índice de um nó descendente */
    while (2 * Idx < N - 1)
    { /* enquanto não chegar às folhas */
        Child = 2 * Idx + 1;
        /* Selecciona o maior descendente. */
        /* Nota: se índice Child é N-1, então só há um descendente */
        if (Child < (N - 1) && wt[Heap[Child]] > wt[Heap[Child + 1]])
            Child++;
        if (!(wt[Heap[Idx]] > wt[Heap[Child]]))
            break; /* condição acervo */
        /* satisfeita */
        aux = Heap[Idx];
        Heap[Idx] = Heap[Child];
        Heap[Child] = aux;
        /* continua a descer a árvore */
        Idx = Child;
    }
}

int PQdelmin(int *queue, int espaco, int *wt)
{
    int aux;
    aux = queue[0];
    queue[0] = queue[espaco - 1];
    queue[espaco - 1] = aux;

    FixDown(queue, 0, espaco - 1, wt);
    /* ultimo elemento não considerado na reordenação */
    return queue[--espaco];
}
