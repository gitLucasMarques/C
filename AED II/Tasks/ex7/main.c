#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int chave;
} Item;

typedef struct SNo *ArvBin;

typedef struct SNo {
  Item item;
  ArvBin esq, dir;
  int alt;
} Noh;

ArvBin inicializaArvore(ArvBin);
ArvBin instanciaArvore(int);

ArvBin pesquisaArvore(ArvBin, int);
ArvBin pesquisaArvore_Ins_Rem(ArvBin, int);

int altura_arvore(ArvBin);
ArvBin insercao(ArvBin, int);
int max(int, int);
ArvBin balanceaArvore(ArvBin);
ArvBin rotacaoLL(ArvBin);
ArvBin rotacaoRR(ArvBin);
ArvBin rotacaoLR(ArvBin);
ArvBin rotacaoRL(ArvBin);

ArvBin remocao(ArvBin, int);
void destroiArvore(ArvBin);

int main() {
  int aux = 0, *vCh, i = 0, num, j;
  ArvBin arvore;

  arvore = inicializaArvore(arvore);

  scanf("%d", &aux);
  arvore = insercao(arvore, aux);
  while (aux >= 0) {
    arvore = insercao(arvore, aux);
    i++;
    scanf("%d", &aux);
  }

  vCh = malloc(i * sizeof(int));
  for (j = 0; j < i; j++) {
    vCh[j] = -1;
  }

  i = 0;
  scanf("%d", &vCh[i]);
  while (vCh[i] >= 0) {
    i++;
    scanf("%d", &vCh[i]);
  }

  scanf("%d", &num);

  printf("%d, %d, %d\n", altura_arvore(arvore), altura_arvore(arvore->esq) + 1,
         altura_arvore(arvore->dir) + 1);

  j = 0;
  while (vCh[j] >= 0) {
    arvore = pesquisaArvore_Ins_Rem(arvore, vCh[j]);
    j++;
  }

  arvore = pesquisaArvore(arvore, num);
  destroiArvore(arvore);

  return 0;
}

ArvBin inicializaArvore(ArvBin arvore) { return NULL; }

ArvBin instanciaArvore(int num) {
  Noh *novoNoh;
  novoNoh = malloc(sizeof(Noh));
  novoNoh->item.chave = num;
  novoNoh->esq = NULL;
  novoNoh->dir = NULL;
  novoNoh->alt = 1;
  return novoNoh;
}

ArvBin pesquisaArvore(ArvBin arvore, int num) {
  if (arvore != NULL) {
    if (arvore->item.chave == num) {
      printf("%d, %d, %d\n", altura_arvore(arvore), altura_arvore(arvore->esq),
             altura_arvore(arvore->dir));
      return arvore;
    } else {
      if (num < arvore->item.chave) {
        return pesquisaArvore(arvore->esq, num);
      } else {
        pesquisaArvore(arvore->dir, num);
      }
    }
  } else {
    printf("Valor nao encontrado\n");
  }
  return NULL;
}

ArvBin pesquisaArvore_Ins_Rem(ArvBin arvore, int num) {
  if (arvore != NULL) {
    if (arvore->item.chave == num) {
      return remocao(arvore, num);
    } else {
      if (num < arvore->item.chave) {
        arvore->esq = pesquisaArvore_Ins_Rem(arvore->esq, num);
      } else {
        arvore->dir = pesquisaArvore_Ins_Rem(arvore->dir, num);
      }
    }
  } else {
    arvore = insercao(arvore, num);
    return arvore;
  }
  return arvore;
}

int altura_arvore(ArvBin arvore) {
  int altura_esq, altura_dir, altura_atual;

  if (arvore == NULL) {
    return -1;
  } else {
    altura_esq = altura_arvore(arvore->esq);
    altura_dir = altura_arvore(arvore->dir);

    if (altura_esq > altura_dir) {
      altura_atual = altura_esq;
    } else {
      altura_atual = altura_dir;
    }

    return altura_atual + 1;
  }
}

int max(int alt1, int alt2) {
  if (alt1 > alt2) {
    return alt1;
  } else {
    return alt2;
  }
}

