#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int chave;
  int cor;
  struct node *pai;
  struct node *dir;
  struct node *esq;
} AVP;

AVP *arv = NULL;

// AVP *inicializa_Arvore(AVP *);
// AVP *instancia_Arvore(int);

// AVP *insercao_AVP(AVP *, AVP *);
// void rotacaoDir_AVP(AVP *);
// void rotacaoEsq_AVP(AVP *);
// void verifica_erros(AVP *, AVP *);

// int altura_max_AVP(AVP *);
// int altura_AVP(AVP *);

// void destroi_AVP(AVP *);

AVP *inicializa_Arvore(AVP *temp) { return NULL; }

AVP *instancia_Arvore(int aux) {
  AVP *temp;

  temp = malloc(sizeof(AVP));
  temp->dir = NULL;
  temp->esq = NULL;
  temp->pai = NULL;
  temp->cor = 1;
  temp->chave = aux;

  return temp;
}

AVP *insercao_AVP(AVP *arv, AVP *temp) {

  if (arv == NULL)
    return temp;

  if (temp->chave < arv->chave) {
    arv->esq = insercao_AVP(arv->esq, temp);
    arv->esq->pai = arv;
  } else if (temp->chave > arv->chave) {
    arv->dir = insercao_AVP(arv->dir, temp);
    arv->dir->pai = arv;
  }

  return arv;
}

void rotacaoDir_AVP(AVP *temp) {
  AVP *esquerda = temp->esq;
  temp->esq = esquerda->dir;
  if (temp->esq)
    temp->esq->pai = temp;
  esquerda->pai = temp->pai;
  if (!temp->pai)
    arv = esquerda;
  else if (temp == temp->pai->esq)
    temp->pai->esq = esquerda;
  else
    temp->pai->dir = esquerda;
  esquerda->dir = temp;
  temp->pai = esquerda;
}

void rotacaoEsq_AVP(AVP *temp) {
  AVP *direita = temp->dir;
  temp->dir = direita->esq;
  if (temp->dir)
    temp->dir->pai = temp;
  direita->pai = temp->pai;
  if (!temp->pai)
    arv = direita;
  else if (temp == temp->pai->esq)
    temp->pai->esq = direita;
  else
    temp->pai->dir = direita;
  direita->esq = temp;
  temp->pai = direita;
}

void verifica_erros(AVP *arvore, AVP *pt) {
  if (arvore == NULL || pt == NULL || pt->pai == NULL)
    return;

  AVP *pai_pt = NULL;
  AVP *vo_pt = NULL;
  AVP *tio_pt = NULL;

  while ((pt != arvore) && (pt->cor != 0) && (pt->pai->cor == 1)) {
    pai_pt = pt->pai;
    vo_pt = pt->pai->pai;

    if (vo_pt == NULL)
      return;

    if (pai_pt == vo_pt->esq) {
      tio_pt = vo_pt->dir;

      if (tio_pt != NULL && tio_pt->cor == 1) {
        vo_pt->cor = 1;
        pai_pt->cor = 0;
        tio_pt->cor = 0;
        pt = vo_pt;
      } else {
        if (pt == pai_pt->dir) {
          rotacaoEsq_AVP(pai_pt);
          pt = pai_pt;
          pai_pt = pt->pai;
          if (pt == arvore)
            arvore = pai_pt;
        }

        if (pai_pt == NULL || vo_pt == NULL)
          return;

        rotacaoDir_AVP(vo_pt);
        int t = pai_pt->cor;
        pai_pt->cor = vo_pt->cor;
        vo_pt->cor = t;
        pt = pai_pt;
      }
    } else {
      tio_pt = vo_pt->esq;

      if (tio_pt != NULL && tio_pt->cor == 1) {
        vo_pt->cor = 1;
        pai_pt->cor = 0;
        tio_pt->cor = 0;
        pt = vo_pt;
      } else {
        if (pt == pai_pt->esq) {
          rotacaoDir_AVP(pai_pt);
          pt = pai_pt;
          pai_pt = pt->pai;
          if (pt == arvore)
            arvore = pai_pt;
        }

        if (pai_pt == NULL || vo_pt == NULL)
          return;

        rotacaoEsq_AVP(vo_pt);
        int t = pai_pt->cor;
        pai_pt->cor = vo_pt->cor;
        vo_pt->cor = t;
        pt = pai_pt;
      }
    }
  }
}

int altura_max_AVP(AVP *temp) {
  if (temp == NULL) {
    return 0;
  } else {
    int altura_esquerda = altura_max_AVP(temp->esq);
    int altura_direita = altura_max_AVP(temp->dir);

    return 1 + (altura_esquerda > altura_direita ? altura_esquerda
                                                 : altura_direita);
  }
}

int altura_AVP(AVP *temp) {
  if (temp == NULL) {
    return 0;
  } else {
    int altura_esquerda = altura_AVP(temp->esq);
    int altura_direita = altura_AVP(temp->dir);

    int maior_altura_filho =
        (altura_esquerda > altura_direita) ? altura_esquerda : altura_direita;
    if (temp->cor == 0) {
      return 1 + maior_altura_filho;
    } else {
      return maior_altura_filho;
    }
  }
}

void destroi_AVP(AVP *arvore) {
  while (arvore != NULL) {
    destroi_AVP(arvore->esq);
    destroi_AVP(arvore->dir);
    free(arvore);
  }
}

int main() {
  int aux = 0, num;
  AVP *temp;

  arv = inicializa_Arvore(arv);
  temp = inicializa_Arvore(temp);

  scanf("%d", &aux);
  temp = instancia_Arvore(aux);
  arv = insercao_AVP(arv, temp);

  while (aux >= 0) {
    scanf("%d", &aux);
    if (aux >= 0) {
      temp = instancia_Arvore(aux);
      arv = insercao_AVP(arv, temp);
      verifica_erros(arv, temp);
      arv->cor = 0;
    } else {
      break;
    }
  }

  printf("%d, %d, %d\n", altura_max_AVP(arv) - 1, altura_max_AVP(arv->esq),
         altura_max_AVP(arv->dir));

  printf("%d\n", altura_AVP(arv));
  free(temp);

  return 0;
}