#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int n1, int n2) {
  int aux;
  aux = v[n1];
  v[n1] = v[n2];
  v[n2] = aux;
}

void bubble_Sort(int *vetor, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        swap(vetor, j, j + 1);
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

  bubble_Sort(v, n);
  imprime_Lista(v, n);

  return 0;
}