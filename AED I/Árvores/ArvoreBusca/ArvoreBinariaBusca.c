#include "ArvoreBinariaBusca.h"

int arvoreVazia(TipoArvore arvore) { return arvore == NULL; }

TipoArvore inicializaArvore(TipoArvore arvore) { return NULL; }

TipoArvore destroiArvore(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
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

TipoArvore insereSubArvoreEsq(TipoArvore raiz, TipoArvore subArvoreEsq) {
  raiz->subArvoreEsq = subArvoreEsq;
  return raiz;
}

TipoArvore insereSubArvoreDir(TipoArvore raiz, TipoArvore subArvoreDir) {
  raiz->subArvoreDir = subArvoreDir;
  return raiz;
}

TipoArvore montaArvore(TipoArvore arvore, TipoArvore subArvoreEsq,
                       TipoArvore subArvoreDir) {
  if (!arvoreVazia(arvore)) {
    arvore->subArvoreEsq = subArvoreEsq;
    arvore->subArvoreDir = subArvoreDir;
    return arvore;
  }
  return NULL;
}

void imprimeArvorePreOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    printf("%d ", arvore->num);
    imprimeArvorePreOrdem(arvore->subArvoreEsq);
    imprimeArvorePreOrdem(arvore->subArvoreDir);
  }
}

void imprimeArvoreEmOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvoreEmOrdem(arvore->subArvoreEsq);
    printf("%d ", arvore->num);
    imprimeArvoreEmOrdem(arvore->subArvoreDir);
  }
}

void imprimeArvorePosOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvorePosOrdem(arvore->subArvoreEsq);
    imprimeArvorePosOrdem(arvore->subArvoreDir);
    printf("%d ", arvore->num);
  }
}

TipoArvore criaArvoreBinariaBusca(TipoArvore raiz, int num) {
  TipoArvore arvore;
  if (raiz == NULL) {
    arvore = (TipoArvore)malloc(sizeof(TipoArvore));
    arvore->subArvoreEsq = NULL;
    arvore->subArvoreDir = NULL;
    arvore->num = num;
    return arvore;
  } else if (num < raiz->num) {
    raiz->subArvoreEsq = criaArvoreBinariaBusca(raiz->subArvoreEsq, num);
  } else {
    raiz->subArvoreDir = criaArvoreBinariaBusca(raiz->subArvoreDir, num);
  }
  return raiz;
}

TipoArvore pesquisaArvoreBinariaBusca(TipoArvore arvore, int num) {
  int auxLet, auxNum;

  if (arvore != NULL) {
    if (arvore->num == num) {
      printf("%d existe\n", num);
    } else {
      auxLet = num;
      auxNum = arvore->num;
      if (auxLet < auxNum) {
        pesquisaArvoreBinariaBusca(arvore->subArvoreEsq,num);
      } else {
        pesquisaArvoreBinariaBusca(arvore->subArvoreDir, num);
      }
    }
  } else {
    printf("%d nao existe\n", num);
  }
  return NULL;
}

TipoArvore buscaIndMax(TipoArvore arvore) {
  if (arvoreVazia(arvore)) {
    return NULL;
  } else if (!arvore->subArvoreDir) {
    return arvore;
  } else {
    return buscaIndMax(arvore->subArvoreDir);
  }
}

TipoArvore removeArvoreBinariaBusca(TipoArvore arvore, int num) {
  TipoArvore arvAux;
  if (arvoreVazia(arvore)) {
    return NULL;
  } else if (arvore->num > num) {
    arvore->subArvoreEsq = removeArvoreBinariaBusca(arvore->subArvoreEsq, num);
  } else if (arvore->num < num) {
    arvore->subArvoreDir = removeArvoreBinariaBusca(arvore->subArvoreDir, num);
  } else if (arvore->subArvoreEsq && arvore->subArvoreDir) {
    arvAux = buscaIndMax(arvore->subArvoreEsq);
    arvore->num = arvAux->num;
    arvore->subArvoreEsq =
        removeArvoreBinariaBusca(arvore->subArvoreEsq, arvore->num);
  } else {
    arvAux = arvore;
    if (arvore->subArvoreEsq == NULL) {
      arvore = arvore->subArvoreDir;
    } else if (arvore->subArvoreDir == NULL) {
      arvore = arvore->subArvoreEsq;
    }
    free(arvAux);
  }

  return arvore;
}