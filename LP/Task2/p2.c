#include <stdio.h>

int main() {
  int n, i; 
  long double f;

  scanf("%d", &n);

  if(n==0){
    printf("O fatorial de 0 é: 1");
  }else{
  if(n<0){
    printf("Não existe fatorial de %d", n);
  }else{
    f = 1;
    i = 1;
    while(i<n){
    f = f*(n-i);
    i++;
  } 
    
  printf("O fatorial de %d é: %0.0Lf", n, f*n);
  }
}
  return 0;
}