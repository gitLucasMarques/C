#include <stdio.h>

int main() {
  int numero, omega, q, j = 0, i, numi = 2, r = 0;
  
  scanf("%d", &numero);
  omega = numero;
  
  while (numero > 1) {
    while (numi <= numero) {
      q = numi;
      while (numero % q == 0) {
        if (numero % q == 0) {
          numero = numero / q;
          j++;
        }
      }
      r = 0;
      numi++;
    }
  }
  
  printf("Omega(%d)=%d\n", omega, j);
  
  return 0;
}