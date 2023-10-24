#include "FilaDinamica.h"

void inicializaFila(TipoFila *fila) {
  fila->n = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
}

void destroiFila(TipoFila *fila) {
  TipoItem item;
  while (!filaVazia(fila))
    retiraDaFila(fila, &item);
}

int filaVazia(TipoFila *fila) { return fila->n == 0; }

int insereNaFila(TipoFila *fila, TipoItem item) {
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  if (novoNoh != NULL) {
    if (!filaVazia(fila)) {
      fila->fim->prox = novoNoh;
    } else {
      fila->inicio = novoNoh;
    }
    fila->n++;
    novoNoh->item = item;
    novoNoh->prox = NULL;
    fila->fim = novoNoh;
    return 1;
  }
  return 0;
}

int retiraDaFila(TipoFila *fila, TipoItem *item) {
  TipoNoh *ptrAux;
  if (!filaVazia(fila)) {
    ptrAux = fila->inicio;
    *item = ptrAux->item;
    if (fila->inicio == fila->fim) {
      fila->inicio = NULL;
      fila->fim = NULL;
    } else {
      fila->inicio = ptrAux->prox;
    }
    free(ptrAux);
    fila->n--;
    return 1;
  }
  return 0;
}

int imprimeFila(TipoFila *fila) {
  TipoNoh *ptrAux;
  if (!filaVazia(fila)) {
    ptrAux = fila->inicio;
    while (ptrAux != NULL) {
      imprimeItem(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item) { printf("%i %s\n", item.chave, item.nome); }