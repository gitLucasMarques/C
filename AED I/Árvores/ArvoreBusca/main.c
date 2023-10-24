#include "ArvoreBinariaBusca.h"
#include <time.h>

int main() {
  TipoArvore arvore;
  int i;
  int valores[12] = {9, 5, 43, 1, 6, 42, 2, 8, 23, 56, 27, 50}; //Exemplo de valores para a Árvore Binária de Busca

  arvore = inicializaArvore(arvore);
  
  for (i = 0; i < 12; i++) {
    arvore = criaArvoreBinariaBusca(arvore, valores[i]);
  }
  
  printf("\nPré-Ordem: \n");
  imprimeArvorePreOrdem(arvore);
  printf("\n\nEm-Ordem: \n");
  imprimeArvoreEmOrdem(arvore);
  printf("\n\nPós-Ordem: \n");
  imprimeArvorePosOrdem(arvore);
  printf("\n");

  printf("\n\nPesquisando na Árvore o valor 6...\n");
  pesquisaArvoreBinariaBusca(arvore, 6);
  printf("\nPesquisando na Árvore o valor 7...\n");
  pesquisaArvoreBinariaBusca(arvore, 7);

  printf("\n\nRemovendo da Árvore o valor 23...\n");
  removeArvoreBinariaBusca(arvore, 23);
  printf("Pré-Ordem: \n");
  imprimeArvorePreOrdem(arvore);
  
  printf("\n\nRemovendo da Árvore o valor 1...\n");
  removeArvoreBinariaBusca(arvore, 1);
  printf("Pré-Ordem: \n");
  imprimeArvorePreOrdem(arvore);

  arvore = destroiArvore(arvore);
  printf("\n\nÁrvore destruída!\n");
  
  return 0;
}