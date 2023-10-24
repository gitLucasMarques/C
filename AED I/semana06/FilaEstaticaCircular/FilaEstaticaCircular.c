#include "FilaEstaticaCircular.h"

void inicializaFila(TipoFila *fila){
  fila->inicio = -1;
  fila->fim = 0;
}

void destroiFila(TipoFila *fila){
  TipoItem item;
  while(!filaVazia(fila))
    retiraDaFila(fila,&item);
}

int filaVazia(TipoFila *fila){
  return fila->inicio==-1;
}

int filaCheia(TipoFila *fila){
  return fila->inicio==fila->fim;
}

int insereNaFila(TipoFila *fila,TipoItem item){
  if(!filaCheia(fila)){
    if(filaVazia(fila))
      fila->inicio = 0;
    fila->itens[fila->fim] = item;
    fila->fim = (fila->fim+1)%MAX;
    return 1;
  }
  return 0;
}

int retiraDaFila(TipoFila *fila,TipoItem *item){
  if(!filaVazia(fila)){
    *item = fila->itens[fila->inicio];
    fila->inicio = (fila->inicio+1)%MAX;
    if(fila->inicio==fila->fim){
      fila->inicio = -1;
      fila->fim = 0;
    }
    return 1;
  }
  return 0;
}

int imprimeFila(TipoFila *fila){
  int i;
  if(!filaVazia(fila)){
    if(fila->inicio<fila->fim){
      for(i=fila->inicio;i<fila->fim;i++)
        imprimeItem(fila->itens[i]);
    }
    else{
      for(i=fila->inicio;i<MAX;i++)
        imprimeItem(fila->itens[i]);
      for(i=0;i<fila->fim;i++)
        imprimeItem(fila->itens[i]);
    }
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}