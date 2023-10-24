#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;

struct nohArvore {
  int num;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(TipoArvore, int);

void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);

TipoArvore criaArvoreBinariaBusca(TipoArvore, int);
TipoArvore removeArvoreBinariaBusca(TipoArvore, int);
TipoArvore pesquisaArvoreBinariaBusca(TipoArvore, int);

TipoArvore buscaIndMax(TipoArvore);

int main() {

  int num;
  char opc[8];
  TipoArvore arvore;

  arvore = inicializaArvore(arvore);

  while (scanf("%s", opc) != EOF) {
    if (strcmp(opc, "I") == 0) {
      scanf("%d", &num);
      arvore = criaArvoreBinariaBusca(arvore, num);
    }
    if (strcmp(opc, "INFIXA") == 0) {
      k = 1;
      imprimeArvoreEmOrdem(arvore);
      printf("\n");
    }
    if (strcmp(opc, "PREFIXA") == 0) {
      k = 1;
      imprimeArvorePreOrdem(arvore);
      printf("\n");
    }
    if (strcmp(opc, "POSFIXA") == 0) {
      k = 1;
      imprimeArvorePosOrdem(arvore);
      printf("\n");
    }
    if (strcmp(opc, "P") == 0) {
      scanf("%d", &num);
      pesquisaArvoreBinariaBusca(arvore, num);
    }
    if (strcmp(opc, "R") == 0) {
      scanf("%d", &num);
      arvore = removeArvoreBinariaBusca(arvore, num);
    }
  }
  arvore = destroiArvore(arvore);
  return 0;
}

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

TipoArvore pesquisaArvoreBinariaBusca(TipoArvore arvore, int num) {
  if (arvore != NULL) {
    if (arvore->num == num) {
      printf("%d existe\n", num);
    } else {
      if (num < arvore->num) {
        pesquisaArvoreBinariaBusca(arvore->subArvoreEsq, num);
      } else {
        pesquisaArvoreBinariaBusca(arvore->subArvoreDir, num);
      }
    }
  } else {
    printf("%d nao existe\n", num);
  }
  return NULL;
}

TipoArvore criaArvoreBinariaBusca(TipoArvore arvore, int num) {
  if (arvoreVazia(arvore)) {
    arvore = instanciaArvore(arvore, num);
  } else if (arvore->num < num) {
    arvore->subArvoreDir = criaArvoreBinariaBusca(arvore->subArvoreDir, num);
  } else {
    arvore->subArvoreEsq = criaArvoreBinariaBusca(arvore->subArvoreEsq, num);
  }
  return arvore;
}

void imprimeArvoreEmOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvoreEmOrdem(arvore->subArvoreEsq);
    if (!k) {
      printf(" %d", arvore->num);
    } else {
      printf("%d", arvore->num);
      k = 0;
    }
    imprimeArvoreEmOrdem(arvore->subArvoreDir);
  }
}

void imprimeArvorePreOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    if (!k) {
      printf(" %d", arvore->num);
    } else {
      printf("%d", arvore->num);
      k = 0;
    }
    imprimeArvorePreOrdem(arvore->subArvoreEsq);
    imprimeArvorePreOrdem(arvore->subArvoreDir);
  }
}

void imprimeArvorePosOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvorePosOrdem(arvore->subArvoreEsq);
    imprimeArvorePosOrdem(arvore->subArvoreDir);
    if (!k) {
      printf(" %d", arvore->num);
    } else {
      printf("%d", arvore->num);
      k = 0;
    }
  }
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