#include <stdio.h>
#include <stdlib.h>

int p;

struct nohArvore {
  int num;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;

typedef struct noh {
  TipoArvore arvore;
  struct noh *prox;
} TipoNoh;

typedef struct fila {
  TipoNoh *inicio;
  TipoNoh *fim;
} TipoFila;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(TipoArvore, int);
TipoArvore criaArvoreBinariaBusca(TipoArvore, int);
void percorreArvoreNiveis(TipoArvore);

void insereNaFila(TipoFila *, TipoArvore);
TipoArvore retiraDaFila(TipoFila *);

int main() {
  TipoArvore arvore;
  int nCasos, nNum, num, i, k;

  arvore = inicializaArvore(arvore);

  scanf("%d", &nCasos);
  for (i = 0; i < nCasos; i++) {
    scanf("%d", &nNum);
    for (k = 0; k < nNum; k++) {
      scanf("%d", &num);
      arvore = criaArvoreBinariaBusca(arvore, num);
    }
    printf("Case %d:\n", i + 1);
    p = 1;
    percorreArvoreNiveis(arvore);
    printf("\n\n");
    arvore = destroiArvore(arvore);
  }
  return 0;
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

  //ptrAux = (TipoNoh *)malloc(sizeof(TipoNoh));
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

int arvoreVazia(TipoArvore arvore) { return arvore == NULL; }

TipoArvore inicializaArvore(TipoArvore arvore) { return NULL; }

TipoArvore destroiArvore(TipoArvore arvore) {
  if (arvoreVazia(arvore) != 0) {
    destroiArvore(arvore->subArvoreEsq);
    destroiArvore(arvore->subArvoreDir);
    free(arvore);
  }
  return NULL;
}

TipoArvore instanciaArvore(TipoArvore arvore, int num) {
  arvore = (TipoArvore)malloc(sizeof(TipoArvore));
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->num = num;
  return arvore;
}

TipoArvore criaArvoreBinariaBusca(TipoArvore raiz, int num) {
  TipoArvore arvore;

  if (arvoreVazia(raiz) == 1) {
    arvore = instanciaArvore(arvore, num);
    return arvore;
  } else {
    if (num < raiz->num) {
      raiz->subArvoreEsq = criaArvoreBinariaBusca(raiz->subArvoreEsq, num);
    } else {
      raiz->subArvoreDir = criaArvoreBinariaBusca(raiz->subArvoreDir, num);
    }
  }
  return raiz;
}

void percorreArvoreNiveis(TipoArvore arvore) {
  TipoFila *fila;
  TipoArvore arvAux;

  fila = (TipoFila *)malloc(sizeof(TipoFila));

  insereNaFila(fila, arvore);
  arvAux = inicializaArvore(arvAux);
  while (fila->inicio != NULL) {
    arvAux = retiraDaFila(fila);
    if (p == 0) {
      printf(" %d", arvAux->num);
      if (arvAux->subArvoreEsq != NULL) {
        insereNaFila(fila, arvAux->subArvoreEsq);
      }
      if (arvAux->subArvoreDir != NULL) {
        insereNaFila(fila, arvAux->subArvoreDir);
      }

    } else {
      printf("%d", arvore->num);
      p = 0;
      if (arvAux->subArvoreEsq != NULL) {
        insereNaFila(fila, arvAux->subArvoreEsq);
      }
      if (arvAux->subArvoreDir != NULL) {
        insereNaFila(fila, arvAux->subArvoreDir);
      }
    }
  }
}