#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HeapFila.h"

char compare(ITEM x, ITEM y) { return x > y ? 1 : (x < y ? -1 : 0); }

bool igual(ITEM x, ITEM y) { return compare(x, y) == 0; }

bool vazia(HEAP *h) {
  if (h->tamanhoAtual == 0)
    return true;
  else
    return false;
}

void exibirItem(ITEM i, HEAP *h) { printf(("(%d)"), h->array[i]); }

// Imprime o arranjo (na ordem que estiver)
void imprimirArranjo(HEAP *h) {
  int tamanho = h->tamanhoAtual;
  int i;
  for (i = 1; i <= tamanho; i++)
    printf("%d ", h->array[i]);
  printf("\n");
}

void inicializarHeap(HEAP *h) {
  h->tamanhoMaximo = INITIAL_CAPACITY;
  h->array = (ITEM *)malloc(h->tamanhoMaximo +
                            1 * sizeof(ITEM)); // Alocação inicial do array.
  h->tamanhoAtual = 0;
  h->tamanhoMaximo = INITIAL_CAPACITY;
}

// Metodo auxiliar que pressupoe que o heap para qualquer j>i esta ordenado
// porem o elemento i nao e necessariamente maior que seus filhos.
void maxHeapify(HEAP *h, ITEM i) {
  int esq = filhoEsquerda(i);
  int dir = filhoDireita(i);
  int temp;
  int maior = i;
  if ((esq <= h->tamanhoAtual) && (h->array[esq] > h->array[i]))
    maior = esq; // verifica se o filho esquerdo é maior que o pai.
  if ((dir <= h->tamanhoAtual) && (h->array[dir] > h->array[maior]))
    maior = dir; // veifica se o filho direito é maior que o pai.
  if (maior !=
      i) { // se maior for diferente de i,faz a troca do filho com o pai.
    temp = h->array[i];
    h->array[i] = h->array[maior];
    h->array[maior] = temp;
    maxHeapify(h, maior); // continua a recursividade.
  }
}

// Constroi heap a partir do arranjo usando o metodo maxHeapify.
void construirHeapMaximo(HEAP *h) {
  int i;
  int metadeTamanho = h->tamanhoAtual / 2;
  for (i = metadeTamanho; i > 0; i--)
    maxHeapify(h, i);
}

/*

                HEAP
 __________________________________        
|                10                |
|         9             8          |
|     7        6     5        4    | 
|  3    2    1                     |
 ----------------------------------

 */

// i = indice

int pai(int i) { return i / 2; }

int filhoEsquerda(ITEM i) { return 2 * i; }

int filhoDireita(ITEM i) { return 2 * i + 1; }

bool inserirHeap(HEAP *h, ITEM valor) {
  int i, temp;
  if (h->tamanhoAtual == h->tamanhoMaximo)
    return false;
  (h->tamanhoAtual)++;
  i = h->tamanhoAtual; // 100 80 7 70
  h->array[i] = valor;
  while (
      (i > 1) &&
      (h->array[pai(i)] <
       h->array[i])) { // verifica em loop se o item colocado é maior que o seu
                       // pai, assim, ajustando sua posição de acordo com o heap
    temp = h->array[i];
    h->array[i] = h->array[pai(i)];
    h->array[pai(i)] = temp;
    i = pai(i);
  }
  return true;
}

// Insere no final do arranjo do heap
bool inserirNoFinal(HEAP *h, ITEM valor) {
  if (h->tamanhoAtual < h->tamanhoMaximo) {
    (h->tamanhoAtual)++;
    h->array[h->tamanhoAtual] = valor;
    return true;
  }
  return false;
}

// remove um item de qualquer posição do heap
bool remover(HEAP *h, ITEM chave) {
  if (chave >= 1 && chave <= h->tamanhoAtual) {
    int temp = h->array[h->tamanhoAtual];
    h->array[h->tamanhoAtual] = h->array[chave];
    h->array[chave] = temp;
    h->tamanhoAtual--;
    construirHeapMaximo(h);
    return true;
  }
  return false;
}

bool removerMaximo(HEAP *h) {
  if (h->tamanhoAtual > 0) {
    int temp = h->array[h->tamanhoAtual];
    h->array[h->tamanhoAtual] = h->array[1];
    h->array[1] = temp;
    h->tamanhoAtual--;
    construirHeapMaximo(h);
  }
  return true;
}

int alturaHeap(HEAP *h) {
  int altura = -1;
  int i = 1;
  while (i <= h->tamanhoAtual) {
    i = filhoEsquerda(i);
    altura++;
  }
  return altura;
}

/*
40 20 15 10 18 12 6 1 5 8 17 3
______________________________________________________
Nível|                      HEAP
-1   |
0    |                       40
1    |                20           15
2    |            10     18      12   6
3    |          1   5   8  17   3
-------------------------------------------------------
*/

// Imprime elementos em ordem crescente e esvazia o heap
void heapSort(HEAP *h) {
  int tamanho = h->tamanhoAtual;
  int i, temp;
  construirHeapMaximo(h); // função feita para caso o heap não esteja correto
  for (i = tamanho; i > 1; i--) {
    temp = h->array[1]; 
    h->array[1] = h->array[i];
    h->array[i] = temp;
    //printf("%d ", temp);
    (h->tamanhoAtual)--;
    maxHeapify(h, 1);
  }
  //printf("\n");
  h->tamanhoAtual = tamanho;
}

// Caminhamento NLR (Atual, Esquerda, Direita)
void PreOrdem(HEAP *h, ITEM atual) {
  if (atual <= h->tamanhoAtual) {
    printf("%i ", h->array[atual]);
    PreOrdem(h, filhoEsquerda(atual));
    PreOrdem(h, filhoDireita(atual));
  }
}

// Destrói o Heap
void destruirHeap(HEAP *h) {
  int tamanho = h->tamanhoMaximo;
  free(h->array); // Libera o espaco de memoria alocado para o array.
  h->tamanhoMaximo = 0;
  h->tamanhoAtual = 0;
}