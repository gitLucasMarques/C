// Escreva um programa recursivo que dado um número inteiro N, imprimir se é
// primo ou não-primo.

#include <stdio.h>

void Receber_Numero(int *n) {
  scanf("%d", n);
  return;
}

int Verificar_Primo(int n, int i) {

  if(n == 2){
    return 2;
  }
  if (n <= 1) {
    return 1;
  } else {
    if (n % i != 0 && i <= (n / 2)) {
      return Verificar_Primo(n, i + 1);
    } else {
      if (n % i == 0) {
        return 1;
      } else {
        return 2;
      }
    }
  }
}

void Imprimir(int n, int i) {
  switch (i) {
  case 1:
    printf("O número %d não é primo!", n);
    break;

  case 2:
    printf("O número %d é primo!", n);
    break;
  }
  return;
}

int main() {
  int n, i;

  Receber_Numero(&n);
  i = Verificar_Primo(n, 2);
  Imprimir(n, i);

  return 0;
}