#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insere_hash(int *, int, int);
void pesquisa_hash(int *, int, int);
void remove_hash(int *, int, int);
void imprime_hash(int *, int);

int hash_um(int, int);
int hash_dois(int, int);
int duplo_hash(int *, int, int);

int main() {
  int *vetor;
  int tam, aux, pesq;
  int i = 0, r;

  scanf("%d", &tam);

  vetor = malloc(tam * sizeof(int));

  for (i = 0; i < tam; i++) {
    vetor[i] = -2;
  }

  scanf("%d", &aux);
  while (aux != -1) {
    r = duplo_hash(vetor, aux, tam);
    insere_hash(vetor, r, aux);
    scanf("%d", &aux);
  }

  scanf("%d", &pesq);
  pesquisa_hash(vetor, pesq, tam);
  printf("\n");

  free(vetor);

  return 0;
}
void insere_hash(int *vetor, int i, int num) { vetor[i] = num; }

void pesquisa_hash(int *vetor, int pesq, int tam) {
  int k = 0, i;

  for (i = 0; i < tam; i++) {
    if (vetor[i] == pesq) {
      remove_hash(&vetor[i], pesq, tam);
      imprime_hash(vetor, tam);
      k = 1;
      break;
    }
  }

  if (k == 0) {
    printf("Valor nao encontrado\n");
    imprime_hash(vetor, tam);
  }
}

void remove_hash(int *vetor, int pesq, int tam) {
  int i = 0;

  for (i = 0; i < tam; i++) {
    if (vetor[i] == pesq) {
      vetor[i] = -1;
    }
  }
}

void imprime_hash(int *vetor, int tam) {
  int i;

  for (i = 0; i < tam; i++) {
    if (vetor[i] == -2) {
      printf("\\ ");
    }

    if (vetor[i] == -1) {
      printf("D ");
    }

    if (vetor[i] >= 0) {
      printf("%d ", vetor[i]);
    }
  }
}

int hash_um(int num, int tam) { return num % tam; }

int hash_dois(int num, int tam) { return 1 + (num % (tam - 1)); }

int duplo_hash(int *vetor, int num, int tam) {
  int hash;
  int j = 0;

  hash = (hash_um(num, tam) + (j * hash_dois(num, tam))) % tam;

  if (vetor[hash] == -2) {
    return hash;
  } else {
    while (vetor[hash] != -2) {
      j++;
      hash = (hash_um(num, tam) + (j * hash_dois(num, tam))) % tam;
    }
    return hash;
  }
}