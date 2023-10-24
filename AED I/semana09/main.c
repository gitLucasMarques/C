#include "Arvore.h"

int main(){
  TipoArvore raiz, pai, filho;

  inicializaArvore(raiz);
  raiz = instanciaArvore(raiz,'A');

  inicializaArvore(pai);
  pai = instanciaArvore(pai,'B');
  
  inicializaArvore(filho);
  filho = instanciaArvore(filho,'E');
  
  pai = insereNaArvore(pai,filho);
  
  filho = instanciaArvore(filho,'F');
  pai = insereNaArvore(pai,filho);
  raiz = insereNaArvore(raiz,pai);
  
  pai = instanciaArvore(pai,'C');
  raiz = insereNaArvore(raiz,pai);

  pai = instanciaArvore(pai,'D');
  
  inicializaArvore(filho);
  filho = instanciaArvore(filho,'G');
  pai = insereNaArvore(pai,filho);
  
  filho = instanciaArvore(filho,'H');
  pai = insereNaArvore(pai,filho);
  
  raiz = insereNaArvore(raiz,pai);
  
  imprimeArvore(raiz,0);
  printf("\n");
  
  raiz = destroiArvore(raiz);
  
  return 0;
}