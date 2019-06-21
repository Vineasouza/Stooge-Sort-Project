#ifndef _ALGORITMOSORDENACAO_H_
#define _ALGORITMOSORDENACAO_H_

//----------- ASSINATURAS DAS FUNÇÕES ------------------
void swap(int*, int*);
int partition(int*, int, int);
int quickSort(int* A, int low, int high, int numComp);
int merge(int *arr, int l, int m, int r, int numComp);
int mergeSort(int *arr, int l, int r, int numComp);
int shellSort(int* A, int n);
int bubbleSort(int vetor[], int tamanho);
void trocar(int *x, int *y);
int insertionSort(int *vetor, int tamanho);
int selectionSort(int *vetor, int tamanho);
int stoogeSort(int *A, int l, int h, int numComp);
//------------------------------------------------------

#endif
