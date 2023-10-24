#include "LLSE.h"

void iniciaLista(LLSE *lista) { lista->ultimo = 0; }

int listaVazia(LLSE *lista) {
  if (lista->ultimo == 0) {
    printf("\nLista Vazia!\n");
    return 0;
  }
  return -1;
}

void imprimeLista(LLSE *lista) {
  int i;
  if (listaVazia(lista) < 0) {
    printf("\n-------Lista-------\n");
    for (i = 0; i < lista->ultimo; i++) {
      printf("\n%d %s", lista->item[i].pos, lista->item[i].nome);
    }
    printf("\n\n");
  }
}

int insereFinal(LLSE *lista, Item item) {
  int pos = lista->ultimo;
  if (pos < 8) {
    lista->item[pos] = item;
    lista->ultimo++;
    return 0;
  }
  return -1;
}

int buscaNome(LLSE *lista, char nome[20]) {
  int i;
  for (i = 0; i < lista->ultimo; i++) {
    if (strcmp(lista->item[i].nome, nome) == 0) {
      printf("\nNome encontrado na posição: %d\n", lista->item[i].pos);
      return 0;
    }
  }
  printf("\nNome não encontrado na lista!\n");
  return -1;
}