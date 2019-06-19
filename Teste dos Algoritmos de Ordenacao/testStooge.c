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

/*Funcao que implementa o  stoogeSort*/
void stoogeSort(int *A, int l, int h) {
    /*Se a posicao inicial(l) for maior
    ou igual a posicao final(h)*/
    if (l >= h) {
        return;
    }

    /*Se o primeiro elemento e menor
    que o ultimo, trocar eles*/
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
        stoogeSort(A, l, h - temp);

        /*recursivamente, sort os ultimos
        2/3 elementos*/
        stoogeSort(A, l + temp, h);

        /*recursivamente, sort os primeiros
        2/3 elementos novamente para confirmar*/
        stoogeSort(A, l, h - temp);
    }
}

int main(int argc, char const *argv[]) {
    int A[] = {1,7,3,8,5,2,9};
    int n = sizeof(A)/4;

    print(A,N);

    stoogeSort(A,0,N);

    print(A,N);

    return 0;
}
