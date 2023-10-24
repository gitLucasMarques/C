#include <stdio.h>
#include <string.h>

void Receber_Strings(char string1[1000], char string2[1000]) {
  scanf("%s", string1);
  scanf("%s", string2);
  return;
}

int Comparar_Strings(int i, char string1[1000], int k, char string2[1000], int ocorr, int auxOcorr) {
  auxOcorr = 0;
  ocorr = 0;
  for (i = 0; i < strlen(string1); i++) {
    for (k = 0; k < strlen(string2); k++) {      
      if (string1[i + k] == string2[k]) {
        auxOcorr++;
      }
      if (auxOcorr == strlen(string2)) {
        ocorr++;
      }
    }
    auxOcorr = 0;
  }
  return ocorr;
}

void Quantidade_Ocorrencias(int ocor) {
  printf("\nNúmero de ocorrência: %d", ocor);
  return;
}

int main() {
  char string1[1000], string2[1000];
  int i, k, ocorr, auxOcorr, x;

  Receber_Strings(string1, string2);

  x = Comparar_Strings(i, &string1[i], k, &string2[k], ocorr, auxOcorr);
  Quantidade_Ocorrencias(x);

  return 0;
}