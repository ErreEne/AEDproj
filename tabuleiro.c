/******************************************************************************
 *
 * NAME
 *   tabuleiro.c
 *
 * DESCRIPTION
 *  Lê o que está no ficheiro e consoante o que é lido escolhe os modos de jogo
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

/******************************************************************************
 * modosDeJogo ()
 *
 * Arguments: Ficheiro de entrada e de saida
 * Returns: ---
 * Side-Effects: none
 *
 * Description: Realiza a leitura do ficheiro de entrada, consoante o que é lido
 *****************************************************************************/

void modosDeJogo(FILE *fpIn, FILE *fpOut)
{
    int solu, aux, aux1, aux3, i, **tabuleiro, li, ci, l1i = 0, c1i = 0, tja, l2i, c2i, npi, tpi, *id, salas, *verticecounter, **matrizadj, salascounter = -1, auxaux = 0;
    char tj[3] = {};
    Grafo *estr;
    LinkedList *aux2;
    while ((fscanf(fpIn, "%d %d ", &li, &ci) == 2)) /*Verifica se existe mais algum tabuleiro*/
    {

        tja = tj[1] - 48; /*Escolhe o modo*/

        tja = li;
        aux1 = ci;
        if ((fscanf(fpIn, "%d %d %d", &l2i, &c2i, &npi) != 3)) /*Formato carateristico do A6*/
            exit(0);
        if (l2i - 1 < 0 || c2i - 1 < 0 || l2i > li || c2i > ci) /*verifica se as peças estão no tabuleiro*/
        {
            solu = -2;
            fprintf(fpOut, "%d\n\n", solu);
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
                exit(-1);
            for (i = 0; i < li; ++i)
            {
                tabuleiro[i] = (int *)calloc(ci, sizeof(int));
            }

            for (i = 0; i < npi; i++)
            {
                if ((fscanf(fpIn, "%d %d %d", &li, &ci, &tpi) != 3))
                    exit(0);
                tabuleiro[li - 1][ci - 1] = tpi;
            }
            li = tja;
            ci = aux1;
            id = (int *)malloc(li * ci * sizeof(int) + 1);
            if (id == NULL)
                exit(-1);
            id = soupintor(tabuleiro, li, ci, id); /*Chama a função que retorna a solução do A6*/
            /*for (i = 0; i < li; i++)
            {
                for (aux = 0; aux < ci; aux++)
                {
                    printf(" %2d ", id[i * ci + aux]);
                }
                printf("\n");
            }*/

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
            salas = -salascounter - 1;
            for (i = 0; i < li; i++)
            {
                for (aux = 0; aux < ci; aux++)
                {
                    printf(" %2d", tabuleiro[i][aux]);
                }
                printf("\n");
            }
            printf("\n\n%d\n\n", salas);
            free(id);
            estr = (Grafo *)calloc(1, sizeof(Grafo));
            estr = criargarph(salas, estr);
            grafonightmare(estr, salas, tabuleiro, li, ci);
            for (i = 0; i < li; i++)
            {
                free(tabuleiro[i]);
            }

            free(tabuleiro);

            // montargraph(estr, matrizadj, salas);
            i = 0;
            while (i < estr->Vertices)
            {
                aux2 = estr->adj[i];
                while (aux2 != NULL)
                {
                    aux1 = getItemLinkedList(aux2);
                    aux = *((int *)getcustoLinkedList(aux2));
                    printf("%d:%d ", aux1, aux);
                    aux2 = getNextNodeLinkedList(aux2);
                }
                printf("-1\n");
                i++;
            }

            exit(0);
            for (i = 0; i < li; i++)
            {
                free(matrizadj[i]);
            }

            free(matrizadj);

            // só temos o graph
        }
    }
}

