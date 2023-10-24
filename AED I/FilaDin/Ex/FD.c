#include "FD.h"

void iniciaFila(FD *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->n = 0;
}

int filaVazia(FD *fila) {
  if (fila->n == 0) {
    return 0;
  }
  return -1;
}

void imprimeItem(Item item) { printf("%d ", item.num); }

void imprimeFila(FD *fila) {
  TipoNoh *ptrAux;

  if (filaVazia(fila) < 0) {
    ptrAux = fila->inicio;
    while (ptrAux->prox != NULL) {
      imprimeItem(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
    imprimeItem(ptrAux->item);
  } else {
    printf("Fila vazia!\n");
  }
}

int insereFila(FD *fila, Item item) { // insere no fim da fila
  TipoNoh *novoNoh, *ptrAux;

  novoNoh = malloc(sizeof(TipoNoh));

  if (filaVazia(fila) >= 0) {
    novoNoh->item = item;
    novoNoh->prox = NULL;
    fila->inicio = novoNoh;
    fila->fim = novoNoh;
    fila->n++;
    return 0;
  }

  if (filaVazia(fila) < 0) {
    ptrAux = fila->inicio;
    while (ptrAux->prox != NULL) {
      ptrAux = ptrAux->prox;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    ptrAux->prox = novoNoh;
    fila->fim = novoNoh;
    fila->n++;
    return 0;
  }
  return -1;
}

int retiraFila(FD *fila) { // remove do inicio da fila
  TipoNoh *ptrAux;

  if (filaVazia(fila) < 0) {
    ptrAux = fila->inicio;
    ptrAux = ptrAux->prox;
    fila->inicio = ptrAux;
    fila->n--;
    return 0;
  }
  return -1;
}

void buscaFila(FD *fila, int num) {
  TipoNoh *ptrAux;

  ptrAux = fila->inicio;
  while (ptrAux->prox != NULL) {
    if (ptrAux->item.num == num) {
      printf("Nome encontrado na posição %d\n", ptrAux->item.num);
    }
    ptrAux = ptrAux->prox;
  }
}

void liberaFila(FD *fila) {
  TipoNoh *ptrAux1, *ptrAux2;

  ptrAux1 = fila->inicio;
  ptrAux2 = ptrAux1->prox;

  while (ptrAux1->prox != NULL) {
    free(ptrAux1);
    ptrAux1 = ptrAux2;
    ptrAux2 = ptrAux1->prox;
  }
  free(ptrAux1);
}