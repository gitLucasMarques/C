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
TipoArvore destroiArvore(TipoArvore); // pós-ordem
TipoArvore instanciaArvore(TipoArvore, char);

TipoArvore insereSubArvoreEsq(TipoArvore, TipoArvore);
TipoArvore insereSubArvoreDir(TipoArvore, TipoArvore);
TipoArvore montaArvore(TipoArvore, TipoArvore, TipoArvore);

void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);

TipoArvore criaArvoreBinariaBusca(TipoArvore, char);

TipoArvore criaArvorePosFixa(char *, char *, int, int);
int pesquisaIndInfixa(char *, int, int, char);

TipoArvore iniciaArvore(char *);