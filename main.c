#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HeapFila.h"

int main() {
  HEAP meuHeap;
  inicializarHeap(&meuHeap);
  inserirNoFinal(&meuHeap, 1);
  inserirNoFinal(&meuHeap, 12);
  inserirNoFinal(&meuHeap, 87);
  inserirNoFinal(&meuHeap, 99);
  inserirNoFinal(&meuHeap, 8);
  inserirNoFinal(&meuHeap, 6);
  inserirNoFinal(&meuHeap, 15);
  inserirNoFinal(&meuHeap, 1);
  inserirNoFinal(&meuHeap, 18);
  inserirNoFinal(&meuHeap, 40);
  inserirNoFinal(&meuHeap, 17);
  inserirNoFinal(&meuHeap, 12);
  printf("(TESTE 1)\n");
  printf("\n=== INSERÇÃO DOS VALORES ===\n");
  imprimirArranjo(&meuHeap);
  printf("\n=== CONSTRUÇÃO DO HEAP ===\n");
  construirHeapMaximo(&meuHeap);
  imprimirArranjo(&meuHeap);
  removerMaximo(&meuHeap);

  printf("\n=== CONSTRUÇÃO DO HEAP POS REMOCAO ===\n");
  construirHeapMaximo(&meuHeap);
  imprimirArranjo(&meuHeap);

  printf("\n=== PRE ORDEM ===\n");
  PreOrdem(&meuHeap, 1);
  printf("\n");
  printf("\n=== HEAPSORT ===\n");
  heapSort(&meuHeap);
  imprimirArranjo(&meuHeap);
  destruirHeap(&meuHeap);
  printf("\n(FIM TESTE 1)\n");

  printf("\n=========================================\n");

  printf("\n(TESTE 2)\n");
  printf("\n=== TESTE ALTURA ===\n");
  inicializarHeap(&meuHeap);
  inserirHeap(&meuHeap, 10);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 5);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 3);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 20);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 8);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 6);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 15);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 1);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 18);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 40);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 17);
  printf("Altura heap: %i\n", alturaHeap(&meuHeap));
  inserirHeap(&meuHeap, 12);
  printf("\n=== CONSTRUÇÃO DO HEAP ===\n");
  imprimirArranjo(&meuHeap);
  // o Heap ja esta corretamente montado, o comando a seguir nao alterara nada
  construirHeapMaximo(&meuHeap);
  printf("");
  imprimirArranjo(&meuHeap);
  printf("\n=== PRE ORDEM ===\n");
  PreOrdem(&meuHeap, 1);
  printf("\n");
  heapSort(&meuHeap);
  printf("\n=== HEAPSORT ===\n");
  imprimirArranjo(&meuHeap);
  destruirHeap(&meuHeap);

  printf("\n(FIM TESTE 2)\n");
}