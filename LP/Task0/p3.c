#include <stdio.h>
int main(){
  float a;
  float b;
  float soma; 
  scanf("%f %f", &a, &b);

  soma = a + b;
  printf("%0.2f + %0.2f = %0.2f", a, b, soma);
  return 0;
}