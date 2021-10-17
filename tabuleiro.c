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

#include "cabecinha.h"

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
    int solu, aux, aux1, i, **tabuleiro, li, ci, l1i, c1i, tja, l2i, c2i, npi, tpi;
    char tj[3];
    while ((fscanf(fpIn, "%d %d %d %d %s", &li, &ci, &l1i, &c1i, tj) == 5))
    {

        tja = tj[1] - 48;
        if (tja == 6)
        {

            tja = li;
            aux1 = ci;

            if ((fscanf(fpIn, "%d %d %d", &l2i, &c2i, &npi) != 3))
                exit(0);
            if (l1i - 1 < 0 || c1i - 1 < 0 || l1i > li || c1i > ci || l2i - 1 < 0 || c2i - 1 < 0 || l2i > li || c2i > ci)
            {
                solu = -2;
                fprintf(fpOut, "%d\n\n", solu);
                for (i = 0; i < npi; i++)
                {
                    if ((fscanf(fpIn, "%d %d %d", &li, &ci, &tpi) != 3))
                        exit(0);
                }
            }
            else
            {

                tabuleiro = (int **)calloc(li, sizeof(int *));
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
                solu = A6(tabuleiro, li, ci, l1i, c1i, l2i, c2i);
                fprintf(fpOut, "%d\n\n", solu);
                printf("oi");
                for (i = 0; i < li; i++)
                {
                    free(tabuleiro[i]);
                }

                free(tabuleiro);
            }
        }
        else
        {

            if ((fscanf(fpIn, "%d", &npi) != 1))
                exit(0);
            if (l1i - 1 < 0 || c1i - 1 < 0 || l1i > li || c1i > ci)
            {
                solu = -2;
                fprintf(fpOut, "%d\n\n", solu);
                for (i = 0; i < npi; i++)
                {
                    if ((fscanf(fpIn, "%d %d %d", &li, &ci, &tpi) != 3))
                        exit(0);
                }
            }
            else
            {
                aux = li;
                aux1 = ci;
                tabuleiro = (int **)calloc(li, sizeof(int *));
                for (i = 0; i < li; i++)
                {
                    tabuleiro[i] = (int *)calloc(ci, sizeof(int));
                }

                for (i = 0; i < npi; i++)
                {
                    if ((fscanf(fpIn, "%d %d %d", &li, &ci, &tpi) != 3))
                        exit(0);
                    tabuleiro[li - 1][ci - 1] = tpi;
                }

                li = aux;
                ci = aux1;
                switch (tja)
                {
                case 1:
                    solu = A1(tabuleiro, l1i, c1i, li, ci);
                    fprintf(fpOut, "%d\n\n", solu);
                    break;

                case 2:
                case 3:
                case 4:
                case 5:
                    solu = procura(tabuleiro, l1i, c1i, li, ci, tj);
                    fprintf(fpOut, "%d\n\n", solu);
                    break;
                default:
                    break;
                }

                for (i = 0; i < li; i++)
                {
                    free(tabuleiro[i]);
                }

                free(tabuleiro);
            }
        }
    }
}
