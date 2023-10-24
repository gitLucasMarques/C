#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, i, *ptrVet;

  printf("Número de elementos do vetor: ");
  scanf("%i",&n);

  ptrVet = malloc(n*sizeof(int));

  srand(time(NULL));
  printf("Vetor: ");
  for(i=0;i<n;i++){
    ptrVet[i] = rand()%101;
    printf("%i\t",ptrVet[i]);
  }

  free(ptrVet);

  return 0;
}