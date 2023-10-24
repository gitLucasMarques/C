#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **v, int a, int d) {
  char *aux;

  aux = v[a];
  v[a] = v[d];
  v[d] = aux;
}

int indiceChave(char *chave, char c) {
  int k = 0;

  while (chave[k] != c) {
    k++;
  }
  return k;
}

int f_validade(char *chave, char *p1, char *p2) {
  int i = 0, i1, i2;

  while (p1[i] && p2[i]) {
    if (p1[i] == p2[i]) {
      i++;
    } else {
      i1 = indiceChave(chave, p1[i]);
      i2 = indiceChave(chave, p2[i]);

      if (i1 < i2) {
        return 1;
      } else {
        return 2;
      }
    }
  }

  if (strlen(p1) < strlen(p2)) {
    return 2;
  } else {
    return 1;
  }
}

void max_heapify(char **v, int i, char *chave, int n) {
  int l, r, max;

  l = 2 * i;
  r = 2 * i + 1;

  if (l <= n && f_validade(chave, v[l], v[i]) == 1) {
    max = l;
  } else {
    max = i;
  }

  if (r <= n && f_validade(chave, v[r], v[max]) == 1) {
    max = r;
  }

  if (max != i) {
    swap(v, i, max);
    max_heapify(v, max, chave, n);
  }
}

void build_max_heap(char **v, char *chave, int n) {
  int i;

  for (i = n / 2; i > 1; i--) {
    max_heapify(v, i, chave, n);
  }
}

char *heap_extract_max(char **v, char *chave, int n) {
  int last;
  char *max;

  *max = *v[1];
  last = n;
  v[1] = v[last];

  v[last] = 0;

  max_heapify(v, 1, chave, n);
  return max;
}

void heap_sort(char **v, char *chave, char **s, int n) {
  int i;

  build_max_heap(v, chave, n);

  while (n > 0) {
    s[n] = heap_extract_max(v, chave, n);
    n--;
  }
}

void erro(char *chave, char **v, int n) {
  int i, k, j, cont = 0, p = 0;
  char *aux;

  for (i = 0; i < n; i++) {
    aux = v[i];
    for (k = 0; k <= strlen(v[i]); k++) {
      for (j = 0; j < strlen(chave); j++) {
        if (aux[k] == chave[j]) {
          cont++;
          p++;
          break;
        }
      }
    }
  }
  if (p != 0) {
    printf("A palavra %s eh invalida", aux);
  }
}

int main() {
  int n, s, i;
  char **palavras, *chave, *vC, *vP, **saida;

  scanf("%d %d", &n, &s);

  chave = malloc(s * sizeof(char));
  getchar();
  fgets(chave, s, stdin);

  palavras = (char **)malloc(n * sizeof(char *));
  for (i = 0; i < n; i++) {
    palavras[i] = malloc(32 * sizeof(char));
    scanf("%s", palavras[i]);
  }

  saida = (char **)malloc(n * sizeof(char *));
  for (i = 0; i < n; i++) {
    saida[i] = malloc(32 * sizeof(char));
  }

  erro(chave, palavras, n);
  heap_sort(palavras, chave, saida, n);

  for (i = 0; i < n; i++) {
    printf("%s ", saida[i]);
  }

  return 0;
}
