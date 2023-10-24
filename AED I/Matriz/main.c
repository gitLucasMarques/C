#include "matriz.h"

void Menu() {
  printf("\n-----MENU-----\n");
  printf("\n1 - Imprime Matriz"
         "\n2 - Insere na Matriz"
         "\n3 - Retira da Matriz"
         "\n4 - Sair"
         "\n\nOpção: ");
}

int main() {
  Matriz m;
  Item item;
  int k;
  int linha, coluna, num;

  iniciaMatriz(&m);

  printf("Quantidade de linhas: ");
  scanf("%d", &m.linha);
  printf("Quantidade de colunas: ");
  scanf("%d", &m.coluna);

  instanciaMatriz(&m, m.linha, m.coluna);

  while (k != 4) {
    Menu();
    scanf("%d", &k);
    switch (k) {
    case 1:
      printf("\n\n");
      imprimeMatriz(&m);
      printf("\n\n");
      break;

    case 2:
      printf("\nLinha: ");
      scanf("%d", &linha);
      printf("\nColuna: ");
      scanf("%d", &coluna);
      printf("\nValor: ");
      scanf("%d", &num);
      insereMatriz(&m, linha, coluna, num);
      break;

    case 3:
      printf("\nLinha: ");
      scanf("%d", &linha);
      printf("\nColuna: ");
      scanf("%d", &coluna);
      removeMatriz(&m, linha, coluna);
      break;
    }
  }

  printf("\nAté mais!\n");
  liberaMatriz(&m);

  return 0;
}