#include <stdio.h>
#include <stdlib.h>
#include "algoritmosordenacao.h"

int main(int argc, char const *argv[]) {

    int vetor[] = {10,3,5,9,7};
    int n = sizeof(vetor)/4;

    quickSort(vetor,0,n);

    printf("OLA");

    return 0;
}
