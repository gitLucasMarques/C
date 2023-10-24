#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
  int chave;
  char nome[50];
} TipoItem;

typedef struct{
  TipoItem itens[MAX];
  int ultimo;
} ListaLinearSE;

int listaVazia(ListaLinearSE*);
int listaCheia(ListaLinearSE*);
void inicializaLista(ListaLinearSE*);
void destroiLista(ListaLinearSE*);
void imprimeItem(TipoItem);
void imprimeLista(ListaLinearSE*);
int insereNoFinal(ListaLinearSE*,TipoItem);
int insereNoInicio(ListaLinearSE*,TipoItem);
int removeDoFinal(ListaLinearSE*,TipoItem*);
int removeDoInicio(ListaLinearSE*,TipoItem*);