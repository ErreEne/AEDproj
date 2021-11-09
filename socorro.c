#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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
    int custo;
};

Grafo *criargarph(int salas, Grafo *estr)
{
    int i;
    if (estr == NULL)
        exit(-1);
    estr->Vertices = salas;
    estr->adj = (LinkedList **)malloc(sizeof(LinkedList *) * salas);
    for (i = 0; i < estr->Vertices; i++)
    {
        estr->adj[i] = NULL;
    }
    return estr;
}

void criarligacao(Grafo *estr, int vertice1, int vertice2, int custo)
{

    LinkedList *aux, *aux1;

    for (aux = estr->adj[vertice1]; aux != NULL; aux = aux->next)
    {
        if (aux->vertice == vertice2)
        {
            if (*(int *)custo > *(int *)aux->custo)
            {
                return;
            }
            else
            {
                for (aux1 = estr->adj[vertice2]; aux1 != NULL; aux1 = aux1->next)
                {
                    if (aux1->vertice == vertice1)
                    {
                        break;
                    }
                }
                aux1->custo = custo;
                aux->custo = custo;
                return;
            }
        }
    }

    estr->adj[vertice1] = insertSortedLinkedList(estr->adj[vertice1], vertice2, custo);
    estr->adj[vertice2] = insertSortedLinkedList(estr->adj[vertice2], vertice1, custo);
}

void montargraph(Grafo *estr, int salas, int vertice1, int vertice2)
{
    int i, j;
    Item aux;
    criarligacao(estr, i, j, aux);
}

int compareItems(int it1, int it2)
{

    int a = it1;
    int b = it2;

    if (a > b)
    {
        return -1;
    }
    else if (a < b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
