#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaLinearSEAlunos.h"

void imprimeMenu();
void leDadosAluno(TipoItem*);
void imprimeDadosAluno(TipoItem);

int main(){
  ListaLinearSE turmaAED;
  int op = 0, RA, pos;
  TipoItem item;
  
  inicializaLista(&turmaAED);
  
  while(op != 5){
    imprimeMenu();
    printf("\nOpcao: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosAluno(&item);
        if(insereNoFinal(&turmaAED,item)){
          printf("\nAluno matriculado!\n");
        }
        else{
          printf("\nNão foi possível matricular o aluno!\n");
        }
        break;
      case 2:
        printf("RA a ser buscado: ");
        scanf("%i",&RA);
        if(retiraEspecifico(&turmaAED,RA,&item,&pos))
          printf("\nAluno retirado com sucesso!\n");
        else
          printf("\nErro! Não foi possível retirar o aluno!\n");
        break;
      case 3:
        printf("RA a ser buscado: ");
        scanf("%i",&RA);
        if(buscaItemNaLista(&turmaAED,RA,&item,&pos)){
          printf("\nAluno:\n");
          imprimeDadosAluno(item);
        }
        else{
          printf("\nAluno não encontrado!\n");
        }
        break;
      case 4:
        if(!listaVazia(&turmaAED)){
          printf("\nAlunos:\n");
          imprimeLista(&turmaAED);
        }
        else{
          printf("\nNenhum aluno matriculado!\n");
        }
        break;
      case 5:
        destroiLista(&turmaAED);
        printf("\nFim!\n");
        break;
      default:
        printf("\nOpção incorreta!\n");
        break;
    }
  }
}

void imprimeMenu(){
  printf("\nMenu:");
  printf("\n1 - Inserir aluno.");
  printf("\n2 - Retirar aluno.");
  printf("\n3 - Buscar aluno pelo RA.");
  printf("\n4 - Listar Alunos.");
  printf("\n5 - Sair.");
}

void leDadosAluno(TipoItem *item){
  int i;
  printf("\nRA: ");
  scanf("%i",&item->RA);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&item->notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&item->freq);
}

void imprimeDadosAluno(TipoItem item){
  int i;
  printf("\nRa: %i",item.RA);
  printf("\nNome: %s",item.nome);
  for(i=0;i<3;i++){
    printf("\nNota %i: %.1f",i+1,item.notas[i]);
  }
  printf("\nFrequencia: %i\n",item.freq);
}