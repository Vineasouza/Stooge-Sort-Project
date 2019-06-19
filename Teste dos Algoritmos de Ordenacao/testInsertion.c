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

void insertionSort(int *A, int n) {
    int i, j, chave;
    for(i = 0; i < n; i++){
        /*atribui o elemento da primeira posicao a chave*/
        chave = A[i];
        j = i - 1;

        /*move os elementos do array que sao maiores que a
        chave para uma posicao a mais da atual*/
        while(j >= 0 && A[j] > chave) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = chave;
    }
}

int main(int argc, char const *argv[]) {
    int A[] = {1,7,3,8,5,2,9};

    print(A,N);

    insertionSort(A,N);

    print(A,N);
    return 0;
}
