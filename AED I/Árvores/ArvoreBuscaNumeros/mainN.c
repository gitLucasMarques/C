#include "ArvoreBuscaN.h"

int main() {
  TipoArvore arvore;
  char opc[8];
  int num;

  inicializaArvore(arvore);

  while (scanf("%s", opc) != EOF) {
    if (strcmp(opc, "I") == 0) {
      scanf("%d", &num);
      arvore = criaArvoreBinariaBusca(arvore, num);
    }
    if (strcmp(opc, "INFIXA") == 0) {
      imprimeArvoreEmOrdem(arvore);
      printf("\n");
    }
    if (strcmp(opc, "PREFIXA") == 0) {
      imprimeArvorePreOrdem(arvore);
      printf("\n");
    }
    if (strcmp(opc, "POSFIXA") == 0) {
      imprimeArvorePosOrdem(arvore);
      printf("\n");
    }
    if (strcmp(opc, "P") == 0) {
      scanf("%d", &num);
      pesquisaArvoreBinariaBusca(arvore, num);
    }
    if (strcmp(opc, "R") == 0) {
      scanf("%d", &num);
      arvore = removeArvoreBinariaBusca(arvore, num);
    }
  }

  destroiArvore(arvore);

  return 0;
}