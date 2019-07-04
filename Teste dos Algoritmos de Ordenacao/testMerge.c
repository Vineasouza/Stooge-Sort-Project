#include <stdio.h>
#include <stdlib.h>
#define N 6

void print(int *A, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf(" %i ", A[i]);
    }
    printf("]");
    printf("\n\n");
}

/*Funcao que implementa o mergeSort*/
void merge(int arr[], int l, int m, int r) {
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
        R[j] = arr[m + 1 + j];
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
void mergeSort(int arr[], int l, int r)
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

int main(int argc, char const *argv[]) {
    int A[] = {1,7,3,8,5,2,9};
    int n = sizeof(A)/4;

    print(A,N);

    mergeSort(A,0,N);

    print(A,N);

    return 0;
}
