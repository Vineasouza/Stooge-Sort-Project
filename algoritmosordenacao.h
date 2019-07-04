#ifndef _ALGORITMOSORDENACAO_H_
#define _ALGORITMOSORDENACAO_H_

//----------- ASSINATURAS DAS FUNÇÕES ------------------
//QUICKSORT
void swap(int*, int*);
int partition(int*, int, int, int*, int*);
void quickSort(int* A, int low, int high, int *numComp, int*numTroca);
//mergeSort
void merge(int *arr, int l, int m, int r, int *numComp, int*numTroca);
void mergeSort(int *arr, int l, int r, int*numComp, int*numTroca);
//ShellSort
void shellSort(int* A, int n, int *numComp, int*numTrocas);
//BubleSort
void bubbleSort(int *arr, int n,int*numCom, int*numTroca);
//INSERTION SORT
void insertionSort(int *vetor, int tamanho, int* numComp, int* numTrocas);
//SELECTIONSORT
void trocando(int *xp, int *yp);
void selectionSort(int *arr, int n, int *numComp, int*numTrocas);
//StoogeSort
void stoogeSort(int *A, int l, int h, int *numComp, int *numTroca);
//------------------------------------------------------

#endif
