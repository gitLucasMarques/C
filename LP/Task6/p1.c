#include <stdio.h>
#include <string.h>

void Receber_frase(int i, char frase1[100], char frase2[100]){
  fgets(frase1, 100, stdin);
  for(i = 0; i < strlen(frase1); i++){
    if(i == strlen(frase1) - 1){
      frase1[i] = 0;
    }
  }
  
  i = 0;
  fgets(frase2, 100, stdin);
  for(i = 0; i < strlen(frase2); i++){
    if(i == strlen(frase2) - 1){
      frase2[i] = 0;
    }
  }
  return;
}

int Codificar_hash(int i, char frase[100], int hash[100]){
  int soma = 0;
  for(i = 0; i < strlen(frase); i++){
    hash[i] = frase[i];
    soma += hash[i];
  }
  return soma;
}

void Imprimir_hash(int i, int soma, char frase[100]){
  printf("Str%d: %s - Codificaçao Hash: %d\n", i, frase, soma);
  return;
}

int main() {
  char frase1[100], frase2[100];
  int i, soma_hash1, soma_hash2, hash[100] = {0};

  Receber_frase(i, frase1, frase2);

  soma_hash1 = Codificar_hash(i, frase1, hash);
  soma_hash2 = Codificar_hash(i, frase2, hash);

  i = 1;
  Imprimir_hash(i ,soma_hash1, frase1);
  i = 2;
  Imprimir_hash(i, soma_hash2, frase2);
    
  return 0;
}