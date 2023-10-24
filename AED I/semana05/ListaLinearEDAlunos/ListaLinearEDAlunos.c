#include "ListaLinearEDAlunos.h"

int listaVazia(ListaLinearED *lista){
  return lista->ultimo==0;
}

void inicializaLista(ListaLinearED *lista){
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void destroiLista(ListaLinearED* lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void imprimeItem(TipoItem item){
  int i;
  printf("\nRa: %i",item.RA);
  printf("\nNome: %s",item.nome);
  for(i=0;i<3;i++){
    printf("\nNota %i: %.1f",i+1,item.notas[i]);
  }
  printf("\nFrequencia: %i\n",item.freq);
}


void imprimeLista(ListaLinearED *lista){
  TipoNoh *ptrAux;
  if(!listaVazia(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux != NULL){
      imprimeItem(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}

int insereNoFinal(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if(!listaVazia(lista)){
      while(ptrAux->prox != NULL)
        ptrAux = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else{
      lista->inicioLista = novoNoh;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int insereNoInicio(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    novoNoh->item = item;
    novoNoh->prox = lista->inicioLista;
    lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int removeDoFinal(ListaLinearED *lista,TipoItem *item){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista->inicioLista = NULL;
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
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int removeDoInicio(ListaLinearED *lista, TipoItem *item){
  TipoNoh *ptrAux;
  if(!listaVazia(lista)){
    ptrAux = lista->inicioLista;
    *item = ptrAux->item;
    lista->inicioLista = ptrAux->prox;
    free(ptrAux);
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int buscaItemNaLista(ListaLinearED *lista,int info,TipoItem *item,int *pos){
  TipoNoh *ptrAux;
  int cont=1;
  if(!listaVazia(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux!=NULL){
      if(verificaIgualdade(ptrAux->item,info)){
        *item = ptrAux->item;
        *pos = cont;
        return 1;
      }
      cont++;
      ptrAux = ptrAux->prox;
    }
  }
  return 0;
}

int retiraDaPosicao(ListaLinearED *lista, TipoItem *item, int pos){
  int cont=1;
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista->inicioLista;
    while(cont<pos && ptrAux1->prox!=NULL){
      ptrAux2 = ptrAux1;
      ptrAux1 = ptrAux1->prox;
      cont++;
    }
    if(cont==pos){
      *item = ptrAux1->item;
      if(ptrAux1==lista->inicioLista){
        lista->inicioLista = ptrAux1->prox;
      }
      else{
        ptrAux2->prox = ptrAux1->prox;
      }
      lista->ultimo--;
      free(ptrAux1);
      return 1;
    }
  }
  return 0;
}

int retiraEspecifico(ListaLinearED *lista,int info,TipoItem *item,int *pos){
  if(!listaVazia(lista)){
    if(buscaItemNaLista(lista,info,item,pos) && retiraDaPosicao(lista,item,*pos))
      return 1;
  }
  return 0;
}

int verificaIgualdade(TipoItem item,int info){
  if(item.RA==info)
    return 1;
  return 0;
}

