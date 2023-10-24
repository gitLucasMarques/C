#include <stdio.h>
int main() {
  int i, v[5], maior;

  for (i = 0; i < 5; i++) {
    scanf("%d", &v[i]);
    if (i == 0) {
      maior = v[i];
    }
    if (v[i] > maior) {
      maior = v[i];
    }
  }
  printf("%d", maior);
  return 0;
}