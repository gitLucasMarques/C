#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int pos;
  char nome[20];
} Item;

struct noh {
  Item item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct {
  TipoNoh *inicio;
  int ultimo;
} LLSD;

void iniciaLista(LLSD *);
int listaVazia(LLSD *);

int insereInicio(LLSD *, Item);
int insereFinal(LLSD *, Item);
int insereOrdenado(LLSD *, Item, int);

void imprimeItem(Item);
void imprimeLista(LLSD *);

void buscaNome(LLSD *, char *);

int retiraInicio(LLSD *);
int retiraFinal(LLSD *);
int retiraEspecifico(LLSD *, int);

void liberaLista(LLSD *);