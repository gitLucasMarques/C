#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocaVetor(int); 
void preencheVetor(int*,int);
void imprimeVetor(int*,int);
void liberaVetor(int*);

int main(){
  int n, *vet;
  printf("N: ");
  scanf("%i",&n);

  vet = alocaVetor(n);
  preencheVetor(vet,n);
  imprimeVetor(vet,n);
  liberaVetor(vet);

  return 0;
}

int* alocaVetor(int n){
  return (int *) malloc(n*sizeof(int));
}

void preencheVetor(int *v, int n){
  int i;
  srand(time(NULL));
  for(i=0;i<n;i++){
    v[i] = rand()%101;
  }
}

void imprimeVetor(int *v, int n){
  int i;
  for(i=0;i<n;i++)
    printf("%i\t",v[i]);
}

void liberaVetor(int *v){
  free(v);
}