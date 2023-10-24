#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int pF;
int dF;

typedef struct {
  char caractere;
} TipoItem;

typedef struct noh {
  TipoItem item;
  struct noh *prox;
} TipoNoh;

typedef struct {
  TipoNoh *topo;
} TipoPilha;

typedef struct nohArvore {
  char caractere;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
  struct nohArvore *prox;
} TipoArvore;

TipoArvore *arvAux = NULL;

void inicializaPilha(TipoPilha *);
int pilhaVazia(TipoPilha *);
int empilha(TipoPilha *, TipoItem);
int desempilha(TipoPilha *, TipoItem *);
int consultaTopo(TipoPilha *, TipoItem *);

void infixaPosfixa(char *, char *, int *);
int desempilhaEnquanto(TipoPilha *, TipoItem *, int *, int *, char *);
void empilhaPilhaVazia(TipoPilha *, TipoItem);

int arvoreVazia(TipoArvore *);
TipoArvore *destroiArvore(TipoArvore *);
TipoArvore *instanciaArvore(char);
void criaArvorePosfixa(TipoArvore *);
TipoArvore *retiraArvorePosfixa();

int alturaArvore(TipoArvore *);
int percorreArvoreNiveis(TipoArvore *, int);

int main() {
  char infixa[100], posfixa[100] = {0};
  int tamInf, i, auxLet, tam;
  TipoArvore *subArvoreDir, *subArvoreEsq, *raiz;
  int p, esp = 0, tamF, qNiv;

  clock_t Ticks[2];

  fgets(infixa, 100, stdin);
  infixa[strlen(infixa) - 1] = '\0';

  while (*infixa != EOF) {

    Ticks[0] = clock();

    tamInf = strlen(infixa);

    for (p = 0; p <= tamInf; p++) {
      if (infixa[p] == ' ' || infixa[p] == '(' || infixa[p] == ')') {
        esp++;
      }
    }

    infixaPosfixa(infixa, posfixa, &tam);

    for (i = 0; i <= tam + 1; i++) {
      auxLet = posfixa[i];
      if (auxLet == 43 || auxLet == 45 || auxLet == 42 || auxLet == 47) {
        raiz = instanciaArvore(posfixa[i]);
        subArvoreDir = retiraArvorePosfixa();
        subArvoreEsq = retiraArvorePosfixa();
        raiz->subArvoreEsq = subArvoreEsq;
        raiz->subArvoreDir = subArvoreDir;
        criaArvorePosfixa(raiz);
      } else if (auxLet != 0 && auxLet != 32) {
        raiz = instanciaArvore(posfixa[i]);
        criaArvorePosfixa(raiz);
      }
    }

    qNiv = alturaArvore(raiz);
    for (p = 0; p <= qNiv; p++) {
      printf("\nNivel %d: ", p);
      percorreArvoreNiveis(raiz, p + 1);
    }
    printf("\n\n");

    for (p = 0; p < 100; p++) {
      infixa[p] = 0;
      posfixa[p] = 0;
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n\n", Tempo);

    fgets(infixa, 100, stdin);
    infixa[strlen(infixa) - 1] = '\0';
  }

  return 0;
}

void infixaPosfixa(char *infixa, char *posfixa, int *tam) {
  TipoPilha pilha;
  TipoItem item, auxItem;
  int i, auxLet, auxitem, k = 0, j = 0, r = 0, c = 0, auxI = 0;
  int pAb = 0, pFe = 0, Fexp = 0, auxExp, auxTam, p = 0, auxK = 0;
  char expAux[100] = {0}, posfixaAux[100] = {0};

  inicializaPilha(&pilha);

  for (i = 0; i < strlen(infixa);) {
    auxLet = infixa[i];
    auxItem.caractere = infixa[i];

    j = 0;
    dF = 0;

    if (auxLet >= 48 && auxLet <= 57 || auxLet >= 65 && auxLet <= 90 ||
        auxLet >= 97 && auxLet <= 122) {
      posfixa[k] = infixa[i];
      pF = 0;
    } else {
      if (auxLet == 42 || auxLet == 43 || auxLet == 45 || auxLet == 47 ||
          auxLet == 32 || auxLet == 40) {
        if (auxLet == 42) {
          if (pilhaVazia(&pilha)) {
            empilhaPilhaVazia(&pilha, auxItem);
          } else {
            consultaTopo(&pilha, &item);
            auxitem = item.caractere;
            if (auxitem == 43 || auxitem == 45) {
              item.caractere = auxItem.caractere;
              empilha(&pilha, item);
            } else {
              while (auxitem == 42 || auxitem == 47) {
                auxitem = desempilhaEnquanto(&pilha, &item, &k, &j, posfixa);
              }
              item.caractere = auxItem.caractere;
              empilha(&pilha, item);
            }
          }
        }

        if (auxLet == 43) {
          if (pilhaVazia(&pilha)) {
            empilhaPilhaVazia(&pilha, auxItem);
          } else {
            consultaTopo(&pilha, &item);
            auxitem = item.caractere;
            while (auxitem == 43 || auxitem == 45 || auxitem == 47 ||
                   auxitem == 42) {
              desempilha(&pilha, &item);
              j++;
              posfixa[k] = item.caractere;
              if (consultaTopo(&pilha, &item) == 0) {
                break;
              } else {
                k++;
                consultaTopo(&pilha, &item);
                auxitem = item.caractere;
              }
            }
            item.caractere = auxItem.caractere;
            empilha(&pilha, item);
          }
        }

        if (auxLet == 45) {
          if (pilhaVazia(&pilha)) {
            empilhaPilhaVazia(&pilha, auxItem);
          } else {
            consultaTopo(&pilha, &item);
            auxitem = item.caractere;
            while (auxitem == 43 || auxitem == 45 || auxitem == 42 ||
                   auxitem == 47) {
              desempilha(&pilha, &item);
              j++;
              posfixa[k] = item.caractere;
              if (consultaTopo(&pilha, &item) == 0) {
                break;
              } else {
                k++;
                consultaTopo(&pilha, &item);
                auxitem = item.caractere;
              }
            }
            item.caractere = auxItem.caractere;
            empilha(&pilha, item);
          }
        }

        if (auxLet == 47) {
          if (pilhaVazia(&pilha)) {
            empilhaPilhaVazia(&pilha, auxItem);
          } else {
            consultaTopo(&pilha, &item);
            auxitem = item.caractere;
            if (auxitem == 43 || auxitem == 45) {
              item.caractere = auxItem.caractere;
              empilha(&pilha, item);
            } else {
              while (auxitem == 42 || auxitem == 47) {
                auxitem = desempilhaEnquanto(&pilha, &item, &k, &j, posfixa);
              }
              item.caractere = auxItem.caractere;
              empilha(&pilha, item);
            }
          }
        }

        if (auxLet == 32) {
          k--;
        }

        pF = 1;

      } else {
        if (auxLet == 40) {
          pAb++;
          p = 0;
          for (c = i + 1; c <= strlen(infixa); c++, p++) {
            auxExp = infixa[c];
            if (auxExp == 40) {
              pAb++;
              expAux[p] = infixa[c];
            }
            if (auxExp == 41) {
              pFe++;
              expAux[p] = infixa[c];
              if (pAb == pFe) {
                Fexp = c;
                expAux[p] = '!';
                infixaPosfixa(expAux, posfixaAux, &auxTam);
                break;
              }
            }
            if (auxExp < 40 || auxExp > 41) {
              expAux[p] = infixa[c];
            }
          }

          r = k;
          for (c = 0; c <= strlen(infixa); c++, r++) {
            auxExp = posfixaAux[c];
            if (auxExp >= 48 && auxExp <= 57 || auxExp >= 65 && auxExp <= 90 ||
                auxExp >= 97 && auxExp <= 122 || auxExp == 42 || auxExp == 43 ||
                auxExp == 45 || auxExp == 47) {
              posfixa[r] = posfixaAux[c];
              auxK++;
            }
          }

          dF = 1;
          auxI = Fexp + 1;
          pF = 2;
        }
      }
    }

    if (pF == 0) {
      k++;
      i++;
    }
    if (pF == 1) {
      if (j != 0) {
        k = k + j;
        i++;
      } else {
        k++;
        i++;
      }
    }
    if (pF == 2) {
      k = k + auxK + 2;
      i = auxI;
    }
  }

  while (!pilhaVazia(&pilha)) {
    if (dF == 1) {
      k = auxI;
      dF = 0;
    }
    desempilha(&pilha, &item);
    posfixa[k] = item.caractere;
    k++;
  }

  *tam = k;
}

int desempilhaEnquanto(TipoPilha *pilha, TipoItem *item, int *k, int *j, char posfixa[100]) {
  int auxitem;
  desempilha(pilha, item);
  j++;
  posfixa[*k] = item->caractere;
  if (consultaTopo(pilha, item) == 0) {
    return 0;
  } else {
    k++;
    consultaTopo(pilha, item);
    auxitem = item->caractere;
    return auxitem;
  }
}

void empilhaPilhaVazia(TipoPilha *pilha, TipoItem auxItem) {
  TipoItem itemAux;
  itemAux.caractere = auxItem.caractere;
  empilha(pilha, itemAux);
}

void inicializaPilha(TipoPilha *pilha) { pilha->topo = NULL; }

int pilhaVazia(TipoPilha *pilha) { return pilha->topo == NULL; }

int empilha(TipoPilha *pilha, TipoItem item) {
  TipoNoh *novoNoh;

  novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  if (novoNoh != NULL) {
    novoNoh->item = item;
    novoNoh->prox = pilha->topo;
    pilha->topo = novoNoh;
    return 1;
  }
  return 0;
}

int desempilha(TipoPilha *pilha, TipoItem *item) {
  TipoNoh *ptrAux;
  if (!pilhaVazia(pilha)) {
    ptrAux = pilha->topo;
    *item = ptrAux->item;
    pilha->topo = ptrAux->prox;
    free(ptrAux);
    return 1;
  }
  return 0;
}

int consultaTopo(TipoPilha *pilha, TipoItem *item) {
  if (!pilhaVazia(pilha)) {
    *item = pilha->topo->item;
    return 1;
  }
  return 0;
}

int arvoreVazia(TipoArvore *arvore) { return arvore == NULL; }

TipoArvore *instanciaArvore(char dado) {
  TipoArvore *arvore;

  arvore = (TipoArvore *)malloc(sizeof(TipoArvore));
  arvore->caractere = dado;
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->prox = NULL;
  return arvore;
}

void criaArvorePosfixa(TipoArvore *arvore) {
  if (arvAux == NULL)
    arvAux = arvore;
  else {
    arvore->prox = arvAux;
    arvAux = arvore;
  }
}

TipoArvore *retiraArvorePosfixa() {
  TipoArvore *arvore;
  arvore = arvAux;
  arvAux = arvAux->prox;
  return arvore;
}

int alturaArvore(TipoArvore *arvore) {
  int hEsq = 0, hDir = 0;
  if (arvore == NULL) {
    return -1;
  } else {
    hEsq = alturaArvore(arvore->subArvoreEsq);
    hDir = alturaArvore(arvore->subArvoreDir);
    if (hEsq < hDir) {
      hDir++;
      return hDir;
    } else {
      hEsq++;
      return hEsq;
    }
  }
}

int percorreArvoreNiveis(TipoArvore *arvore, int qNiv) {
  if (arvore == NULL) {
    return 0;
  }
  if (qNiv == 1) {
    printf("%c", arvore->caractere);
  } else if (qNiv > 1) {
    percorreArvoreNiveis(arvore->subArvoreEsq, qNiv - 1);
    percorreArvoreNiveis(arvore->subArvoreDir, qNiv - 1);
  }
  return 1;
}