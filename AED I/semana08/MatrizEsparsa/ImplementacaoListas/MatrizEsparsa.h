#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

typedef struct{
  TipoLista* matriz;
  int nLinhas;
  int nColunas;
} TipoMatriz;

void inicializaMatriz(TipoMatriz*);
int matrizVazia(TipoMatriz*);
int instanciaMatriz(TipoMatriz*,int,int);
void destroiMatriz(TipoMatriz*);
int insereNaMatriz(TipoMatriz*,int,int,int);
int retiraDaMatriz(TipoMatriz*,int,int);
void imprimeMatriz(TipoMatriz*);