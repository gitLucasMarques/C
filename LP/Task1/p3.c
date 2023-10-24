#include <stdio.h>
#include <math.h>
 
int main(){
    float a, b, c; 
    float d, r1, r2;
    
    scanf("%f %f %f",&a,&b,&c);
   
  d = (b*b) + (-4*a*c);
  r1 = (-b +sqrt(d))/2*a;
  r2 = (-b -sqrt(d))/2*a;
 
    if(a==0){
        r1 = -(c)/(b);
        printf("Raiz: %.2f", r1);
    }
    
    else{
        if(d<0){
            printf("Não existem raízes reais");
        }
        
        else if(d==0){
            printf("Raiz: %.2f",r1);
        }
    
        else{
            printf("Raiz 1: %.2f\n",r1);
            printf("Raiz 2: %.2f",r2);
        }
    }
}