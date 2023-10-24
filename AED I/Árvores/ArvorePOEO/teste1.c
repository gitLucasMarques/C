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

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(char);

int buscaIndiceInfixa(char *, int, int, char);
TipoArvore criaArvore(char *, char *, int, int);
void imprimeArvorePosOrdem(TipoArvore);

int k;

int main() {
  TipoArvore arvore;
  int nCasos, nNos, i;
  char prefixa[52], infixa[52];

  arvore = inicializaArvore(arvore);
  scanf("%d", &nCasos);

  while (nCasos > 0) {
    scanf("%d %s %s", &nNos, prefixa, infixa);
    
    printf("\npref = %lu\ninf = %lu\n", strlen(prefixa), strlen(infixa));
    printf("\npref = %sP\ninf = %sP\n", prefixa, infixa);
    
    k = 0;
    arvore = criaArvore(infixa, prefixa, 0, nNos - 1);
    imprimeArvorePosOrdem(arvore);
    printf("\n");
    nCasos--;
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

TipoArvore instanciaArvore(char letra) {
  TipoArvore arvore;
  arvore = (TipoArvore)malloc(sizeof(TipoArvore));
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->letra = letra;
  return arvore;
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
  arvore = instanciaArvore(prefixa[k++]);
  
  if (inicio == fim) {
    return arvore;
  }
  
  inIndex = buscaIndiceInfixa(infixa, inicio, fim, arvore->letra);
  arvore->subArvoreEsq = criaArvore(infixa, prefixa, inicio, inIndex - 1);
  arvore->subArvoreDir = criaArvore(infixa, prefixa, inIndex + 1, fim);
  return arvore;
}

void imprimeArvorePosOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvorePosOrdem(arvore->subArvoreEsq);
    imprimeArvorePosOrdem(arvore->subArvoreDir);
    printf("%c", arvore->letra);
  }
}