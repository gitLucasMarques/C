#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char x;
} TipoItem;

typedef struct noh {
  TipoItem item;
  struct noh *prox;
} TipoNoh;

typedef struct {
  TipoNoh *topo;
} TipoPilha;

void inicializaPilha(TipoPilha *);
void destroiPilha(TipoPilha *);
int pilhaVazia(TipoPilha *);
int empilha(TipoPilha *, TipoItem);
int desempilha(TipoPilha *, TipoItem *);
int consultaTopo(TipoPilha *, TipoItem *);
int imprimePilha(TipoPilha *);
void imprimeItem(TipoItem);