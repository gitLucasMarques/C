#include <stdio.h>
#include <stdlib.h>

// Função que realiza a troca de dois elementos de um vetor
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função que retorna o índice da mediana de três elementos de um vetor
int get_median(int arr[], int left, int right) {
  int center = (left + right) / 2;
  if (arr[left] > arr[center])
    swap(&arr[left], &arr[center]);
  if (arr[left] > arr[right])
    swap(&arr[left], &arr[right]);
  if (arr[center] > arr[right])
    swap(&arr[center], &arr[right]);
  swap(&arr[center], &arr[right - 1]);
  return arr[right - 1];
}

// Função que particiona um vetor em relação a um pivô
int partition(int arr[], int left, int right, int pivot) {
  int i = left;
  int j = right - 2;
  while (1) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i < j) {
      swap(&arr[i], &arr[j]);
      i++;
      j--;
    } else {
      break;
    }
  }
  swap(&arr[i], &arr[right - 1]);
  return i;
}

// Função que ordena um vetor utilizando o algoritmo QuickSort recursivo com
// pivô fixo
int quick_sort_fixed(int arr[], int left, int right, int depth) {
  if (left >= right)
    return 0;
  int pivot = arr[right - 1];
  int index = partition(arr, left, right, pivot);
  int left_depth = quick_sort_fixed(arr, left, index, depth + 1);
  int right_depth = quick_sort_fixed(arr, index + 1, right, depth + 1);
  return (left_depth > right_depth ? left_depth : right_depth) + depth;
}

// Função que ordena um vetor utilizando o algoritmo QuickSort recursivo com
// pivô mediana de três
int quick_sort_med(int arr[], int left, int right, int depth) {
  if (left >= right)
    return 0;
  int pivot = get_median(arr, left, right);
  int index = partition(arr, left, right, pivot);
  int left_depth = quick_sort_med(arr, left, index, depth + 1);
  int right_depth = quick_sort_med(arr, index + 1, right, depth + 1);
  return (left_depth > right_depth ? left_depth : right_depth) + depth;
}

int main() {
  
}