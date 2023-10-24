/*Escreva a função para cálculo do N-ésimo termo da série de Fibonacci
utilizando recursividade.*/

// 0,1,1,2,3,5,8,13,21,34,55...

/*#include <stdio.h>

int Fibonacci(int n, int soma) {

  if (n == 0) {
    return 0;
  } else {
    if (n == 1) {
      return 1;
    } else {
      if (n == 2) {
        return 1;
      } else {
        return soma += Fibonacci(n - 1, soma) + Fibonacci(n - 2, soma);
      }
    }
  }
}

void Imprimir_Resultado(int soma) {
  printf("\nResultado: %d", soma);
  return;
}

int main() {
  int n, soma = 0, i = 2, k;

  scanf("%d", &n);
  soma = Fibonacci(n, soma);
  Imprimir_Resultado(soma);

  return 0;
}*/

/* Escreva uma função recursiva que calcule a soma dos dígitos de um número
inteiro. Por exemplo, se a entrada for 123, a saída deverá ser 1+2+3 = 6.

#include <stdio.h>
#include <string.h>

#define TAM 100

void Receber_Numero(int *num) {
  scanf("%d", num);
  return;
}

int Quantidade_Digitos(int *num[TAM]){
  int aux1, aux2 = 1, i = 0;

  aux1 = *num[i]%10;

  for(i = 1; aux2%10 != 0; i++){
    aux1 = *num[i]%10;
    aux2 = *num[i] - aux1;
  }

  return i;
}

int Somar_Digitos(int *num, int *soma, int *i) {
  int aux1, aux2;
  if (i <= 0) {
    return *soma;
  } else {
    aux1 = num[*i]%10;
    *soma += aux1;
    aux2 = num[*i] - aux1;
    return Somar_Digitos(&aux2, soma, i-1);
  }

}

void Imprimir_Soma(int *soma){
  printf("\nSoma = %d", *soma);
  return;
}

int main(){
  int num[TAM];
  int soma = 0, i;

  Receber_Numero(num);
  i = Quantidade_Digitos(&num);
  soma = Somar_Digitos(num, &soma, &i);
  Imprimir_Soma(&soma);

  return 0;
} */

/*Crie uma função recursiva que receba um número inteiro positivo N e calcule o
somatório dos números de 1 a N

#include <stdio.h>

void Receber_Valor(int *a) {
  scanf("%d", a);
  return;
}

int Somar_Valores(int *soma, int *a, int i) {

  if (i > *a) {
    return *soma;
  } else {
    *soma += i;
    return Somar_Valores(soma, a, i+1);
  }
  return *soma;
}

void Imprimir(int soma) {
  printf("\nSoma = %d", soma);
  return;
}

int main() {
  int soma = 0, a, i = 1;

  Receber_Valor(&a);
  soma = Somar_Valores(&soma, &a, i);
  Imprimir(soma);

  return 0;
}*/

// Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
// em um número natural N.
/*Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.

#include <stdio.h>
#include <string.h>

#define TAM 11

void Receber_Valor(char num[TAM]) {
  int i;

  for(i = 0; i < TAM; i++){
    scanf("%c", &num[i]);
  }

  return;
}

int Ocorr_Dig_Num(char *num, int *k, int i){

  if(i == TAM){
    return *k;
  } else {
    if(strcmp(&num[i],&num[TAM-1]) == 0){
      k++;
      return Ocorr_Dig_Num(num, k, i+1);
    }
  }
}

void Imprimir(int k) {
  printf("\nOcorrências = %d", k);
  return;
}

int main(){
  int k = 0, i = 0;
  char num[TAM];

  Receber_Valor(num);
  for(i = 0; i < TAM; i++){
    printf("\nnum[%d] = %c", i, num[i]);
  }
  k = Ocorr_Dig_Num(num, &k, i);
  printf("\nk = %d", k);
  Imprimir(k);

  return 0;
}*/

