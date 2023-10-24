#include "ArvoreBuscaL.h"

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
  int z;
  for (z = 0; z < i; ++z)
    if (!z)
      printf("%c", letrasInfixa[z]);
    else
      printf(" %c", letrasInfixa[z]);

  i = 0;
  printf("\n");
}

void imprimeArvorePreOrdem(char *letras) {
  int z;
  for (z = 0; z < k; ++z)
    if (!z)
      printf("%c", letrasPrefixa[z]);
    else
      printf(" %c", letrasPrefixa[z]);

  k = 0;
  printf("\n");
}

void imprimeArvorePosOrdem(char *letras) {
  int z;
  for (z = 0; z < j; ++z)
    if (!z)
      printf("%c", letrasPosfixa[z]);
    else
      printf(" %c", letrasPosfixa[z]);

  j = 0;
  printf("\n");
}

void infixa(TipoArvore arvore) {
  if (arvore) {
    infixa(arvore->subArvoreEsq);
    letrasInfixa[i++] = arvore->letra;
    infixa(arvore->subArvoreDir);
  }
}

void posfixa(TipoArvore arvore) {
  if (arvore) {
    posfixa(arvore->subArvoreEsq);
    posfixa(arvore->subArvoreDir);
    letrasPosfixa[j++] = arvore->letra;
  }
}

void prefixa(TipoArvore arvore) {
  if (arvore) {
    letrasPrefixa[k++] = arvore->letra;
    prefixa(arvore->subArvoreEsq);
    prefixa(arvore->subArvoreDir);
  }
}

/*void imprimeArvorePreOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    printf("%c", arvore->letra);
    imprimeArvorePreOrdem(arvore->subArvoreEsq);
    imprimeArvorePreOrdem(arvore->subArvoreDir);
  }
}

void imprimeArvoreEmOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvoreEmOrdem(arvore->subArvoreEsq);
    printf("%c", arvore->letra);
    imprimeArvoreEmOrdem(arvore->subArvoreDir);
  }
}

void imprimeArvorePosOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvorePosOrdem(arvore->subArvoreEsq);
    imprimeArvorePosOrdem(arvore->subArvoreDir);
    printf("%c", arvore->letra);
  }
}*/

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