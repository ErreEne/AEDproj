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

int A1(int **tabuleiro, int l1i, int c1i, int li, int ci){
    //ver se pertence ao tabuleiro
    if(l1i-1 < 0 || c1i-1 < 0 || l1i-1 > li-1 || c1i-1>ci-1 ){
        return -2;
    }
    else{
    int valor = tabuleiro[l1i-1][c1i-1];
    if(valor==-1){
        return -1;
        printf("está certa1");
    }else if(valor==0){
        return 0;
        printf("está certa");
    }else if(valor>0){
        return valor;
        printf("está certa2");
    }
}
return -3;
}


int procura(int **tabuleiro, int l1i, int c1i, int li, int ci, char tj[3]){

int aux = tj[1] - 48, id[9]={0},aux1, i=0;

if (l1i - 1 < 0 ||c1i -1 < 0 || c1i > ci || l1i > li)
{
    //Coordenada não disponível
    return -2;
}

    for (i = 0; i <= 8; i++)
    {
        id[i] = -2;
    }
    /*Vai guardar todas as peças numa array*/
    for (aux = -1, i = 0; aux <= 1; aux++){
        if( l1i + aux - 1 < 0){
            aux++;
            i+=3;
        }else if(l1i + aux - 1 >  li - 1){
            break;
            
        }
        for (aux1 = -1; aux1 <= 1; aux1++, i++)
        {
            if(c1i + aux1 - 1 < 0 ){
            }else if(c1i + aux1 - 1 > ci - 1){
                printf("%d %d %d %d\n", l1i-1 + aux, c1i-1 + aux1, li-1, ci-1);
                break;
                }else{
            printf("%d ", tabuleiro[l1i-1+aux][c1i-1+aux1]);
            id[i] = tabuleiro[l1i - 1 + aux][c1i - 1 + aux1];
        }
        }

    }    
aux = tj[1] - 48;
printf("Aux = %d\n", aux);
switch (aux)
{
case 2:

    
    for (aux = 1; aux < 9; aux+=2)
    {
       if(id[aux] == 0){
           printf("ola");
           return 1;

       }else{

           //não é vizinha branca
       } 
    }
    break;

case 3:
    for (aux = 1; aux < 9; aux+=2)
    {
       if(id[aux] == 0){
           printf("ola");
           return 1;

       }else{

           //não é vizinha cinzenta
       } 
    }
    break;

case 4:
    for (aux = 1; aux < 9; aux+=2)
    {
       if(id[aux] == 0){
           printf("ola");
           return 1;

       }else{

           //não é vizinha preta
       } 
    }

    break;

case 5:

    if((id[1] == 0 && id[7] == 0) || (id[3]==0 && id[5]==0)) return 1;
    
    break;

default:

    break;
}

return -1;
}

void FazerFicehiro(){}
int main(int argc, char *argv[])
{

    /*l-linha, c-coluna, c1-Primeira Cordenada, c2-Segunda Cordenada, tj-Tipo de Jogo, np-Número de paças, tp- Tipo de Peça */
    int li = 0, ci = 0, c1i = 0, c2i = 0, npi = 0, tpi = 0, i = 0, tja, solu;
    int **tabuleiro;
    char tj[3]={""};
    int opt = 0, flag, aux = 0, aux1=0,loop=1;
    char filename[40] = {""};

    FILE *fp; /*ler ficheiro*/
    
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
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("porra");
        exit(-1);
    }

    while (1)
    { 
        //alterar este metodo com o fscanf para ver quando ficheiro está NULL porque como está agora vamos ter probleminhas no valgrind
        if ((fscanf(fp, "%d %d %d %d %s %d", &li, &ci, &c1i, &c2i, tj, &npi)) != 6)
        {   
            break;
        }
        else
        {   
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
            tabuleiro[li - 1][ci - 1] = tpi;
        }
    
    tja = tj[1]-48;
    printf("%d", tabuleiro[9][9]);
    li = aux;
    ci = aux1;
    switch (tja)
    {
    case 1:
        solu = A1(tabuleiro, c1i, c2i, li, ci);
        printf("solu = %d", solu);
        break;
    
    case 2:
    case 3:
    case 4:
    case 5:
        solu = procura(tabuleiro,c1i, c2i, li, ci, tj);
        printf("solu = %d", solu);
        break;
    default:
        break;
    }
    
    /*for (i = 0; i < ci; i++)
    {
        free(tabuleiro [i]);
    }
    
    free(tabuleiro);
    }*/
    }
    fclose(fp);


}