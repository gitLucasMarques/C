#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
  int chave;
  char nome[30];
} TipoItem;

struct noh {
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

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