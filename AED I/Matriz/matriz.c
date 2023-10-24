#include "matriz.h"

void iniciaMatriz(Matriz *m) {
  m->listas = NULL;
  m->linha = 0;
  m->coluna = 0;
}

int matrizVazia(Matriz *m) {
  if (m->listas == NULL) {
    printf("Matriz vazia!\n\n");
    return 0;
  }
  return -1;
}

int instanciaMatriz(Matriz *m, int linha, int coluna) {
  int i;

  m->listas = malloc(linha * sizeof(LLSD));
  if (m->listas != NULL) {
    m->linha = linha;
    m->coluna = coluna;
    for (i = 0; i < linha; i++) {
      m->listas[i] = *iniciaLista(&m->listas[i]);
    }
    return 0;
  }
  return -1;
}

int insereMatriz(Matriz *m, int linha, int coluna, int num) {
  Item item;
  if (linha < 0 || linha >= m->linha || coluna < 0 || coluna >= m->coluna ||
      num == 0) {
    return -1;
  }
  item.elemento = num;
  item.coluna = coluna;
  m->listas[linha] = insereOrdenado(&m->listas[linha], item, coluna);
  return 0;
}

int removeMatriz(Matriz *m, int linha, int coluna) {
  if (linha < 0 || linha >= m->linha || coluna < 0 || coluna >= m->coluna) {
    return -1;
  }
  m->listas[linha] = *retiraEspecifico(&m->listas[linha], coluna);
  return 0;
}

void imprimeMatriz(Matriz *m) {
  int i;
  for (i = 0; i < m->linha; i++) {
    imprimeLista(&m->listas[i]);
    printf("\n");
  }
}

void liberaMatriz(Matriz *m) {
  int i;
  for (i = 0; i < m->linha; i++) {
    liberaLista(&m->listas[i]);
  }
}