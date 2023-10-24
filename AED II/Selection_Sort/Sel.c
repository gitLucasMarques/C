#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int n1, int n2) {
  int aux;
  aux = v[n1];
  v[n1] = v[n2];
  v[n2] = aux;
}

void selection_Sort(int *vetor, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (vetor[j] < vetor[i]) {
        swap(vetor, i, j);
      }
    }
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

  selection_Sort(v, n);
  imprime_Lista(v, n);

  return 0;
}