#include "LLSD.h"

typedef struct {
  LLSD *listas;
  int linha;
  int coluna;
} Matriz;

void iniciaMatriz(Matriz *);
int matrizVazia(Matriz *);
int instanciaMatriz(Matriz *, int, int);

int insereMatriz(Matriz *, int, int, int);
int removeMatriz(Matriz *, int, int);

void imprimeMatriz(Matriz *);
void liberaMatriz(Matriz *);