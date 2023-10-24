#include "ArvoreBinariaBusca.h"

int main() {
  TipoArvore arvore;
  int num, Ncasos, NNum, i, k;

  inicializaArvore(arvore);

  scanf("%d", &Ncasos);

  for (i = 0; i < Ncasos; i++) {
    scanf("%d", &NNum);
    for (k = 0; k < NNum; k++) {
      scanf("%d", &num);
      arvore = criaArvoreBinariaBusca(arvore, num);
    }
    printf("Case %d:\n", i + 1);

    printf("Pre.:");
    imprimeArvorePreOrdem(arvore);

    printf("\nIn..:");
    imprimeArvoreEmOrdem(arvore);

    printf("\nPost.:");
    imprimeArvorePosOrdem(arvore);

    printf("\n\n");
    destroiArvore(arvore);
  }

  return 0;
}