/*
#include <stdio.h>
#include <string.h>

#define TAM 100
#define TAM_VALOR 4
#define TAM_QUANT 1000
#define TAM_PROD 10000

typedef struct {
  char nome[TAM];
  float valor[TAM_VALOR];
  float quant[TAM_QUANT];
} Item;

Item produto[TAM_PROD];

void Menu() {
  printf("-----------------------------------------------------------------------------------------------");
  printf("\nMENU\n\n1 - Adicionar Item\n2 - Valor Total da Compra\n3 - Mostrar
Relatório\n4 - Sair\n\nOpção: "); return;
}

void Adicionar_Item(int i){

  printf("\nProduto: ");
  scanf("%s", produto[i].nome);
  printf("Valor: ");
  scanf("%f", produto[i].valor);
  printf("Quantidade: ");
  scanf("%f", produto[i].quant);
  printf("\n");
  return;
}

float Valor_Total(int i, float soma, int k) {

  if (k == i) {
    return soma;
  } else {
    soma += *produto[k].valor * *produto[k].quant;
    return Valor_Total(i, soma, k+1);
  }
}

void Verificar_Lista(){
  int k;
  for(k = 0; k < TAM_PROD; k++){
    if(strlen(produto[k].nome) <= 1){
      k++;
    } else {
      continue;
    }
  }
  if(k == TAM_PROD){
    printf("\nAinda não há itens na lista!\n");
  } else {

  }
}

void Mostrar_Relatorio(int i) {
  int k = i;

  Verificar_Lista();

  if (i < 0) {
  } else {
    printf("\nProduto: %s\t\tValor: R$ %0.2f\tQuantidade: %0.0f\n",
produto[i].nome, *produto[i].valor, *produto[i].quant); return
Mostrar_Relatorio(i - 1);
  }
}

void Sair() {

  printf("\nAté a próxima!");
  return;
}

void Imprimir(float soma){
  printf("\nValor Total da Compra: R$ %0.2f\n", soma);
  return;
}

void Acao_Menu() {
  int n, i = 0, k = 0;
  float soma = 0, somaAux;

  while (n != 4) {
    Menu();
    scanf("%d", &n);

    switch (n) {
      case 1:
      Adicionar_Item(i);
      i++;
      break;

    case 2:
      somaAux = Valor_Total(i, soma, k);
      Imprimir(somaAux);
      break;

    case 3:
      i--;
      Mostrar_Relatorio(i);
      i++;
      break;

    case 4:
      Sair();
      break;
    }
  }
  return;
}

int main() {

  Acao_Menu();

  return 0;
}*/

/*#include <stdio.h>

void Inicializa_Matriz(int matriz[3][3]){
  int l, c;

  for (l = 0; l < 3; l++){
    for(c = 0 ; c < 3; c++){
      scanf("%d", &matriz[l][c]);
    }
  }
  return;
}

void Mostrar_Posição(int matriz[3][3], int *x) {
  int l, c;
  scanf("%d", x);
  for (l = 0; l < 20; l++) {
    for (c = 0; c < 20; c++) {
      if (matriz[l][c] == *x) {
        printf("\nA primeira ocorrência de 'x' é na linha: %d e coluna: %d", l,
c); break; } else { continue;
      }
    }
  }
  return;
}

int main(){
  int matriz[3][3] = {0} , x, l, c;

  Mostrar_Posição(matriz, &x);

  return 0;
}*/

/*#include <stdio.h>
#include <string.h>

typedef struct {
  char string[100];
} strings;

strings string[5];

void Strings() {
  int i;

  for (i = 0; i < 5; i++) {
    fgets(string[i].string, 100, stdin);
  }
  return;
}

void Achar_String() {
  int i, k;
  char str;

  for (i = 0; i < 5; i++) {
    printf("\n%s", string[i].string);
  }

  printf("\nSTR: ");
  fgets(&str, 100, stdin);

  for (i = 0; i < 5; i++) {
    if (strcmp(&str, string[i].string) == 0) {
      printf("As strings são iguais em: string[%d]", i);
    } else {
      continue;
    }
  }
  return;
}

int main() {

  Strings();
  Achar_String();

  return 0;
}*/

//. Faça um programa que cria um vetor com 5 elementos inteiros, lê 5 números do
// teclado, armazena os números no vetor e imprime o vetor na ordem inversa.

/*#include <stdio.h>

void Receber_Inteiros(int valor[5]){
  int i;

  printf("\nVetor: ");
  for(i = 0; i < 5; i++){
    scanf("%d", &valor[i]);
  }

  return;
}

void Imprimir_Vetor(int valor[5]){
  int i;

  printf("\nVetor inverso: ");
  for(i = 4; i >= 0; i--){
    printf("%d ", valor[i]);
  }

  return;
}

int main(){
  int valor[5];

  Receber_Inteiros(valor);
  Imprimir_Vetor(valor);

  return 0;
}*/

// Faça um programa que lê uma matriz de 3 x 3 elementos usando um comando for,
// multiplica cada elemento por 5 e imprime o resultado.

