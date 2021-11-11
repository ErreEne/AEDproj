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

    if (argc != 2)
        exit(0);
    char *FileIn = '\0', *FileOut = '\0';
    char *temp;
    FILE *fpIn = NULL, *fpOut = NULL;
    int lenght = strlen(argv[1]);
    if (strlen(argv[1]) < 3)
        exit(0);
    if ((argv[1][lenght - 1]) != 'n' || (argv[1][lenght - 2]) != 'i' || (argv[1][lenght - 3]) != '.')
        exit(0);
    /*Aloca espaço para o nome dos ficheiros*/
    FileIn = (char *)malloc(sizeof(char) * (lenght + 1));

    if (FileIn == NULL)
        exit(0);
    strcpy(FileIn, argv[1]);
    FileOut = (char *)malloc(sizeof(char) * (strlen(FileIn) + 2));
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
