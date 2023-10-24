#include <math.h>
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
void divide_filhos(ArvB *, int, ArvB *, int);
void insere_ArvB(ArvB **, int, int);
void insere_ArvB_espaco(ArvB *, int, int);
ArvB *pesquisa_ArvB(ArvB *, int);

ArvB *inicia_arvB(ArvB *arvore) { return NULL; }

ArvB *cria_noh(bool folha, int t) {
  ArvB *novoNoh = malloc(sizeof(ArvB));
  novoNoh->pag = malloc(((2 * t) - 1) * sizeof(int));
  novoNoh->filho = (ArvB **)malloc(2 * t * sizeof(ArvB *));
  novoNoh->folha = folha;
  novoNoh->qntPag = 0;

  return novoNoh;
}

void insere_ArvB(ArvB **arvore, int pag, int t) {
  ArvB *noh = *arvore;

  if (noh == NULL) {
    ArvB *novoNoh = cria_noh(true, t);
    novoNoh->pag[0] = pag;
    novoNoh->qntPag = 1;
    *arvore = novoNoh;
    return;
  }

  if (noh->qntPag == ((2 * t) - 1)) {
    ArvB *novoNoh = cria_noh(false, t);
    novoNoh->filho[0] = noh;
    *arvore = novoNoh;
    divide_filhos(novoNoh, 0, noh, t);
    insere_ArvB_espaco(novoNoh, pag, t);
  } else {
    insere_ArvB_espaco(noh, pag, t);
  }
}

void insere_ArvB_espaco(ArvB *noh, int pag, int t) {
  int i = noh->qntPag - 1;

  if (noh->folha) {
    while (i >= 0 && pag < noh->pag[i]) {
      noh->pag[i + 1] = noh->pag[i];
      i--;
    }

    noh->pag[i + 1] = pag;
    noh->qntPag++;
  } else {
    while (i >= 0 && pag < noh->pag[i]) {
      i--;
    }

    i++;

    if (noh->filho[i]->qntPag == ((2 * t) - 1)) {
      divide_filhos(noh, i, noh->filho[i], t);

      if (pag > noh->pag[i]) {
        i++;
      }
    }

    insere_ArvB_espaco(noh->filho[i], pag, t);
  }
}

void divide_filhos(ArvB *NohPai, int ind, ArvB *NohFilho, int t) {
  ArvB *novoNoh = cria_noh(NohFilho->folha, t);
  novoNoh->qntPag = t - 1;

  for (int i = 0; i < t - 1; i++) {
    novoNoh->pag[i] = NohFilho->pag[i + t];
  }

  if (!NohFilho->folha) {
    for (int i = 0; i < t; i++) {
      novoNoh->filho[i] = NohFilho->filho[i + t];
    }
  }

  NohFilho->qntPag = t - 1;

  for (int i = NohPai->qntPag; i > ind; i--) {
    NohPai->filho[i + 1] = NohPai->filho[i];
  }

  NohPai->filho[ind + 1] = novoNoh;

  for (int i = NohPai->qntPag - 1; i >= ind; i--) {
    NohPai->pag[i + 1] = NohPai->pag[i];
  }

  NohPai->pag[ind] = NohFilho->pag[t - 1];
  NohPai->qntPag++;
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

int main() {
  ArvB *arvore, *resultado;
  int m, num, pesq, i;

  arvore = inicia_arvB(arvore);
  scanf("%d", &m);

  scanf("%d", &num);
  while (num >= 0) {
    insere_ArvB(&arvore, num, m);
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
