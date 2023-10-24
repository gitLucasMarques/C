#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[12];
} pessoa;

int main() {
  int n, i, auxL, auxQ;
  float l, q;
  float ar;
  pessoa p[10];

  scanf("%d %f %f", &n, &l, &q);
  if (n > 0 && n <= 10 && l > 0 && l <= 20 && q > 0 && q < 1) {
    for (i = 0; i <= n; i++) {
      fgets(p[i].nome, 12, stdin);
    }
    auxL = l * 1000;
    auxQ = q * 1000;
    ar = (auxL % auxQ) / 1000;
    printf("%s %0.1f\n", p[n].nome, ar);
  }

  return 0;
}