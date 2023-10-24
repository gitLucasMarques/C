#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int num;
  char c;
} Item;

struct noh {
  Item item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct {
  TipoNoh *topo;
} Pilha;

void iniciaPilha(Pilha *);
int pilhaVazia(Pilha *);
int consultaTopo(Pilha *, Item *);

int push(Pilha *, Item);
int pop(Pilha *, Item *);

void imprimeItem(Item);
void imprimePilha(Pilha *);

void liberaPilha(Pilha *);
