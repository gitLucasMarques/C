#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int coluna;
  int elemento;
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

typedef LLSD *Lista;

Lista iniciaLista(Lista);
int listaVazia(Lista);

Lista insereInicio(Lista, Item);
Lista insereFinal(Lista, Item);
LLSD insereOrdenado(Lista, Item, int);

void imprimeItem(Item);
void imprimeLista(Lista);

Lista retiraInicio(Lista);
Lista retiraFinal(Lista);
Lista retiraEspecifico(Lista, int);

void liberaLista(Lista);