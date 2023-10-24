#include <stdio.h>

void incrementaInt(int);
void incrementaInt01(int *);

int main(){
  int n1, n2;

  printf("N1: ");
  scanf("%i",&n1);
  printf("N2: ");
  scanf("%i",&n2);
  incrementaInt(n1);
  incrementaInt01(&n2);
  printf("\nN1: %i",n1);
  printf("\nN2: %i",n2);
  
  return 0;
}

void incrementaInt(int n){
  n = n+1;
}

void incrementaInt01(int *ptrInt){
  *ptrInt = *ptrInt + 1;
}