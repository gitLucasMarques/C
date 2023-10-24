#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_lower(char *palavra) {
  int i;

  for (i = 0; i < strlen(palavra); i++) {
    palavra[i] = tolower(palavra[i]);
  }
}

void counting_sort(int *a, int *b, int maior, int n) {
  int *c, i;

  c = malloc((25 + 1) * sizeof(int *));

  for (i = 0; i <= 26; i++) {
    c[i] = 0;
  }

  for (i = 0; i < n; i++) {
    c[a[i]] = c[a[i]] + 1;
  }

  for (i = 1; i <= 26; i++) {
    c[i] = c[i] + c[i - 1];
  }

  for (i = n - 1; i >= 0; i--) {
    b[c[a[i]] - 1] = a[i];
    c[a[i]] = c[a[i]] - 1;
  }

  for (i = 0; i <= 26; i++) {
    if (i < 26) {
      printf("%d ", c[i]);
    } else {
      printf("%d\n", c[i]);
    }
  }

  free(c);
}

void radix_sort(int *a, int *b, int k, int n, int strMaior) {
  int i;

  for (i = 0; i < strMaior; i++) {
    counting_sort(a, b, k, n);
    int *temp = a;
    a = b;
    b = temp;
  }

  if (n % 2 != 0) {
    for (i = 0; i < n; i++) {
      b[i] = a[i];
    }
  }
}

int main() {
  int n, i, j, strMaior = 0, *aux1, *aux2, *s, maior = 0;
  char **palavras, *chave, letra, *vAux;

  scanf("%d", &n);

  chave = malloc(26 * sizeof(char));
  scanf("%s", chave);

  palavras = (char **)malloc(n * sizeof(char *));

  for (i = 0; i < n; i++) {
    palavras[i] = malloc(20 * sizeof(char));
    getchar();
    scanf("%s", palavras[i]);
  }

  for (i = 0; i < n; i++) {
    string_lower(palavras[i]);
  }

  for (i = 0; i < n; i++) {
    printf("\n%s.", palavras[i]);
  }

  for (i = 0; i < n; i++) {
    if (strlen(palavras[i]) > strMaior) {
      strMaior = strlen(palavras[i]);
    }
  }

  printf("\n%d\n", strMaior);

  vAux = malloc(strMaior * sizeof(char));
  for (i = 0; i < n; i++) {
    for (j = 0; j < strlen(palavras[i]); j++) {
      vAux[j] = palavras[i][j];
    }
  }
  for (i = j; i < strMaior; i++) {
    strcpy(&vAux[i], " ");
  }

  //                              //

  aux1 = malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    letra = palavras[i][0];
    for (j = 0; j < strlen(chave); j++) {
      if (letra == chave[j]) {
        aux1[i] = j;
        break;
      }
    }
  }

  aux2 = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    aux2[i] = aux1[i];
  }

  for (i = 0; i < n; i++) {
    if (aux1[i] > maior) {
      maior = aux1[i];
    }
  }

  s = malloc(n * sizeof(int));
  radix_sort(aux1, s, maior, n, strMaior);

  printf("\n\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (s[i] == aux2[j]) {
        aux2[j] = -1;

        printf("\n%s", palavras[j]);
        break;
      }
    }
  }
  printf("\n\n");

  return 0;
}