#include <stdio.h>

int Receber_numero(int numero){
  scanf("%d", &numero);
  return numero;
}

int Divisao_por_primos(int numero, int numi, int q, int j, int r){
  
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
  return j;
}

void Imprimir_omega(omega, j){
  printf("Omega(%d)=%d\n", omega, j);
  return;
}

int main() {
  int numero, omega, q, j = 0, i, numi = 2, r = 0;

  numero = Receber_numero(numero);
  omega = numero;

  j = Divisao_por_primos(numero, numi, q, j, r);
  
  Imprimir_omega(omega, j);
  
  return 0;
}