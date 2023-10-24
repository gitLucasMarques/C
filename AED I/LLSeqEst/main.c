#include "LLSE.h"

void Menu() {
  printf("\n-----MENU-----\n");
  printf("\n1 - Imprime\n2 - Insere no Final\n3 - Pesquisa nome\n4 - "
         "Sair\n\nOpção: ");
}

int main() {
  LLSE lista;
  Item item;
  int k = 0;
  char nome[20];

  iniciaLista(&lista);

  while (k != 4) {
    Menu();
    scanf("%d", &k);
    switch (k) {
    case 1:
      imprimeLista(&lista);
      break;

    case 2:
      if (lista.ultimo >= 8) {
        printf("\nERRO! Tamanho excedido!\n");
      } else {
        item.pos = lista.ultimo;
        printf("\nNome: ");
        scanf("%s", item.nome);
        insereFinal(&lista, item);
      }
      break;
    case 3:
      if (listaVazia(&lista) < 0) {
        printf("\nNome procurado: ");
        scanf("%s", nome);
        buscaNome(&lista, nome);
      }
      break;
    }
  }

  printf("\nAté mais!\n");
  return 0;
}