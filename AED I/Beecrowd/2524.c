#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 1, m = 1;
  int i, qPac = 0;
  int *b, aux, sB = 0;

  while (scanf("%d %d", &n, &m) != EOF) {
    if (n >= 1 && m <= 1000) {
      b = malloc(m * sizeof(int));
      for (i = 0; i < m; i++) {
        scanf("%d", &aux);
        if (aux >= 1 && aux <= 1000000000) {
          b[i] = aux;
        }
      }

      

      printf("%d\n", qPac);
    }
  }

  return 0;
}