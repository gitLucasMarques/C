#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
  int chave;
  char nome[30];
} TipoItem;

typedef struct{
  TipoItem itens[MAX];
  int ultimo;
} TipoFila;

void inicializaFila(TipoFila*);
void destroiFila(TipoFila*);
int filaVazia(TipoFila*);
int filaCheia(TipoFila*);
int insereNaFila(TipoFila*,TipoItem);
int retiraDaFila(TipoFila*,TipoItem*);
int imprimeFila(TipoFila*);
void imprimeItem(TipoItem);