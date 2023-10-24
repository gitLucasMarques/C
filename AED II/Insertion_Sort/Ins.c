#include <stdio.h>
#include <stdlib.h>

void insertion_Sort(int *vetor, int n) {
  for (int j = 1; j < n; j++) {
    int chave = vetor[j];
    int i = j - 1;
    while (i >= 0 && vetor[i] > chave) {
      vetor[i + 1] = vetor[i];
      i--;
    }
    vetor[i + 1] = chave;
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

  insertion_Sort(v, n);
  imprime_Lista(v, n);

  return 0;
}