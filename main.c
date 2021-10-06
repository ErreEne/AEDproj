//Projeto da tua mae de quatro

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv)
{

    /*l-linha, c-coluna, c1-Primeira Cordenada, c2-Segunda Cordenada, tj-Tipo de Jogo, np-Número de paças, tp- Tipo de Peça */
    /*char *l = NULL, *c= NULL, *c1= NULL, *c2= NULL, *tj= NULL, *np= NULL, *tp= NULL;*/
    int li = 0, ci = 0, c1i = 0, c2i = 0, npi = 0, tpi = 0, i = 0, **tabuleiro;
    char tj[2];
    int opt = 0, flag, aux = 0, aux1=0;
    char filename[] = "";

    FILE *fp;
    /*ler ficheiro*/

    if ((fp = fopen(filename, "r")) == NULL)
    {
        exit(0);
    }

    while (opt = getopt(argc, argv, "s:"))
    {
        switch (opt)
        {
        case 's':
            sscanf(optarg, " %s", filename);
            if (filename[strlen(filename) - 1] == '1')
                //FLAG QUE ATIVA A LEITURA DO FICHEIRO .in1
                flag = 0; //por exemplo, depois mudar o nome
            break;
        }
    }

    while (1)
    {
        aux = fscanf(fp, " %d %d %d %d %s %d", li, ci, c1i, c2i, tj, npi);
        if (aux = !6)
        {
            break;
        }
        else
        {
            /* li = atoi(l);
            ci = atoi(c);
            c1i = atoi(c1);
            c2i = atoi(c2);
            npi = atoi(np); */
            aux=li;
            aux1=ci;
            tabuleiro = (int **)calloc(li, sizeof(int *));
            for (i = 0; i < li; ++i)
            {
                tabuleiro[i] = (int *)calloc(ci, sizeof(int));
            }
            continue;
        }
        for (i = 0; i < npi; i++)
        {
            fscanf(fp, "%d %d %d", li, ci, tpi);
            /*li = atoi(l);
            ci = atoi(c);
            tpi = atoi(tp);*/
            tabuleiro[li - 1][ci - 1] = tpi;
        }
    li = aux;
    ci = aux1;
    }

    fclose(fp);
}

void A1(int **tabuleiro, int l1i, int c1i, FILE *fp, int li, int ci){
    int valor = tabuleiro[l1i][c1i];
    //ver se pertence ao tabuleiro
    if(l1i-1 < 0 || c1i-1 < 0 || l1i > li || c1i>ci ){
        //Não pertence no fodendo tabuleiro
    }else{
    
    if(valor<0){
        //peça será preta
    }else if(valor==0){
        //peça branca
    }else{
        //peça cinzenta
    }
}
}
//Procurar o tipo de peça, ou seja, a2/a3/a4
void peepee(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[2]){

    


}



    /*for (i = 0; i < c; i++)
        tabuleiro[i] = (int*)calloc(c,sizeof(int));*/

