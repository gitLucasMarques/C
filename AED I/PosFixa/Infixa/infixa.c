#include "PilhaDinamica.h"

void InFixa(char exp[99]);

int main() {
  char exp[99];
  float valor;

  printf("\nDigite uma expressão posfixa simples: ");
  fgets(exp, 99, stdin);

  InFixa(exp);

  printf("\nExprssão infixa aritmética: %s", exp);

  return 0;
}

void InFixa(char *exp) {
  int i;
  TipoPilha pilha1, pilha2;
  TipoItem item, itemAux;

  inicializaPilha(&pilha1);
  inicializaPilha(&pilha2);

  for (i = 0; i < strlen(exp); i++) {
    item.x = exp[i];
    empilha(&pilha1, item);
  }

  consultaTopo(&pilha1, &item);
  while (item.x < 48) {
    desempilha(&pilha1, &item);
    empilha(&pilha2, item);
    consultaTopo(&pilha1, &item);
  }

  for (i = 0; i < strlen(exp); i += 2) {
    desempilha(&pilha1, &item);
    exp[strlen(exp) - 1 - i] = item.x;
    if (!pilhaVazia(&pilha2)) {
      desempilha(&pilha2, &item);
      exp[strlen(exp) - 2 - i] = item.x;
    }
  }

  destroiPilha(&pilha1);
  destroiPilha(&pilha2);
}