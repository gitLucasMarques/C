#include <stdio.h>

int main() {
  int quantNum, contador, numero;
  float media, total;

  scanf("%d", &quantNum);

  total = 0;
  contador = 1;
  while(contador<=quantNum){
    scanf("%d", &numero);
    total = total + numero;
    contador++;
  }
  media = (total)/(quantNum);
  printf("A media aritmética dos %d valores é: %0.1f", quantNum, media);
  
return 0;
}