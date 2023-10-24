#include <stdio.h>

int main() {
  int num, quantNum;
  float media, total;

  scanf("%d", &num);
  
  quantNum = 0;
  while(num!=0){
    total = total + num;
    scanf("%d", &num);
    quantNum++;
  }
  media = (total)/(quantNum);
  printf("A media aritmética dos %d valores é: %0.1f", quantNum, media);
  
return 0;
}