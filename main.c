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

void A1(double **tabuleiro, int l1i, int c1i, int li, int ci){
    //ver se pertence ao tabuleiro
    if(l1i-1 < 0 || c1i-1 < 0 || l1i-1 > li || c1i-1>ci ){
        //Não pertence no fodendo tabuleiro
        printf("mete essa merda no tabuleiro\n");
        //exit(0);
    }else{
    int valor = tabuleiro[l1i-1][c1i-1];
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


void procura(double **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3]){

int aux = tj[1] - 48, id[9]={0},aux1, i=0;
    if(l1i-1 < 0 || c1i-1 < 0 || l1i-1 > li || c1i-1>ci ){
        //Não pertence no fodendo tabuleiro
        printf("mete essa merda no tabuleiro\n");
        exit(0);
    }
    for (i = 0; i <= 8; i++)
    {
        id[i] = -2;
    }    

switch (aux)
{
case 2:
    printf("entrei");
    //exit(0);
    for (aux = -1, i = 0; aux <= 1; aux++){
        if( l1i + aux - 1 < 0 || l1i + aux - 1 > li){
            aux++;
            i+=3;
            printf("loop\n");
        }
        for (aux1 = -1; aux1 <= 1; aux1++, i++)
        {
            if(c1i + aux1 - 1 < 0 || c1i + aux1 - 1 > ci){
              //fica quietinho
            }else{
            id[i] = tabuleiro[l1i - 1 + aux][c1i - 1 + aux1];
        }
        }

        
    }
    //exit(0);
            for (i = 0; i < 8; i++)
        {
            printf("%d", id[i]);
        }
    for (aux = 0; aux < 9; aux+=2)
    {
       if(id[aux] == 0){
           printf("ola");
           //é vizinha branca

       }else{

           //não é vizinha branca
       } 
    }
    printf("oi?\n");
    //exit(0);
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
    int li = 0, ci = 0, c1i = 0, c2i = 0, npi = 0, tpi = 0, i = 0, tja;
    double **tabuleiro;
    char tj[3]={""};
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
    {   //printf("oi2\n");
        if ((fscanf(fp, "%d %d %d %d %s %d", &li, &ci, &c1i, &c2i, tj, &npi)) != 6)
        {   //printf("%c",tj[1] );
            printf("oi1\n");
            break;
        }
        else
        {   printf("dshbfzajn\n");
            aux=li;
            aux1=ci;
           tabuleiro = (double **)calloc(li, sizeof(double *));
            for (i = 0; i < li; ++i)
            {
                tabuleiro[i] = (double *)calloc(ci, sizeof(double));
            }
        }
        for (i = 0; i < npi; i++)
        {   
            fscanf(fp, "%d %d %d", &li, &ci, &tpi);
            //printf("%d %d %d\n", li, ci, tpi);
            tabuleiro[li - 1][ci - 1] = tpi;
        }
    tja = tj[1]-48;
    printf("\n%d\n", tja);
    

    switch (tja)
    {
    case 1:
        A1(tabuleiro, c1i, c2i, li, ci);
        break;
    
    case 2:
        printf("sheesh\n");
        procura(tabuleiro,c1i, c2i, li, ci, tj);
        printf("saí");
        break;
    default:
        break;
    }
    li = aux;
    ci = aux1;
    //free(tabuleiro);
    }
    
    printf("\nola");
    //exit(0);
    fclose(fp);


}