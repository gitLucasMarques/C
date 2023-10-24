#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void counting_Sort(int *vetorE, int *vetorS, int k, int n) {
  int *vetorC;

  vetorC = malloc((k + 1) * sizeof(int));
  for (int i = 0; i <= k; i++) {
    vetorC[i] = 0;
  }

  for (int j = 0; j < n; j++) {
    vetorC[vetorE[j]] = vetorC[vetorE[j]] + 1;
  }

  for (int i = 1; i <= k; i++) {
    vetorC[i] = vetorC[i] + vetorC[i - 1];
  }

  for (int j = n - 1; j >= 0; j--) {
    vetorS[vetorC[vetorE[j]] - 1] = vetorE[j];
    vetorC[vetorS[j]] = vetorC[vetorS[j]] - 1;
  }
}

void imprime_Lista(int *vetor, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int *vE, *vS, n;

  scanf("%d", &n);
  vE = malloc(n * sizeof(int));
  vS = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &vE[i]);
  }

  counting_Sort(vE, vS, MAX, n);
  imprime_Lista(vS, n);

  return 0;
}