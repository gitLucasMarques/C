#include "pilha.h"

void Menu() {
  printf("\n-----MENU-----\n");
  printf("\n1 - Imprime Pilha"
         "\n2 - Insere na Pilha"
         "\n3 - Retira da Pilha"
         "\n4 - Sair"
         "\n\nOpção: ");
}

int main() {
  Pilha pilha;
  Item item;
  int k = 0;
  char c;

  iniciaPilha(&pilha);

  while (k != 4) {
    Menu();
    scanf("%d", &k);
    switch (k) {
    case 1:
      printf("\n\n");
      imprimePilha(&pilha);
      printf("\n\n");
      break;

    case 2:
      printf("\nCaracter: ");
      getchar();
      scanf("%c", &item.c);
      push(&pilha, item);
      break;

    case 3:
      pop(&pilha, &item);
      printf("\nItem retirado: ");
      imprimeItem(item);
      break;
    }
  }

  printf("\nAté mais!\n");
  liberaPilha(&pilha);
  
  return 0;
}