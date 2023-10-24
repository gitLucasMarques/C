#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaLinearSE.h"

int main(){
  ListaLinearSE lista;
  TipoItem item;
  int i,n;
  
  inicializaLista(&lista);
  
  printf("Número de itens a serem inseridos: ");
  scanf("%i",&n);
  for(i=0;i<n;i++){
    printf("Item %i\n",i+1);
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    item.nome[strlen(item.nome)-1] = '\0';
    if(!insereNoInicio(&lista,item)){
      printf("Erro! Tamanho limite excedido!\n");
      break;
    }
  }

  if(!listaVazia(&lista)){
    printf("\nItens na lista:\n");
    imprimeLista(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }

  if(!removeDoFinal(&lista,&item)){
    printf("Erro! Lista Vazia!\n");
  }
  printf("\nItem removido: %i %s",item.chave,item.nome);

  if(!listaVazia(&lista)){
    printf("\nItens na lista:\n");
    imprimeLista(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }

  if(!removeDoInicio(&lista,&item)){
    printf("Erro! Lista Vazia!\n");
  }
  printf("\nItem removido: %i %s",item.chave,item.nome);

  if(!listaVazia(&lista)){
    printf("\nItens na lista:\n");
    imprimeLista(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }
  
  return 0;
}