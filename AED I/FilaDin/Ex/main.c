#include "FD.h"

int main() {
  FD f, fI, fP;
  Item item;
  TipoNoh *ptrAux;
  int i;

  iniciaFila(&f);

  srand(time(NULL));
  for (i = 0; i < 100; i++) {
    item.num = rand() % 101;
    insereFila(&f, item);
  }

  printf("\nFila Principal I: ");
  imprimeFila(&f);

  iniciaFila(&fI);
  iniciaFila(&fP);

  ptrAux = f.inicio;
  while (ptrAux->prox != NULL) {
    if (ptrAux->item.num % 2 == 0) {
      item.num = ptrAux->item.num;
      insereFila(&fP, item);
    }
    if (ptrAux->item.num % 2 != 0) {
      item.num = ptrAux->item.num;
      insereFila(&fI, item);
    }
    retiraFila(&f);
    ptrAux = ptrAux->prox;
  }

  item.num = ptrAux->item.num;
  if (item.num % 2 == 0) {
    insereFila(&fP, item);
  }
  if (item.num % 2 != 0) {
    insereFila(&fI, item);
  }
  retiraFila(&f);

  printf("\n\nFila Principal II: ");
  imprimeFila(&f);
  printf("\n\nFila Pares: ");
  imprimeFila(&fP);
  printf("\n\nFila Ímpares: ");
  imprimeFila(&fI);
  printf("\n\n");

  liberaFila(&fP);
  liberaFila(&fI);

  return 0;
}
