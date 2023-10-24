#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohArvore {
  char letra;
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
TipoArvore instanciaArvore(TipoArvore, char);

TipoArvore criaArvoreExpressao(TipoArvore, char);

void insereNaFila(TipoFila *, TipoArvore);
TipoArvore retiraDaFila(TipoFila *);
void percorreArvoreNiveis(TipoArvore);

int main() {
  TipoArvore arvore;
  char exp[100];
  int i, k, auxElem;
  int pAb = 0, pFe = 0;

  fgets(exp, 100, stdin);
  arvore = inicializaArvore(arvore);

  for (k = 0; k < strlen(exp); k++) {
    if (exp[k] == '(') {
      pAb++;
    }
    if (exp[k] == ')') {
      pFe++;
    }
    if (exp[k] == '+' && pAb == 0 && pFe == 0) {
    }
  }

  for (i = 0; i < strlen(exp); i++) {
    arvore = criaArvoreExpressao(arvore, exp[i]);
  }

  // percorreArvoreNiveis(arvore);

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

/*
A - Z = 65 90
a - z = 97 122
0 - 9 = 48 57
( 40
) 41
* 42
+ 43
- 45
*/
// 4 * a - ( 6 + b ) + 8 / ( 9 - 7 )
TipoArvore criaArvoreExpressao(TipoArvore arvore, char letra) {
  int auxLet;

  auxLet = letra;

  if (letra == '+') {
    arvore = instanciaArvore(arvore, letra);
  }
}

void percorreArvoreNiveis(TipoArvore arvore) {
  TipoFila *fila;
  TipoArvore arvAux;

  fila = (TipoFila *)malloc(sizeof(TipoFila));

  insereNaFila(fila, arvore);
  arvAux = inicializaArvore(arvAux);
  while (fila->inicio != NULL) {
    arvAux = retiraDaFila(fila);
    printf("%c", arvAux->letra);
    if (arvAux->subArvoreEsq != NULL) {
      insereNaFila(fila, arvAux->subArvoreEsq);
    }
    if (arvAux->subArvoreDir != NULL) {
      insereNaFila(fila, arvAux->subArvoreDir);
    }
  }
}