void grafonightmare(Grafo *estr, int salas, int **tabuleiro, int li, int ci)
{
    int i, aux, aux1;
    for (i = 0; i < li; i++)
    {
        for (aux = 0; aux < ci; aux++)
        {
            if (quebravel(tabuleiro, i, aux, li, ci) == 1)
            {
                criarligacao(estr, tabuleiro[i - 1][aux] + salas + 1, tabuleiro[i + 1][aux] + salas + 1, (Item)&tabuleiro[i][aux]);
            }
            else if (quebravel(tabuleiro, i, aux, li, ci) == 2)
            {

                criarligacao(estr, tabuleiro[i][aux + 1] + salas + 1, tabuleiro[i][aux + 1] + salas + 1, (Item)&tabuleiro[i][aux]);
            }
            else if (quebravel(tabuleiro, i, aux, li, ci) == 3)
            {
                criarligacao(estr, tabuleiro[i - 1][aux] + salas + 1, tabuleiro[i + 1][aux] + salas + 1, (Item)&tabuleiro[i][aux]);
                criarligacao(estr, tabuleiro[i][aux - 1] + salas + 1, tabuleiro[i][aux + 1] + salas + 1, (Item)&tabuleiro[i][aux]);
            }
        }
    }
}

int **criarmatriz(int **tabuleiro, int li, int ci, int *verticecounter, int **matrizadj, int salas, int l1i, int c1i)
{
    int aux, aux1, i, aux2;
    for (i = 0, aux1 = 0, aux2 = 0; i < li; i++)
    {
        for (aux = 0; aux < ci; aux++)
        {
            if (quebravel(tabuleiro, i, aux, li, ci) == 1)
            {

                for (aux1 = 0; aux1 < salas; aux1++)
                {
                    if (verticecounter[aux1] == tabuleiro[i + 1][aux])
                    {
                        break;
                    }
                }
                for (aux2 = 0; aux2 < salas; aux2++)
                {
                    if (verticecounter[aux2] == tabuleiro[i - 1][aux])
                    {
                        break;
                    }
                }
                if (matrizadj[aux1][aux2] == 0)
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
                else if (matrizadj[aux1][aux2] > tabuleiro[i][aux])
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
            }
            else if (quebravel(tabuleiro, i, aux, li, ci) == 2)
            {
                for (aux1 = 0; aux1 < salas; aux1++)
                {
                    if (verticecounter[aux1] == tabuleiro[i][aux + 1])
                    {
                        break;
                    }
                }
                for (aux2 = 0; aux2 < salas; aux2++)
                {
                    if (verticecounter[aux2] == tabuleiro[i][aux - 1])
                    {
                        break;
                    }
                }
                if (matrizadj[aux1][aux2] == 0)
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
                else if (matrizadj[aux1][aux2] > tabuleiro[i][aux])
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
            }
            else if (quebravel(tabuleiro, i, aux, li, ci) == 3)
            {

                for (aux1 = 0; aux1 < salas; aux1++)
                {
                    if (verticecounter[aux1] == tabuleiro[i + 1][aux])
                    {
                        break;
                    }
                }
                for (aux2 = 0; aux2 < salas; aux2++)
                {
                    if (verticecounter[aux2] == tabuleiro[i - 1][aux])
                    {
                        break;
                    }
                }
                if (matrizadj[aux1][aux2] == 0)
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
                else if (matrizadj[aux1][aux2] > tabuleiro[i][aux])
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
                for (aux1 = 0; aux1 < salas; aux1++)
                {
                    if (verticecounter[aux1] == tabuleiro[i][aux + 1])
                    {
                        break;
                    }
                }
                for (aux2 = 0; aux2 < salas; aux2++)
                {
                    if (verticecounter[aux2] == tabuleiro[i][aux - 1])
                    {
                        break;
                    }
                }
                if (matrizadj[aux1][aux2] == 0)
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
                else if (matrizadj[aux1][aux2] > tabuleiro[i][aux])
                {
                    matrizadj[aux1][aux2] = tabuleiro[i][aux];
                    matrizadj[aux2][aux1] = tabuleiro[i][aux];
                }
            }
        }
    }
    return matrizadj;
}

/*int numligacoes(int *tabuleiro, int li, int ci)
{
    int i, j;
    for (i = 0; i < ci; i++)
    {
        for (j = 0; i < li; j++)
        {
                }
    }
}*/
