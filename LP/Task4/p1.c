#include <stdio.h>
int main() {
  int num[1000][1000] = {0}, l, c, soma=0, tamanho;
 
  scanf("%d", &tamanho);
 
  for (l = 0; l < tamanho; l++) {
    for (c = 0; c < tamanho; c++) {
      scanf("%d", &num[l][c]);
    }
  }
  for (l = 0; l < tamanho; l++) {
    for (c = 0; c < tamanho; c++) {
      if (l <= c ) {
        soma += num[l][c];
      }
    }
  }
  printf("%d\n", soma);
  return 0;
}