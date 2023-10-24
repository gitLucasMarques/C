#include <stdio.h>

int main() {
  int a = 0, n = 0, i = 0, soma = 0;

  scanf("%d %d", &a, &n);
  if (n <= 0) {
    while (n <= 0) {
      scanf("%d", &n);
    }
  }
  for (i = 0; 0 <= i && i <= n - 1; i++) {
    soma = soma + a + i;
  }
  printf("%d\n", soma);
  return 0;
}