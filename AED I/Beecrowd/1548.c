#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;
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
} Fila;

void inFila(Fila *f) {
  f->inicio = NULL;
  f->fim = NULL;
  f->n = 0;
}

int insFila(Fila *f, Item i) {
  TipoNoh *novoNoh, *ptrAux;

  novoNoh = malloc(sizeof(TipoNoh));

  if (f->n == 0) {
    novoNoh->item = i;
    novoNoh->prox = NULL;
    f->inicio = novoNoh;
    f->fim = novoNoh;
    f->n++;
    return 0;
  }

  if (f->n != 0) {
    ptrAux = f->inicio;
    while (ptrAux->prox != NULL) {
      ptrAux = ptrAux->prox;
    }
    novoNoh->item = i;
    novoNoh->prox = NULL;
    ptrAux->prox = novoNoh;
    f->fim = novoNoh;
    f->n++;
    return 0;
  }

  return -1;
}

int verFila(Fila *f) {
  TipoNoh *ptrAux1, *ptrAux2;
  int k = 0;

  ptrAux1 = f->inicio;
  ptrAux2 = ptrAux1->prox;

  while (ptrAux2->prox != NULL) {
    if (ptrAux1->item.num <= ptrAux2->item.num) {
      k++;
    }
    ptrAux1 = ptrAux2;
    ptrAux2 = ptrAux1->prox;
  }
  return k;
}

int main() {
  Fila f;
  Item item;
  int i, k, count = 0;
  int nCases, nP;

  scanf("%d", &nCases);

  for (i = 0; i < nCases; i++) {
    scanf("%d", &nP);
    inFila(&f);
    for (k = 0; k < nP; k++) {
      scanf("%d", &item.num);
      printf("A\n\n");
      insFila(&f, item);
    }

    count = verFila(&f);
    printf("\nCount = %d\n\n", count);
  }

  return 0;
}