#include <stdio.h>
#include <stdlib.h>

void swap(int *vetor, int n1, int n2) {
  int aux;
  aux = vetor[n1];
  vetor[n1] = vetor[n2];
  vetor[n2] = aux;
}

void max_Heapify(int *vetor, int ind, int n) {
  int max = 0;
  int esq = 2 * ind;
  int dir = (2 * ind) + 1;

  if (esq <= n && vetor[esq] > vetor[ind]) {
    max = esq;
  } else {
    max = ind;
  }

  if (dir <= n && vetor[dir] > vetor[max]) {
    max = dir;
  }

  if (max != ind) {
    swap(vetor, ind, max);
    max_Heapify(vetor, max, n);
  }
}

void build_Max_Heap(int *vetor, int n) {
  for (int j = (n / 2); j >= 1; j--) {
    max_Heapify(vetor, j, n);
  }
}

int heap_Extract_Max(int *vetor, int n) {
  if (n < 1) {
    return -1;
  }

  int max = vetor[1];
  int last = n;
  vetor[1] = vetor[last];
  n--;
  max_Heapify(vetor, 1, n);
  return max;
}

void heap_Sort(int *vetorE, int *vetorS, int n) {
  build_Max_Heap(vetorE, n);

  while (n > 0) {
    vetorS[n] = heap_Extract_Max(vetorE, n);
    n--;
  }
}

void imprime_Lista(int *vetor, int n) {
  for (int i = 1; i <= n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int *vE, *vS, n;

  scanf("%d", &n);
  vE = malloc((n + 1) * sizeof(int));
  vS = malloc((n + 1) * sizeof(int));

  vE[0] = -1;
  vS[0] = -1;
  
  for (int i = 1; i <= n; i++) {
    scanf("%d", &vE[i]);
  }

  heap_Sort(vE, vS, n);
  imprime_Lista(vS, n);

  return 0;
}