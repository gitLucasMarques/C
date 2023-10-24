#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int v[10], i;
  int *ptrV;

  srand(time(NULL));
  printf("v = ");
  for(i=0;i<10;i++){
    v[i] = rand()%11;
    printf("%i\t",v[i]);
  }

  ptrV = v + 5;
  printf("\n*ptrV = %i",*ptrV);
  printf("\n*(v+5)) = %i",*(v+5));

  return 0;
}