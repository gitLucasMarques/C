#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[30];
  int RA;
  float notas[3];
  int frequencia;
} aluno;

int main() {
  aluno turmaAED[5];
  aluno *ptrAluno;
  int i, j;

  ptrAluno = turmaAED;

  for (i = 0; i < 5; i++) {
    printf("\nNome: ");
    fgets(turmaAED[i].nome, sizeof(turmaAED[i].nome), stdin);
    turmaAED[i].nome[strlen(turmaAED[i].nome) - 1] = '\0';
    printf("RA: ");
    scanf("%i", &turmaAED[i].RA);
    for (j = 0; j < 3; j++) {
      printf("Nota%i: ", i + 1);
      scanf("%f", &turmaAED[i].notas[j]);
    }
    printf("Frequencia: ");
    scanf("%i", &turmaAED[i].frequencia);
    getchar();
  }

  for (i = 0; i < 5; i++, ptrAluno++) {
    printf("\n\nNome: %s", ptrAluno->nome);
    printf("\nRA: %i", ptrAluno->RA);
    for (j = 0; j < 3; j++) {
      printf("\nNota%i: %.2f", i + 1, ptrAluno->notas[j]);
    }
    printf("\nFrequencia: %i", ptrAluno->frequencia);
  }
}