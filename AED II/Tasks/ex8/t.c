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

typedef struct node {
  int chave;
  int cor;
  struct node *pai;
  struct node *dir;
  struct node *esq;
} AVP;

AVP *arv = NULL;

ArvBin inicializaArvore(ArvBin);
ArvBin instanciaArvore(int);

int max(int, int);
int altura(ArvBin);
int balanceaArvore(ArvBin);
ArvBin rotacaoDir(ArvBin);
ArvBin rotacaoEsq(ArvBin);
ArvBin insercao(ArvBin, int, int *, int *);

ArvBin minVal(ArvBin);
ArvBin remocao(ArvBin, int, int *, int *);
void destroiArvore(ArvBin);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AVP *inicializa_Arvore(AVP *);
AVP *instancia_Arvore(int);

AVP *insercao_AVP(AVP *, AVP *);
void rotacaoDir_AVP(AVP *);
void rotacaoEsq_AVP(AVP *);
void verifica_erros(AVP *, AVP *, int *, int *, int *);

int altura_max_AVP(AVP *);
int altura_AVP(AVP *);

void destroi_AVP(AVP *);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  int aux = 0, num;
  int mCorAVP = 0, rDirAVP = 0, rEsqAVP = 0, rDirAVL = 0, rEsqAVL = 0;
  ArvBin arvore;
  AVP *temp;

  arvore = inicializaArvore(arvore);

  arv = inicializa_Arvore(arv);
  temp = inicializa_Arvore(temp);

  scanf("%d", &aux);
  arvore = insercao(arvore, aux, &rDirAVL, &rEsqAVL);

  temp = instancia_Arvore(aux);
  arv = insercao_AVP(arv, temp);

  while (aux >= 0) {
    scanf("%d", &aux);
    if (aux >= 0) {
      arvore = insercao(arvore, aux, &rDirAVL, &rEsqAVL);

      temp = instancia_Arvore(aux);
      arv = insercao_AVP(arv, temp);
      verifica_erros(arv, temp, &rDirAVP, &rEsqAVP, &mCorAVP);
      arv->cor = 0;
    } else {
      break;
    }
  }

  printf("%d, %d, %d\n", altura(arvore) - 1, altura(arvore->esq),
         altura(arvore->dir));

  printf("%d, %d, %d\n", altura_max_AVP(arv) - 1, altura_max_AVP(arv->esq),
         altura_max_AVP(arv->dir));

  printf("%d\n", altura_AVP(arv));

  printf("%d, %d, %d\n", mCorAVP, rDirAVP + rEsqAVP, rDirAVL + rEsqAVL);

  //destroiArvore(arvore);
  free(temp);

  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int altura(ArvBin arvore) {
  if (arvore == NULL)
    return 0;
  return arvore->alt;
}

int balanceaArvore(ArvBin arvore) {
  if (arvore == NULL)
    return 0;
  return altura(arvore->esq) - altura(arvore->dir);
}

ArvBin rotacaoDir(ArvBin arvore) {
  ArvBin temp = arvore->esq;
  ArvBin arv = temp->dir;

  temp->dir = arvore;
  arvore->esq = arv;

  arvore->alt = max(altura(arvore->esq), altura(arvore->dir)) + 1;
  temp->alt = max(altura(temp->esq), altura(temp->dir)) + 1;

  return temp;
}

ArvBin rotacaoEsq(ArvBin arvore) {
  ArvBin temp = arvore->dir;
  ArvBin arv = temp->esq;

  temp->esq = arvore;
  arvore->dir = arv;

  arvore->alt = max(altura(arvore->esq), altura(arvore->dir)) + 1;
  temp->alt = max(altura(temp->esq), altura(temp->dir)) + 1;

  return temp;
}

ArvBin insercao(ArvBin arvore, int num, int *dir, int *esq) {
  if (arvore == NULL) {
    return instanciaArvore(num);
  }

  if (num < arvore->item.chave) {
    arvore->esq = insercao(arvore->esq, num, dir, esq);
  } else if (num > arvore->item.chave) {
    arvore->dir = insercao(arvore->dir, num, dir, esq);
  } else {
    return arvore;
  }

  arvore->alt = 1 + max(altura(arvore->esq), altura(arvore->dir));

  int balanco = balanceaArvore(arvore);

  if (balanco > 1 && num < arvore->esq->item.chave) {
    (*dir)++;
    return rotacaoDir(arvore);
  }

  if (balanco < -1 && num > arvore->dir->item.chave) {
    (*esq)++;
    return rotacaoEsq(arvore);
  }

  if (balanco > 1 && num > arvore->esq->item.chave) {
    (*esq)++;
    arvore->esq = rotacaoEsq(arvore->esq);
    (*dir)++;
    return rotacaoDir(arvore);
  }

  if (balanco < -1 && num < arvore->dir->item.chave) {
    (*dir)++;
    arvore->dir = rotacaoDir(arvore->dir);
    (*esq)++;
    return rotacaoEsq(arvore);
  }

  return arvore;
}

