#include <stdio.h>

int main() {
  int a, b, c, d, k = 0;

  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (b > c && d > a) {
    if (c + d > a + b) {
      if (c > 0 && d > 0) {
        if (a % 2 == 0) {
          k = 1;
        } else {
          k = 0;
        }
      } else {
        k = 0;
      }
    } else {
      k = 0;
    }
  } else {
    k = 0;
  }

  switch (k) {
  case 0:
    printf("Valores nao aceitos\n");
    break;

  case 1:
    printf("Valores aceitos\n");
    break;
  }
  
  return 0;
}