#include <stdio.h>

int main() {
  int i, j;
  float n1, n2, d;

  scanf("%d", &i);

  for (j = 0; j < i; j++) {
    scanf("%f %f", &n1, &n2);
    if (n2 == 0) {
      printf("divisao impossivel\n");
    } else {
      d = n1 / n2;
      printf("%0.1f\n", d);
    }
  }

  return 0;
}