#include <stdio.h>
#include <stdlib.h>

void quick_sort_end(int *, int, int, int *, int *, int *);
void quick_sort_med(int *, int, int, int *, int *, int *);

int partition_end(int *, int, int);

int partition_med(int *, int, int);
void med(int *v, int p, int r);

void swap(int *, int, int);

int main() {
  int n, k, contI = 0, contF = 0, contReal = 0;
  int *v1, *v2;

  scanf("%d", &n);
  v1 = malloc(n * sizeof(int));
  v2 = malloc(n * sizeof(int));

  for (k = 0; k < n; k++) {
    scanf("%d", &v1[k]);
    v2[k] = v1[k];
  }

  contI = n;

  quick_sort_end(v1, 0, n - 1, &contI, &contF, &contReal);
  printf("\n%d\n", contF - contI);

  contReal = 0;
  contF = 0;
  contI = n;

  quick_sort_med(v2, 0, n - 1, &contI, &contF, &contReal);
  printf("%d\n", contF - contI);

  free(v1);
  free(v2);

  return 0;
}

void swap(int *v, int posA, int posP) {
  int aux;

  aux = v[posA];
  v[posA] = v[posP];
  v[posP] = aux;
}

int partition_end(int *v, int p, int r) {
  int x, i, j;

  x = v[r];
  i = p - 1;

  for (j = p; j < r; j++) {
    if (v[j] < x) {
      i = i + 1;
      swap(v, i, j);
    }
  }
  swap(v, i + 1, r);
  return i + 1;
}

void quick_sort_end(int *v, int p, int r, int *contI, int *contF,
                    int *contReal) {
  int q;

  (*contReal)++;
  if (p < r) {
    q = partition_end(v, p, r);
    quick_sort_end(v, p, q - 1, contI, contF, contReal);
    quick_sort_end(v, q + 1, r, contI, contF, contReal);
  } else {
    if ((*contReal) > (*contF)) {
      (*contF) = (*contReal);
    }
    if ((*contReal) < (*contI)) {
      (*contI) = (*contReal);
    }
  }
  (*contReal)--;
  return;
}

void med(int *v, int p, int r) {
  int posMed = r, m;

  m = (p + r) / 2;

  if (v[p] > v[r]) {
    if (v[p] > v[m]) {
      if (v[m] > v[r])
        posMed = m;
    } else
      posMed = p;
  }

  else {
    if (v[p] > v[m])
      posMed = p;
    else if (v[m] < v[r])
      posMed = m;
  }

  if (posMed != r)
    swap(v, r, posMed);
}

int partition_med(int *v, int p, int r) {
  int x, i, j;

  med(v, p, r);

  x = v[r];
  i = p - 1;

  for (j = p; j < r; j++) {
    if (v[j] < x) {
      i = i + 1;
      swap(v, i, j);
    }
  }
  swap(v, i + 1, r);
  return i + 1;
}

void quick_sort_med(int *v, int p, int r, int *contI, int *contF,
                    int *contReal) {
  int q, pivot;

  (*contReal)++;
  if (p < r) {
    q = partition_med(v, p, r);
    quick_sort_med(v, p, q - 1, contI, contF, contReal);
    quick_sort_med(v, q + 1, r, contI, contF, contReal);
  } else {
    if ((*contReal) > (*contF)) {
      (*contF) = (*contReal);
    }
    if ((*contReal) < (*contI)) {
      (*contI) = (*contReal);
    }
  }
  (*contReal)--;
}
