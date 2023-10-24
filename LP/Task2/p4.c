    #include <stdio.h>
     
    int main() {
      
      int num, i, a = 2, b = 0;
      scanf("%d", &num);
      
      if(num<2){
          printf("Não tem primos!");
      }
      
      while (a <= num) {   
        i = 2;
        while (i <= a / 2) {
          if (a % i == 0) {
            b++;
            break;
          }
          i++;
        }
         if (b == 0) {
          printf("%d\n", a);
         }
        b = 0;
        a++;
      }
      
      return 0;
    }