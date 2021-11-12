#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "defs.h"
#include "socorro.h"
#include "modos.h"
#include "queueue.h"
#include "tabuleiro.h"
#include "dijk.h"

/******************************************************************************
 * PQinsert()
 *
 * Arguments:vertice, queue, wt, qsize, queueaux, w
 * Returns:
 * Side-Effects:
 *
 * Description:
 *****************************************************************************/

void PQinsert(int vertice, int *queue, int *wt, int qsize, int *queueaux, int w, int espaco)
{
    if ((espaco + 1) < qsize)
    {
        queue[espaco] = vertice;
        FixUp(queue, espaco, wt, queueaux, w);
    }
}

/******************************************************************************
 * IsEmpty()
 *
 * Arguments:espaco
 * Returns:
 * Side-Effects:
 *
 * Description:Ver o estado da queue, ou seja, se está vazia
 *****************************************************************************/

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

/******************************************************************************
 * FixUp()
 *
 * Arguments:Heap,idx,wt,queueaux,w
 * Returns:
 * Side-Effects:
 *
 * Description:Realiza o FixUp
 *****************************************************************************/

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

/******************************************************************************
 * FixDown()
 *
 * Arguments:Heap, Idx, N, wt, queueaux
 * Returns:
 * Side-Effects:
 *
 * Description:Realiza o FixDown
 *****************************************************************************/

void FixDown(int *Heap, int Idx, int N, int *wt, int *queueaux)
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

/******************************************************************************
 * PQdelmin()
 *
 * Arguments:queue,wt,queueaux,espaco
 * Returns:queue[espaco-1]
 * Side-Effects:
 *
 * Description:Retira o próximo valor na Priority queue
 *****************************************************************************/

int PQdelmin(int *queue, int *wt, int *queueaux, int espaco)
{
    int aux;

    queueaux[queue[0]] = -1;
    queueaux[queue[espaco - 1]] = 0;

    aux = queue[0];
    queue[0] = queue[espaco - 1];
    queue[espaco - 1] = aux;

    FixDown(queue, 0, espaco - 1, wt, queueaux);
    /* ultimo elemento não considerado na reordenação */
    return queue[espaco - 1];
}
