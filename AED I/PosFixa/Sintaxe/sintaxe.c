#include "PilhaDinamica.h"

int Sintaxe(char exp[700], int nChar);

int main() {
  char exp[700];
  int nPares, nCaracteres, val;

  printf("\nNúmero de pares de cararacteres (1 ≤ M ≤ 50): ");
  scanf("%d", &nPares);
  printf("\nNúmero de caracteres (1 ≤ N ≤ 1000): ");
  scanf("%d", &nCaracteres);

  printf("\nDigite a sequência de caracteres: ");
  getchar();
  fgets(exp, 700, stdin);

  val = Sintaxe(exp, nCaracteres);

  switch (val) {
  case 0:
    printf("\nCorreto!\n");
    break;
  case 1:
    printf("\nSímbolo esquerdo não esperado!\n");
    break;
  case 2:
    printf("\nSímbolo direito não esperado!\n");
    break;
  }

  return 0;
}

int Sintaxe(char exp[700], int nChar) {
  int i, aux;
  TipoPilha pilha1;
  TipoItem item, itemAux;

  inicializaPilha(&pilha1);

  for (i = 0; i < nChar; i++) {
    aux = exp[i];
    if (aux == 40 || aux == 47 || aux == 60 || aux == 91 || aux == 123) {
      item.x = exp[i];
      empilha(&pilha1, item);
    } else {
      if (aux == 41 || aux == 92 || aux == 62 || aux == 93 || aux == 125) {
        item.x = exp[i];
        consultaTopo(&pilha1, &item);
        itemAux.x = item.x;
        switch (aux) {
        case 41:
          if (itemAux.x == 40) {
            desempilha(&pilha1, &item);
          } else {
            if (itemAux.x == 41) {
              return 1;
            } else {
              return 2;
            }
          }
          break;

        case 92:
          if (itemAux.x == 47) {
            desempilha(&pilha1, &item);
          } else {
            if (itemAux.x == 92) {
              return 1;
            } else {
              return 2;
            }
          }
          break;

        case 62:
          if (itemAux.x == 60) {
            desempilha(&pilha1, &item);
          } else {
            if (itemAux.x == 62) {
              return 1;
            } else {
              return 2;
            }
          }
          break;

        case 93:
          if (itemAux.x == 91) {
            desempilha(&pilha1, &item);
          } else {
            if (itemAux.x == 93) {
              return 1;
            } else {
              return 2;
            }
          }
          break;

        case 125:
          if (itemAux.x == 123) {
            desempilha(&pilha1, &item);
          } else {
            if (itemAux.x == 125) {
              return 1;
            } else {
              return 2;
            }
          }
          break;
        }
      }
    }
  }

  destroiPilha(&pilha1);
  return 0;
}