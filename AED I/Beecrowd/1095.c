#include <stdio.h>

int main() {
  int i, j = 60;

  for (i = 1; j >= 0; i = i + 3) {
    printf("I=%d J=%d\n", i, j);
    j = j - 5;
  }
  return 0;
}