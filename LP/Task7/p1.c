#include <stdio.h>

void Receber_N(int *n) {

  scanf("%d", n);
  return;
}

int Analisa_N(int n) {
  int k = 0;

  if (n < 0) {
    k++;
  }
  return k;
}

int Fatorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * Fatorial(n - 1);
  }
}

void Imprimir(int n, int f, int k){
  switch(k){
    case 0: printf("O fatorial de %d é: %d", n, f);
    break;
    case 1: printf("Não existe fatorial de %d", n);
    break;
  }
  return;
}

int main() {
  int n, f, k;

  Receber_N(&n);
  k = Analisa_N(n);
  if (k == 0){
    f = Fatorial(n);
    Imprimir(n, f, k);
  }else{
    Imprimir(n, f, k);
  }

  return 0;
}