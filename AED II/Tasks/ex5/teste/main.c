#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

struct noh {
  int num;
  int imp;
  struct noh *prox;
  struct noh *pred;
};

typedef struct noh *Noh;

struct grafo {
  int vertices;
  int arestas;
  Noh *adj;
};

typedef struct grafo *Grafo;

Grafo inicializa_Grafo(int, int);
void inicializa_Raiz(Grafo, int);
void insere_Aresta(Grafo, int, int, int);
void relax(Noh, Noh, int, int);
void Bellmond_Ford(Grafo, int, int);
void imprime_IMP(Grafo);
void imprime_lista_Noh(Noh);
void imprime_Grafo(Grafo);
void retira_Lista_Noh(Noh);
void retira_Grafo(Grafo);

Grafo inicializa_Grafo(int vertices, int arestas) {
  int k = 0, i;
  Grafo grafo = malloc(sizeof(struct grafo));
  grafo->vertices = vertices;
  grafo->arestas = arestas;
  grafo->adj = malloc(vertices * sizeof(Noh));
  k++;
  for (i = 0; i < vertices; i++) {
    grafo->adj[i] = malloc(sizeof(struct noh));
    grafo->adj[i]->num = i;
    grafo->adj[i]->imp = 0;
    grafo->adj[i]->prox = NULL;
  }
  return grafo;
}

void inicializa_Raiz(Grafo grafo, int raiz) {
  int k = 0, i;
  for (i = 0; i < grafo->vertices; i++) {
    grafo->adj[i]->imp = MAX;
    grafo->adj[i]->pred = grafo->adj[raiz];
    k++;
  }
  grafo->adj[raiz]->imp = 0;
  grafo->adj[raiz]->pred = NULL;
  k++;
}

void insere_Aresta(Grafo grafo, int inicial, int final, int imp) {
  Noh novoNoh = malloc(sizeof(struct noh));
  novoNoh->num = final;
  novoNoh->imp = imp;
  Noh nohAux = grafo->adj[inicial];

  while (nohAux->prox != NULL && nohAux->prox->num < novoNoh->num) {
    nohAux = nohAux->prox;
  }
  novoNoh->prox = nohAux->prox;
  nohAux->prox = novoNoh;
}

void relax(Noh noh1, Noh noh2, int imp_aresta, int ques) {
  if (noh1->imp + imp_aresta < noh2->imp && noh2->pred != NULL &&
      imp_aresta <= ques) {
    noh2->pred = noh1;
    noh2->imp = noh1->imp + imp_aresta;
  }
}

void Bellmond_Ford(Grafo grafo, int raiz, int ques) {
  int i, j;
  inicializa_Raiz(grafo, raiz);
  Noh nohAux;
  for (i = 0; i < grafo->vertices - 2; i++) {
    for (j = 0; j < grafo->vertices; j++) {
      nohAux = grafo->adj[j];
      while (nohAux->prox != NULL) {
        nohAux = nohAux->prox;
        relax(grafo->adj[j], grafo->adj[nohAux->num], nohAux->imp, ques);
      }
    }
  }
}

void imprime_IMP(Grafo grafo) {
  int i;
  for (i = 0; i < grafo->vertices; i++) {
    printf("%d ", grafo->adj[i]->imp);
  }
}

void imprime_lista_Noh(Noh noh) {
  Noh nohAux = noh;
  while (nohAux != NULL) {
    printf("%d ", nohAux->imp);
    nohAux = nohAux->prox;
  }
}

void imprime_Grafo(Grafo grafo) {
  int i;
  for (i = 0; i < grafo->vertices; i++) {
    imprime_lista_Noh(grafo->adj[i]);
    printf("\n");
  }
}

void retira_Lista_Noh(Noh noh) {
  Noh nohAux;
  while (noh != NULL) {
    nohAux = noh->prox;
    free(noh);
    noh = nohAux;
  }
}

void retira_Grafo(Grafo grafo) {
  int i;
  for (i = 0; i < grafo->vertices; i++) {
    retira_Lista_Noh(grafo->adj[i]);
  }
  free(grafo);
}

int main() {
  int raiz, vertices, arestas, inicial, final, imp_aresta, ques;
  int j;
  Grafo grafo;

  scanf("%d %d %d %d", &raiz, &ques, &vertices, &arestas);

  grafo = inicializa_Grafo(vertices, arestas);

  for (j = 0; j < arestas; j++) {
    scanf("%d %d %d", &inicial, &final, &imp_aresta);
    insere_Aresta(grafo, inicial, final, imp_aresta);
  }

  Bellmond_Ford(grafo, raiz, ques);
  imprime_IMP(grafo);
  retira_Grafo(grafo);

  return 0;
}