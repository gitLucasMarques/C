#include "pilha.h"

int main() {
  Pilha p, pI, pP;
  Item item;
  int i;

  iniciaPilha(&p);

  srand(time(NULL));
  for (i = 0; i < 20; i++) {
    item.num = rand() % 101;
    push(&p, item);
  }

  printf("\nPilha Principal I:\n\n");
  imprimePilha(&p);
  printf("\n\n");

  iniciaPilha(&pI);
  iniciaPilha(&pP);

  for (i = 0; i < 20; i++) {
    pop(&p, &item);
    if (item.num % 2 == 0) {
      push(&pP, item);
    }
    if (item.num % 2 != 0) {
      push(&pI, item);
    }
  }

  printf("\nPilha Principal II: ");
  imprimePilha(&p);
  printf("\n\n");
  printf("\nPilha Pares:\n\n");
  imprimePilha(&pP);
  printf("\n\n");
  printf("\nPilha Ímpares:\n\n");
  imprimePilha(&pI);
  printf("\n\n");

  liberaPilha(&p);
  liberaPilha(&pI);
  liberaPilha(&pP);

  return 0;
}