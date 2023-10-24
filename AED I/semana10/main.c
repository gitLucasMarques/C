#include "ArvoreBinaria.h"

int main() {
  TipoArvore raiz, pai, ArvoreAux1, ArvoreAux2, subArvoreEsq, subArvoreDir;
  char prefixa[9] = {'A', 'B', 'D', 'H', 'E', 'C', 'F', 'I', 'G'};
  char infixa[9] = {'H', 'D', 'B', 'E', 'A', 'I', 'F', 'C', 'G'};

  inicializaArvore(raiz);
  raiz = instanciaArvore(raiz, 'A');

  inicializaArvore(pai);
  pai = instanciaArvore(pai, 'B');

  inicializaArvore(subArvoreEsq);
  subArvoreEsq = instanciaArvore(subArvoreEsq, 'D');
  inicializaArvore(ArvoreAux1);
  ArvoreAux1 = instanciaArvore(ArvoreAux1, 'H');
  subArvoreEsq = insereSubArvoreEsq(subArvoreEsq, ArvoreAux1);

  inicializaArvore(subArvoreDir);
  subArvoreDir = instanciaArvore(subArvoreDir, 'E');
  pai = montaArvore(pai, subArvoreEsq, subArvoreDir);

  raiz = insereSubArvoreEsq(raiz, pai);

  pai = instanciaArvore(pai, 'C');

  ArvoreAux1 = instanciaArvore(ArvoreAux1, 'F');
  ArvoreAux2 = instanciaArvore(ArvoreAux2, 'I');
  subArvoreEsq = insereSubArvoreEsq(ArvoreAux1, ArvoreAux2);
  subArvoreDir = instanciaArvore(subArvoreDir, 'G');
  pai = montaArvore(pai, subArvoreEsq, subArvoreDir);

  raiz = insereSubArvoreDir(raiz, pai);

  printf("\nPré-Ordem: \n");
  imprimeArvorePreOrdem(raiz);
  printf("\n\nEm-Ordem: \n");
  imprimeArvoreEmOrdem(raiz);
  printf("\n\nPós-Ordem: \n");
  imprimeArvorePosOrdem(raiz);
  printf("\n");

  raiz = destroiArvore(raiz);
  printf("\nÁrvore destruída!\n\n");

  
  printf("\nCriando a Árvore Binária a partir da função criaArvore...\n");

  raiz = inicializaArvore(raiz);
  raiz = criaArvore(infixa, prefixa, 0, 8);

  printf("\nPré-Ordem: \n");
  imprimeArvorePreOrdem(raiz);
  printf("\n\nEm-Ordem: \n");
  imprimeArvoreEmOrdem(raiz);
  printf("\n\nPós-Ordem: \n");
  imprimeArvorePosOrdem(raiz);
  printf("\n\nEm níveis: \n");
  percorreArvoreNiveis(raiz);
  printf("\n");

  raiz = destroiArvore(raiz);
  printf("\nÁrvore destruída!\n");
  
  return 0;
}