#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int chave;
  char nome[30];
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct noh* TipoLista;

int listaVazia(TipoLista);
void inicializaLista(TipoLista);
void destroiLista(TipoLista);
void imprimeItem(TipoItem);
void imprimeLista(TipoLista);
TipoLista insereNoFinal(TipoLista,TipoItem);
TipoLista insereNoInicio(TipoLista,TipoItem);
TipoLista removeDoFinal(TipoLista,TipoItem*);
TipoLista removeDoInicio(TipoLista,TipoItem*);