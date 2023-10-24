#include "FD.h"

void Menu() {
  printf("\n-----MENU-----\n");
  printf("\n1 - Imprime Fila"
         "\n2 - Insere na Fila"
         "\n3 - Retira da Fila"
         "\n4 - Busca Nome"
         "\n5 - Sair"
         "\n\nOpção: ");
}

int main() {
  FD fila;
  Item item;
  char nome[20];
  int k = 0;

  iniciaFila(&fila);

  while (k != 5) {
    Menu();
    scanf("%d", &k);
    switch (k) {
    case 1:
      printf("\n\n");
      imprimeFila(&fila);
      printf("\n\n");
      break;

    case 2:
      item.pos = fila.n;
      printf("\nNome: ");
      scanf("%s", item.nome);
      insereFila(&fila, item);
      break;

    case 3:
      retiraFila(&fila);
      break;

    case 4:
      if (filaVazia(&fila) < 0) {
        printf("\nNome procurado: ");
        scanf("%s", nome);
        buscaFila(&fila, nome);
      }
      break;
    }
  }

  printf("\nAté mais!\n");
  liberaFila(&fila);
  return 0;
}