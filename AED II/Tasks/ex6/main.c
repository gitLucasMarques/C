#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 270

int radix_sort(char **, char **, char *, int, int);
int counting_sort(char **, char **, int *, int);

int preenche_espaco(char **, int, int);
int palavra_min(char **, int);
int str_Maior(char **, int);
int *pos_vet(char **, char *, int *, int, int);

int main() {
  int i, wN, tamkey = 27, strMaior;
  char **w1, **w2, *keys;

  scanf("%d", &wN);

  keys = (char *)malloc(tamkey * sizeof(char));
  w1 = (char **)malloc(wN * sizeof(char *));
  w2 = (char **)malloc(wN * sizeof(char *));

  for (i = 0; i < wN; i++) {
    w1[i] = (char *)malloc(TAM_MAX * sizeof(char));
    w2[i] = (char *)malloc(TAM_MAX * sizeof(char));
  }

  scanf("%s", keys);

  for (i = tamkey - 1; i > 0; i--) {
    keys[i] = keys[i - 1];
  }

  keys[0] = ' ';

  for (i = 0; i < wN; i++) {
    scanf("%s", w1[i]);
  }

  palavra_min(w1, wN);

  for (i = 0; i < wN; i++) {
    printf("%s.\n", w1[i]);
  }

  strMaior = str_Maior(w1, wN);

  printf("%d\n", strMaior);

  preenche_espaco(w1, wN, strMaior);

  radix_sort(w1, w2, keys, strMaior, wN);

  for (i = 0; i < wN; i++) {
    printf("%s\n", w2[i]);
  }

  for (i = 0; i < wN; i++) {
    free(w1[i]);
  }

  // free(w1);
  // free(w2);
  // free(keys);

  return 0;
}

int radix_sort(char **w1, char **w2, char *keys, int strMaior, int wN) {
  int i, j, *wP = (int *)malloc(wN * sizeof(int));

  for (i = strMaior - 1; i >= 0; i--) {
    wP = pos_vet(w1, keys, wP, wN, i);
    counting_sort(w1, w2, wP, wN);
  }
  free(wP);

  return 0;
}

int counting_sort(char **w1, char **w2, int *wP, int wN) {
  int i, *c, tam_key = 27;

  c = (int *)malloc(tam_key * sizeof(int));

  for (i = 0; i < tam_key; i++) {
    c[i] = 0;
  }

  for (i = 0; i < wN; i++) {
    c[wP[i]] = c[wP[i]] + 1;
  }

  for (i = 1; i < tam_key; i++) {
    c[i] = c[i] + c[i - 1];
  }

  for (i = 0; i < tam_key; i++) {
    printf("%d", c[i]);
  }

  printf("\n");

  for (i = wN - 1; i >= 0; i--) {
    w2[c[wP[i]] - 1] = w1[i];
    c[wP[i]] = c[wP[i]] - 1;
  }

  for (i = 0; i <= wN; i++) {
    w1[i] = w2[i];
  }

  free(c);

  return 0;
}

int *pos_vet(char **w1, char *keys, int *wP, int wN, int index) {
  int i, j;

  for (i = 0; i < wN; i++) {
    for (j = 0; j < strlen(keys); j++) {
      if (w1[i][index] == keys[j]) {
        wP[i] = j;
        break;
      }
    }
  }

  return wP;
}

int str_Maior(char **w, int wN) {
  int i, strMaior;

  strMaior = strlen(w[0]);

  for (i = 0; i < wN; i++) {
    if (strMaior < strlen(w[i])) {
      strMaior = strlen(w[i]);
    }
  }

  return strMaior;
}

int preenche_espaco(char **w, int wN, int strMaior) {
  int i, j;

  for (i = 0; i < wN; i++) {
    for (j = strlen(w[i]); j < strMaior; j++) {
      w[i][j] = ' ';
    }
    w[i][j] = '\0';
  }

  return 0;
}

int palavra_min(char **w, int wN) {
  int i, j;

  for (i = 0; i < wN; i++) {
    for (j = 0; j < strlen(w[i]); j++) {
      w[i][j] = tolower(w[i][j]);
    }
  }
  return 0;
}
