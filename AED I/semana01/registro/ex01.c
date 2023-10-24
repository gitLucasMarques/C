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

int main(){
  struct aluno alunoAED;
  int i;

  //Lendo os dados do aluno
  printf("Nome: ");
  fgets(alunoAED.nome,sizeof(alunoAED.nome),stdin);
  alunoAED.nome[strlen(alunoAED.nome)-1] = '\0';
  printf("Data de Nascimento\n");
  printf("Dia: ");
  scanf("%i",&alunoAED.dataNasc.dia);
  printf("Mes: ");
  scanf("%i",&alunoAED.dataNasc.mes);
  printf("Ano: ");
  scanf("%i",&alunoAED.dataNasc.ano);
  printf("RA: ");
  scanf("%i",&alunoAED.ra);
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&alunoAED.notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&alunoAED.freq);

  //Imprimindo os dados lidos
  printf("\n\nNome: %s\n",alunoAED.nome);
  printf("Data de Nascimento: %i/%i/%i\n",alunoAED.dataNasc.dia,alunoAED.dataNasc.mes,alunoAED.dataNasc.ano);
  printf("RA: %i\n",alunoAED.ra);
  for(i=0;i<3;i++)
    printf("Nota %i: %.2f\n",i+1,alunoAED.notas[i]);
  printf("Frequencia: %i\n",alunoAED.freq);

  return 0;
}