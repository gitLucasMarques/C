#include <stdio.h>
#include <stdlib.h>

struct node {
  int chave;
  int cor;
  struct node *prox;
};

typedef struct node *Noh;

struct grafo {
  int vertices;
  int arestas;
  Noh *adj;
};

typedef struct grafo *Grafo;

typedef struct {
  int *vetor;
  int index;
} lista;

void inicia_Lista(lista *p, int n) {
  p->vetor = malloc(n * sizeof(int));
  p->index = 0;
}

Grafo inicia_Grafo(int vertices, int arestas) {
  Grafo novo_grafo = malloc(sizeof(struct grafo));
  novo_grafo->vertices = vertices;
  novo_grafo->arestas = arestas;
  novo_grafo->adj = malloc(vertices * sizeof(Noh));
  for (int i = 0; i < vertices; i++) {
    novo_grafo->adj[i] = malloc(sizeof(struct node));
    novo_grafo->adj[i]->chave = i;
    novo_grafo->adj[i]->prox = NULL;
  }

  return novo_grafo;
}

int remove_Inicio(lista *p) {
  int aux = p->vetor[0];

  for (int i = 0; i < p->index - 1; i++) {
    p->vetor[i] = p->vetor[i + 1];
  }

  p->index--;

  return aux;
}

void empilha(lista *p, int n) {
  p->vetor[p->index] = n;
  p->index++;
}

void insere_Aresta(Grafo G, int inicial, int final) {
  Noh novo_node = malloc(sizeof(struct node));
  novo_node->chave = final;

  Noh aux = G->adj[inicial];

  while (aux->prox != NULL && aux->prox->chave < novo_node->chave) {
    aux = aux->prox;
  }

  novo_node->prox = aux->prox;
  aux->prox = novo_node;
}

void apaga_Lista_Noh(Noh node) {
  Noh aux;

  while (node != NULL) {
    aux = node->prox;
    free(node);
    node = aux;
  }
}

void imprime_Lista_Noh(Noh node) {
  Noh aux = node;

  while (aux != NULL) {
    printf("%i ", aux->chave);
    aux = aux->prox;
  }
}

void imprime_Grafo(Grafo G) {
  for (int i = 0; i < G->vertices; i++) {
    imprime_Lista_Noh(G->adj[i]);
    printf("\n");
  }
}

void DFSVisit(Grafo G, Noh u, lista *p) {
  empilha(p, u->chave);
  u->cor = 1;

  Noh aux = u;
  int n;

  while (aux->prox != NULL) {
    aux = aux->prox;

    n = aux->chave;
    if (G->adj[n]->cor == 0) {
      DFSVisit(G, G->adj[n], p);
    }
  }

  u->cor = 2;
}

void DFS(Grafo G, int raiz_busca, lista *p) {
  for (int i = 0; i < G->vertices; i++) {
    G->adj[i]->cor = 0;
  }

  DFSVisit(G, G->adj[raiz_busca], p);

  for (int i = 0; i < G->vertices; i++) {
    if (G->adj[i]->cor == 0) {
      DFSVisit(G, G->adj[i], p);
    }
  }
}

void BFS(Grafo G, int raiz_busca, lista *p) {
  for (int i = 0; i < G->vertices; i++) {
    G->adj[i]->cor = 0;
  }

  Noh aux;
  int n;
  lista fila;
  inicia_Lista(&fila, G->arestas);

  empilha(p, raiz_busca);
  G->adj[raiz_busca]->cor = 1;

  empilha(&fila, raiz_busca);

  while (fila.index > 0) {
    n = remove_Inicio(&fila);
    aux = G->adj[n];

    while (aux->prox != NULL) {
      aux = aux->prox;

      if (G->adj[aux->chave]->cor == 0) {
        G->adj[aux->chave]->cor = 1;
        empilha(p, aux->chave);

        empilha(&fila, aux->chave);
      }
    }

    G->adj[n]->cor = 3;
  }
}

void deleta_Grafo(Grafo G) {
  for (int i = 0; i < G->vertices; i++) {
    apaga_Lista_Noh(G->adj[i]);
  }

  free(G);
}

void imprime_Lista(lista *lista) {
  for (int i = 0; i < lista->index; i++) {
    printf("%d ", lista->vetor[i]);
  }
}

int main() {
  int raiz, vertices, arestas, inicial, final;
  Grafo G;
  lista profundidade, largura;

  scanf("%d %d %d", &raiz, &vertices, &arestas);

  inicia_Lista(&largura, vertices);
  inicia_Lista(&profundidade, vertices);
  G = inicia_Grafo(vertices, arestas);

  for (int i = 0; i < arestas; i++) {
    scanf("%d %d", &inicial, &final);
    insere_Aresta(G, inicial, final);
  }

  BFS(G, raiz, &largura);
  imprime_Lista(&largura);
  printf("\n");

  DFS(G, raiz, &profundidade);
  imprime_Lista(&profundidade);

  deleta_Grafo(G);
  free(profundidade.vetor);
  free(largura.vetor);

  return 0;
}