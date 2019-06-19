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

/*Funcao que implementa o shellSort */
void shellSort(int* A, int n) {
    int h = 1, i = 0, j = 0, chave = 0, k = 1;

    do{
        h = (h*3) + 1;
    } while(h < n);

    do{
        h = h/3;

        for(i = h; i < n; i++) {
            chave = A[i];
            j = i - h;

            while(j >= 0 && chave < A[j]) {
                A[j + h] = A[j];
                j = j - h;
            }

            A[j + h] = chave;
        }
    } while (h > 1);
}

int main(int argc, char const *argv[]) {
    int A[] = {1,7,3,8,5,2,9};
    int n = sizeof(A)/4;

    print(A,N);

    shellSort(A,N);

    print(A,N);

    return 0;
}
