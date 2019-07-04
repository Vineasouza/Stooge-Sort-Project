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

void bubbleSort(int *A, int n) {
    int i, j, tmp;

    for(i = 0; i < n; i++) {

        for(j = i+1; j< n; j++) {
            if(A[j] < A[i]) {
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int A[] = {1,7,3,8,5,2,9};

    print(A,N);

    bubbleSort(A,N);

    print(A,N);

    return 0;
}
