/******************************************************************************
 *
 * NAME
 *   tabuleiro.c
 *
 * DESCRIPTION
 *
 *
 * COMMENTS
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "header.h"
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

/*
 *  Função:
 *    criartabuleiro
 *
 *  Descrição:
 *
 *
 *  Argumentos:
 *    Ponteiros com o ficheiro de entrada e de saida
 *
 *  Retorna:
 *      void
 */

void criartabuleiro(FILE *fpIn, FILE *fpOut)
{
    int aux1, i, **tabuleiro, li, ci, tja, l2i, c2i, npi, tpi, *id, salas, salascounter = -1, salachegada;
    while ((fscanf(fpIn, "%d %d ", &li, &ci) == 2)) /*Verifica se existe mais algum tabuleiro*/
    {

        tja = li;
        aux1 = ci;
        if ((fscanf(fpIn, "%d %d %d", &l2i, &c2i, &npi) != 3)) /*Formato carateristico do A6*/
            exit(0);
        if (l2i - 1 < 0 || c2i - 1 < 0 || l2i > li || c2i > ci || li <= 0 || ci <= 0) /*verifica se as peças estão no tabuleiro*/
        {
            fprintf(fpOut, "-1\n");
            for (i = 0; i < npi; i++)
            {
                if ((fscanf(fpIn, "%d %d %d", &li, &ci, &tpi) != 3)) /*Faz uma leitura do ficheiro para poder prosseguir para o proximo tabuleiro*/
                    exit(0);
            }
        }
        else
        {

            tabuleiro = (int **)calloc(li, sizeof(int *));
            if (tabuleiro == NULL)
                exit(0);
            for (i = 0; i < li; ++i)
            {
                tabuleiro[i] = (int *)calloc(ci, sizeof(int));
                if (tabuleiro[i] == NULL)
                    exit(0);
            }

            for (i = 0; i < npi; i++)
            {
                if ((fscanf(fpIn, "%d %d %d", &li, &ci, &tpi) != 3))
                    exit(0);
                tabuleiro[li - 1][ci - 1] = tpi;
            }
            li = tja;
            ci = aux1;
            if (tabuleiro[l2i - 1][c2i - 1] > 0 || tabuleiro[l2i - 1][c2i - 1] == -1)
            {
                fprintf(fpOut, "-1\n");
                for (i = 0; i < li; i++)
                {
                    free(tabuleiro[i]);
                }
                free(tabuleiro);
            }
            else
            {

                id = (int *)malloc(li * ci * sizeof(int));
                if (id == NULL)
                    exit(0);
                id = soupintor(tabuleiro, li, ci, id); /*Chama a função que retorna a solução do A6*/

                salascounter = salascounters(tabuleiro, id, li, ci);
                for (salachegada = (l2i - 1) * ci + c2i - 1; salachegada >= 0; salachegada = id[salachegada])
                    ;

                free(id);
                if (salachegada == -2)
                {
                    fprintf(fpOut, "%d\n", 0);
                    for (i = 0; i < li; i++)
                    {
                        free(tabuleiro[i]);
                    }
                    free(tabuleiro);
                }
                else
                {

                    salachegada = -salachegada - 2;
                    salas = -salascounter - 1;
                    grafotime(salas, tabuleiro, li, ci, salachegada, fpOut);
                }
            }
        }
        fprintf(fpOut, "\n");
    }
}

/*
 *  Função:
 *    salascounters
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

int salascounters(int **tabuleiro, int *id, int li, int ci)
{
    int salascounter = -1, i, aux, aux1;
    for (i = 0, aux1 = -2; i < li; i++)
    {
        for (aux = 0; aux < ci; aux++)
        {
            if (tabuleiro[i][aux] == 0)
            {
                if (id[i * ci + aux] == i * ci + aux)
                {
                    salascounter--;
                    id[i * ci + aux] = salascounter;
                }

                for (aux1 = i * ci + aux; aux1 >= 0; aux1 = id[aux1])
                    ;
                tabuleiro[i][aux] = aux1;
            }
        }
    }
    return salascounter;
}