/*#include <stdio.h>

void Receber_Matriz(int matriz[3][3]){
  int l, c;

  for(l = 0; l < 3; l++){
    for(c = 0; c < 3; c++){
      scanf("%d", &matriz[l][c]);
    }
  }
  return;
}

void Multiplicar_Matriz(int matriz[3][3]){
  int l, c;

  for(l = 0; l < 3; l++){
    for(c = 0; c < 3; c++){
      matriz[l][c] *= 5;
    }
  }
  return;
}

void Imprimir_Matriz(int matriz[3][3]){
  int l, c;
  printf("\nMatriz Multplicada por 5:\n");
  for(l = 0; l < 3; l++){
    printf("\n");
    for(c = 0; c < 3; c++){
      printf("%d\t", matriz[l][c]);
    }
  }

  return;
}

int main(){
  int matriz[3][3] = {};

  Receber_Matriz(matriz);
  Multiplicar_Matriz(matriz);
  Imprimir_Matriz(matriz);

  return 0;
}*/

// Fazer um programa em "C" que lê uma lista de 20 produtos e e precós e
// armazêna-os em um array do tipo da estrutura abaixo. O programa deve, em
// seguida, ordenar o vetor em ordem alfabética de nome de produto e inflacionar
// os produtos cujo valor for menor que 100 em 5%. Por fim a lista de
// produtos/preços deve ser impressa.

#include <stdio.h>
#include <string.h>

#define TAM_PROD 100
#define TAM_NOME 25
#define TAM_PRECO 1
#define TAM_PRODUT 20

typedef struct {
  char produto[TAM_NOME];
  float preco[TAM_PRECO];
} Produtos;

Produtos prod[TAM_PRODUT];

void Limpar_Strings() {
  int i, k;

  for (i = 0; i < TAM_PRODUT; i++) {
    for (k = 0; k < TAM_NOME; k++) {
      strcpy(&prod[i].produto[k], " ");
    }
  }
}

void Receber_Produtos() {
  int i, k;

  for (i = 0; i < TAM_PRODUT; i++) {
    printf("\nProduto: ");
    scanf("%s", prod[i].produto);
    printf("Preço: ");
    scanf("%f", prod[i].preco);
  }

  return;
}

void Ordem_Alfabetica() {
  int i, k = 0, j;
  int auxProduto[TAM_PRECO];

  for (i = 0; i < TAM_PRODUT; i++) {
    for (k = 0; k < TAM_NOME; k++) {
      strcpy(auxProduto[i], &prod[i].produto[k]);
      for (j = 65; j <= 90; j++) {
        if (auxProduto[i] == j) {
          printf("\nProduto: %s\t\tPreço: % 0.2f", prod[i].produto, *prod[i].preco);
        } else {
          continue;
        }
      }
    }
  }

  return;
}

int main() {

  // Limpar_Strings();
  Receber_Produtos();

  return 0;
}

/*#include <stdio.h>
#include <string.h>

int main(){
  char nome[10];
  int i;

  //fgets(nome, 100, stdin);
  //puts(nome);

  scanf("%s", nome);
  //printf("%s", nome);

  for (i = 0; i < 10; i++){
    scanf("%c", &nome[i]);
  }

  for (i = 0; i < 10; i++){
    printf("%c", nome[0]);
  }

  return 0;
}*/

/*
for (i = 0; i < TAM_PRODUT; i++) {
    printf("\nProduto: ");
    for (k = 0; k < TAM_NOME; k++) {
      //printf("\nEntrei no for do k!\n\nk = %d\ti = %d\n\n", k, i);
      scanf("%c", &prod[i].auxProduto[k]);
      if (strcmp(&prod[i].auxProduto[k], "\n") == 0) {
        break;
      } else {
        strcpy(&prod[i].produto[k], &prod[i].auxProduto[k]);
      }
    }

    printf("Preço: ");
    scanf("%f", prod[i].preco);
  }

for (i = 0; i < TAM_PRODUT; i++) {
    printf("\nProduto: ");
    for (k = 0; k < TAM_NOME; k++) {
      printf("\nEntrei no for do k!\n\nk = %d\ti = %d\n\n", k, i);
      scanf("%c", &prod[i].auxProduto[k]);
      printf("--A%cA---------------------------", prod[i].auxProduto[k]); //%c
== \n if (strcmp(&prod[i].auxProduto[k], "\n") == 0) { printf("\nentrei no IF");
        break;
      } else {
        strcpy(&prod[i].produto[k], &prod[i].auxProduto[k]);
        continue;
      }
    }

    printf("\nPreço: ");
    scanf("%f", prod[i].preco);
  }

for (i = 0; i < TAM_PRODUT; i++) {
    printf("\nProduto: ");
    scanf("%s", prod[i].produto);
    printf("Preço: ");
    scanf("%f", prod[i].preco);
  }
*/
