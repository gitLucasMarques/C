#include "FilaDinamicaCircular.h"

void inicializaFila(TipoFila *fila){
  fila->n = 0;
  fila->fim = NULL;
}

void destroiFila(TipoFila *fila){
  TipoItem item;
  while(!filaVazia(fila))
    retiraDaFila(fila,&item);
}

int filaVazia(TipoFila *fila){
  return fila->n==0;
}

int insereNaFila(TipoFila *fila,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh!=NULL){
    
    return 1;
  }
  return 0;
}

int retiraDaFila(TipoFila *fila,TipoItem *item){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    
    return 1;
  }
  return 0;
}

int imprimeFila(TipoFila *fila){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}