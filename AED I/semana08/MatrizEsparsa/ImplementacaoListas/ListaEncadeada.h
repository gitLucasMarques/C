#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int coluna;
  int elemento;
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef TipoNoh *TipoLista;

int listaVazia(TipoLista);
TipoLista inicializaLista(TipoLista); 
TipoLista destroiLista(TipoLista);
void imprimeLista(TipoLista,int);
TipoLista insereNoFinal(TipoLista,TipoItem);
TipoLista insereNoInicio(TipoLista,TipoItem);
TipoLista insereOrdenado(TipoLista,TipoItem);
TipoLista removeDoFinal(TipoLista,TipoItem*);
TipoLista removeDoInicio(TipoLista,TipoItem*);
TipoLista removeEspecifico(TipoLista,int,TipoItem*);
