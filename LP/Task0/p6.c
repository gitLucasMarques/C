#include <stdio.h>

int main() 
{
  int a;
  int b;
  scanf("%d %d", &a, &b);
  printf("Os valores digitados foram a: %d e b: %d.\n", a, b);
  
  a = a + b;
  b = a - b;
  a = a - b;
  printf("Os valores atuais são a: %d e b: %d.", a, b);
  return 0;
}