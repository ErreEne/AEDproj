#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "socorro.h"
#include "modos.h"
#include "tabuleiro.h"
#include "dijk.h"
#include "LinkedList.h"
#include "defs.h"

/*
 *  Tipo de dados: grafo
 *
 *  Descrição: Estrutura com:
 *      1) Vértices: Números de salas
 *      2) Arestas
 *      3) Matriz de adjacências
 *
 */

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
 * criargraph()
 *
 * Arguments: salas, pointer para o Grafo
 * Returns: Grafo
 * Side-Effects: none
 *
 * Description: aloca o espaço necessário para toda a estrutura do Grafo
 *****************************************************************************/

Grafo *criargarph(int salas, Grafo *estr)
{
    int i;
    if (estr == NULL)
        exit(0);
    estr->Vertices = salas;
    estr->adj = (LinkedList **)malloc(sizeof(LinkedList *) * salas);
    if (estr->adj == NULL)
        exit(0);
    for (i = 0; i < estr->Vertices; i++)
    {
        estr->adj[i] = NULL;
    }
    return estr;
}

/******************************************************************************
 * criarligacao()
 *
 * Arguments: pointer para o Grafo, vertice1, vertice2, custo, linha, coluna
 * Returns: 0
 * Side-Effects: none
 *
 * Description: Estabelece a ligação entre vertices
 *****************************************************************************/

void criarligacao(Grafo *estr, int vertice1, int vertice2, int custo, int linha, int coluna)
{
    LinkedList *aux, *aux1;

    for (aux = estr->adj[vertice1]; aux != NULL; aux = aux->next)
    {
        if (aux->vertice == vertice2) /*se a ligação já existem, substituir o custo*/
        {
            if (custo >= aux->custo)
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
                aux1->colunamc = coluna;
                aux->colunamc = coluna;
                aux1->linhamc = linha;
                aux->linhamc = linha;
                return;
            }
        }
    }

    estr->adj[vertice1] = insertSortedLinkedList(estr->adj[vertice1], vertice2, custo, linha, coluna);
    estr->adj[vertice2] = insertSortedLinkedList(estr->adj[vertice2], vertice1, custo, linha, coluna);
}

/******************************************************************************
 * compareItems()
 *
 * Arguments: it1,it2
 * Returns:
 * Side-Effects: none
 *
 * Description: Compara dois inteiros
 *****************************************************************************/

int compareItems(int it1, int it2)
{

    int a = it1;
    int b = it2;

    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/******************************************************************************
 * grafonightmare()
 *
 * Arguments: pointer para o Grafo, salas, tabuleiro, li, ci
 * Returns:
 * Side-Effects: Free do tabuleiro
 *
 * Description: Vê quando é possível criar uma ligação entre vertices do grafo
 *****************************************************************************/

void grafonightmare(Grafo *estr, int salas, int **tabuleiro, int li, int ci)
{
    int i, aux;
    for (i = 0; i < li; i++)
    {
        for (aux = 0; aux < ci; aux++)
        {
            if (quebravel(tabuleiro, i, aux, li, ci) == 1 && tabuleiro[i][aux] > 0) /*quebravel na vertical*/
            {
                if (-tabuleiro[i - 1][aux] - 2 != -tabuleiro[i + 1][aux] - 2) /*não é a mesma sala*/
                {
                    criarligacao(estr, -tabuleiro[i - 1][aux] - 2, -tabuleiro[i + 1][aux] - 2, tabuleiro[i][aux], i, aux);
                }
            }
            else if (quebravel(tabuleiro, i, aux, li, ci) == 2 && tabuleiro[i][aux] > 0) /*quebravel na horizontal*/
            {
                if (-tabuleiro[i][aux + 1] - 2 != -tabuleiro[i][aux - 1] - 2) /*não é a mesma sala*/
                {
                    criarligacao(estr, -tabuleiro[i][aux - 1] - 2, -tabuleiro[i][aux + 1] - 2, tabuleiro[i][aux], i, aux);
                }
            }
            else if (quebravel(tabuleiro, i, aux, li, ci) == 3 && tabuleiro[i][aux] > 0) /*quebravel na vertical e na horizontal*/
            {
                if (-tabuleiro[i - 1][aux] - 2 != -tabuleiro[i + 1][aux] - 2) /*não é a mesma sala*/
                {
                    criarligacao(estr, -tabuleiro[i - 1][aux] - 2, -tabuleiro[i + 1][aux] - 2, tabuleiro[i][aux], i, aux);
                }
                if (-tabuleiro[i][aux + 1] - 2 != -tabuleiro[i][aux - 1] - 2)
                {
                    criarligacao(estr, -tabuleiro[i][aux - 1] - 2, -tabuleiro[i][aux + 1] - 2, tabuleiro[i][aux], i, aux);
                }
            }
        }
        if (i >= 2)
        {

            free(tabuleiro[i - 2]);
        }
    }
    if (i > 1)
    {
        free(tabuleiro[i - 2]);
    }
    free(tabuleiro[i - 1]);
}

/******************************************************************************
 * grafotime()
 *
 * Arguments: salas, tabuleiro, li, ci, pointer para o Output
 * Returns:
 * Side-Effects:
 *
 * Description: Realiza todas as operações do Grafo e da procura
 *****************************************************************************/

void grafotime(int salas, int **tabuleiro, int li, int ci, int salachegada, FILE *fpOut)
{
    Grafo *estr;
    estr = (Grafo *)malloc(sizeof(Grafo));
    if (estr == NULL)
        exit(0);
    estr = criargarph(salas, estr);
    grafonightmare(estr, salas, tabuleiro, li, ci);
    free(tabuleiro);
    Dijkstra(estr, salachegada, fpOut);
    freeGraph(estr);
}

/******************************************************************************
 * freeGrapf()
 *
 * Arguments: pointer para o Grafo
 * Returns:
 * Side-Effects:
 *
 * Description: Liberta o espaço ocupado pelo Grafo
 *****************************************************************************/

void freeGraph(Grafo *G)
{
    int i;

    for (i = 0; i < G->Vertices; i++)
    {
        freeLinkedList(G->adj[i]);
    }

    free(G->adj);
    free(G);
}
