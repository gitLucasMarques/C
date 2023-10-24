#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

char letrasInfixa[TAM] = {0};
char letrasPosfixa[TAM] = {0};
char letrasPrefixa[TAM] = {0};

int i = 0;
int j = 0;
int k = 0;

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

TipoArvore insereSubArvoreEsq(TipoArvore, TipoArvore);
TipoArvore insereSubArvoreDir(TipoArvore, TipoArvore);
TipoArvore montaArvore(TipoArvore, TipoArvore, TipoArvore);

TipoArvore criaArvoreBinariaBusca(TipoArvore, char);
TipoArvore pesquisaArvoreBinariaBusca(TipoArvore, char);

void listaInfixa(TipoArvore);
void listaPrefixa(TipoArvore);
void listaPosfixa(TipoArvore);

void imprimeArvoreEmOrdem(char *);
void imprimeArvorePreOrdem(char *);
void imprimeArvorePosOrdem(char *);

int main() {
  TipoArvore arvore;
  char opc[8], letra;
  int n;

  arvore = inicializaArvore(arvore);

  while (scanf("%s", opc) != EOF) {
    if (strcmp(opc, "I") == 0) {
      getchar();
      scanf("%c", &letra);
      arvore = criaArvoreBinariaBusca(arvore, letra);
    }
    if (strcmp(opc, "INFIXA") == 0) {
      listaInfixa(arvore);
      imprimeArvoreEmOrdem(letrasInfixa);
      printf("\n");
    }
    if (strcmp(opc, "PREFIXA") == 0) {
      listaPrefixa(arvore);
      imprimeArvorePreOrdem(letrasPrefixa);
      printf("\n");
    }
    if (strcmp(opc, "POSFIXA") == 0) {
      listaPosfixa(arvore);
      imprimeArvorePosOrdem(letrasPosfixa);
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

void imprimeArvoreEmOrdem(char *letras) {
  int p;
  for (p = 0; p < i; p++) {
    if (!p) {
      printf("%c", letrasInfixa[p]);
    } else {
      printf(" %c", letrasInfixa[p]);
    }
  }
  i = 0;
}

void imprimeArvorePreOrdem(char *letras) {
  int p;
  for (p = 0; p < k; p++) {
    if (!p) {
      printf("%c", letrasPrefixa[p]);
    } else {
      printf(" %c", letrasPrefixa[p]);
    }
  }
  k = 0;
}

void imprimeArvorePosOrdem(char *letras) {
  int p;
  for (p = 0; p < j; p++) {
    if (!p) {
      printf("%c", letrasPosfixa[p]);
    } else {
      printf(" %c", letrasPosfixa[p]);
    }
  }
  j = 0;
}

void listaInfixa(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    listaInfixa(arvore->subArvoreEsq);
    letrasInfixa[i++] = arvore->letra;
    listaInfixa(arvore->subArvoreDir);
  }
}

void listaPosfixa(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    listaPosfixa(arvore->subArvoreEsq);
    listaPosfixa(arvore->subArvoreDir);
    letrasPosfixa[j++] = arvore->letra;
  }
}

void listaPrefixa(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    letrasPrefixa[k++] = arvore->letra;
    listaPrefixa(arvore->subArvoreEsq);
    listaPrefixa(arvore->subArvoreDir);
  }
}

TipoArvore criaArvoreBinariaBusca(TipoArvore raiz, char letra) {
  TipoArvore arvore;
  int auxNum, auxLet;

  if (raiz == NULL) {
    arvore = (TipoArvore)malloc(sizeof(TipoArvore));
    arvore->subArvoreEsq = NULL;
    arvore->subArvoreDir = NULL;
    arvore->letra = letra;
    return arvore;
  } else {
    auxLet = letra;
    auxNum = raiz->letra;
    if (auxLet < auxNum) {
      raiz->subArvoreEsq = criaArvoreBinariaBusca(raiz->subArvoreEsq, letra);
    } else {
      raiz->subArvoreDir = criaArvoreBinariaBusca(raiz->subArvoreDir, letra);
    }
  }
  return raiz;
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