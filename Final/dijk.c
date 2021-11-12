#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <limits.h>

#include "socorro.h"
#include "modos.h"
#include "queueue.h"
#include "tabuleiro.h"
#include "dijk.h"

#include "LinkedList.h"
#include "defs.h"

struct grafo
{
    int Vertices;
    int arestas;
    LinkedList **adj;
};

/*
 *  Tipo de dados: LinkedListStruct
 *
 *  Descrição: Estrutura com:
 *      1) Vértices: Números de salas
 *      2) Pointer para o próximo nó
 *      3) Custo
 *      4) Linha com o menor custo
 *      5) Coluna com o menor custo
 *
 */

struct LinkedListStruct
{
    int vertice;
    LinkedList *next;
    int custo;
    int linhamc;
    int colunamc;
};

/*
 *  Função:
 *
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

void GRAPHpfs(Grafo *G, int salachegada, FILE *fpOut)
{
    int v, w, solu, *queue, *st, *wt, *queueaux, aux;
    queue = (int *)calloc(G->Vertices, sizeof(int));
    if (queue == NULL)
        exit(0);
    queueaux = (int *)malloc(G->Vertices * sizeof(int));
    if (queueaux == NULL)
        exit(0);
    st = (int *)malloc(sizeof(int) * G->Vertices);
    if (st == NULL)
        exit(0);
    wt = (int *)malloc(sizeof(int) * G->Vertices);
    if (wt == NULL)
        exit(0);
    LinkedList *t;
    PQinit(G->Vertices, queue, G->Vertices, queueaux);
    for (v = 0; v < G->Vertices; v++)
    {
        st[v] = -1;
        wt[v] = __INT_MAX__;
        queueaux[v] = -1;
    }

    wt[salachegada] = 0;

    PQinsert(salachegada, queue, wt, G->Vertices, queueaux, salachegada);
    while (!IsEmpty())
    {
        v = PQdelmin(queue, wt, queueaux);
        for (t = G->adj[v]; t != NULL; t = t->next)
            if (wt[w = t->vertice] > wt[v] + t->custo)
            {
                wt[w] = wt[v] + t->custo; // guardar custo
                if (queueaux[w] == -1)
                {
                    PQinsert(w, queue, wt, G->Vertices, queueaux, w);
                }
                else
                {

                    aux = queueaux[w];
                    FixUp(queue, aux, wt, queueaux, w);
                }

                st[w] = v; // guardar sitio mais "barato"
            }
    }
    free(queue);
    free(queueaux);
    if (st[0] == -1)
    {
        fprintf(fpOut, "-1");
        free(st);
        free(wt);
    }
    else
    {
        solu = retirarsolucao(0, wt, st);
        fprintf(fpOut, "%d\n", solu);
        caminho(G, salachegada, wt, st, fpOut);
        free(st);
        free(wt);
    }
}

/*
 *  Função:
 *    retirarsolucao
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

int retirarsolucao(int salachegada, int *wt, int *st)
{
    return wt[salachegada];
}

/*
 *  Função:
 *    caminho
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

void caminho(Grafo *G, int salachegada, int *wt, int *st, FILE *fpOut)
{
    int aux = 0, numpartida = 0;
    LinkedList *lista;

    while (st[aux] != -1)
    {
        aux = st[aux];
        numpartida++;
    }
    aux = 0;
    fprintf(fpOut, "%d\n", numpartida);

    while (-1 != st[aux])
    {
        if (aux == 0)
        {
            for (lista = G->adj[aux]; lista != NULL; lista = lista->next)
            {
                if (lista->vertice == st[aux])
                {
                    break;
                }
            }
            fprintf(fpOut, "%d %d %d\n", lista->linhamc + 1, lista->colunamc + 1, lista->custo);
            aux = st[aux];
        }
        else if (aux > 0)
        {

            for (lista = G->adj[aux]; lista != NULL; lista = lista->next)
            {
                if (lista->vertice == st[aux])
                {
                    break;
                }
            }
            fprintf(fpOut, "%d %d %d\n", lista->linhamc + 1, lista->colunamc + 1, lista->custo);

            aux = st[aux];
        }
    }
}
