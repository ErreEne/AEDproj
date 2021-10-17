#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

#include "cabecinha.h"
/******************************************************************************
 *
 * NAME
 *   main.c
 *
 * DESCRIPTION
 *
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

    FileIn = (char *)malloc(sizeof(char) * (strlen(argv[2]) + 1));
    strcpy(FileIn, argv[2]);
    FileOut = (char *)malloc(sizeof(char) * (strlen(argv[2]) + 2));

    strcpy(FileOut, FileIn);
    temp = strrchr(FileOut, '.');
    *temp = '\0';
    strcat(FileOut, ".sol2");
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
            if (FileIn[strlen(FileIn) - 1] == '1')
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
    modosDeJogo(fpIn, fpOut);
    fclose(fpIn);
    fclose(fpOut);
    free(FileIn);
    free(FileOut);
    return 0;
}