#include <stdio.h>

int main() {
  int d1, m1, a1, d2, m2, a2;
  
  scanf("%d/%d/%d %d/%d/%d", &d1, &m1, &a1, &d2, &m2, &a2);
  
  if(a1==a2){
    if(m1==m2)
      
        if(d1<d2){
          printf("A primeira data ocorreu antes da segunda.");
        }else{
          printf("A segunda data ocorreu antes da primeira.");
        }
      
        else
         if(m1<m2){
        printf("A primeira data ocorreu antes da segunda.");
      }else{
        printf("A segunda data ocorreu antes da primeira.");
      }
    
  }else{
    if(a1<a2){
      printf("A primeira data ocorreu antes da segunda.");
    }else{
      printf("A segunda data ocorreu antes da primeira.");
    }
  }
  
  return 0;
}