ArvBin minVal(ArvBin arvore) {
  ArvBin atual = arvore;

  while (atual->esq != NULL)
    atual = atual->esq;

  return atual;
}

ArvBin remocao(ArvBin arvore, int num, int *dir, int *esq) {
  ArvBin temp;
  if (arvore == NULL) {
    return arvore;
  }

  if (num < arvore->item.chave) {
    arvore->esq = remocao(arvore->esq, num, dir, esq);
  }

  else if (num > arvore->item.chave) {
    arvore->dir = remocao(arvore->dir, num, dir, esq);
  } else {
    if ((arvore->esq == NULL) || (arvore->dir == NULL)) {
      temp = arvore->esq ? arvore->esq : arvore->dir;

      if (temp == NULL) {
        temp = arvore;
        arvore = NULL;
      } else {
        arvore = temp;
      }
      free(temp);
    } else {
      temp = minVal(arvore->dir);

      arvore->item.chave = temp->item.chave;

      arvore->dir = remocao(arvore->dir, temp->item.chave, dir, esq);
    }
  }

  if (arvore == NULL) {
    return arvore;
  }

  arvore->alt = 1 + max(altura(arvore->esq), altura(arvore->dir));

  int balanco = balanceaArvore(arvore);

  if (balanco > 1 && balanceaArvore(arvore->esq) >= 0) {
    (*dir)++;
    return rotacaoDir(arvore);
  }

  if (balanco > 1 && balanceaArvore(arvore->esq) < 0) {
    (*esq)++;
    arvore->esq = rotacaoEsq(arvore->esq);
    (*dir)++;
    return rotacaoDir(arvore);
  }

  if (balanco < -1 && balanceaArvore(arvore->dir) <= 0) {
    (*esq)++;
    return rotacaoEsq(arvore);
  }

  if (balanco < -1 && balanceaArvore(arvore->dir) > 0) {
    (*dir)++;
    arvore->dir = rotacaoDir(arvore->dir);
    (*esq)++;
    return rotacaoEsq(arvore);
  }

  return arvore;
}

void destroiArvore(ArvBin arvore) {
  while (arvore != NULL) {
    destroiArvore(arvore->esq);
    destroiArvore(arvore->dir);
    free(arvore);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

void verifica_erros(AVP *arvore, AVP *pt, int *dir, int *esq, int *cor) {
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
        (*cor) = (*cor) + 3;
        vo_pt->cor = 1;
        pai_pt->cor = 0;
        tio_pt->cor = 0;
        pt = vo_pt;
      } else {
        if (pt == pai_pt->dir) {
          rotacaoEsq_AVP(pai_pt);
          (*esq)++;
          pt = pai_pt;
          pai_pt = pt->pai;
          if (pt == arvore)
            arvore = pai_pt;
        }

        if (pai_pt == NULL || vo_pt == NULL)
          return;

        rotacaoDir_AVP(vo_pt);
        (*dir)++;
        (*cor) = (*cor) + 2;
        int t = pai_pt->cor;
        pai_pt->cor = vo_pt->cor;
        vo_pt->cor = t;
        pt = pai_pt;
      }
    } else {
      tio_pt = vo_pt->esq;

      if (tio_pt != NULL && tio_pt->cor == 1) {
        (*cor) = (*cor) + 3;
        vo_pt->cor = 1;
        pai_pt->cor = 0;
        tio_pt->cor = 0;
        pt = vo_pt;
      } else {
        if (pt == pai_pt->esq) {
          rotacaoDir_AVP(pai_pt);
          (*dir)++;
          pt = pai_pt;
          pai_pt = pt->pai;
          if (pt == arvore)
            arvore = pai_pt;
        }

        if (pai_pt == NULL || vo_pt == NULL)
          return;

        rotacaoEsq_AVP(vo_pt);
        (*esq)++;
        (*cor) = (*cor) + 2;
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