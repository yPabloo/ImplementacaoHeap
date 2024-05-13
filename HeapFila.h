#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HEAP_FILA
#define HEAP_FILA

#define INITIAL_CAPACITY 100

typedef int ITEM;

// Este programa implementa um heap MAXIMO em uma implementação estática de uma
// árvore binária. A posição 0 do array não está sendo utilizada.

typedef struct {
  ITEM *array;
  ITEM tamanhoAtual;
  ITEM tamanhoMaximo;
} HEAP;

/*
   Compara o item x com o y, retornando:
     1 caso x > y
     0 caso x = y
    -1 caso x < y
*/
char compare(ITEM x, ITEM y);

// Retorna true se x = y e false caso contrario
bool igual(ITEM x, ITEM y);

// Retorna True se a Lista estiver vazia
bool vazia(HEAP *h);

// Funcao que mostra o item de uma posicao do array
void exibirItem(ITEM i, HEAP *h);

// Funcao feita para imprimir o arranjo (na ordem que estiver)
void imprimirArranjo(HEAP *h);

// Inicializa a heap deixando-o pronto para ser utilizado.
void inicializarHeap(HEAP *h);

// Metodo auxiliar que pressupoe que o heap para qualquer j>i esta ordenado
// porem o elemento i nao e necessariamente maior que seus filhos
void maxHeapify(HEAP *h, ITEM i);

// Constroi heap a partir do arranjo usando o metodo maxHeapify
void construirHeapMaximo(HEAP *h);

// Função que retorna o pai de um item.
int pai(ITEM i);

// Função que retorna o filho esquerdo de um item.
int filhoEsquerda(ITEM i);

// Função que retorna o filho direito de um item.
int filhoDireita(ITEM i);

// Funcao que insere um item de acordo com a definicao da heap.
bool inserirHeap(HEAP *h, ITEM chave);

// Funcao que insere um novo item no final do arranjo do heap
bool inserirNoFinal(HEAP *h, ITEM valor);

// Funcao que remove o item desejado.
bool remover(HEAP *h, ITEM chave);

// Funcao que remover o item de maior prioridade do heap.
bool removerMaximo(HEAP *h);

// Função que retorna a altura da heap.
int alturaHeap(HEAP *h);

// Funcao que imprime elementos em ordem crescente e esvazia o heap
void heapSort(HEAP *h);

// Percorre a heap, visitando primeiro a raiz, depois a subarvore
// esquerda e por ultimo a subarvore direita.
void PreOrdem(HEAP *h, ITEM atual);

// Função que destroi a heap criada anteriormente.
void destruirHeap(HEAP *h);

#endif // HEAP