#include <stdio.h>

#define TAM 1000

int Receber_Valores(int valor[TAM]) {
  int i, aux;

  for (i = 0; i < TAM; i++) {
    scanf("%d", &aux);
    if (aux == 0) {
      valor[i] = aux;
      break;
    }
    if (aux != 0) {
      valor[i] = aux;
    }
  }

  return i;
}

int Maior_Valor(int valor[TAM], int i, int k) {

  if (valor[i] < k && i >= 1) {
    return Maior_Valor(valor, i - 1, k);
  } else {
    if (i == 0) {
      return k;
    } else {
      k = valor[i];
      return Maior_Valor(valor, i - 1, k);
    }
  }
}
  

void Imprimir_Maior(int maior) {
  printf("\n%d", maior);
  return;
}

int main() {
  int maior, i, valor[TAM], auxMaior, k;

  i = Receber_Valores(valor);
  k = valor[0];
  maior = Maior_Valor(valor, i, k);
  Imprimir_Maior(maior);

  return 0;
}

/*
if (valor[i] > *maior) {
    *maior = valor[i];
    return *maior;
  } else {
    return Maior_Valor(valor, i - 1, maior);
  }
}
*/