/******************************************************************************
 * NAME
 *      LinkedList.c
 *
 * DESCRIPTION
 *      Implementação de uma Linked List
 *
 *  Implementation details:
 *      Nó da lista:  Cada nó da lista tem um item e um pointer que aponta para o próximo nó.
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

/*
 *  Tipo de dados: LinkedListStruct
 *
 *  Descrição: Estrutura com:
 *      1) Vértices: Números de salas
 *      2) Pointer para o próximo nó
 *      3) Custo
 *      4) Linha com o menor custo
 *      5) Coluna com o menor custo
 *
 */
struct LinkedListStruct
{
    int vertice;
    LinkedList *next;
    int custo;
    int linhamc;
    int colunamc;
};

/*
 *  Função:
 *    initLinkedList
 *
 *  Descrição:
 *    Inicializa a Linked List
 *
 *  Argumentos:
 *    Nenhum
 *
 *  Retorna:
 *      Retorna um pointeiro para a nova linked list
 */
LinkedList *initLinkedList(void)
{
    return NULL;
}

/*
 *  Função:
 *    getcustoLinkedList
 *
 *  Descrição:
 *
 *
 *  Argumentos:
 *      Ponteiro para o nó atual onde estamos (LinkedList *) node
 *
 *  Retorna:
 *      Retorna o ponteiro para o nó onde está o custo
 */
int getcustoLinkedList(LinkedList *node)
{
    if (node == NULL) /* Check that node is not empty */
        return 0;

    return node->custo;
}
/*
 *  Função:
 *    freeLinkedList
 *
 *  Descrição:
 *    Liberta a memória alocada na lista
 *
 *  Argumentos:
 *    Pointeiro para o primeiro elemento da lista: (LinkedList *) first
 *    Função que liberta a memória alocada nos items: void freeItem(Item)
 *
 *  Retorna:
 *      Nenhum
 */
void freeLinkedList(LinkedList *first)
{
    LinkedList *aux, *next;

    /* Ciclo desde o primeiro ao ultimo elemento           */
    for (aux = first; aux != NULL; aux = next)
    {
        next = aux->next; /* Vê o próximo nó */
        free(aux);        /* Liberta o nó atual    */
    }
    return;
}

/*
 *  Função:
 *    lengthLinkedList
 *
 *  Descrição
 *    Determina o comprimento da lista
 *
 *  Argumentos:
 *    Ponteiro para o primeiro nó da lista (LinkedList *) first
 *
 *  Retorna:
 *    Retorna o comprimento
 */
int lengthLinkedList(LinkedList *first)
{
    LinkedList *aux;
    int counter;

    /* Ciclo que descobre o comprimento                                  */
    for (aux = first, counter = 0;
         aux != NULL;
         counter++, aux = aux->next)
        ;

    return counter;
}

/*
 *  Função:
 *    getNextNodeLinkedList
 *
 *  Descrição:
 *    Retorna o próximo nó da lista
 *
 *  Arguments:
 *    Ponteiro para o nó atual onde estamos (LinkedList *) node
 *
 *  Retorna:
 *    Retorna o ponteiro para o próximo nó da lista.
 *    Retorna NULL caso o nó atual está vazio ou não existe um nó aseguir
 */
LinkedList *getNextNodeLinkedList(LinkedList *node)
{
    return ((node == NULL) ? NULL : node->next);
}

/*
 *  Função:
 *    getItemLinkedList
 *
 *  Descrição:
 *    Fica com o Item do nó da lista
 *
 *  Argumentos:
 *    Ponteiro para o nó da lista
 *
 *  Retorna:
 *    Retorna o ponteiro para o item do nó da lista. Retorna NULL se o nó estiver vazio
 *
 */
int getItemLinkedList(LinkedList *node)
{
    if (node == NULL) /* Verifica se o nó não está vazio */
        return 0;

    return node->vertice;
}

/*
 *  Função:
 *    insertUnsortedLinkedList
 *
 *  Descrição:
 *    Cria um novo nó no inicio da lista.
 *
 *  Argumentos:
 *    Item associado ao próximo nó: Item this.
 *      Item this
 *    Ponteiro para o próximo nó: (LinkedList *) next
 *
 *  Retorna:
 *    Retorna o ponteiro para o novo inicio da lista (head).
 */
LinkedList *insertUnsortedLinkedList(LinkedList *next, int vertice)
{
    LinkedList *new;
    new = (LinkedList *)malloc(sizeof(LinkedList));
    if (new == NULL)
        return NULL;

    /* IInicialização do novo nó */
    new->vertice = vertice;
    new->next = next;

    return new;
}

/*
 *  Função:
 *    insertSortedLinkedList
 *
 *  Descrição:
 *    Insere um item por ordem na lista.
 *
 *  Argumentos:
 *    Ponteiro para o primeiro nó da lista: (LinkedList *) first
 *
 *    Ponteiro para o item a ser inserido: Item item
 *
 *    Ponteiro para afunção que faz a comparação: int comparisonItemFnt(void * item1, void * item2)
 *
 *    Ponteiro para um inteiro para escrever valores de retorno errados (int *) err
 *     0 para o caso de sucesso, 1 quando o item é NULL e 2 se alocar mal a memória
 *
 *  Retorna:
 *    Retorna o ponteiro para o primeiro nó da lista.
 */
LinkedList *insertSortedLinkedList(LinkedList *first, int verticenovo, int custo, int linha, int coluna)
{
    LinkedList *new, *aux;

    new = (LinkedList *)malloc(sizeof(LinkedList));
    if (new == NULL)
        return NULL;

    new->vertice = verticenovo; /* inicializa o novo nó  */
    new->custo = custo;
    new->linhamc = linha;
    new->colunamc = coluna;
    new->next = NULL;

    if (first == NULL) /* primeiro item da lista */
    {
        return new;
    }
    /* a lista nao está vazia, logo insere */
    /* insere na cabeça */
    if ((compareItems(verticenovo, first->vertice) <= 0))
    {
        new->next = first;
        return new;
    }
    /* insere no segundo nó e continua */
    aux = first;
    while (aux != NULL)
    {
        if (aux->next != NULL)
        {
            if (compareItems(verticenovo, aux->next->vertice) <= 0)
            {
                new->next = aux->next;
                aux->next = new;
                return first;
            }
        }
        else /* acabam logo insere na tail */
        {
            aux->next = new;
            return first;
        }
        aux = aux->next;
    }
    return NULL;
}
