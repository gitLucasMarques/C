#include <stdio.h>
#include <stdlib.h>

void swap(int *vetor, int n1, int n2) {
  int aux;
  aux = vetor[n1];
  vetor[n1] = vetor[n2];
  vetor[n2] = aux;
}

int partition(int *vetor, int p, int r) {
  int x = vetor[r];

  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (vetor[j] <= x) {
      i++;
      swap(vetor, i, j);
    }
  }
  swap(vetor, i + 1, r);
  return i + 1;
}

void quick_Sort(int *vetor, int p, int r) {
  if (p < r) {
    int q = partition(vetor, p, r);
    quick_Sort(vetor, p, q - 1);
    quick_Sort(vetor, q + 1, r);
  }
}

void imprime_Lista(int *vetor, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int *v, n;

  scanf("%d", &n);
  v = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  quick_Sort(v, 0, n - 1);
  imprime_Lista(v, n);

  return 0;
}