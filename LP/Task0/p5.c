#include <stdio.h>

int main() {
  float n;
  scanf("%f", &n);
  printf("A parte inteira: %d\n", (int)n);
  printf("A parte decimal: %0.0f", (n - (int)n)*100);
  return 0;
}
