#include "PilhaDinamica.h"

float valor_PosFixa(char exp[99]);

int main() {
  char exp[99];
  float valor;

  printf("\nDigite uma expressão posfixa simples: ");
  fgets(exp, 99, stdin);

  valor = valor_PosFixa(exp);
  printf("\nValor da expressão posfixa: %0.2f", valor);

  return 0;
}

float valor_PosFixa(char exp[99]) {
  TipoPilha pilha1, pilha2;
  TipoItem item, itemAux;
  int i;
  float valor, valorAux;

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

  desempilha(&pilha1, &item);
  valor = item.x % 48;

  while (!pilhaVazia(&pilha1)) {
    desempilha(&pilha2, &item);
    desempilha(&pilha1, &itemAux);
    valorAux = itemAux.x % 48;
    switch (item.x) {
    case 42:
      valor *= valorAux;
      break;

    case 43:
      valor += valorAux;
      break;

    case 45:
      valor -= valorAux;
      break;

    case 47:
      valor /= valorAux;
      break;
    default:
      break;
    }
  }

  destroiPilha(&pilha1);
  destroiPilha(&pilha2);

  return valor;
}