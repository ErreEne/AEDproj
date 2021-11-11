#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "defs.h"
#include "header.h"

/* tamanho da tabela */
static int espaco;

/*
 *  Função:
 *    PQinit
 *
 *  Descrição:
 *      Inicializa a fila cpm prioridade
 *
 *  Argumentos:
 *    Ponteiro para a fila: *queue e ponteiro auxiliar: *queueuaux
 *    sala, qsize
 *
 *  Retorna:
 *      void
 */

void PQinit(int sala, int *queue, int qsize, int *queueaux)
{
    espaco = 0;
    qsize = sala;
}

/*
 *  Função:
 *    PQinsert
 *
 *  Descrição:
 *      insere novo elemento no fim da fila e restabelece ordenação com FixUp
 *
 *  Argumentos:
 *    Ponteiro para a fila: *queue e ponteiro auxiliar: *queueuaux
 *    vertice, qsize, w
 *
 *  Retorna:
 *      void
 */

void PQinsert(int vertice, int *queue, int *wt, int qsize, int *queueaux, int w)
{
    if ((espaco + 1) < qsize)
    {
        queue[espaco] = vertice;
        FixUp(queue, espaco, wt, queueaux, w);
        espaco++;
    }
}

/*
 *  Função:
 *    IsEmpty
 *
 *  Descrição:
 *      Faz os testes para quando a lista está vazia
 *
 *  Argumentos:
 *    Nenhuns
 *
 *  Retorna:
 *      void
 */

int IsEmpty()
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

/*
 *  Função:
 *    FixUp
 *
 *  Descrição:
 *
 *
 *  Argumentos:
 *
 *
 *  Retorna:
 *      void
 */

void FixUp(int *Heap, int Idx, int *wt, int *queueuaux, int w)
{
    int aux;

    while (Idx > 0 && wt[Heap[(Idx - 1) / 2]] > wt[Heap[Idx]])
    {
        queueuaux[Heap[(Idx - 1) / 2]] = Idx;
        queueuaux[Heap[Idx]] = (Idx - 1) / 2;
        aux = Heap[Idx];
        Heap[Idx] = Heap[(Idx - 1) / 2];
        Heap[(Idx - 1) / 2] = aux;

        Idx = (Idx - 1) / 2;
    }
}

/*
 *  Função:
 *    FixDown
 *
 *  Descrição:
 *
 *
 *  Argumentos:
 *
 *
 *  Retorna:
 *      void
 */

void FixDown(int Heap[], int Idx, int N, int *wt, int *queueaux)
{
    int Child, aux;
    while (2 * Idx < N - 1)
    {
        Child = 2 * Idx + 1;
        if (Child < (N - 1) && wt[Heap[Child]] > wt[Heap[Child + 1]])
            Child++;
        if (!(wt[Heap[Idx]] > wt[Heap[Child]]))
            break;

        queueaux[Heap[Idx]] = Child;
        queueaux[Heap[Child]] = Idx;

        aux = Heap[Idx];
        Heap[Idx] = Heap[Child];
        Heap[Child] = aux;
        Idx = Child;
    }
}

/*
 *  Função:
 *    Pqdelmin
 *
 *  Descrição:
 *
 *
 *  Argumentos:
 *
 *
 *  Retorna:
 *
 */

int PQdelmin(int *queue, int *wt, int *queueaux)
{
    int aux;

    queueaux[queue[0]] = -1;
    queueaux[queue[espaco - 1]] = 0;

    aux = queue[0];
    queue[0] = queue[espaco - 1];
    queue[espaco - 1] = aux;

    FixDown(queue, 0, espaco - 1, wt, queueaux);
    /* ultimo elemento não considerado na reordenação */
    return queue[--espaco];
}
