#include <stdio.h>

int main(){
  int v[5];
  int *ptrInt;

  ptrInt = v;

  ptrInt[0] = 1;
  v[1] = 2;
  v[2] = 3;
  v[3] = 4;
  v[4] = 5;
  
  printf("*(v+3) = %i",*(v+3));

  return 0;
}