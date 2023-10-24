#include "ArvorePO.h"

int main() {
  TipoArvore arvore;
  int nCasos, nNos, i;
  char prefixa[52], infixa[52];

  scanf("%d", &nCasos);
  for (i = 0; i < nCasos; i++) {
    scanf("%d", &nNos);
    getchar();
    fgets(prefixa, nNos + 1, stdin);
    getchar();
    fgets(infixa, nNos + 1, stdin);

    arvore = inicializaArvore(arvore);
    arvore = criaArvorePosFixa(infixa, prefixa, 0, nNos - 1);
    
    printf("\n");
    imprimeArvorePosOrdem(arvore);
    printf("\n");
    arvore = destroiArvore(arvore);
  }
  return 0;
}