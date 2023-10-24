#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *v1, int tam);
int to_compare(int *v1, int *v2, int tam);
void swap(int *v1, int posAnt);

int main() {
  int qPac;
  int *qMic, *pDos;
  int i;

  scanf("%d", &qPac);
  qMic = malloc(qPac * sizeof(int));

  for (i = 0; i < qPac; i++) {
    scanf("%d", &qMic[i]);
  }

  pDos = malloc(qPac * sizeof(int));
  for (i = 0; i < qPac; i++) {
    scanf("%d", &pDos[i]);
  }

  bubble_sort(qMic, qPac);
  bubble_sort(pDos, qPac);

  if (to_compare(qMic, pDos, qPac) == 1) {
    printf("sim\n");
  } else {
    printf("nao\n");
  }

  free(qMic);
  free(pDos);

  return 0;
}

void swap(int *v1, int posAnt) {
  int aux = 0;

  aux = v1[posAnt];
  v1[posAnt] = v1[posAnt + 1];
  v1[posAnt + 1] = aux;
}

void bubble_sort(int *v1, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (v1[j] > v1[j + 1]) {
        swap(v1, j);
      }
    }
  }
}

int to_compare(int *v1, int *v2, int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (v2[i] <= v1[i]) {
      return 0;
    }
  }
  return 1;
}