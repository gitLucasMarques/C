#include "LLSD.h"

Lista iniciaLista(Lista lista) {
  lista->inicio = NULL;
  lista->ultimo = 0;
  return lista;
}

int listaVazia(LLSD *lista) {
  if (lista->ultimo == 0) {
    printf("\nLista Vazia!\n");
    return 0;
  }
  return -1;
}

Lista insereInicio(Lista lista, Item item) {
  TipoNoh *ptrAux;

  ptrAux = malloc(sizeof(TipoNoh));
  ptrAux->item = item;
  ptrAux->prox = lista->inicio;
  lista->inicio = ptrAux;
  lista->ultimo++;
  return lista;
}

Lista insereFinal(Lista lista, Item item) {
  TipoNoh *ptrAux, *novoNoh;

  novoNoh = malloc(sizeof(TipoNoh));
  ptrAux = lista->inicio;
  if (listaVazia(lista) < 0) {
    while (ptrAux->prox != NULL) {
      ptrAux = ptrAux->prox;
    }
    ptrAux->prox = novoNoh;
  } else {
    lista->inicio = novoNoh;
  }
  novoNoh->item = item;
  novoNoh->prox = NULL;
  lista->ultimo++;
  return lista;
}

LLSD insereOrdenado(Lista lista, Item item, int pos) {
  TipoNoh *ptrAux1, *ptrAux2, *novoNoh;
  int i, count = 0;

  novoNoh = malloc(sizeof(TipoNoh));

  if (pos == 0) {
    insereInicio(lista, item);
  }

  if (pos < lista->ultimo) {
    ptrAux1 = lista->inicio;
    for (i = 0; i < pos - 1; i++) {
      ptrAux1 = ptrAux1->prox;
    }
    ptrAux2 = ptrAux1->prox;
    novoNoh->item = item;
    novoNoh->prox = ptrAux2;
    ptrAux1->prox = novoNoh;
    lista->ultimo++;
  }

  if (pos > lista->ultimo) {
    ptrAux1 = lista->inicio;
    while (ptrAux1->prox != NULL) {
      ptrAux1 = ptrAux1->prox;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    ptrAux1->prox = novoNoh;
    lista->ultimo++;
  }

  if (pos == lista->ultimo) {
    ptrAux1 = lista->inicio;
    for (i = 0; i <= pos; i++) {
      ptrAux1 = ptrAux1->prox;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    ptrAux1->prox = novoNoh;
    lista->ultimo++;
  }
  return *lista;
}

void imprimeItem(Item item) { printf("%d ", item.elemento); }

void imprimeLista(LLSD *lista) {
  TipoNoh *ptrAux;

  ptrAux = lista->inicio;
  if (listaVazia(lista) < 0) {
    while (ptrAux != NULL) {
      imprimeItem(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}

Lista retiraInicio(Lista lista) {
  TipoNoh *ptrAux;

  if (listaVazia(lista) < 0) {
    ptrAux = lista->inicio;
    ptrAux = ptrAux->prox;
    lista->inicio = ptrAux;
    lista->ultimo--;
    return lista;
  }
  return NULL;
}

Lista retiraFinal(Lista lista) {
  TipoNoh *ptrAux;
  int i, count = 0;

  if (listaVazia(lista) < 0) {
    ptrAux = lista->inicio;
    while (ptrAux->prox != NULL) {
      ptrAux = ptrAux->prox;
      count++;
    }

    ptrAux = lista->inicio;
    for (i = 0; i < count - 1; i++) {
      ptrAux = ptrAux->prox;
    }
    ptrAux->prox = NULL;
    lista->ultimo--;
    return lista;
  }
  return NULL;
}

Lista retiraEspecifico(Lista lista, int pos) {
  TipoNoh *ptrAux1, *ptrAux2;
  int i;

  if (listaVazia(lista) < 0) {
    if (pos <= lista->ultimo) {
      ptrAux1 = lista->inicio;
      for (i = 0; i < pos - 1; i++) {
        ptrAux1 = ptrAux1->prox;
      }
      ptrAux2 = ptrAux1->prox;
      ptrAux2 = ptrAux2->prox;
      ptrAux1->prox = ptrAux2;
    }
    if (pos == 0) {
      retiraInicio(lista);
    }
    lista->ultimo--;
    return lista;
  }
  return NULL;
}

void liberaLista(Lista lista) {
  TipoNoh *ptrAux1, *ptrAux2;

  ptrAux1 = lista->inicio;
  ptrAux2 = ptrAux1->prox;
  while (ptrAux1->prox != NULL) {
    free(ptrAux1);
    ptrAux1 = ptrAux2;
    ptrAux2 = ptrAux1->prox;
  }
  free(ptrAux1);
  lista->inicio = NULL;
  lista->ultimo = 0;
}