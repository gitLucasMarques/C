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
  TipoNoh *fim;
  int n;
} FD;

void iniciaFila(FD *);
int filaVazia(FD *);

void imprimeItem(Item);
void imprimeFila(FD *);

int insereFila(FD *, Item);
int retiraFila(FD *);
void buscaFila(FD *, char *);

void liberaFila(FD *);