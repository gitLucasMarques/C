//Primeiro exemplo de registro (struct)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
  int dia;
  int mes;
  int ano;
};

struct aluno{
  char nome[30];
  struct data dataNasc;
  int ra;
  float notas[3];
  int freq;
};

void imprimeMenu();
void insereAluno(struct aluno[],int);
void listaAlunos(struct aluno[],int);

int main(){
  struct aluno turmaAED[50];
  int n = 0, op = 0;

  while(op != 5){
    imprimeMenu();
    printf("\nOpcao: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        insereAluno(turmaAED,n);
        n++;
        break;
      case 2:
        //removeAluno()
        break;
      case 3:
        listaAlunos(turmaAED,n);
        break;
      case 4:
        //buscarAluno()
        break;
      case 5:
        printf("\nObrigado.");
        break;
      default:
        printf("\nOpção Inválida.");
        break;
    }
  }

  return 0;
}

void imprimeMenu(){
  printf("\n1 - Inserir Aluno.");
  printf("\n2 - Remover Aluno.");
  printf("\n3 - Listar Alunos.");
  printf("\n4 - Buscar Aluno.");
  printf("\n5 - Sair.");
}

void insereAluno(struct aluno turma[],int n){
  int i;

  getchar();
  printf("Nome: ");
  fgets(turma[n].nome,sizeof(turma[n].nome),stdin);
  turma[n].nome[strlen(turma[n].nome)-1] = '\0';
  printf("Data de Nascimento\n");
  printf("Dia: ");
  scanf("%i",&turma[n].dataNasc.dia);
  printf("Mes: ");
  scanf("%i",&turma[n].dataNasc.mes);
  printf("Ano: ");
  scanf("%i",&turma[n].dataNasc.ano);
  printf("RA: ");
  scanf("%i",&turma[n].ra);
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&turma[n].notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&turma[n].freq);
}

void listaAlunos(struct aluno turma[],int n){
  int i,j;

  for(i=0;i<n;i++){
    printf("\n\nNome: %s\n",turma[i].nome);
    printf("Data de Nascimento: %i/%i/%i\n",turma[i].dataNasc.dia,turma[i].dataNasc.mes,turma[i].dataNasc.ano);
    printf("RA: %i\n",turma[i].ra);
    for(j=0;j<3;j++)
      printf("Nota %i: %.2f\n",i+1,turma[i].notas[j]);
    printf("Frequencia: %i\n",turma[i].freq);
  }
}