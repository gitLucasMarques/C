#include <stdio.h>

void trocaInt(int*, int*);

int main(){
  int n1, n2;

  printf("N1: ");
  scanf("%i",&n1);
  printf("N2: ");
  scanf("%i",&n2);

  trocaInt(&n1,&n2);

  printf("\nN1: %i",n1);
  printf("\nN2: %i",n2);

  return 0;  
}

void trocaInt(int *x, int *y){
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}