ArvBin insercao(ArvBin arvore, int num) {
  int fb;

  if (arvore == NULL) {
    arvore = instanciaArvore(num);
    return arvore;
  }

  if (num < arvore->item.chave) {
    arvore->esq = insercao(arvore->esq, num);
  } else if (num > arvore->item.chave) {
    arvore->dir = insercao(arvore->dir, num);
  }

  arvore->alt = max(altura_arvore(arvore->esq), altura_arvore(arvore->dir));
  fb = altura_arvore(arvore->esq) - altura_arvore(arvore->dir);
  if (fb < -1 || fb > 1) {
    arvore = balanceaArvore(arvore);
  }
  return arvore;
}

ArvBin balanceaArvore(ArvBin arvore) {
  int fb;

  fb = altura_arvore(arvore->esq) - altura_arvore(arvore->dir);
  if (fb > 1) {
    if (altura_arvore(arvore->esq->esq) >= altura_arvore(arvore->esq->dir)) {
      arvore = rotacaoLL(arvore);
    } else {
      arvore = rotacaoLR(arvore);
    }
  } else if (fb < -1) {
    if (altura_arvore(arvore->dir->dir) >= altura_arvore(arvore->dir->esq)) {
      arvore = rotacaoRR(arvore);
    } else {
      arvore = rotacaoRL(arvore);
    }
  }

  return arvore;
}

ArvBin remocao(ArvBin arvore, int num) {
  ArvBin arvAux, pai, filho;

  if (arvore == NULL) {
    return NULL;
  } else if (num < arvore->item.chave) {
    arvore->esq = remocao(arvore->esq, num);
  } else if (arvore->item.chave < num) {
    arvore->dir = remocao(arvore->dir, num);
  } else {
    if (arvore->esq == NULL && arvore->dir == NULL) {
      free(arvore);
      return NULL;
    } else if (arvore->esq == NULL) {
      arvAux = arvore;
      arvore = arvore->dir;
      free(arvAux);
    } else if (arvore->dir == NULL) {
      arvAux = arvore;
      arvore = arvore->esq;
      free(arvAux);
    } else {
      pai = arvore;
      filho = arvore->esq;
      while (filho->dir != NULL) {
        pai = filho;
        filho = filho->dir;
      }
      arvore->item.chave = filho->item.chave;
      arvore->esq = remocao(arvore->esq, filho->item.chave);
    }
  }

  if (arvore != NULL) {
    arvore->alt =
       max(altura_arvore(arvore->esq), altura_arvore(arvore->dir));
    int fb = altura_arvore(arvore->esq) - altura_arvore(arvore->dir);
    if (fb < -1 || fb > 1) {
      arvore = balanceaArvore(arvore);
    }
  }
  return arvore;
}

ArvBin rotacaoLL(ArvBin arvore) {
  Noh *pA, *pB;

  pA = arvore;
  pB = pA->esq;
  pA->esq = pB->dir;
  pB->dir = pA;
  pA = pB;

  return pA;
}

ArvBin rotacaoRR(ArvBin arvore) {
  Noh *pA, *pB;

  pA = arvore;
  pB = pA->dir;
  pA->dir = pB->esq;
  pB->esq = pA;
  pA = pB;

  return pA;
}

ArvBin rotacaoLR(ArvBin arvore) {
  Noh *pA, *pB, *pC;

  pA = arvore;

  pB = pA->esq;
  pC = pB->dir;
  pB->dir = pC->esq;
  pC->esq = pB;
  pA->esq = pC->dir;
  pC->dir = pA;
  pA = pC;

  return pA;
}

ArvBin rotacaoRL(ArvBin arvore) {
  Noh *pA, *pB, *pC;

  pA = arvore;

  pB = pA->dir;
  pC = pB->esq;
  pB->esq = pC->dir;
  pC->dir = pB;
  pA->dir = pC->esq;
  pC->esq = pA;
  pA = pC;

  return pA;
}

void destroiArvore(ArvBin arvore) {
  while (arvore != NULL) {
    destroiArvore(arvore->esq);
    destroiArvore(arvore->dir);
    free(arvore);
  }
}