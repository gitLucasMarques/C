#include "ListaLinearSE.h"

int listaVazia(ListaLinearSE *lista){
  return lista->ultimo==0;
}

int listaCheia(ListaLinearSE *lista){
  return lista->ultimo==MAX;
}

void inicializaLista(ListaLinearSE *lista){
  lista->ultimo = 0;
}

void destroiLista(ListaLinearSE *lista){
  lista->ultimo = 0;
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}

void imprimeLista(ListaLinearSE *lista){
  int i;

  for(i=0;i<lista->ultimo;i++){
    imprimeItem(lista->itens[i]);
  }
}


int insereNoFinal(ListaLinearSE *lista, TipoItem novoItem){
  int pos = lista->ultimo;

  if(!listaCheia(lista)){
    lista->itens[pos] = novoItem;
    lista->ultimo++;
    return 1;
  }
  else
    return 0;
}

int insereNoInicio(ListaLinearSE *lista, TipoItem novoItem){
  int pos = lista->ultimo;
  int i;

  if(!listaCheia(lista)){
    for(i=pos;i>0;i--)
      lista->itens[i] = lista->itens[i-1];
    lista->itens[0] = novoItem;
    lista->ultimo++;
    return 1;
  }
  else
    return 0;
}

int removeDoFinal(ListaLinearSE *lista,TipoItem *item){
  int pos = lista->ultimo;

  if(!listaVazia(lista)){
    *item = lista->itens[pos-1];
    lista->ultimo--;
    return 1;
  }
  else
    return 0;
}

int removeDoInicio(ListaLinearSE *lista,TipoItem *item){
  int pos = lista->ultimo;
  int i;
  
  if(!listaVazia(lista)){
    *item = lista->itens[0];
    for(i=1;i<pos;i++){
      lista->itens[i-1] = lista->itens[i];
    }
    lista->ultimo--;
    return 1;
  }
  else
    return 0;
}