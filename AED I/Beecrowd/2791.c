#include <stdio.h>

int main() {
  int v[4] = {0}, i;

  for (i = 0; i < 4; i++) {
    scanf("%d", &v[i]);
  }
  for (i = 0; i < 4; i++) {
    if (v[i] == 1) {
      printf("%d", i + 1);
    }
  }
  return 0;
}