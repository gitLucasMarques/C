#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"

void imprimeMenu();
void leDadosItem(TipoItem*);
void imprimeDadosItem(TipoItem);

int main(){
  TipoLista lista;
  TipoItem item;
  int op = 0;
  
  inicializaLista(lista);

  while(op!=6){
    imprimeMenu();
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosItem(&item);
        lista = insereNoInicio(lista,item);
        break;
      case 2:
        leDadosItem(&item);
        lista = insereNoFinal(lista,item);
        break;
      case 3:
        lista = removeDoInicio(lista,&item);
        printf("\nItem removido: ");
        imprimeDadosItem(item);
        break;
      case 4:
        lista = removeDoFinal(lista,&item);
        printf("\nItem removido: ");
        imprimeDadosItem(item);
        break;
      case 5:
        printf("\nLista:\n");
        imprimeLista(lista);
        break;
      case 6:
        destroiLista(lista);
        break;
      default:
        printf("\nOpção incorreta.\n");
        break;
    }
  }
  
}

void imprimeMenu(){
  printf("\nMenu:");
  printf("\n1 - Inserir no início");
  printf("\n2 - Inserir no final");
  printf("\n3 - Remover do início");
  printf("\n4 - Remover do final");
  printf("\n5 - Listar");
  printf("\n6 - Sair");
  printf("\nOpção: ");
}

void leDadosItem(TipoItem *item){
  printf("Chave: ");
  scanf("%i",&item->chave);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
}

void imprimeDadosItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}