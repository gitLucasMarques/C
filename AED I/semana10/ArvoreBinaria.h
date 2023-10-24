#include <stdio.h>
#include <stdlib.h>

struct nohArvore {
  char dado;
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

int k;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore); // pós-ordem
TipoArvore instanciaArvore(TipoArvore, char);

TipoArvore insereSubArvoreEsq(TipoArvore, TipoArvore);
TipoArvore insereSubArvoreDir(TipoArvore, TipoArvore);
TipoArvore montaArvore(TipoArvore, TipoArvore, TipoArvore);

void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);

int buscaIndiceInfixa(char *, int, int, char);
TipoArvore criaArvore(char *, char *, int, int);

void insereNaFila(TipoFila *, TipoArvore);
TipoArvore retiraDaFila(TipoFila *);
void percorreArvoreNiveis(TipoArvore);