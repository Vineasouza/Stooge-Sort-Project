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

int quickSort(int* A, int low, int high, int numComp) {
    
    if(low < high) {

        /*pi e a particao do index, A[p] e agora
        o lugar certo*/
        int pi = partition(A, low, high);
        numComp = pi + numComp;
        /*separadamente sort os elementos antes de
        particionar e depois de particionar*/
        quickSort(A, low, pi-1,numComp);
        quickSort(A, pi+1, high,numComp);
    }

    return numComp;
}

//---------------------------------------------------------------------


// ----------------- MERGE SHORT ------------------------------------

/*Funcao que implementa o mergeSort*/
int merge(int *arr, int l, int m, int r, int numComp) {
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
        numComp++;
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

    return numComp;
}


/*L e para o index da esquerda e r para o index da direita do
subarray de A que vai ser sorted*/
int mergeSort(int *arr, int l, int r, int numComp)
{
    if (l < r) {
        /* O mesmo que (l+r)/2, mas evita overflow de l grande e h*/
        int m = l+(r-l)/2;

        /*Sort primeira e segunda metade */
        mergeSort(arr, l, m,numComp);
        mergeSort(arr, m+1, r,numComp);

       numComp = merge(arr, l, m, r, numComp);
    }

    return numComp;
}

//-------------------- ShellSort -----------

int shellSort(int* A, int n) {
    int h = 1, i = 0, j = 0, chave = 0, k = 1;
    int numeroRep = 0;

    do{
        h = (h*3) + 1;
    } while(h < n);

    do{
        h = h/3;

        for(i = h; i < n; i++) {
            chave = A[i];
            j = i - h;

            while(j >= 0 && chave < A[j]) {
                numeroRep++;
                A[j + h] = A[j];
                j = j - h;
            }

            A[j + h] = chave;
        }
    } while (h > 1);

    return numeroRep;
}

//--------------------------------------------------------------

//-------------- Bubble Sort ---------------------------------
int bubbleSort(int vetor[], int tamanho) {
    int i, j, numeroCom = 0;
    for (i = 0; i < (tamanho - 1); i++)
        for (j = 0; j < (tamanho - (i + 1)); j++)
            numeroCom++;
            if (vetor[j] > vetor[j + 1])
                trocar(&vetor[j], &vetor[j + 1]);
    return numeroCom;
}

/* Funcao auxiliar do Bubble Sort */
void trocar(int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

//------------------------------------------------------------------------

//--------------------- Insertion Sort --------------------------------------


int insertionSort(int *vetor, int tamanho) {
    int i, j, k, numeComp = 0;
    
    for (i = 1; i < tamanho; ++i) {
        k = vetor[i];
        j = i - 1;

        while ((j >= 0) && (k < vetor[j])) {
            numeComp++;
            vetor[j + 1] = vetor[j];
            --j;
        }

        vetor[j + 1] = k;
    }

    return numeComp + 1;
}

//---------------------------------------------------------



//---------------- SelectionSort -------------------------------

int selectionSort(int *vetor, int tamanho) {
    int i, j, min;
    int numComp = 0;
    for (i = 0; i < tamanho - 1; i++) {
        min = i;
        for (j = i + 1; j < tamanho; j++)
            numComp++;
            if (vetor[j] < vetor[min])
                min = j;

        trocar(&vetor[i], &vetor[min]);
    }

    return numComp;
}

//------------------------------------------------------------------------

//------------------- StoogeSort----------------------------------------

int stoogeSort(int *A, int l, int h, int numComp) {
    /*Se a posicao inicial(l) for maior
    ou igual a posicao final(h)*/
    if (l >= h) {
        return numComp;
    }

    /*Se o primeiro elemento e menor
    que o ultimo, trocar eles*/
    numComp++;
    if(A[l] > A[h]) {
        int temp = A[l];
        A[l] = A[h];
        A[h] = temp;
    }

    /*Se ha mais de dois elementos
    dentro do array*/
    if(h - l + 1 > 2) {
        int temp = (h - l + 1) / 3;

        /*recursivamente, sort os primeiros
        2/3 elementos*/
        stoogeSort(A, l, h - temp,numComp);

        /*recursivamente, sort os ultimos
        2/3 elementos*/
        stoogeSort(A, l + temp, h,numComp);

        /*recursivamente, sort os primeiros
        2/3 elementos novamente para confirmar*/
        stoogeSort(A, l, h - temp,numComp);
    }
}

//---------------------------------------------------------

