#include <stdio.h>

int Receber_grau(int grau) {
  scanf("%d", &grau);
  return grau;
}

float Receber_coeficientes(int i, float coef[i], int grau) {
  for (i = 1; i < grau + 2; i++) {
    scanf("%f", &coef[i]);
  }
  return coef[i];
}

void Imprimir_equacao(int i, int grau, float coef[i], int gr, float aux) {
  printf("\nEquação: ");
  for (i = 1; i <= grau + 1; i++, gr--) {
    if (i == grau + 1) {
      if (coef[i] > 0) {
        printf("+ %0.1fx^0", coef[i]);
      } else {
        aux = coef[i]/(-1);
        printf("- %0.1fx^0", aux);
      }
    } else {
      if (i == 1) {
        if (coef[i] > 0) {
          printf("%0.1fx^%d ", coef[i], gr);
        } else {
          aux = coef[i]/(-1);
          printf("-%0.1fx^%d ", aux, gr);
        }
      } else {
        if (coef[i] > 0) {
          printf("+ %0.1fx^%d ", coef[i], gr);
        } else {
          aux = coef[i]/(-1);
          printf("- %0.1fx^%d ", aux, gr);
        }
      }
    }
  }
  return;
}

void Imprimir_derivadas(int i, int grau, int gr, float coef[i], float coefDer[i], int j, float auxgrau1, int auxgrau2, int auxgr) {

  for (j = 1; j <= auxgr; j++) {
    if(j != auxgr){
      printf("\nDev %d: Equação: ", j);
    }else{
      printf("\nDev %d: ", j);
    }
    gr--;
    grau = auxgrau2;
    auxgrau2--;

    for (i = 1; i <= gr + 1; i++) {
      if (i == gr + 1) {
        coefDer[i] = (coef[i]) * (grau);
        coef[i] = coefDer[i];
        if (coefDer[i] > 0 && j == auxgr) {
          printf("%0.1fx^0", coefDer[i]);
        } else {
          if(coefDer[i] > 0){
            printf("+ %0.1fx^0", coefDer[i]);
          } else {
            coefDer[i] /= (-1);
            printf("- %0.1fx^0", coefDer[i]);
          }
        }
      } else {
        if (i == 1) {
          coefDer[i] = (coef[i]) * (grau);
          coef[i] = coefDer[i];
          auxgrau1 = grau--;
          if (coefDer[i] > 0) {
            printf("%0.1fx^%0.0f ", coefDer[i], auxgrau1 - 1);
          } else {
            coefDer[i] /= (-1);
            printf("-%0.1fx^%0.0f ", coefDer[i], auxgrau1 - 1);
          }
          
        } else {
          coefDer[i] = (coef[i]) * (grau);
          coef[i] = coefDer[i];
          auxgrau1 = grau--;
          if (coefDer[i] > 0) {
            printf("+ %0.1fx^%0.0f ", coefDer[i], auxgrau1 - 1);
          } else {
            coefDer[i] /= (-1);
            printf("- %0.1fx^%0.0f ", coefDer[i], auxgrau1 - 1);
          }
        }
      }
    }
  }
  return;
}

int main() {
  int grau, i, j, gr, auxgr, auxgrau2;
  float coef[1000] = {0}, coefDer[1000] = {0}, auxGrau[1000], auxgrau1, aux;

  grau = Receber_grau(grau);
  gr = grau;
  auxgr = grau;
  auxgrau1 = grau;
  auxgrau2 = grau;

  coef[i] = Receber_coeficientes(i, &coef[i], grau);

  if (grau < 0) {
    printf("Grau inválido");
  } else {
    Imprimir_equacao(i, grau, &coef[i], gr, aux);
    Imprimir_derivadas(i, grau, gr, &coef[i], &coefDer[i], j, auxgrau1, auxgrau2, auxgr);
  }

  return 0;
}
