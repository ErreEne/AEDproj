/******************************************************************************

 * NAME
 *   LinkedList.h
 *
 * Descrição
 *  ficheiro .h para a implementação de uma linked list
 *
 *  Data type list:
 *    Linked list node: LinkedList
 *
 *  Função list:
 *    A) Initialization & Termination
 *        initLinkedList
 *        freeLinkedList
 *
 *    B) Properties
 *        lengthLinkedList
 *
 *    C) Navigation
 *        getNextNodeLinkedList
 *
 *    D) Lookup
 *        getItemLinkedList
 *
 *    E) Insertion - simple at head, sorted
 *       insertUnsortedLinkedList
 *       insertSortedLinkedList
 *
 *****************************************************************************/

#ifndef LinkedListHeader
#define LinkedListHeader

/* Header file for the definition of the Item type */
#include "header.h"
#include "defs.h"

/*
 *  Tipo de dados: LinkedList
 *
 *  Descrição: Nó da linked list
 */
typedef struct LinkedListStruct LinkedList;

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
LinkedList *initLinkedList(void);

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
void freeLinkedList(LinkedList *first);

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
int lengthLinkedList(LinkedList *first);

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
LinkedList *getNextNodeLinkedList(LinkedList *node);

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
int getItemLinkedList(LinkedList *node);

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
LinkedList *insertUnsortedLinkedList(LinkedList *next, int vertice);

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
LinkedList *insertSortedLinkedList(LinkedList *first, int verticenovo, int custo, int linha, int coluna);

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

int getcustoLinkedList(LinkedList *node);

/* End of: Protect multiple inclusions                              */
#endif
