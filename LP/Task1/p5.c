#include <stdio.h>

int main() {
  int r1, r2, r3;

  scanf("%d%d%d", &r1, &r2, &r3);

  if((r1+r2)>r3){
    if((r1+r3)>r2){
      if((r2+r3)>r1){
        
        if(r1==r2){  
          if(r1==r3){
            printf("O triângulo é equilátero");
          }else{
            printf("O triângulo é isóceles");
          }
        }else{
          if(r1!=r3){
            if(r2!=r3){
              printf("O triângulo é escaleno");
        }
      }
    }
      }else{
        printf("Não é possível formar um triângulo");
      }
    }else{
      printf("Não é possível formar um triângulo");
    }
  }else{
    printf("Não é possível formar um triângulo");
  }
  return 0;
}



