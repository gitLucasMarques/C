#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int chave;
} itemChave;

struct noh {
  itemChave chave;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct {
  TipoNoh *inicio;
  TipoNoh *fim;
  int ultimo;
} Chaves;

void iniciaLista(Chaves *);
int listaVazia(Chaves *);
int add_inicio(Chaves *, itemChave *);
int add_final(Chaves *, itemChave *);
void imprimeLista(Chaves *);
void destroi_lista(Chaves *);

void merge(Chaves *, int, int, int);
int merge_sort(Chaves *, int, int, int);

int main() {
  int nCh, i, cont = 0;
  itemChave chave;
  Chaves ch;

  scanf("%d", &nCh);
  iniciaLista(&ch);

  for (i = 0; i < nCh; i++) {
    scanf("%d", &chave.chave);
    add_final(&ch, &chave);
  }

  cont = merge_sort(&ch, 1, nCh, cont);
  imprimeLista(&ch);

  printf("\ncont = %d\n\n", cont);
  destroi_lista(&ch);

  return 0;
}

void iniciaLista(Chaves *lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->ultimo = 0;
}

int listaVazia(Chaves *lista) { return lista->ultimo == 0; }

int add_inicio(Chaves *lista, itemChave *chave) {
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  if (novoNoh != NULL) {
    novoNoh->chave = *chave;
    novoNoh->prox = lista->inicio;
    lista->inicio = novoNoh;
    lista->ultimo++;
    return 1;
  } else {
    return 0;
  }
}

int add_final(Chaves *lista, itemChave *chave) {
  TipoNoh *novoNoh, *ptrAuXIL;
  novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  if (novoNoh != NULL) {
    ptrAuXIL = lista->inicio;
    if (listaVazia(lista)) {
      lista->inicio = novoNoh;
    } else {
      while (ptrAuXIL->prox != NULL) {
        ptrAuXIL = ptrAuXIL->prox;
      }
      ptrAuXIL->prox = novoNoh;
    }
    novoNoh->chave = *chave;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  } else {
    return 0;
  }
}

TipoNoh *buscaNaPosicao(Chaves *lista, int posicao) {
  int i, valor;
  TipoNoh *ptrAux;

  if (posicao == 1)
    ptrAux = lista->inicio;
  else if (posicao == lista->ultimo)
    ptrAux = lista->fim;

  else {
    ptrAux = lista->inicio;
    for (i = 1; i < posicao; i++)
      ptrAux = ptrAux->prox;
  }
  return ptrAux;
}

void destroi_lista(Chaves *lista) {
  TipoNoh *ptrAux1, *ptrAux2;
  if (!listaVazia(lista)) {
    ptrAux1 = lista->inicio;
    ptrAux2 = ptrAux1->prox;
    while (ptrAux1->prox != NULL) {
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->ultimo = 0;
}

void merge(Chaves *lista, int p, int q, int r) {
  int nL, nR;
  int i, k, j;
  itemChave chAux;
  TipoNoh *novoNohL, *novoNohR, *ptrAux;
  Chaves L, R;

  iniciaLista(&L);
  iniciaLista(&R);

  if (r % 2 == 0) {
    nL = q - p;
  } else {
    nL = q - p + 1;
  }
  nR = r - q;

  novoNohL = lista->inicio;
  for (i = 1; i <= nL; i++) {
    chAux = novoNohL->chave;
    add_final(&L, &chAux);
    novoNohL = novoNohL->prox;
  }
  imprimeLista(&L);

  for (j = 0; j <= nR; j++) {
    chAux = novoNohL->chave;
    add_final(&R, &chAux);
    if (novoNohL->prox == NULL) {
      break;
    }
    novoNohL = novoNohL->prox;
  }
  imprimeLista(&R);
  

  chAux.chave = INFINITY;
  add_final(&L, &chAux);
  add_final(&R, &chAux);

  novoNohL = L.inicio;
  novoNohR = R.inicio;

  /*printf("\nL: ");
  imprimeLista(&L);
  printf("\nR: ");
  imprimeLista(&R);

  for (k = p; k < r; k++) {
    if (novoNohL->chave.chave <= novoNohR->chave.chave) {
      chAux = novoNohL->chave;
      add_final(lista, &chAux);
      novoNohL = novoNohL->prox;
    } else {
      chAux = novoNohR->chave;
      add_final(lista, &chAux);
      novoNohR = novoNohR->prox;
    }
  }*/

  i = 1;
  j = 1;

  ptrAux = buscaNaPosicao(lista, p);
  novoNohL = buscaNaPosicao(&L, i);
  novoNohR = buscaNaPosicao(&R, j);

  for (k = p; k <= r; k++) {
    if (novoNohL->chave.chave <= novoNohR->chave.chave) {
      ptrAux->chave = novoNohL->chave;
      novoNohL = novoNohL->prox;
      i++;
    } else {
      ptrAux->chave = novoNohR->chave;
      novoNohR = novoNohR->prox;
      j++;
    }
    ptrAux = ptrAux->prox;
  }

  destroi_lista(&L);
  destroi_lista(&R);
}

/*void merge(Chaves *lista, int p, int q, int r) {
  int nL, nR;
  int i = 1, k, j = 1;
  TipoNoh *novoNohL, *novoNohR, *chAux;
  Chaves L, R;

  iniciaLista(&L);
  iniciaLista(&R);

  nL = q - p + 1;
  nR = r - q;

  novoNohL = buscaNaPosicao(lista, p + i - 1);
  printf("A\n\n");
  for (i = 1; i <= nL; i++) {
    add_final(&L, &novoNohL->chave);
    novoNohL = novoNohL->prox;
  }

  imprimeLista(&L);
  imprimeLista(&R);

  novoNohR = buscaNaPosicao(lista, q + j);
  printf("B\n\n");
  for (j = 1; j <= nR; j++) {
    add_final(&R, &novoNohR->chave);
    novoNohR = novoNohR->prox;
    // printf("D\n\n");
  }

  chAux->chave.chave = INFINITY;
  add_final(&L, &chAux->chave);
  add_final(&R, &chAux->chave);
  printf("D\n\n");

  i = 1;
  j = 1;

  chAux = buscaNaPosicao(lista, p);
  novoNohL = buscaNaPosicao(&L, i);
  novoNohR = buscaNaPosicao(&R, j);

  for (k = p; k <= r; k++) {
    if (novoNohL->chave.chave <= novoNohR->chave.chave) {
      chAux->chave = novoNohL->chave;
      novoNohL = novoNohL->prox;
      i++;
    } else {
      chAux->chave = novoNohR->chave;
      novoNohR = novoNohR->prox;
      j++;
    }
    chAux = chAux->prox;
  }

  destroi_lista(&L);
  destroi_lista(&R);
}*/

int merge_sort(Chaves *lista, int p, int r, int cont) {
  int q;
  if (p < r) {
    q = (p + r) / 2;
    merge_sort(lista, p, q, cont);
    cont = merge_sort(lista, q + 1, r, cont);
    merge(lista, p, q, r);
  }
  return cont + 1;
}

void imprimeLista(Chaves *lista) {
  TipoNoh *ptrImprime;

  ptrImprime = lista->inicio;
  while (ptrImprime != NULL) {
    printf("%d ", ptrImprime->chave.chave);
    ptrImprime = ptrImprime->prox;
  }
  printf("\n\n\n");
  return;
}
