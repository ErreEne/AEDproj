#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <limits.h>

#include "header.h"
#include "LinkedList.h"
#include "defs.h"
struct grafo
{
    int Vertices;
    int arestas;
    LinkedList **adj;
};
struct LinkedListStruct
{
    int vertice;
    LinkedList *next;
    Item custo;
};

void GRAPHpfs(Grafo *G, int s, int st[], int wt[], int *queue, int espaco)
{
    int v, w;
    Item aux;
    LinkedList *t;
    PQinit(G->Vertices);
    for (v = 0; v < G->Vertices; v++)
    {
        st[v] = -1;
        wt[v] = __INT_MAX__;
    }

    wt[0] = 0;
    PQinsert(0, queue, espaco, wt);
    while (!IsEmpty())
    {
        v = PQdelmin(queue, espaco, wt);
        for (t = G->adj[v]; t != NULL; t = t->next)
            if (wt[w = t->vertice] > wt[v] + *(int *)t->custo)
            {
                //
                if (wt[w] == __INT_MAX__)
                {
                    PQinsert(w, queue, espaco, wt);
                }
                //
                wt[w] = wt[v] + *(int *)t->custo; // guardar custo

                for (int i = 0; i < espaco; i++)
                {
                    if (queue[i] == t->vertice)
                    {
                        FixUp(queue, espaco, wt);
                        break;
                    }
                }

                st[w] = v; // guardar sitio mais "barato"
            }
    }
}

int retirarsolucao(int salachegada, int *wt, int *st)
{
    int aux = salachegada, resultado = 0;
    while (aux != 0)
    {
        resultado += wt[aux];
        aux = st[aux];
    }
    return 0;
}