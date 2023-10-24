#include <stdio.h>

int main() {
  float M[12][12], soma = 0;
  int i, j, k;
  char c;

  scanf("%c", &c);
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 12; j++) {
      scanf("%f", &M[i][j]);
    }
  }
  if (c == 'S') {
    k = 1;
    for (i = 11; i > 6; i--) {
      for (j = k; j <= 11 - k; j++) {
        soma = soma + M[i][j];
      }
      k++;
    }
    printf("%0.1f\n", soma);
  }

  if (c == 'M') {
    k = 1;
    for (i = 11; i > 6; i--) {
      for (j = k; j <= 11 - k; j++) {
        soma = soma + M[i][j];
      }
      k++;
    }
    printf("%0.1f\n", soma / 30);
  }

  return 0;
}