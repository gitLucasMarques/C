#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int p, int q, int r) {
  int *L = malloc(((q + 1) - p) * sizeof(int));
  int *R = malloc((r - q) * sizeof(int));

  int k = p;
  int i, j;

  for (i = 0; k <= q; i++) {
    L[i] = vetor[k];
    k++;
  }

  k = q + 1;

  for (j = 0; k <= r; j++) {
    R[j] = vetor[k];
    k++;
  }

  k = p;
  i = 0;
  j = 0;

  while (i < q - p + 1 && j < r - q) {
    if (L[i] < R[j]) {
      vetor[k] = L[i];
      i++;
    } else {
      vetor[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < q - p + 1) {
    vetor[k] = L[i];
    k++;
    i++;
  }

  while (j < r - q) {
    vetor[k] = R[j];
    k++;
    j++;
  }
}

void merge_Sort(int *vetor, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_Sort(vetor, p, q);
    merge_Sort(vetor, q + 1, r);
    merge(vetor, p, q, r);
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

  merge_Sort(v, 0, n - 1);
  imprime_Lista(v, n);

  return 0;
}