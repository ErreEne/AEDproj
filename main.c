#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

    /*for (i = 0; i < c; i++)
        tabuleiro[i] = (int*)calloc(c,sizeof(int));*/

/*A6 = Se ponto de partida - branca ->inicializar a -2. 
Correr algoritmo de procura e escolher uma peça branca. 
Ponto de chegada? Não então colocar -2. Repetir processo até ponto de chegada. 
Chega ao ponto de chegada, usar variavel auxiliar para saber que podem estar na mesma sala. Exit.*/

void A1(int **tabuleiro, int l1i, int c1i, int li, int ci){
    int valor = tabuleiro[l1i-1][c1i-1];
    //ver se pertence ao tabuleiro
    if(l1i-1 < 0 || c1i-1 < 0 || l1i > li || c1i>ci ){
        //Não pertence no fodendo tabuleiro
    }else{
    
    if(valor==-1){
        //peça será preta
        printf("está certa1");
    }else if(valor==0){
        //peça branca
        printf("está certa");
    }else if(valor>0){
        //peça cinzenta
        printf("está certa2");
    }
}
}


void procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[2]){
int aux = tj[1] - 30, id[9]={},aux1;



switch (aux)
{
case 2:

    for (aux = -1; aux <= 1; aux++)
    {
        for (aux1 = -1; aux <= 1; aux1++, *id+=1)
        {
            id[0] = tabuleiro[l1i - aux][c1i - aux1];
        }
        
        
    }
    *id+=-9;
    
    for (aux = 0; aux < 9; aux+=2)
    {
       if(id[aux] == 0){

           //é vizinha branca

       }else{

           //não é vizinha branca
       } 
    }
    

    break;
case 3:

    for (aux = -1; aux <= 1; aux++)
    {
        for (aux1 = -1; aux <= 1; aux1++, *id+=1)
        {
            id[0] = tabuleiro[l1i - aux][c1i - aux1];
        }
        
        
    }
    *id+=-9;
    
    for (aux = 0; aux < 9; aux+=2)
    {
       if(id[aux] > 0){

           //é vizinha grey

       }else{

           //não é vizinha grey
       } 
    }
    

    break;
case 4:
    for (aux = -1; aux <= 1; aux++)
    {
        for (aux1 = -1; aux <= 1; aux1++, *id+=1)
        {
            id[0] = tabuleiro[l1i - aux][c1i - aux1];
        }
        
        
    }
    *id+=-9;
    
    for (aux = 0; aux < 9; aux+=2)
    {
       if(id[aux] == -1){

           //é vizinha negra

       }else{

           //não é vizinha negra
       } 
    }
    

    break;

default:

    break;
}


}


void FazerFicehiro(){}
int main(int argc, char *argv[])
{

    /*l-linha, c-coluna, c1-Primeira Cordenada, c2-Segunda Cordenada, tj-Tipo de Jogo, np-Número de paças, tp- Tipo de Peça */
    /*char *l = NULL, *c= NULL, *c1= NULL, *c2= NULL, *tj= NULL, *np= NULL, *tp= NULL;*/
    int li = 0, ci = 0, c1i = 0, c2i = 0, npi = 0, tpi = 0, i = 0, **tabuleiro;
    char tj[2];
    int opt = 0, flag, aux = 0, aux1=0,loop=1;
    char filename[40] = {""};

    FILE *fp; /*ler ficheiro*/
    
    printf("teste again");
    /*if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("porra");
        exit(-1);
    }*/

    while ((opt = getopt(argc, argv, "s:")) != -1)
    {   printf("sexo");
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
    printf("oi");
    
    fp = fopen(filename, "r");
    while (1)
    {   printf("oi2\n");
        aux = fscanf(fp, " %d %d %d %d %s %d", &li, &ci, &c1i, &c2i, tj, &npi);
        if ((aux != 6))
        {
            printf("oi1\n");
            break;
        }
        else
        {   printf("dshbfzajn\n");
            aux=li;
            aux1=ci;
           tabuleiro = (int **)calloc(li, sizeof(int *));
            for (i = 0; i < li; ++i)
            {
                tabuleiro[i] = (int *)calloc(ci, sizeof(int));
            }
        }
        for (i = 0; i < npi; i++)
        {   
            fscanf(fp, "%d %d %d", &li, &ci, &tpi);
            printf("%d %d %d\n", li, ci, tpi);
            tabuleiro[li - 1][ci - 1] = tpi;
        }
    A1(tabuleiro, c1i, c2i, li, ci);
    li = aux;
    ci = aux1;
    //free(tabuleiro);
    }
    
    printf("\nola");
    
    //exit(0);
    fclose(fp);
    printf("bomdia");


}