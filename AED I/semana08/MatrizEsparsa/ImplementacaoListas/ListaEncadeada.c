#include "ListaEncadeada.h"

int listaVazia(TipoLista lista){
  return lista==NULL;
}

TipoLista inicializaLista(TipoLista lista){
  return NULL;
}

TipoLista destroiLista(TipoLista lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  return NULL;
}

void imprimeLista(TipoLista lista,int n){
  TipoNoh *ptrAux;
  int cont = 0;
  if(!listaVazia(lista)){
    ptrAux = lista;
    while(ptrAux != NULL){
      while(ptrAux->item.coluna>cont){
        printf("0\t");
        cont++;
      }
      printf("%i\t",ptrAux->item.elemento);
      cont++;
      ptrAux = ptrAux->prox;
    }
  }
  while(cont<n){
    printf("0\t");
    cont++;
  }
  printf("\n");
}

TipoLista insereNoFinal(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  ptrAux = lista;
  if(!listaVazia(lista)){
    while(ptrAux->prox != NULL)
      ptrAux = ptrAux->prox;
    ptrAux->prox = novoNoh;
  }
  else{
    lista = novoNoh;
  }
  novoNoh->item = item;
  novoNoh->prox = NULL;
  return lista;
}

TipoLista insereNoInicio(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = lista;
  lista = novoNoh;
  return lista;
}

TipoLista insereOrdenado(TipoLista lista,TipoItem item){
  if(listaVazia(lista)){
    lista = insereNoInicio(lista,item);
    return lista;
  }
  if(lista->item.coluna==item.coluna)
    lista->item.elemento = item.elemento;
  else
    if(lista->item.coluna>item.coluna)
      lista = insereNoInicio(lista,item);
    else
      lista->prox = insereOrdenado(lista->prox,item);
  return lista;
}

TipoLista removeDoFinal(TipoLista lista,TipoItem *item){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista = NULL;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else{
      while(ptrAux2->prox != NULL){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = NULL;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    return lista;
  }
  return NULL;
}

TipoLista removeDoInicio(TipoLista lista, TipoItem *item){
  TipoNoh *ptrAux;
  if(!listaVazia(lista)){
    ptrAux = lista;
    *item = ptrAux->item;
    lista = ptrAux->prox;
    free(ptrAux);
    return lista;
  }
  return NULL;
}

TipoLista removeEspecifico(TipoLista lista,int coluna,TipoItem *item){
  TipoNoh *ptrAux;
  
  if(!listaVazia(lista)){
    if(lista->item.coluna==coluna){
      ptrAux = lista;
      *item = ptrAux->item;
      lista = ptrAux->prox;
      free(ptrAux);
      return lista;
    }
    lista->prox = removeEspecifico(lista->prox,coluna,item);
    return lista;
  }
  return NULL;
}