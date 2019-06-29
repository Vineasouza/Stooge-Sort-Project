#ifndef _ALGORITMOSORDENACAO_H_
#define _ALGORITMOSORDENACAO_H_

//----------- ASSINATURAS DAS FUNÇÕES ------------------
//QUICKSORT
void swap(int*, int*);
int partition(int*, int, int, int*, int*);
int quickSort(int* A, int low, int high, int *numComp, int*numTroca, int condicao);
//mergeSort
void merge(int *arr, int l, int m, int r, int *numComp, int*numTroca);
int mergeSort(int *arr, int l, int r, int*numComp, int*numTroca, int condicao);
//ShellSort
int shellSort(int* A, int n, int condicao);
//BubleSort
int bubbleSort(int *vetor, int tamanho,int codicao);
void trocar(int *x, int *y);
//INSERTION SORT
int insertionSort(int *vetor, int tamanho, int condicao);
//SELECTIONSORT
int selectionSort(int *vetor, int tamanho, int condicao);
//StoogeSort
int stoogeSort(int *A, int l, int h, int *numComp, int *numTroca, int condicao);
//------------------------------------------------------

#endif
