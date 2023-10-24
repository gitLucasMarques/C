#include "pilha.h"

void iniciaPilha(Pilha *pilha) { pilha->topo = NULL; }

int pilhaVazia(Pilha *pilha) {
  if (pilha->topo == NULL) {
    return 0;
  }
  return -1;
}

int consultaTopo(Pilha *pilha, Item *item) {
  if (pilhaVazia(pilha) < 0) {
    *item = pilha->topo->item;
    return 0;
  }
  return -1;
}

int push(Pilha *pilha, Item item) {
  TipoNoh *novoNoh;

  novoNoh = malloc(sizeof(TipoNoh));

  if (novoNoh != NULL) {
    novoNoh->item = item;
    novoNoh->prox = pilha->topo;
    pilha->topo = novoNoh;
    return 0;
  }
  return -1;
}

int pop(Pilha *pilha, Item *item) {
  if (pilhaVazia(pilha) < 0) {
    *item = pilha->topo->item;
    pilha->topo = pilha->topo->prox;
    return 0;
  }
  return -1;
}

void imprimeItem(Item item) { printf("%d\n", item.num); }

void imprimePilha(Pilha *pilha) {
  TipoNoh *ptrAux;

  ptrAux = pilha->topo;
  while (ptrAux != NULL) {
    imprimeItem(ptrAux->item);
    ptrAux = ptrAux->prox;
  }
}

void liberaPilha(Pilha *pilha) {
  TipoNoh *ptrAux;

  if (pilhaVazia(pilha) < 0) {
    ptrAux = pilha->topo;
    while (ptrAux != NULL) {
      pilha->topo = ptrAux->prox;
      free(ptrAux);
      ptrAux = pilha->topo;
    }
  }
}