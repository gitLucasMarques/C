#include <stdio.h>

int main() {
  int n, max, min;

  scanf("%d", &n);
  max = n;
  min = n;

  for (; n != 0; scanf("%d", &n)) {
    if (n > max) {
      max = n;
    } else {
      if (n < min) {
        min = n;
      }
    }
  }

  printf("min:%d\nmax:%d", min, max);
  return 0;
}
