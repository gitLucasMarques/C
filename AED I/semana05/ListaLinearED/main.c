#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaLinearED.h"

int main(){
  ListaLinearED lista;
  TipoItem item;
  int n, i;

  inicializaLista(&lista);
  printf("Numeros de itens a serem inseridos: ");
  scanf("%i",&n);
  for(i=0;i<n;i++){
    printf("Item %i\n",i+1);
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    item.nome[strlen(item.nome)-1] = '\0';
    if(!insereNoFinal(&lista,item)){
      printf("\nErro! Não foi possível inserir!\n");
      break;
    }
  }

  if(!listaVazia(&lista)){
    printf("\nLista: \n");
    imprimeLista(&lista);
  }
  else
    printf("\nLista Vazia!\n");

  if(removeDoFinal(&lista,&item))
    printf("\nItem Removido: %i %s\n",item.chave,item.nome);
  else
    printf("\nLista Vazia!\n");

  if(!listaVazia(&lista)){
    printf("\nLista: \n");
    imprimeLista(&lista);
  }
  else
    printf("\nLista Vazia!\n");
  
  destroiLista(&lista);

  return 0;
}