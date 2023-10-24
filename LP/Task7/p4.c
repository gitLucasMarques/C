#include <stdio.h>

#define TAM 1000

int Receber_Valores(float valor[TAM]) {
  int i;
  float aux;

  for (i = 0; i < TAM; i++) {
    scanf("%f", &aux);
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

float Media_Aritmetica(int i, float valor[TAM], float *soma, int k) {

  if (i < 0) {
    return (*soma) / (k);
  } else {
    *soma += valor[i];
    return Media_Aritmetica(i - 1, valor, soma, k);
  }
}

void Imprimir_Media(int i, float media) {
  printf("\nA media aritmética dos %d valores é: %0.1f\n", i, media);
  return;
}

int main() {
  int i, k;
  float media, valor[TAM] = {0}, soma = 0;

  i = Receber_Valores(valor);
  k = i;
  media = Media_Aritmetica(i, valor, &soma, k);
  Imprimir_Media(i, media);

  return 0;
}
