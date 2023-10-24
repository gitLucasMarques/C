#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int*,int);

int main(){
  int n, *vet, i;

  printf("N: ");
  scanf("%i",&n);

  vet = (int *) malloc(n*sizeof(int));

  preencheVetor(vet,n);

  for(i=0;i<n;i++){
    printf("%i\t",vet[i]);
  }
  
  free(vet);

  return 0;
}

void preencheVetor(int *v, int n){
  int i;
  srand(time(NULL));
  for(i=0;i<n;i++){
    v[i] = rand()%101;
  }
}