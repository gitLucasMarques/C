#include <stdio.h>
int main() {
  int i, v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, num, quant[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  while(num!=0){
    scanf("%d", &num);
    switch(num){
      case 1:
      quant[0]++;
      break;

      case 2:
      quant[1]++;
      break;

      case 3:
      quant[2]++;
      break;

      case 4:
      quant[3]++;
      break;

      case 5:
      quant[4]++;
      break;

      case 6:
      quant[5]++;
      break;

      case 7:
      quant[6]++;
      break;

      case 8:
      quant[7]++;
      break;

      case 9:
      quant[8]++;
      break;
    }
  }
    
  printf("O histograma é: %d %d %d %d %d %d %d %d %d", quant[0], quant[1], quant[2], quant[3], quant[4], quant[5], quant[6], quant[7], quant[8]);
  
  return 0;
}
    

    
  