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

    *numTroca = *numTroca + 1;
    swap(&A[i+1], &A[high]);
    return (i+1);
}

/*funcao que implementa o quickSort, sendo low
o index inicial e high o index final*/

void quickSort(int* A, int low, int high, int *numComp, int* numTroca) {
    
    if(low < high) {

        /*pi e a particao do index, A[p] e agora
        o lugar certo*/
        *numComp= *numComp + 1;
        int pi = partition(A, low, high, numComp, numTroca);
        /*separadamente sort os elementos antes de
        particionar e depois de particionar*/
        quickSort(A, low, pi-1,numComp,numTroca);
        quickSort(A, pi+1, high,numComp,numTroca);
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
void mergeSort(int *arr, int l, int r, int* numComp, int* numTroca)
{
    if (l < r) {
        /* O mesmo que (l+r)/2, mas evita overflow de l grande e h*/
        int m = l+(r-l)/2;

        /*Sort primeira e segunda metade */
        mergeSort(arr, l, m, numComp, numTroca);
        mergeSort(arr, m+1, r, numComp, numTroca);

       merge(arr, l, m, r, numComp, numTroca);
    }

}

//-------------------- ShellSort -----------

void shellSort(int* A, int n, int *numComp, int*numTrocas) {
    int h = 1, i = 0, j = 0, chave = 0, k = 1;
    
    
    do{
        h = (h*3) + 1;
    } while(h < n);

    do{
        h = h/3;

        for(i = h; i < n; i++) {
            chave = A[i];
            j = i - h;

            *numComp = *numComp + 1;
            while(j >= 0 && chave < A[j]) {
                *numTrocas = *numTrocas + 1;
                A[j + h] = A[j];
                j = j - h;
            }

            *numTrocas = *numTrocas + 1;
            A[j + h] = chave;
        }
    } while (h > 1);


}

//--------------------------------------------------------------

//-------------- Bubble Sort ---------------------------------


/**
 * Implementacao do algoritmo de ordenacao Bubble Sort
 * Este algoritmo trabalha com a ideia de passagens, ou passes, 
 * que eh simplemente o que ocorre quando escaneamos um vetor da esq para dir
 * Para cada 1 pass, o algortimo empurra para a direita o maior elemento do vetor
 * Este algoritmo foi otimizado atraves de uma variavel flag e, para cada pass,
 * pode-se notar que ele nao percorre a parte que ja esta ordenada do vetor
 * Tudo isso ajuda a diminuir os passos computacionais do algortimo
 */




void bubbleSort(int *arr, int n, int*numCom, int*numTroca) { 
    int i, k, flag;

    // garante que serao feitas n passagens (n passes) e o vetor sera ordenado corretamente
    for (k = 0; k < n; k++) {
        flag = 0;
        // faz uma passagem (1 pass) pelo subvetor
        // vai de 0 ate n-k-1 pois assim garantimos que ele nao ira perder tempo com a parte do vetor que ja esta ordenado 
        for (i = 0; i < n-k-1; i++) {
            *numCom = *numCom + 1;  
            if (arr[i] > arr[i+1]) {
                *numTroca = *numTroca + 1;
                swap(&arr[i], &arr[i+1]);
                flag = 1;
            }
        }

        // A fim de otimizar ainda mais o codigo, add uma variavel flag,
        // se ao final de 1 pass, ou 1 passagem ele ainda valer 0, eh porque
        // ao fazer o pass, nao foi feita nenhuma TROCA, se nao foi feita nenhuma troca,
        // quer dizer que nao eh necessario mais fazer mais loops (ou passagens)
        if (flag == 0) break;
    }
} 
//------------------------------------------------------------------------

//--------------------- Insertion Sort --------------------------------------

void insertionSort(int *vetor, int tamanho, int* numComp, int* numTrocas) {
    int i, j, k;
    
    for (i = 1; i < tamanho; ++i) {
        k = vetor[i];
        j = i - 1;
        
        *numComp = *numComp  + 1;
        while ((j >= 0) && (k < vetor[j])) {
            *numTrocas = *numTrocas + 1;
            vetor[j + 1] = vetor[j];
            --j;
        }
        *numTrocas = *numTrocas + 1;
        vetor[j + 1] = k;
    }

  
}

//---------------------------------------------------------



//---------------- SelectionSort -------------------------------
/**
 * Funcao auxiliar da funcao principal utilizada 
 * para trocar dois valores entre si
 */
void trocando(int *xp, int *yp) {
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/**
 * O algoritmo Selection Sort baseia-se na ideia
 * de encontrar o menor elemento do array e coloca-lo na primeira posicao,
 * depois na segunda, terceira, etc. Tambem se trabalha a ideia de sub-array,
 * onde e criado um sub-array para cada iteracao do loop interno, em que se busca
 * encontrar o menor elemento do sub-array */
void selectionSort(int *arr, int n, int *numComp, int *numTrocas) {
    int i, j, min_idx;

    // Mover um por um o limite do sub-array desordenado
    for (i = 0; i < n - 1; i++) {
        // Encontrar o menor elemento do array desordenado
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            *numComp = *numComp + 1;

            if (arr[j] < arr[min_idx]) {
                *numTrocas = *numTrocas + 1;
                min_idx = j;
            }
        }

        // Trocar o menor elemento encontrado pelo primeiro elemento
        trocando(&arr[min_idx], &arr[i]);
    }
}

//------------------------------------------------------------------------

//------------------- StoogeSort----------------------------------------

void stoogeSort(int *A, int l, int h, int *numComp, int* numTroca) {
    /*Se a posicao inicial(l) for maior
    ou igual a posicao final(h)*/
    if (l >= h) {
        return;
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
        stoogeSort(A, l, h - temp,numComp,numTroca);

        /*recursivamente, sort os ultimos
        2/3 elementos*/
        stoogeSort(A, l + temp, h,numComp,numTroca);

        /*recursivamente, sort os primeiros
        2/3 elementos novamente para confirmar*/
        stoogeSort(A, l, h - temp,numComp,numTroca);
    }
}

//---------------------------------------------------------

