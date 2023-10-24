#include <stdio.h>
#include <stdlib.h>

typedef struct noh {
  int chave;
  int dado;
} Item;

typedef struct Noh *Arvore_Binaria_Busca;

typedef struct Noh {
  Item dados;
  struct noh *pai;
  struct noh *esq;
  struct noh *dir;
  struct noh *prox_noh;
} ABB;

Arvore_Binaria_Busca inicializa_ABB(Arvore_Binaria_Busca *arvore) {
  return NULL;
}

Arvore_Binaria_Busca inserir_ABB(Arvore_Binaria_Busca *arvore, int num) {
  ABB *novoNoh;
  ABB *nohAux;

  if (arvore == NULL) {
    novoNoh = malloc(sizeof(ABB));
    novoNoh->dados.chave = num;
    novoNoh->dados.dado = 0;
    novoNoh->dir = NULL;
    novoNoh->esq = NULL;
    novoNoh->pai = NULL;
    novoNoh->prox_noh = NULL;
  }

  //
  //
}