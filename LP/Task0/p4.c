#include <stdio.h>

int main() {
  int valorSalario;
  int valorReajuste;
  float novoSalario;
  scanf("%d %d", &valorSalario, &valorReajuste);
  
  novoSalario = (valorSalario*valorReajuste/100) + valorSalario; 
  printf("O reajuste salarial de %d%% é: R$%0.2f", valorReajuste, novoSalario);
  return 0;
}