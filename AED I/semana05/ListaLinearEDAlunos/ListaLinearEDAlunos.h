#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  int RA;
  char nome[30];
  float notas[3];
  int freq;
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  TipoNoh *inicioLista;
  int ultimo;
} ListaLinearED;

int listaVazia(ListaLinearED*);
void inicializaLista(ListaLinearED*);
void destroiLista(ListaLinearED*);
void imprimeItem(TipoItem);
void imprimeLista(ListaLinearED*);
int insereNoFinal(ListaLinearED*,TipoItem);
int insereNoInicio(ListaLinearED*,TipoItem);
int removeDoFinal(ListaLinearED*,TipoItem*);
int removeDoInicio(ListaLinearED*,TipoItem*);
int buscaItemNaLista(ListaLinearED*,int,TipoItem*,int*);
int retiraDaPosicao(ListaLinearED*,TipoItem*,int);
int retiraEspecifico(ListaLinearED*,int,TipoItem*,int*);
int verificaIgualdade(TipoItem,int);