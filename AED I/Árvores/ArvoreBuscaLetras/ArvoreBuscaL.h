#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char letrasInfixa[MAXSIZE] = {0};
char letrasPosfixa[MAXSIZE] = {0};
char letrasPrefixa[MAXSIZE] = {0};

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
TipoArvore destroiArvore(TipoArvore); // pós-ordem
TipoArvore instanciaArvore(TipoArvore, char);

TipoArvore insereSubArvoreEsq(TipoArvore, TipoArvore);
TipoArvore insereSubArvoreDir(TipoArvore, TipoArvore);
TipoArvore montaArvore(TipoArvore, TipoArvore, TipoArvore);

/*void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);*/

TipoArvore criaArvoreBinariaBusca(TipoArvore, char);
TipoArvore pesquisaArvoreBinariaBusca(TipoArvore, char);

void infixa(TipoArvore);
void prefixa(TipoArvore);
void posfixa(TipoArvore);

void imprimeArvoreEmOrdem(char *);
void imprimeArvorePreOrdem(char *);
void imprimeArvorePosOrdem(char *);