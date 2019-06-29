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

int partition (int* A, int low, int high, int *numComp, int *numTroca) {
    int pivot = A[high];
    /*index do menor elemento*/
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {

        /*se o elemento atual e menor ou igual ao pivot*/
        *numComp = *numComp + 1;
        if(A[j] <= pivot) {
            /*incrementa o index do menor elemento*/
            i++;
            *numTroca = *numTroca + 1;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i+1], &A[high]);
    return (i+1);
}

/*funcao que implementa o quickSort, sendo low
o index inicial e high o index final*/

int quickSort(int* A, int low, int high, int *numComp, int* numTroca,int condicao) {
    
    if(low < high) {

        /*pi e a particao do index, A[p] e agora
        o lugar certo*/
        int pi = partition(A, low, high, numComp, numTroca);
        /*separadamente sort os elementos antes de
        particionar e depois de particionar*/
        quickSort(A, low, pi-1,numComp,numTroca,condicao);
        quickSort(A, pi+1, high,numComp,numTroca,condicao);
    }
    
    //DEFININDO ATRÁVES DA CONDICAO PASSADA COM O RETORNO
    if(condicao == 0){
        int retorTotalComp = *numComp;
        return retorTotalComp;
    }else{
        int retornoTotalTroca = *numTroca;
        return retornoTotalTroca;
    }
 
}

//---------------------------------------------------------------------


// ----------------- MERGE SHORT ------------------------------------

/*Funcao que implementa o mergeSort*/
void merge(int *arr, int l, int m, int r, int* numComp, int* numTroca) {
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
        *numComp = *numComp + 1;

        if (L[i] <= R[j]) {
            *numTroca = *numTroca + 1;
            arr[k] = L[i];
            i++;
        } else {
            *numTroca = *numTroca + 1;
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
int mergeSort(int *arr, int l, int r, int* numComp, int* numTroca, int condicao)
{
    if (l < r) {
        /* O mesmo que (l+r)/2, mas evita overflow de l grande e h*/
        int m = l+(r-l)/2;

        /*Sort primeira e segunda metade */
        mergeSort(arr, l, m, numComp, numTroca, condicao);
        mergeSort(arr, m+1, r, numComp, numTroca, condicao);

       merge(arr, l, m, r, numComp, numTroca);
    }

    //DEFININDO RETORNO
    if(condicao == 0){
        return (*numComp);
    }else{
        return (*numTroca);
    }

}

//-------------------- ShellSort -----------

int shellSort(int* A, int n, int condicao) {
    int h = 1, i = 0, j = 0, chave = 0, k = 1;
    int numeroCom = 0;
    int numeroTroca = 0;
    do{
        h = (h*3) + 1;
    } while(h < n);

    do{
        h = h/3;

        for(i = h; i < n; i++) {
            chave = A[i];
            j = i - h;

            numeroCom++;
            while(j >= 0 && chave < A[j]) {
                numeroTroca++;
                A[j + h] = A[j];
                j = j - h;
            }

            numeroTroca++;
            A[j + h] = chave;
        }
    } while (h > 1);

    if(condicao == 0){
        return numeroCom;
    }else{
        return numeroTroca;
    }
  
}

//--------------------------------------------------------------

//-------------- Bubble Sort ---------------------------------
int bubbleSort(int *vetor, int tamanho, int condicao) {
    int i, j, numeroCom = 0, numeroTroca = 0;
    for (i = 0; i < (tamanho - 1); i++)
        for (j = 0; j < (tamanho - (i + 1)); j++)
            numeroCom++;
            if (vetor[j] > vetor[j + 1])
                numeroTroca++;
                trocar(&vetor[j], &vetor[j + 1]);
    
    if(condicao == 0){
        return numeroCom;
    }else{
        return numeroTroca;
    }

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


int insertionSort(int *vetor, int tamanho, int condicao) {
    int i, j, k, numeComp = 0, numeroTroca = 0;
    
    for (i = 1; i < tamanho; ++i) {
        k = vetor[i];
        j = i - 1;
        
        numeComp++;
        while ((j >= 0) && (k < vetor[j])) {
            numeroTroca++;
            vetor[j + 1] = vetor[j];
            --j;
        }
        numeroTroca++;
        vetor[j + 1] = k;
    }

    if(condicao == 0){
        return numeComp;
    }else{
        return numeroTroca;
    }
}

//---------------------------------------------------------



//---------------- SelectionSort -------------------------------

int selectionSort(int *vetor, int tamanho, int condicao) {
    int i, j, min;
    int numComp = 0;
    int numeroTroca = 0;
    for (i = 0; i < tamanho - 1; i++) {
        min = i;
        for (j = i + 1; j < tamanho; j++)
            numComp++;
            if (vetor[j] < vetor[min])
                min = j;

        numeroTroca++;
        trocar(&vetor[i], &vetor[min]);
    }

    if(condicao == 0){
        return numComp;
    }else{
        return numeroTroca;
    }
    
}

//------------------------------------------------------------------------

//------------------- StoogeSort----------------------------------------

int stoogeSort(int *A, int l, int h, int *numComp, int* numTroca, int condicao) {
    /*Se a posicao inicial(l) for maior
    ou igual a posicao final(h)*/
    if (l >= h) {
        if(condicao == 0){
            return (*numComp);
        }else{
            return(*numTroca);
        }
    }

    /*Se o primeiro elemento e menor
    que o ultimo, trocar eles*/
    *numComp = *numComp + 1;
    
    if(A[l] > A[h]) {
        *numTroca = *numTroca + 1;
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
        stoogeSort(A, l, h - temp,numComp,numTroca,condicao);

        /*recursivamente, sort os ultimos
        2/3 elementos*/
        stoogeSort(A, l + temp, h,numComp,numTroca,condicao);

        /*recursivamente, sort os primeiros
        2/3 elementos novamente para confirmar*/
        stoogeSort(A, l, h - temp,numComp,numTroca,condicao);
    }
}

//---------------------------------------------------------

