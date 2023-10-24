#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *v, int a, int d);

void max_heapify(int *v, int i);
void build_max_heap(int *v);
int heap_extract_max(int *v);
void heap_sort(int *v, int *s);

void swap(int *v, int a, int d) {
  int aux;

  aux = v[a];
  v[a] = v[d];
  v[d] = aux;
}

void max_heapify(int *v, int i) {
  int l, r, max;

  l = 2 * i;
  r = 2 * i + 1;

  if (l <= 6 && v[l] > v[i]) {
    max = l;
  } else {
    max = i;
  }

  if (r <= 6 && v[r] > v[max]) {
    max = r;
  }

  if (max != i) {
    swap(v, i, max);
    max_heapify(v, max);
  }
}

void build_max_heap(int *v) {
  int n, i;

  n = 6;
  for (i = n / 2; i > 1; i--) {
    max_heapify(v, i);
  }
}

int heap_extract_max(int *v) {
  int max, last;

  max = v[1];
  last = 6;
  v[1] = v[last];

  v[last] = 0;

  max_heapify(v, 1);
  return max;
}

void heap_sort(int *v, int *s) {
  int n, i;

  build_max_heap(v);
  n = 6;

  while (n > 0) {
    s[n] = heap_extract_max(v);
    n--;
  }
}

int main() {
  int v[7] = {0, 10, 5, 7, 4, 2, 1}, *s;
  int i;

  for (i = 0; i < 7; i++) {
    printf("%d ", v[i]);
  }

  s = malloc(7 * sizeof(int));

  heap_sort(v, s);

  printf("\n\n\n\n");
  for (i = 0; i < 7; i++) {
    printf("%d ", s[i]);
  }

  return 0;
}