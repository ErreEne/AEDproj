/******************************************************************************
 *
 * NAME
 *   modos.c
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

#include "cabecinha.h"

/******************************************************************************
 * A1 ()
 *
 * Arguments: tabuleiro
 * Returns: -2
 * Side-Effects: none
 *
 * Description: Identifica o tipo de célula, modo A1
 *****************************************************************************/

int A1(int **tabuleiro, int l1i, int c1i, int li, int ci)
{

    int valor = tabuleiro[l1i - 1][c1i - 1];
    if (valor == -1)
    {
        return -1;
    }
    else if (valor == 0)
    {
        return 0;
    }
    else if (valor > 0)
    {
        return valor;
    }
    return -2;
}

/******************************************************************************
 * procura ()
 *
 * Arguments: tabuleiro, l1i, c1i, li, ci, tj[3]
 * Returns: 0
 * Side-Effects: none
 *
 * Description: Realiza os modos A2, A3, 4 e A5
 *****************************************************************************/

int procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3])
{

    int i, aux, aux1, nswe[9] = {0};

    for (i = 0; i <= 8; i++)
    {
        nswe[i] = -2;
    }
    for (aux = -1, i = 0; aux <= 1; aux++)
    {
        if (l1i + aux - 1 < 0)
        {
            aux++;
            i += 3;
        }
        else if (l1i + aux - 1 > li - 1)
        {
            break;
        }
        for (aux1 = -1; aux1 <= 1; aux1++, i++)
        {
            if (c1i + aux1 - 1 < 0)
            {
            }
            else if (c1i + aux1 - 1 > ci - 1)
            {
            }
            else
            {

                nswe[i] = tabuleiro[l1i - 1 + aux][c1i - 1 + aux1];
            }
        }
    }

    aux = tj[1] - 48;

    switch (aux)
    {
    case 2:

        for (aux = 1; aux < 9; aux += 2)
        {
            if (nswe[aux] == 0)
            {
                return 1;
            }
            else
            {
            }
        }
        break;

    case 3:
        for (aux = 1; aux < 9; aux += 2)
        {
            if (nswe[aux] > 0)
            {
                return 1;
            }
            else
            {
            }
        }
        break;

    case 4:
        for (aux = 1; aux < 9; aux += 2)
        {
            if (nswe[aux] == -1)
            {
                return 1;
            }
            else
            {
            }
        }

        break;

    case 5:
        if (nswe[4] <= 0)
            return -1;
        if ((nswe[1] == 0 && nswe[7] == 0) || (nswe[3] == 0 && nswe[5] == 0))
            return 1;

        break;

    default:

        break;
    }

    return 0;
}

/******************************************************************************
 * A6 ()
 *
 * Arguments: tabela, li, ci, l1i, c1i, l2i, c2i
 * Returns: 0
 * Side-Effects: none
 *
 * Description: Modo A6
 *****************************************************************************/

int A6(int **tabela, int li, int ci, int l1i, int c1i, int l2i, int c2i)
{
    int aux, aux1, *sz, i, j, p, q, *id;
    sz = (int *)malloc(li * ci * sizeof(int));
    id = (int *)malloc(li * ci * sizeof(int));

    for (aux = 0; aux < li * ci; aux++)
    {
        id[aux] = aux;
        sz[aux] = 1;
    }
    for (i = 0; i < li; i++)
    {
        for (j = 0; j < ci; j++)
        {
            if (i - 1 >= 0)
            {
                if (tabela[i][j] == tabela[i - 1][j] && tabela[i][j] == 0)
                {

                    p = (i - 1) * ci + j;
                    q = i * ci + j;
                    for (aux = p; aux != id[aux]; aux = id[aux])
                        ;
                    for (aux1 = q; aux1 != id[aux1]; aux1 = id[aux1])
                        ;
                    if (aux == aux1)
                    {
                    }
                    else
                    {
                        if (sz[aux] < sz[aux1])
                        {
                            id[aux] = aux1;
                            sz[aux1] += sz[aux];
                        }
                        else
                        {
                            id[aux1] = aux;
                            sz[aux] += sz[aux1];
                        }
                    }
                }
            }
            if (j - 1 >= 0)
            {
                if (tabela[i][j] == tabela[i][j - 1] && tabela[i][j] == 0)
                {

                    p = i * ci + j - 1;
                    q = i * ci + j;
                    for (aux = p; aux != id[aux]; aux = id[aux])
                        ;
                    for (aux1 = q; aux1 != id[aux1]; aux1 = id[aux1])
                        ;
                    if (aux == aux1)
                    {
                    }
                    else
                    {
                        if (sz[aux] < sz[aux1])
                        {
                            id[aux] = aux1;
                            sz[aux1] += sz[aux];
                        }
                        else
                        {
                            id[aux1] = aux;
                            sz[aux] += sz[aux1];
                        }
                    }
                }
            }
        }
    }

    for (aux = (l1i - 1) * ci + c1i - 1; aux != id[aux]; aux = id[aux])
        ;
    for (aux1 = (l2i - 1) * ci + c2i - 1; aux1 != id[aux1]; aux1 = id[aux1])
        ;
    if (aux == aux1)
    {

        free(id);
        free(sz);
        return 1;
    }

    free(id);
    free(sz);
    return 0;
}
