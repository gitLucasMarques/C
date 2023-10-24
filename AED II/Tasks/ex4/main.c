#include <stdio.h>
#include <stdlib.h>

void quick_sort_end(int *, int, int, int *, int *, int);
void quick_sort_med(int *, int, int, int *, int *, int);

int partition_end(int *, int, int);

int partition_med(int *, int, int);
int med(int *, int, int);

void swap(int *, int, int);

int main() {
  int n, k, cont1I = 0, cont1F = 0, cont2I = 0, cont2F = 0;
  int *v1, *v2;

  scanf("%d", &n);
  v1 = malloc(n * sizeof(int));
  v2 = malloc(n * sizeof(int));

  for (k = 0; k < n; k++) {
    scanf("%d", &v1[k]);
    v2[k] = v1[k];
  }

  cont1I = n;
  cont2I = n;

  quick_sort_end(v1, 0, n - 1, &cont1I, &cont1F, 0);
  printf("\n%d\n", cont1F - cont1I);

  quick_sort_med(v2, 0, n - 1, &cont2I, &cont2F, 0);
  printf("%d\n", cont2F - cont2I);

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

void quick_sort_end(int *v, int p, int r, int *contI, int *contF, int def) {
  int q;

  if (p < r) {
    q = partition_end(v, p, r);
    quick_sort_end(v, p, q - 1, contI, contF, def + 1);
    quick_sort_end(v, q + 1, r, contI, contF, def + 1);

  } else {
    if (def > (*contF)) {
      (*contF) = def;
    }

    if (def < (*contI)) {
      (*contI) = def;
    }
  }
}

int med(int *v, int p, int r) {
  int m;
  m = (p + r) / 2;

  if ((v[m] < v[p] && v[p] < v[r]) || (v[m] > v[p] && v[p] > v[r])) {
    return p;
  } else if ((v[m] < v[r] && v[r] < v[p]) || (v[m] > v[r] && v[r] > v[p])) {
    return r;
  } else {
    return m;
  }
}

int partition_med(int *v, int p, int r) {
  int pivot;

  pivot = med(v, p, r);
  swap(v, p, r);

  return partition_end(v, p, r);
}

void quick_sort_med(int *v, int p, int r, int *contI, int *contF, int def) {
  int q, pivot;

  if (p < r) {
    q = partition_med(v, p, r);

    quick_sort_med(v, p, q - 1, contI, contF, def + 1);
    quick_sort_med(v, q + 1, r, contI, contF, def + 1);
  } else {
    if (def >= (*contF)) {
      (*contF) = def;
    }

    if (def < (*contI)) {
      (*contI) = def;
    }
  }
}
