#include <stdio.h>
#include <stdlib.h>
#include "algoritmosordenacao.h"


// ---------- QUICK SORT --------

void swap(int*a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*Funcao que pega o ultimo elemento como pivot,
coloca o elemento pivot na posicao correta no
array sorted, e coloca todos os menores que o pivot
para a esquerda do pivot e todos os maiores a
direita do pivot*/

int partition (int* A, int low, int high) {
    int pivot = A[high];
    /*index do menor elemento*/
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {

        /*se o elemento atual e menor ou igual ao pivot*/
        if(A[j] <= pivot) {
            /*incrementa o index do menor elemento*/
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i+1], &A[high]);
    return (i+1);
}

/*funcao que implementa o quickSort, sendo low
o index inicial e high o index final*/

void quickSort(int* A, int low, int high) {

    if(low < high) {

        /*pi e a particao do index, A[p] e agora
        o lugar certo*/
        int pi = partition(A, low, high);

        /*separadamente sort os elementos antes de
        particionar e depois de particionar*/
        quickSort(A, low, pi-1);
        quickSort(A, pi+1, high);
    }
}

//---------------------------------------------------------------------


// ----------------- MERGE SHORT ------------------------------------

/*Funcao que implementa o mergeSort*/
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* cria um array temporario*/
    int L[n1], R[n2];

    /* Copia os dados para os arrays temporarios L[] e R[] */
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
    }

    /* Merge os arrays temporarios de volta para o array[l..r]*/
    i = 0; /*index inicial do primeiro subarray*/
    j = 0; /*index inicial do segundo subarray*/
    k = l; /*index inicial do array merged*/
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /*Copia os elementos restantes para L[], se houver algum*/
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /*Copia os elementos restantes para R[], se houver algum*/
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


/*L e para o index da esquerda e r para o index da direita do
subarray de A que vai ser sorted*/
void mergeSort(int *arr, int l, int r)
{
    if (l < r) {
        /* O mesmo que (l+r)/2, mas evita overflow de l grande e h*/
        int m = l+(r-l)/2;

        /*Sort primeira e segunda metade */
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

//--------------------------------------------------------------
