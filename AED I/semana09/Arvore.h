#include <stdio.h>
#include <stdlib.h>

struct nohLista {
  struct nohArvore *item;
  struct nohLista *prox;
};

struct nohArvore {
  char dado;
  struct nohLista *listaFilhos;
};

typedef struct nohArvore *TipoItem;

typedef struct nohLista TipoNoh;

typedef TipoNoh *TipoLista;

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

// Funções Lista
int listaVazia(TipoLista);
TipoLista inicializaLista(TipoLista);
TipoLista destroiLista(TipoLista);
TipoLista insereNoFinal(TipoLista, TipoItem);
TipoLista insereNoInicio(TipoLista, TipoItem);
TipoLista insereOrdenado(TipoLista, TipoItem);
TipoLista removeDoFinal(TipoLista, TipoItem *);
TipoLista removeDoInicio(TipoLista, TipoItem *);
void imprimeLista(TipoLista, int);

// Funções Árvore
int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(TipoArvore, char);
TipoArvore insereNaArvore(TipoArvore, TipoArvore);
void imprimeArvore(TipoArvore, int);