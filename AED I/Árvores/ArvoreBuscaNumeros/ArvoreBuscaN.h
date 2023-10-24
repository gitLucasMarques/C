#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohArvore {
  int num;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore); // pós-ordem
TipoArvore instanciaArvore(TipoArvore, int);

TipoArvore insereSubArvoreEsq(TipoArvore, TipoArvore);
TipoArvore insereSubArvoreDir(TipoArvore, TipoArvore);
TipoArvore montaArvore(TipoArvore, TipoArvore, TipoArvore);

void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);

TipoArvore criaArvoreBinariaBusca(TipoArvore, int);
TipoArvore pesquisaArvoreBinariaBusca(TipoArvore, int);

TipoArvore removeArvoreBinariaBusca(TipoArvore, int);