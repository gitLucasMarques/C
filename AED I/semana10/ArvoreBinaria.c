#include "ArvoreBinaria.h"

int arvoreVazia(TipoArvore arvore) { return arvore == NULL; }

TipoArvore inicializaArvore(TipoArvore arvore) { return NULL; }

TipoArvore destroiArvore(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    destroiArvore(arvore->subArvoreEsq);
    destroiArvore(arvore->subArvoreDir);
    free(arvore);
  }
  return NULL;
} // pós-ordem

TipoArvore instanciaArvore(TipoArvore arvore, char dado) {
  arvore = (TipoArvore)malloc(sizeof(TipoArvore));
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->dado = dado;
  return arvore;
}

TipoArvore insereSubArvoreEsq(TipoArvore raiz, TipoArvore subArvoreEsq) {
  if (!arvoreVazia(raiz)) {
    raiz->subArvoreEsq = subArvoreEsq;
    return raiz;
  }
  return NULL;
}

TipoArvore insereSubArvoreDir(TipoArvore raiz, TipoArvore subArvoreDir) {
  if (!arvoreVazia(raiz)) {
    raiz->subArvoreDir = subArvoreDir;
    return raiz;
  }
  return NULL;
}

TipoArvore montaArvore(TipoArvore raiz, TipoArvore subArvoreEsq,
                       TipoArvore subArvoreDir) {
  if (!arvoreVazia(raiz)) {
    raiz->subArvoreEsq = subArvoreEsq;
    raiz->subArvoreDir = subArvoreDir;
    return raiz;
  }
  return NULL;
}

// A, B, D, H, E, C, F, I, G

void imprimeArvorePreOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    printf("%c ", arvore->dado);
    imprimeArvorePreOrdem(arvore->subArvoreEsq);
    imprimeArvorePreOrdem(arvore->subArvoreDir);
  }
}

// H, D, B, E, A, I, F, C, G

void imprimeArvoreEmOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvoreEmOrdem(arvore->subArvoreEsq);
    printf("%c ", arvore->dado);
    imprimeArvoreEmOrdem(arvore->subArvoreDir);
  }
}

// H, D, E, B, I, F, G, C, A

void imprimeArvorePosOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvorePosOrdem(arvore->subArvoreEsq);
    imprimeArvorePosOrdem(arvore->subArvoreDir);
    printf("%c ", arvore->dado);
  }
}

int buscaIndiceInfixa(char *infixa, int inicio, int fim, char letra) {
  int i;
  for (i = inicio; i <= fim; i++) {
    if (infixa[i] == letra) {
      return i;
    }
  }
  return -1;
}

TipoArvore criaArvore(char *infixa, char *prefixa, int inicio, int fim) {
  TipoArvore arvore;
  int inIndex;
  if (inicio > fim) {
    return NULL;
  }
  arvore = inicializaArvore(arvore);
  arvore = instanciaArvore(arvore, prefixa[k++]);

  if (inicio == fim) {
    return arvore;
  }

  inIndex = buscaIndiceInfixa(infixa, inicio, fim, arvore->dado);
  arvore->subArvoreEsq = criaArvore(infixa, prefixa, inicio, inIndex - 1);
  arvore->subArvoreDir = criaArvore(infixa, prefixa, inIndex + 1, fim);
  return arvore;
}

void insereNaFila(TipoFila *fila, TipoArvore arvore) {
  TipoNoh *novoNoh;

  novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  novoNoh->arvore = arvore;
  novoNoh->prox = NULL;

  if (fila->fim != NULL) {
    fila->fim->prox = novoNoh;
  } else {
    fila->inicio = novoNoh;
  }
  fila->fim = novoNoh;
}

TipoArvore retiraDaFila(TipoFila *fila) {
  TipoNoh *ptrAux;
  TipoArvore arvAux;

  arvAux = inicializaArvore(arvAux);

  if (fila->inicio != NULL) {
    ptrAux = fila->inicio;
    arvAux = ptrAux->arvore;
    fila->inicio = ptrAux->prox;
    if (fila->inicio == NULL) {
      fila->fim = NULL;
    }
    free(ptrAux);
    return arvAux;
  }
  return NULL;
}

void percorreArvoreNiveis(TipoArvore arvore) {
  TipoFila *fila;
  TipoArvore arvAux;

  fila = (TipoFila *)malloc(sizeof(TipoFila));

  insereNaFila(fila, arvore);
  arvAux = inicializaArvore(arvAux);
  while (fila->inicio != NULL) {
    arvAux = retiraDaFila(fila);
    printf("%c ", arvAux->dado);
    if (arvAux->subArvoreEsq != NULL) {
      insereNaFila(fila, arvAux->subArvoreEsq);
    }
    if (arvAux->subArvoreDir != NULL) {
      insereNaFila(fila, arvAux->subArvoreDir);
    }
  }
}