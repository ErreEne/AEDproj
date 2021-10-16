#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

int A1(int **tabuleiro, int l1i, int c1i, int li, int ci)
{
    // ver se pertence ao tabuleiro
    if (l1i - 1 < 0 || c1i - 1 < 0 || l1i - 1 > li - 1 || c1i - 1 > ci - 1)
    {

        return -2;
    }
    else
    {
        int valor = tabuleiro[l1i - 1][c1i - 1];
        if (valor == -1)
        {
            return -1;
            printf("está certa1");
        }
        else if (valor == 0)
        {
            return 0;
            printf("está certa");
        }
        else if (valor > 0)
        {
            return valor;
            printf("está certa2");
        }
    }
    return -2;
}

int procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3])
{

    int aux = tj[1] - 48, id[9] = {0}, aux1, i = 0;

    if (l1i - 1 < 0 || c1i - 1 < 0 || c1i > ci || l1i > li)
    {
        // Coordenada não disponível
        return -2;
    }

    for (i = 0; i <= 8; i++)
    {
        id[i] = -2;
    }
    /*Vai guardar todas as peças à volta numa array*/
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
                break;
            }
            else
            {

                id[i] = tabuleiro[l1i - 1 + aux][c1i - 1 + aux1];
            }
        }
    }
    aux = tj[1] - 48;
    switch (aux)
    {
    case 2:

        for (aux = 1; aux < 9; aux += 2)
        {
            if (id[aux] == 0)
            {
                return 1;
            }
            else
            {

                // não é vizinha branca
            }
        }
        break;

    case 3:
        for (aux = 1; aux < 9; aux += 2)
        {
            if (id[aux] > 0)
            {
                return 1;
            }
            else
            {

                // não é vizinha cinzenta
            }
        }
        break;

    case 4:
        for (aux = 1; aux < 9; aux += 2)
        {
            if (id[aux] == -1)
            {
                return 1;
            }
            else
            {

                // não é vizinha preta
            }
        }

        break;

    case 5:
        if (id[4] <= 0)
            return -1;
        if ((id[1] == 0 && id[7] == 0) || (id[3] == 0 && id[5] == 0))
            return 1;

        break;

    default:

        break;
    }

    return 0;
}
int A6(int **tabela, int li, int ci, int l1i, int c1i, int l2i, int c2i)
{
    int aux, aux1, *sz, i, j, p, q, *id;
    sz = (int *)malloc(li * ci * sizeof(int));
    id = (int *)malloc(li * ci * sizeof(int));
    if (c1i - 1 < 0 || c1i > ci || l1i - 1 < 0 || l1i > li || c2i - 1 < 0 || c2i > ci || l2i - 1 < 0 || l2i > li)
    {
        return -2;
    }

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
    /*for (i = 0; i < li*ci; i++)
    {
        printf("%d\n",id[i]);
    }*/
    //exit(0);
    if (id[(l1i - 1) * ci + c1i - 1] == id[(l2i - 1) * ci + c2i - 1])
        return 1;
    return 0;
    free(id);
    free(sz);
}
/*void FazerFicheiro(){

char *filename;

filename =  (char*) malloc (sizeof(char) * (strlen(ficheiro) + strlen(".sol1") + 1));

strcat(filename, ".sol1");

}*/
int main(int argc, char *argv[])
{

    /*l-linha, c-coluna, c1-Primeira Cordenada, c2-Segunda Cordenada, tj-Tipo de Jogo, np-Número de paças, tp- Tipo de Peça */
    int li = 0, ci = 0, c1i = 0, l1i = 0, npi = 0, tpi = 0, i = 0, tja, solu, l2i = 0, c2i = 0, opt = 0, flag, aux = 0, aux1 = 0, **tabuleiro;
    char tj[3] = {""};
    char *FileIn, *FileOut;
    char *temp;
    char extOut[] = ".sol1";
    FILE *fpIn, *fpOut;

    FileIn = argv[2];
    FileOut = (char *)malloc(sizeof(char) * (strlen(argv[2]) + 5));

    strcpy(FileOut, FileIn);
    temp = strchr(FileOut, '.');
    *temp = '\0';
    strcat(FileOut, ".sol1");
    printf("%s", FileOut);

    fpIn = fopen(FileIn, "r");

    if (fpIn == NULL)
        exit(0);

    while ((opt = getopt(argc, argv, "s:")) != -1)
    {
        switch (opt)
        {
        case 's':
            sscanf(optarg, " %s", FileIn);
            if (FileIn[strlen(FileIn) - 1] == '1')
                // FLAG QUE ATIVA A LEITURA DO FICHEIRO .in1
                flag = 0; // por exemplo, depois mudar o nome
            break;
        }
    }

    fpIn = fopen(FileIn, "r");
    if ((fpIn = fopen(FileIn, "r")) == NULL)
    {
        exit(0);
    }

    fpOut = fopen(FileOut, "w");
    if (fpOut == NULL)
        exit(0);

    while (1)
    {
        aux = fscanf(fpIn, "%d %d %d %d %s", &li, &ci, &l1i, &c1i, tj);
        if (aux != 5)
            break;

        // alterar este metodo com o fscanf para ver quando ficheiro está NULL porque como está agora vamos ter probleminhas no valgrind
        tja = tj[1] - 48;
        // exit(0);
        if (tja == 6)
        {

            tja = li;
            aux1 = ci;

            fscanf(fpIn, "%d %d %d", &l2i, &c2i, &npi);

            tabuleiro = (int **)calloc(li, sizeof(int *));
            for (i = 0; i < li; ++i)
            {
                tabuleiro[i] = (int *)calloc(ci, sizeof(int));
            }

            for (i = 0; i < npi; i++)
            {
                fscanf(fpIn, "%d %d %d", &li, &ci, &tpi);
                tabuleiro[li - 1][ci - 1] = tpi;
            }
            /*for (aux = 0; aux < li; aux++)
            {
                for (i = 0; i < ci; i++)
                {
                    printf("%d ", tabuleiro[aux][i]);
                }
                printf("\n");
                
            }*/

            li = tja;
            ci = aux1;
            solu = A6(tabuleiro, li, ci, l1i, c1i, l2i, c2i);
            printf("%d\n", solu);
        }
        else
        {

            fscanf(fpIn, "%d", &npi);
            aux = li;
            aux1 = ci;
            tabuleiro = (int **)calloc(li, sizeof(int *));
            for (i = 0; i < li; ++i)
            {
                tabuleiro[i] = (int *)calloc(ci, sizeof(int));
            }

            for (i = 0; i < npi; i++)
            {
                fscanf(fpIn, "%d %d %d", &li, &ci, &tpi);
                tabuleiro[li - 1][ci - 1] = tpi;
            }

            li = aux;
            ci = aux1;
            switch (tja)
            {
            case 1:
                solu = A1(tabuleiro, l1i, c1i, li, ci);
                fprintf(fpOut, "%d\n", solu);
                break;

            case 2:
            case 3:
            case 4:
            case 5:
                solu = procura(tabuleiro, l1i, c1i, li, ci, tj);
                printf("%d\n", solu);
                break;
            default:
                break;
            }
        }
        for (i = 0; i < li; i++)
        {
            free(tabuleiro[i]);
        }

        free(tabuleiro);
    }
    fclose(fpIn);
    fclose(fpOut);
}
