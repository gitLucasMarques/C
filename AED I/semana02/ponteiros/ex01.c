#include <stdio.h>

int main(){
  int n;
  int *ptrN;

  printf("N: ");
  scanf("%i",&n);
  ptrN = &n;
  
  printf("n = %i\n",n);
  printf("ptrN = %p\n",ptrN);
  printf("&n = %p\n",&n);
  printf("*ptrN = %i\n",*ptrN);
  return 0;
}