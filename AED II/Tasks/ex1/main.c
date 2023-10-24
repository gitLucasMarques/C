#include <stdio.h>
#include <stdlib.h>

int binary_search(int *vet, int ini, int end, int value, int *count);

int main() {
  int n, i;
  int count = 0, value, res = 0;
  int *vet;

  scanf("%d", &n);

  vet = malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  scanf("%d", &value);

  res = binary_search(vet, 0, n - 1, value, &count);

  if (res == -1) {
    printf("%d nao foi encontrado", value);
  } else {
    printf("%d", count);
  }
  free(vet);

  return 0;
}

int binary_search(int *vet, int ini, int end, int value, int *count) {
  int pos;

  pos = (ini + end) / 2;

  if (ini > end) {
    return -1;
  }
  if (vet[pos] == value) {
    return 1;
  }

  *count += 1;
  if (vet[pos] < value) {
    return binary_search(vet, pos + 1, end, value, count);
  } else {
    return binary_search(vet, ini, pos - 1, value, count);
  }
}