#include <stdio.h>
#include <string.h>

void Receber_String(char string[1000]) {
  fgets(string, 1000, stdin);
  return;
}

void Ordenar_String(int i, char stringPrimeiro, char stringUltimo, char string[1000], int tam) {
  for (i = 0; i < (tam - 1)/2; i++) {
    stringPrimeiro = string[i];
    stringUltimo = string[tam-2-i];

    string[i] = stringUltimo;
    string[tam-2-i] = stringPrimeiro;
  }
  return;
}

void Imprimir_String_Inversa(char string[1000]){
  printf("%s", string);
  return; 
}
  
int main(){
    int i, k, tam;
    char string[1000] = {" "}, stringPrimeiro, stringUltimo;

    Receber_String(string);

    tam = strlen(string);

    Ordenar_String(i, stringPrimeiro, stringUltimo, &string[i], tam);
    Imprimir_String_Inversa(string);

  return 0;
}