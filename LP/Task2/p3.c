#include <stdio.h>

int main() {
  int n, i;

  scanf("%d", &n);

  if (n == 1) {
    printf("O número 1 não é primo!");
  } else {
    if (n == 2) {
      printf("O número 2 é primo!");
    } else {
      i = 2;
      while (n % i != 0 && i <= (n / 2)) {
        i++;
        break;
      }
      if (n % i == 0) {
        printf("O número %d não é primo!", n);
      } else {
        printf("O número %d é primo!", n);
      }
    }
  }
  return 0;
}