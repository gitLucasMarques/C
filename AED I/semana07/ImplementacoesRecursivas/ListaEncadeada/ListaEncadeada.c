#include "ListaEncadeada.h"

int listaVazia(TipoLista lista){
  return lista==NULL;
}

void inicializaLista(TipoLista lista){
  lista = NULL;
}

void destroiLista(TipoLista lista){
  TipoNoh *ptrAux;
  if(lista!=NULL){
    ptrAux = lista->prox;
    free(lista);
    destroiLista(ptrAux);
  }
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);  
}

void imprimeLista(TipoLista lista){
  if(lista!=NULL){
    imprimeItem(lista->item);
    imprimeLista(lista->prox);
  }
}

TipoLista insereNoFinal(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  if(lista==NULL){
    novoNoh = (TipoNoh *) malloc(sizeof(TipoNoh));
    novoNoh->item = item;
    novoNoh->prox = NULL;
    return novoNoh;
  }
  else{
    lista->prox = insereNoFinal(lista->prox,item);
    return lista;
  }
}

TipoLista insereNoInicio(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh *) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = lista;
  return novoNoh;
}

TipoLista removeDoFinal(TipoLista lista,TipoItem *item){
  if(lista!=NULL){
    if(lista->prox==NULL){
      *item = lista->item;
      free(lista);
      return NULL;
    }
    else{
      lista->prox = removeDoFinal(lista->prox,item);
      return lista;
    }
  }
  return NULL;
}

TipoLista removeDoInicio(TipoLista lista,TipoItem *item){
  TipoNoh *ptrAux;
  if(lista!=NULL){
    ptrAux = lista;
    lista = lista->prox;
    *item = ptrAux->item;
    free(ptrAux);
    return lista;
  }
  return NULL;
}