#include "MatrizEsparsa.h"

void inicializaMatriz(TipoMatriz *mat){
  mat->matriz = NULL;
  mat->nColunas = 0;
  mat->nLinhas = 0;
}

int matrizVazia(TipoMatriz *mat){
  return mat->matriz==NULL;  
}

int instanciaMatriz(TipoMatriz *mat,int linhas,int colunas){
  int i;
  mat->matriz = (TipoLista*) malloc(linhas*sizeof(TipoLista));
  if(mat->matriz!=NULL){
    mat->nLinhas = linhas;
    mat->nColunas = colunas;
    for(i=0;i<linhas;i++){
      mat->matriz[i] = inicializaLista(mat->matriz[i]);
    }
    return 1;
  }
  return 0;
}

void destroiMatriz(TipoMatriz *mat){
  int i;
  for(i=0;i<mat->nLinhas;i++){
    mat->matriz[i] = destroiLista(mat->matriz[i]);
  }
  free(mat->matriz);
}

int insereNaMatriz(TipoMatriz *mat,int linha,int coluna,int elemento){
  TipoItem item;
  if(linha<0 || linha>=mat->nLinhas || coluna<0 || coluna>=mat->nColunas || elemento==0)
    return 0;
  item.coluna = coluna;
  item.elemento = elemento;
  mat->matriz[linha] = insereOrdenado(mat->matriz[linha],item);
  return 1;
}

int retiraDaMatriz(TipoMatriz *mat,int linha,int coluna){
  TipoItem item;
  if(linha<0 || linha>=mat->nLinhas || coluna<0 || coluna>=mat->nColunas)
    return 0;
  mat->matriz[linha] = removeEspecifico(mat->matriz[linha],coluna,&item);
  return 1;
}


void imprimeMatriz(TipoMatriz *mat){
  int i;
  for(i=0;i<mat->nLinhas;i++){
    imprimeLista(mat->matriz[i],mat->nColunas);
  }
}