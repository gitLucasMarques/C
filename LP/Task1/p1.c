#include <stdio.h>

int main() {
  float p1, p2, p3, p4, p5, media;
  
  scanf("%f %f %f %f %f", &p1, &p2, &p3, &p4, &p5);
  media = (p1+p2+p3+p4+p5)/5;
  printf("p1= %0.1f p2= %0.1f p3= %0.1f p4= %0.1f p5= %0.1f media= %0.2f", p1, p2, p3, p4, p5, media);
  return 0;
}