/******************************************************************************
 *
 * NAME
 *   modos.c
 *
 * DESCRIPTION
 *  Realiza as variantes de funcionamento consoante o ficheiro de entrada.
 *
 * COMMENTS
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "modos.h"
#include "tabuleiro.h"

/******************************************************************************
 * vertipo ()
 *
 * Arguments:
 * Returns:
 *
 * Description: Identifica o tipo de célula
 *****************************************************************************/

int vertipo(int **tabuleiro, int l1i, int c1i, int li, int ci)
{
    return tabuleiro[l1i - 1][c1i - 1];
}

/******************************************************************************
 * procura ()
 *
 * Arguments: tabuleiro, l1i, c1i, li, ci, tj[3]
 * Returns: 0
 * Side-Effects: none
 *
 * Description: Realiza os modos A2, A3, 4 e A5 (verifica os vizinhos)
 *****************************************************************************/

int procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3])
{

    int i, aux, aux1, nswe[9] = {0};

    for (i = 0; i <= 8; i++) /*inicializa uma array, que será os blocos à volta da coordenada dada,
    com um valor impossível de aparecer no tabuleiro*/
    {
        nswe[i] = -2;
    }
    for (aux = -1, i = 0; aux <= 1; aux++) /*Vai guardar os valores na array*/
    {
        if (l1i + aux - 1 < 0) /*Se estiver fora do tabuleiro dará break ou pulará a linha*/
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

        for (aux = 1; aux < 9; aux += 2) /*irá procurar nas posições a norte sul oeste e este pela peça pretendida*/
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
 * soupintor()
 *
 * Arguments: tabela, li, ci, id
 * Returns: id
 * Side-Effects: none
 *
 * Description: Pinura das salas através da conectividade (CWQU)
 *****************************************************************************/

int *soupintor(int **tabela, int li, int ci, int *id)
{
    int aux, aux1, i, j, p, q, x, t, ij, ji;

    for (aux = 0; aux < li * ci; aux++)
    {
        id[aux] = aux;
    }

    for (i = 0; i < li; i++) /*irá analisar todas as peças do tabuleiro, e se tiver as condições
    necessárias(peças adjacentes brancas), irá aplicar o algoritmo WQU para conectar as peças*/
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

                        if (aux < aux1)
                        {
                            id[aux1] = aux;
                            t = aux;
                        }
                        else
                        {
                            id[aux] = aux1;
                            t = aux1;
                        }
                        for (ij = p; ij != id[ij]; ij = x)
                        {
                            x = id[ij];
                            id[ij] = t;
                        }

                        for (ji = q; ji != id[ji]; ji = x)
                        {
                            x = id[ji];
                            id[ji] = t;
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

                        if (aux < aux1)
                        {
                            id[aux1] = aux;
                            t = aux;
                        }
                        else
                        {
                            id[aux] = aux1;
                            t = aux1;
                        }
                        for (ij = p; ij != id[ij]; ij = x)
                        {
                            x = id[ij];
                            id[ij] = t;
                        }

                        for (ji = q; ji != id[ji]; ji = x)
                        {
                            x = id[ji];
                            id[ji] = t;
                        }
                    }
                }
            }
        }
    }
    return id;
}

/******************************************************************************
 * quebravel()
 *
 * Arguments: tabela, l1i, c1i, li, ci
 * Returns: 0 se não for quebravel, 1 se for quebravel somente no eixo dos y, 2 se for quebravel somento no eixo dos x e 3 se for em ambos os sentidos
 * Side-Effects: none
 *
 * Description: Returna um valor dependendo se a celula analisada é não quebravel
 *****************************************************************************/

int quebravel(int **tabuleiro, int l1i, int c1i, int li, int ci)
{
    // por ifs para verificar que está fora do tabuleiro

    if (c1i == 0 || c1i == ci - 1 || l1i == 0 || l1i == li - 1 || tabuleiro[l1i][c1i] <= -1)
    {
        /* code */
    }
    else if (tabuleiro[l1i + 1][c1i] <= -2 && tabuleiro[l1i - 1][c1i] <= -2 && tabuleiro[l1i][c1i + 1] <= -2 && tabuleiro[l1i][c1i - 1] <= -2)
    {
        if (tabuleiro[l1i + 1][c1i] == tabuleiro[l1i - 1][c1i] || tabuleiro[l1i][c1i + 1] == tabuleiro[l1i][c1i - 1])
        {
            return 0;
        }
        return 3;
    }

    if (l1i == 0 || l1i == li - 1 || tabuleiro[l1i][c1i] <= -1)
    {
    }
    else if (tabuleiro[l1i + 1][c1i] <= -2 && tabuleiro[l1i - 1][c1i] <= -2)
    {
        if (tabuleiro[l1i + 1][c1i] == tabuleiro[l1i - 1][c1i])
        {
            return 0;
        }
        return 1;
    }

    if (c1i == 0 || c1i == ci - 1 || tabuleiro[l1i][c1i] <= -1)
    {
        /* code */
    }
    else if (tabuleiro[l1i][c1i + 1] <= -2 && tabuleiro[l1i][c1i - 1] <= -2)
    {
        if (tabuleiro[l1i][c1i + 1] == tabuleiro[l1i][c1i - 1])
        {
            return 0;
        }
        return 2;
    }

    return 0;
}

/******************************************************************************
 * salascounter()
 *
 * Arguments: tabuleiro, id, li, ci
 * Returns: numero de salas
 * Side-Effects:pintar o tabuleiro
 *
 * Description: conta o numero de salas e "pinta" o tabuleiro
 *****************************************************************************/

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