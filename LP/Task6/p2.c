#include <stdio.h>
#include <string.h>

void Receber_lancamentos(char lan[1000]) {
  fgets(lan, 1000, stdin);
  return;
}

void Achar_informacoes(int *lanc, int *cara, int *coroa, char lan[1000], int i) {
  int k = 0, c = 0;
  *lanc = strlen(lan) - 1;
  for (i = 0; i < strlen(lan) - 1; i++) {
    if (lan[i] == 75) {
      k++;
    } else {
      c++;
    }
  }
  *cara = k;
  *coroa = c;
  
  return;
}

void Imprimir_informacoes(int *lanc, int *cara, int *coroa){
  printf("Numero de lancamentos: %d\n", *lanc);
  printf("Quantidade de cara: %d\n", *cara);
  printf("Quantidade de coroa: %d\n", *coroa);
  return;
}

int main() {
  int lanc, cara, coroa, i;
  char lan[1000];

  Receber_lancamentos(lan);
  Achar_informacoes(&lanc, &cara, &coroa, lan, i);
  Imprimir_informacoes(&lanc, &cara, &coroa);

  return 0;
}