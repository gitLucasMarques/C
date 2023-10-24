#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NohB {
  int *pag;
  struct NohB **filho;
  int qntPag;
  bool folha;
} ArvB;

ArvB *inicia_arvB(ArvB *);
ArvB *cria_noh(bool, int);

ArvB *insere_ArvB(ArvB *, int, int);
void divide_filhos(ArvB *, int);

ArvB *pesquisa_noh(ArvB *, int, int);

void desloca_valor(ArvB *, int);
int pesquisa_pos(ArvB *, int);

ArvB *pesquisa_ArvB(ArvB *, int);

int main() {
  ArvB *arvore, *resultado;
  int m, num, pesq, i;

  arvore = inicia_arvB(arvore);
  scanf("%d", &m);

  scanf("%d", &num);
  while (num >= 0) {
    printf("Z\n");
    arvore = insere_ArvB(arvore, num, m);
    for (i = 0; i < 2 * m; i++) {
      printf("%d ", arvore->pag[i]);
    }
    printf("\nG\n");
    scanf("%d", &num);
  }

  scanf("%d", &pesq);
  resultado = pesquisa_ArvB(arvore, pesq);
  printf("%d\n", arvore->qntPag);

  if (resultado != NULL) {
    printf("%d\n", resultado->qntPag);
    for (i = 0; i < 2 * m; i++) {
      if (resultado->pag[i] > 0) {
        printf("%d ", resultado->pag[i]);
      }
    }
  } else {
    printf("Valor nao encontrado\n");
  }
  printf("\n");

  return 0;
}

ArvB *inicia_arvB(ArvB *arvore) { return NULL; }

ArvB *cria_noh(bool folha, int t) {
  int i;
  ArvB *novoNoh = malloc(sizeof(ArvB));
  novoNoh->pag = malloc(((2 * t) - 1) * sizeof(int));
  novoNoh->filho = (ArvB **)malloc(2 * t * sizeof(ArvB *));
  for (i = 0; i < 2 * t; i++) {
    novoNoh->pag[i] = 1000000000;
    novoNoh->filho[i] = NULL;
  }
  novoNoh->folha = folha;
  novoNoh->qntPag = 0;

  return novoNoh;
}

void divide_filhos(ArvB *arvore, int t) {
  ArvB *novoNoh_F, *novoNoh_R;
  int i;

  novoNoh_F = cria_noh(true, t);
  for (i = 0; i <= t - 1; i++) {
    novoNoh_F->pag[i] = arvore->pag[i + t];
  }
  novoNoh_F->qntPag = t;
  arvore->qntPag = t;

  novoNoh_R = cria_noh(false, t);
  novoNoh_R->filho[0] = arvore;
  novoNoh_R->filho[1] = novoNoh_F;

  arvore = novoNoh_R;
}

ArvB *pesquisa_noh(ArvB *arvore, int pag, int t) {
  ArvB *noh;
  int i = 0;

  while (i < arvore->qntPag) {
    if (pag < arvore->pag[i] && arvore->filho[i] != NULL) {
      noh = pesquisa_noh(arvore->filho[i], pag, t);
      return noh;
    }

    if (pag > arvore->pag[i] && arvore->filho[i + 1] != NULL) {
      noh = pesquisa_noh(arvore->filho[i + 1], pag, t);
      return noh;
    }
    i++;
  }
  return arvore;
}

void desloca_valor(ArvB *arvore, int i) {
  int j;

  for (j = arvore->qntPag; j > i; j--) {
    printf("A: %d ", arvore->pag[j - 1]);
    arvore->pag[j] = arvore->pag[j - 1];
    printf("D: %d ", arvore->pag[j - 1]);
  }
}

int pesquisa_pos(ArvB *arvore, int pag) {
  int i, pos = 0;

  if (arvore->qntPag == 1) {
    if (arvore->pag[0] < pag) {
      return 1;
    } else {
      desloca_valor(arvore, 0);
      return 0;
    }
  }

  for (i = 0; i < arvore->qntPag; i++) {
    if (arvore->pag[i] <= pag && pag <= arvore->pag[i + 1]) {
      pos = i;
    }
  }
  if (pos == 0) {
    return arvore->qntPag;
  }
  desloca_valor(arvore, pos);
  return pos;
}

ArvB *insere_ArvB(ArvB *arvore, int pag, int t) {
  ArvB *novoNoh, *noh, *nohAux;
  int i, pos;

  noh = arvore;

  // if (noh->qntPag == 2 * t) {
  //   printf("B\n");
  //   divide_filhos(noh, t);
  //   noh->pag[0] = pag;
  // }

  if (arvore == NULL) {
    novoNoh = cria_noh(true, t);
    novoNoh->pag[0] = pag;
    novoNoh->qntPag = 1;
    arvore = novoNoh;
    printf("K\n");
  } else {
    nohAux = pesquisa_noh(noh, pag, t);
    printf("DPrimeiro\n\n");
    for (i = 0; i < 2 * t; i++) {
      printf("%d ", nohAux->pag[i]);
    }
    pos = pesquisa_pos(nohAux, pag);
    nohAux->pag[pos] = pag;
    for (i = 0; i < 2 * t; i++) {
      printf("%d ", arvore->pag[i]);
    }
    nohAux->qntPag++;
    printf("\n\nXUltimo\n");
  }

  return arvore;
}

ArvB *pesquisa_ArvB(ArvB *arvore, int pag) {
  int i = 0;
  while (i < arvore->qntPag && pag > arvore->pag[i]) {
    i++;
  }

  if (arvore->pag[i] == pag) {
    return arvore;
  }

  if (arvore->folha == true) {
    return NULL;
  }

  return pesquisa_ArvB(arvore->filho[i], pag);
}