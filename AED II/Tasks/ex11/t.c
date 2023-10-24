#include <stdio.h>
#include <stdlib.h>

// 0 -> BRANCO
// 1 -> CINZA
// 2 -> PRETO

typedef struct Noh {
  int valor;
  int cor;
  int pre;
  struct Noh *pred;
  struct Noh *prox;
} TipoNoh;

typedef struct {
  TipoNoh *inicio;
  TipoNoh *fim;
  int ult;
} Lista;

void trocarNohs(TipoNoh *a, TipoNoh *b) {
  int temp = a->valor;
  a->valor = b->valor;
  b->valor = temp;
}

void ordenarLista(Lista *lista) {
  int trocado;
  TipoNoh *atual;
  TipoNoh *ultimo = NULL;

  if (lista->inicio == NULL || lista->inicio->prox == NULL) {
    return;
  }

  do {
    trocado = 0;
    atual = lista->inicio;

    while (atual->prox != ultimo) {
      if (atual->valor > atual->prox->valor) {
        trocarNohs(atual, atual->prox);
        trocado = 1;
      }
      atual = atual->prox;
    }
    ultimo = atual;
  } while (trocado);
}

void inserirNoh(Lista *lista, int novoValor) {
  TipoNoh *novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  novoNoh->valor = novoValor;
  novoNoh->cor = 0;
  novoNoh->pre = 0;
  novoNoh->pred = NULL;
  novoNoh->prox = NULL;

  if (lista->inicio == NULL) {
    lista->inicio = novoNoh;
    lista->fim = novoNoh;
  } else {
    novoNoh->prox = lista->inicio;
    lista->inicio->pred = novoNoh;
    lista->inicio = novoNoh;
  }

  lista->ult++;
}

void dfsUtil(TipoNoh *noh) {
  noh->cor = 1;
  printf("%d ", noh->valor);

  TipoNoh *adjacente = noh->prox;
  while (adjacente != NULL) {
    if (adjacente->cor == 0) {
      adjacente->pred = noh;
      dfsUtil(adjacente);
    }
    adjacente = adjacente->prox;
  }
}

void dfs(Lista *lista, int valorInicial) {
  TipoNoh *nohInicial = lista->inicio;

  while (nohInicial != NULL) {
    if (nohInicial->valor == valorInicial) {
      break;
    }
    nohInicial = nohInicial->prox;
  }

  dfsUtil(nohInicial);
  printf("\n");
}

void bfs(Lista *lista, int valorInicial) {
  TipoNoh *fila = NULL;
  TipoNoh *nohInicial = lista->inicio;

  while (nohInicial != NULL) {
    if (nohInicial->valor == valorInicial) {
      break;
    }
    nohInicial = nohInicial->prox;
  }

  nohInicial->cor = 1;
  fila = nohInicial;

  while (fila != NULL) {
    TipoNoh *adjacente = fila->prox;
    printf("%d ", fila->valor);

    while (adjacente != NULL) {
      if (adjacente->cor == 0) {
        adjacente->cor = 1;
        printf("%d ", adjacente->valor);
        inserirNoh(lista, adjacente->valor);
      }
      adjacente = adjacente->prox;
    }

    fila->cor = 2;
    fila = fila->prox;
  }
  printf("\n");
}

void imprimirLista(Lista *lista) {
  TipoNoh *atual = lista->inicio;
  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->prox;
  }
  printf("\n");
}

int main() {
  Lista *vetorG;
  int inicio, nos, arestas;
  int noh, valor;
  int i;

  scanf("%d", &inicio);
  scanf("%d %d", &nos, &arestas);

  vetorG = malloc(nos * sizeof(Lista));

  for (i = 0; i < nos; i++) {
    vetorG[i].inicio = NULL;
    vetorG[i].fim = NULL;
    vetorG[i].ult = 0;
  }

  for (i = 0; i < nos; i++) {
    scanf("%d %d", &noh, &valor);
    inserirNoh(&vetorG[noh], valor);
  }

  dfs(&vetorG[inicio], inicio);
  printf("\n");
  bfs(&vetorG[inicio], inicio);

  return 0;
}
