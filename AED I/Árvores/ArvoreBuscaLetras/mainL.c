#include "ArvoreBuscaL.h"

int main() {
  TipoArvore arvore;
  char opc[8], letra;
  int n;

  arvore = inicializaArvore(arvore);

  while (scanf("%s", opc) != EOF) {
    if (strcmp(opc, "I") == 0) {
      getchar();
      scanf("%c", &letra);
      arvore = criaArvoreBinariaBusca(arvore, letra);
    }
    if (strcmp(opc, "INFIXA") == 0) {
      infixa(arvore);
      imprimeArvoreEmOrdem(letrasInfixa);
      printf("\n");
    }
    if (strcmp(opc, "PREFIXA") == 0) {
      prefixa(arvore);
      imprimeArvorePreOrdem(letrasPrefixa);
      printf("\n");
    }
    if (strcmp(opc, "POSFIXA") == 0) {
      posfixa(arvore);
      imprimeArvorePosOrdem(letrasPosfixa);
      printf("\n");
    }
    if (strcmp(opc, "P") == 0) {
      getchar();
      scanf("%c", &letra);
      pesquisaArvoreBinariaBusca(arvore, letra);
    }
  }

  arvore = destroiArvore(arvore);

  return 0;
}