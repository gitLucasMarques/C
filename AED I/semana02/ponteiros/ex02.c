#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[30];
  int RA;
  float nota[3];
  int frequencia;
} aluno;

int main(){
  aluno alunoAED;
  aluno *ptrAluno;
  int i;

  printf("Nome: ");
  fgets(alunoAED.nome,sizeof(alunoAED.nome),stdin);
  alunoAED.nome[strlen(alunoAED.nome)-1] = '\0';
  printf("RA: ");
  scanf("%i",&alunoAED.RA);
  for(i=0;i<3;i++){
    printf("Nota%i: ",i+1);
    scanf("%f",&alunoAED.nota[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&alunoAED.frequencia);
  
  ptrAluno = &alunoAED;
  printf("\nNome: %s\n",ptrAluno->nome);
  printf("RA: %i\n",ptrAluno->RA);
  for(i=0;i<3;i++){
    printf("Nota%i: %.2f\n",i+1,ptrAluno->nota[i]);
  }
  printf("Frequencia: %i\n",ptrAluno->frequencia);

  getchar();
  printf("\nNome: ");
  fgets(ptrAluno->nome,sizeof(ptrAluno->nome),stdin);
  ptrAluno->nome[strlen(ptrAluno->nome)-1] = '\0';
  printf("RA: ");
  scanf("%i",&ptrAluno->RA);
  for(i=0;i<3;i++){
    printf("Nota%i: ",i+1);
    scanf("%f",&ptrAluno->nota[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&ptrAluno->frequencia);

  printf("\nNome: %s\n",alunoAED.nome);
  printf("RA: %i\n",alunoAED.RA);
  for(i=0;i<3;i++){
    printf("Nota%i: %.2f\n",i+1,alunoAED.nota[i]);
  }
  printf("Frequencia: %i\n",alunoAED.frequencia);
  
  return 0;
  
}