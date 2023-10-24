#include "PilhaDinamica.h"

void insereNaPilha(TipoPilha *pilha, int disks);
void escolhaPino(int *pinoI, int *pinoF);
int trocaPino(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3, int pinoI, int pinoF);
void imprimeHanoi(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3);
void verificaHanoi(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3);
int torreDeHanoi(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3, int disks, int movs);

int main() {
  TipoPilha pilha1, pilha2, pilha3;
  int disks, movs;

  inicializaPilha(&pilha1);
  inicializaPilha(&pilha2);
  inicializaPilha(&pilha3);

  printf("\nQuantidade de discos que serão utilizados: ");
  scanf("%d", &disks);
  printf("\nQuantidade de movimentos que serão realizados: ");
  scanf("%d", &movs);

  insereNaPilha(&pilha1, disks);
  imprimeHanoi(&pilha1, &pilha2, &pilha3);
  torreDeHanoi(&pilha1, &pilha2, &pilha3, disks, movs);

  destroiPilha(&pilha1);
  destroiPilha(&pilha2);
  destroiPilha(&pilha3);

  return 0;
}

void insereNaPilha(TipoPilha *pilha, int disks) {
  TipoItem item;
  int i;

  for (i = disks; i > 0; i--) {
    item.x = i + 48;
    empilha(pilha, item);
  }
}

void escolhaPino(int *pinoI, int *pinoF) {
  printf("\nEntre com o pino do qual o disco será retirado: ");
  scanf("%d", pinoI);
  printf("\nEntre com o pino que receberá o disco: ");
  scanf("%d", pinoF);
}

int trocaPino(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3, int pinoI, int pinoF) {
  TipoItem item, itemAux;

  switch (pinoI) {
  case 1:
    if (!desempilha(pilha1, &item))
      return 0;
    break;
  case 2:
    if (!desempilha(pilha2, &item))
      return 0;
    break;
  case 3:
    if (!desempilha(pilha3, &item))
      return 0;
    break;
  default:
    return 0;
    break;
  }

  switch (pinoF) {
  case 1:
    if (consultaTopo(pilha1, &itemAux)) {
      if (item.x < itemAux.x)
        empilha(pilha1, item);
      else
        return 0;
    } else
      empilha(pilha1, item);
    break;
  case 2:
    if (consultaTopo(pilha2, &itemAux)) {
      if (item.x < itemAux.x)
        empilha(pilha2, item);
      else
        return 0;
    } else
      empilha(pilha2, item);
    break;
  case 3:
    if (consultaTopo(pilha3, &itemAux)) {
      if (item.x < itemAux.x)
        empilha(pilha3, item);
      else
        return 0;
    } else
      empilha(pilha3, item);
    break;
  default:
    return 0;
    break;
  }

  return 1;
}

void imprimeHanoi(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3) {
  printf("\nPilha1:\n");
  imprimePilha(pilha1);
  printf("\n");
  printf("\nPilha2:\n");
  imprimePilha(pilha2);
  printf("\n");
  printf("\nPilha3:\n");
  imprimePilha(pilha3);
  printf("\n");
}

void verificaHanoi(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3) {

  if (!pilhaVazia(pilha1) && !pilhaVazia(pilha2))
    printf("Unsolved\n");
  else
    printf("Solved\n");
}

int torreDeHanoi(TipoPilha *pilha1, TipoPilha *pilha2, TipoPilha *pilha3, int disks, int movs) {
  int i, pinoI, pinoF;

  for (i = 0; i < movs; i++) {
    escolhaPino(&pinoI, &pinoF);
    if (!trocaPino(pilha1, pilha2, pilha3, pinoI, pinoF)) {
      printf("\nWrong move\n");
      return 0;
    }
    imprimeHanoi(pilha1, pilha2, pilha3);
  }

  verificaHanoi(pilha1, pilha2, pilha3);

  return 1;
}