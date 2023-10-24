#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[30];
  int RA;
  float notas[3];
  int frequencia;
} aluno;

int main(){
  aluno turmaAED[5];
  aluno *ptrAluno;
  int i,j;

  ptrAluno = turmaAED;
  for(i=0;i<5;i++){
    printf("\nNome: ");
    fgets(ptrAluno[i].nome,sizeof(ptrAluno[i].nome),stdin);
    ptrAluno[i].nome[strlen(ptrAluno[i].nome)-1] = '\0';
    printf("RA: ");
    scanf("%i",&ptrAluno[i].RA);
    for(j=0;j<3;j++){
      printf("Nota%i: ",i+1);
      scanf("%f",&ptrAluno[i].notas[j]);
    }
    printf("Frequencia: ");
    scanf("%i",&ptrAluno[i].frequencia);
    getchar();
  }

  for(i=0;i<5;i++){
    printf("\n\nNome: %s",turmaAED[i].nome);
    printf("\nRA: %i",turmaAED[i].RA);
    for(j=0;j<3;j++){
      printf("\nNota%i: %.2f",i+1,turmaAED[i].notas[j]);
    }
    printf("\nFrequencia: %i",turmaAED[i].frequencia);
  }
  
}