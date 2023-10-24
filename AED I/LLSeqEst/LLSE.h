#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int pos;
  char nome[50];
} Item;

typedef struct {
  Item item[8];
  int ultimo;
} LLSE;

void iniciaLista(LLSE *);
int listaVazia(LLSE *);
void imprimeLista(LLSE *);
int insereFinal(LLSE *, Item);

int buscaNome(LLSE *, char *);