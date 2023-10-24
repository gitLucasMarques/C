#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i, j, **matriz;
  
  matriz = (int **) malloc(5*sizeof(int*));

  for(i=0;i<5;i++){
    matriz[i] = (int *) malloc(5*sizeof(int));
  }

  srand(time(NULL));
  printf("Matriz: \n");
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      matriz[i][j] = rand()%11;
      printf("%i\t",matriz[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<5;i++){
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}