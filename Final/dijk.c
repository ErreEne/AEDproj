#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <limits.h>

#include "socorro.h"
#include "queueue.h"
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

/******************************************************************************
 * Djikstra()
 *
 * Arguments: pointer para o Grafo, salachegada,pointer para o output
 * Returns:
 * Side-Effects: none
 *
 * Description: Realiza todo o algoritmo de procura de Djikstra
 *****************************************************************************/

void Dijkstra(Grafo *G, int salachegada, FILE *fpOut)
{
    int v, w, solu, *queue, *melhorsala, *menorcusto, *queueaux, aux, espaco = 0;
    queue = (int *)calloc(G->Vertices, sizeof(int));
    if (queue == NULL)
        exit(0);
    queueaux = (int *)malloc(G->Vertices * sizeof(int));
    if (queueaux == NULL)
        exit(0);
    melhorsala = (int *)malloc(sizeof(int) * G->Vertices);
    if (melhorsala == NULL)
        exit(0);
    menorcusto = (int *)malloc(sizeof(int) * G->Vertices);
    if (menorcusto == NULL)
        exit(0);
    LinkedList *t;
    for (v = 0; v < G->Vertices; v++)
    {
        melhorsala[v] = -1;
        menorcusto[v] = __INT_MAX__;
        queueaux[v] = -1;
    }

    menorcusto[salachegada] = 0;
    /*insere a 1a posição, que neste caso será a sala de chegada já que iremos tentar encontrar o caminho mais barato até a sala inicial*/
    PQinsert(salachegada, queue, menorcusto, G->Vertices, queueaux, salachegada, espaco);
    espaco++;
    while (!IsEmpty(espaco))
    {
        v = PQdelmin(queue, menorcusto, queueaux, espaco);
        espaco--;
        for (t = G->adj[v]; t != NULL; t = t->next)
            if (menorcusto[w = t->vertice] > menorcusto[v] + t->custo)
            {
                menorcusto[w] = menorcusto[v] + t->custo;
                if (queueaux[w] == -1)
                {
                    PQinsert(w, queue, menorcusto, G->Vertices, queueaux, w, espaco); /*inserir pela primeira vez*/
                    espaco++;
                }
                else
                {

                    aux = queueaux[w];
                    FixUp(queue, aux, menorcusto, queueaux, w); /*Se o valor já existe na queue, reoordenar com o novo custo*/
                }

                melhorsala[w] = v;
            }
    }
    free(queue);
    free(queueaux);
    if (melhorsala[0] == -1)
    {
        fprintf(fpOut, "-1");
        free(melhorsala);
        free(menorcusto);
    }
    else
    {
        solu = retirarsolucao(0, menorcusto, melhorsala);
        fprintf(fpOut, "%d\n", solu);
        caminho(G, salachegada, menorcusto, melhorsala, fpOut);
        free(melhorsala);
        free(menorcusto);
    }
}

/******************************************************************************
 * retirarsolucao()
 *
 * Arguments: salachegada, wt, st
 * Returns: wt[salachegada]
 * Side-Effects: none
 *
 * Description: retorna um valor do wt
 *****************************************************************************/

int retirarsolucao(int salachegada, int *wt, int *st)
{
    return wt[salachegada];
}

/******************************************************************************
 * caminho()
 *
 * Arguments: Pointer para o Grafo, salachegada, wt, st, pointer para o output
 * Returns: 0
 * Side-Effects: none
 *
 * Description: Dá fprintf do caminho das salas em sequência
 *****************************************************************************/

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
