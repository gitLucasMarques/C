#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;

struct nohArvore {
  char letra;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;
typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(TipoArvore, char);

void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);

TipoArvore criaArvoreBinariaBusca(TipoArvore, char);
TipoArvore pesquisaArvoreBinariaBusca(TipoArvore, char);

int main() {
  char opc[8], letra;
  TipoArvore arvore;

  arvore = inicializaArvore(arvore);

  while (scanf("%s", opc) != EOF) {
    if (strcmp(opc, "I") == 0) {
      getchar();
      scanf("%c", &letra);
      arvore = criaArvoreBinariaBusca(arvore, letra);
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
      getchar();
      scanf("%c", &letra);
      pesquisaArvoreBinariaBusca(arvore, letra);
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

TipoArvore instanciaArvore(TipoArvore arvore, char letra) {
  arvore = (TipoArvore)malloc(sizeof(TipoArvore));
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->letra = letra;
  return arvore;
}

TipoArvore pesquisaArvoreBinariaBusca(TipoArvore arvore, char letra) {
  int auxLet, auxNum;

  if (arvore != NULL) {
    if (arvore->letra == letra) {
      printf("%c existe\n", letra);
    } else {
      auxLet = letra;
      auxNum = arvore->letra;
      if (auxLet < auxNum) {
        pesquisaArvoreBinariaBusca(arvore->subArvoreEsq, letra);
      } else {
        pesquisaArvoreBinariaBusca(arvore->subArvoreDir, letra);
      }
    }
  } else {
    printf("%c nao existe\n", letra);
  }
  return NULL;
}

TipoArvore criaArvoreBinariaBusca(TipoArvore arvore, char letra) {
  int auxLet, auxNum;

  if (arvoreVazia(arvore)) {
    arvore = instanciaArvore(arvore, letra);
  } else {
    auxLet = letra;
    auxNum = arvore->letra;
    if (auxNum < auxLet) {
      arvore->subArvoreDir =
          criaArvoreBinariaBusca(arvore->subArvoreDir, letra);
    } else {
      arvore->subArvoreEsq =
          criaArvoreBinariaBusca(arvore->subArvoreEsq, letra);
    }
  }
  return arvore;
}

void imprimeArvoreEmOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvoreEmOrdem(arvore->subArvoreEsq);
    if (!k) {
      printf(" %c", arvore->letra);
    } else {
      printf("%c", arvore->letra);
      k = 0;
    }
    imprimeArvoreEmOrdem(arvore->subArvoreDir);
  }
}

void imprimeArvorePreOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    if (!k) {
      printf(" %c", arvore->letra);
    } else {
      printf("%c", arvore->letra);
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
      printf(" %c", arvore->letra);
    } else {
      printf("%c", arvore->letra);
      k = 0;
    }
  }
}