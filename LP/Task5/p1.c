#include <math.h>
#include <stdio.h>

float Receber_variaveis(float valor) {
  scanf("%f", &valor);
  return valor;
}

float Calculo_linear(float b, float c, float raizLinear) {
  raizLinear = -(c) / (b);
  return raizLinear;
}

void Imprimir_linear(float resultadoLinear) {
  printf("\nRaiz: %0.2f\n", resultadoLinear);
  return;
}

float Calcular_delta(float a, float b, float c, float delta) {
  delta = pow((b), 2) - (4 * (a) * (c));
  return delta;
}

float Calcular_raiz1(float a, float b, float raiz1, float delta) {
  raiz1 = (-(b) + sqrt(delta)) / 2 * (a);
  return raiz1;
}

float Calcular_raiz2(float a, float b, float raiz2, float delta) {
  raiz2 = (-(b)-sqrt(delta)) / 2 * (a);
  return raiz2;
}

void Imprimir_raizes(float raiz1, float raiz2) {
  printf("\nRaiz 1: %0.2f\nRaiz 2: %0.2f\n", raiz1, raiz2);
  return;
}

int main() {
  float a, b, c, valor;
  float delta, raiz1, raiz2, raiz, raizLinear;

  a = Receber_variaveis(valor);
  b = Receber_variaveis(valor);
  c = Receber_variaveis(valor);

  if (a == 0) {
    raiz = Calculo_linear(b, c, raizLinear);
    Imprimir_linear(raiz);
  } else {
    delta = Calcular_delta(a, b, c, delta);

    if (delta == 0) {
      raiz1 = Calcular_raiz1(a, b, raiz1, delta);
      raiz2 = raiz1;
    }
    if (delta < 0) {
      printf("Não existem raízes reais");
    }
    if (delta > 0) {
      raiz1 = Calcular_raiz1(a, b, raiz1, delta);
      raiz2 = Calcular_raiz2(a, b, raiz2, delta);
    }
    Imprimir_raizes(raiz1, raiz2);
  }

  return 0;
}

/*
#include <math.h>
#include <stdio.h>

float Receber_variaveis(float valor) {
  scanf("%f", &valor);
  return valor;
}

float Calculo_linear(float b, float c, float raizLinear) {
  raizLinear = -(c) / (b);
  return raizLinear;
}

void Imprimir_linear(float resultadoLinear) {
  printf("\nRaiz: %0.2f\n", resultadoLinear);
  return;
}

float Calcular_delta(float a, float b, float c, float delta) {
  delta = pow((b), 2) - (4 * (a) * (c));
  return delta;
}

float Calcular_raiz1(float a, float b, float raiz1, float delta) {
  raiz1 = (-(b) + sqrt(delta)) / 2 * (a);
  return raiz1;
}

float Calcular_raiz2(float a, float b, float raiz2, float delta) {
  raiz2 = (-(b)-sqrt(delta)) / 2 * (a);
  return raiz2;
}

void Imprimir_raizes(float raiz1, float raiz2) {
  printf("\nRaiz 1: %0.2f\nRaiz 2: %0.2f\n", raiz1, raiz2);
  return;
}

int main() {
  float a, b, c, valor;
  float delta, raiz1, raiz2, raiz, raizLinear;

  a = Receber_variaveis(valor);
  b = Receber_variaveis(valor);
  c = Receber_variaveis(valor);

  if (a == 0) {
    raiz = Calculo_linear(b, c, raizLinear);
    Imprimir_linear(raiz);
  } else {
    delta = Calcular_delta(a, b, c, delta);

    if (delta == 0) {
      raiz1 = raiz2;
    }
    if (delta < 0) {
      printf("Não existem raízes reais");
    }
    if (delta > 0) {
      raiz1 = Calcular_raiz1(a, b, raiz1, delta);
      raiz2 = Calcular_raiz2(a, b, raiz2, delta);

      Imprimir_raizes(raiz1, raiz2);
    }
  }

  return 0;
}
*/