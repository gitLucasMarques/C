#include <stdio.h>
int main() {
  int tamanho, l, c, num[1000][1000] = {0}, somaC[1000] = {0}, somaL[1000] = {0}, i = 0, j = 0;

  scanf("%d", &tamanho);

  for (l = 0; l < tamanho; l++) {
    for (c = 0; c < tamanho; c++) {
      scanf("%d", &num[l][c]);
    }
  }
  
  for (l = 0; l < tamanho; l++) {
    for (c = 0; c < tamanho; c++) {
      somaC[l] += num[l][c];
    }
  }
  for (c = 0; c < tamanho; c++) {
    for (l = 0; l < tamanho; l++) {
      somaL[c] += num[l][c];
    }
  }

  for (l = 0; l < tamanho; l++) {
    if (somaC[l] != 1) {
      i++;
    }
  }
  for (c = 0; c < tamanho; c++) {
    if (somaL[c] != 1) {
      j++;
    }
  }
  
  if (i == 0 && j == 0) {
    printf("verdadeiro\n");
  } else {
    printf("falso\n");
  }
  return 0;
}
