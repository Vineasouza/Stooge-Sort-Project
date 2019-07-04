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

/*Funcao que troca os elementos*/
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*Funcao que implementa o selectionSort*/
void selectionSort(int *A, int n) {
    int i, j, menor;

    /*um a um move o limite do array nao ordenado */
    for(i = 0; i < n-1; i++) {

        /*encontra o menor elemento do array nao ordenado*/
        menor = i;
        for(j = i + 1; j < n; j++) {
            if(A[j] < A[menor]) {
                menor = j;
            }
        }

        /*troca o menor elemento encontrado
        com o primeiro elemento*/
        swap(&A[menor], &A[i]);
    }
}

int main(int argc, char const *argv[]) {
    int A[] = {1,7,3,8,5,2,9};
    int n = sizeof(A)/4;

    print(A,N);

    selectionSort(A,N);

    print(A,N);

    return 0;
}
