#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

#include "header.h"
/******************************************************************************
 *
 * NAME
 *   main.c
 *
 * DESCRIPTION
 *  Realiza a abertura e o fecho do ficheiro. Faz a troca de extensão
 do ficheiro de entrada para o ficheiro de saida. Leitura do argumento -s
 *
 * COMMENTS
 *
 ******************************************************************************/

int main(int argc, char *argv[])
{

    int opt = 0;
    char *FileIn, *FileOut;
    char *temp;
    FILE *fpIn, *fpOut;
    /*Aloca espaço para o nome dos ficheiros*/
    FileIn = (char *)malloc(sizeof(char) * (strlen(argv[2]) + 1));
    if (FileIn == NULL)
        exit(0);
    strcpy(FileIn, argv[2]);
    FileOut = (char *)malloc(sizeof(char) * (strlen(argv[2]) + 2));
    if (FileOut == NULL)
        exit(0);

    strcpy(FileOut, FileIn);
    temp = strrchr(FileOut, '.');
    *temp = '\0';
    strcat(FileOut, ".so2"); /*Extensão da solução*/
    fpIn = fopen(FileIn, "r");

    if (fpIn == NULL)
    {

        free(FileIn);
        free(FileOut);

        exit(0);
    }
    while ((opt = getopt(argc, argv, "s:")) != -1)
    {
        switch (opt)
        {
        case 's':
            sscanf(optarg, " %s", FileIn);
            if (FileIn[strlen(FileIn) - 1] == 'n')
                break;
        }
    }

    fpOut = fopen(FileOut, "w");
    if (fpOut == NULL)
    {

        fclose(fpIn);
        free(FileIn);
        free(FileOut);
        exit(0);
    }
    criartabuleiro(fpIn, fpOut); /*Chama a função que inicia o tabuleiro e decide os modos de jogo*/
    fclose(fpIn);
    fclose(fpOut);
    free(FileIn);
    free(FileOut);
    return 0;
}