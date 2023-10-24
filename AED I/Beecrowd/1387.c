#include <stdio.h>

int main() {
  int f1 = 1, f2 = 1;

  while (f1 != 0 && f2 != 0) {
    scanf("%d %d", &f1, &f2);
    if (f1 >= 1 && f2 <= 5) {
      printf("%d\n", f1 + f2);
    }
  }

  return 0;
}