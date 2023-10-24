#include "LLSD.h"

void Menu() {
  printf("\n-----MENU-----\n");
  printf("\n1 - Imprime Lista"
         "\n2 - Insere no Inicio"
         "\n3 - Insere no Final"
         "\n4 - Insere Ordenado"
         "\n5 - Busca Nome"
         "\n6 - Retira do Inicio"
         "\n7 - Retira do Final"
         "\n8 - Retira Ordenado"
         "\n9 - Sair"
         "\n\nOpção: ");
}

int main() {
  LLSD lista;
  Item item;
  int k = 0;
  char nome[20];

  iniciaLista(&lista);

  while (k != 9) {
    Menu();
    scanf("%d", &k);
    switch (k) {
    case 1:
      printf("\n\n");
      imprimeLista(&lista);
      printf("\n\n");
      break;

    case 2:
      item.pos = lista.ultimo;
      printf("\nNome: ");
      scanf("%s", item.nome);
      insereInicio(&lista, item);
      break;

    case 3:
      item.pos = lista.ultimo;
      printf("\nNome: ");
      scanf("%s", item.nome);
      insereFinal(&lista, item);
      break;

    case 4:
      printf("\nPosição: ");
      scanf("%d", &item.pos);
      printf("\nNome: ");
      scanf("%s", item.nome);
      insereOrdenado(&lista, item, item.pos);
      break;

    case 5:
      if (listaVazia(&lista) < 0) {
        printf("\nNome procurado: ");
        scanf("%s", nome);
        buscaNome(&lista, nome);
      }
      break;

    case 6:
      retiraInicio(&lista);
      break;

    case 7:
      retiraFinal(&lista);
      break;

    case 8:
      printf("\nPosição: ");
      scanf("%d", &item.pos);
      retiraEspecifico(&lista, item.pos);
      break;
    }
  }

  printf("\nAté mais!\n");
  liberaLista(&lista);
  return 0;
}