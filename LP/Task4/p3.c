/*Os elementos aij de uma matriz representam a distância entre os pontos i e j
de uma cidade.
Dado um trajeto com k pontos, calcular a distância percorrida.

Entrada:
Uma linha contendo o tamanho da matriz. N linhas com os valores da
matriz.
Uma linha com o número de pontos do trajeto e uma linha com o pontos do
trajeto.

Saída: Distância percorrida no trajeto.*/

/*
Entrada
3
4 6 2
1 2 8
2 5 9
5
0 2 1 2 1

Saída
20
*/

#include <stdio.h>
int main() {
  int mat[1000][1000] = {0}, l, c, tamanho, quantPontos, i = 0, ponto[1000], dist = 0;

  scanf("%d", &tamanho);

  for (l = 0; l < tamanho; l++) {
    for (c = 0; c < tamanho; c++) {
      scanf("%d", &mat[l][c]);
    }
  }

  scanf("%d", &quantPontos);

  for (i = 0; i < quantPontos; i++) {
    scanf("%d", &ponto[i]);
  }

  for (i = 0; i < quantPontos - 1; i++) {
    dist += mat[ponto[i]][ponto[i + 1]];
  }

  printf("%d", dist);

  return 0;
}
