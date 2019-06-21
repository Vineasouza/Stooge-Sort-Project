#include <stdio.h>
#include <stdlib.h>
#include "algoritmosordenacao.h"

int main(int argc, char const *argv[]) {

    int vetor[] = {10,3,5,9,7};
    int n = 5;
    int dados;
    int op;
    FILE *arquivo_dados;

    //ARQUIVO QUE RECEBE OS DtesADOS 
    arquivo_dados =fopen("Exemplo.csv","a");

    
    
    /* 
    dados = selectionSort(vetor,n);
    printf("%d, ", dados);

    dados = shellSort(vetor,n);
    printf("%d, ", dados);

    dados = insertionSort(vetor,n);
    printf("%d, ", dados);

    dados = bubbleSort(vetor,n);
    printf("%d, ", dados);

    dados = quickSort(vetor,0,5,0);
    printf("%d, ", dados);

    dados = mergeSort(vetor,0,5,0);
    printf("%d, ", dados);

    dados = stoogeSort(vetor,0,5,0);
    printf("%d.", dados);
    */

    dados = insertionSort(vetor,n);
    fprintf(arquivo_dados,"%d;",dados);

    dados = selectionSort(vetor,n);
    fprintf(arquivo_dados,"%d;",dados);

    dados = mergeSort(vetor,0,5,0);
    fprintf(arquivo_dados,"%d;",dados);
    
    dados = bubbleSort(vetor,n);
    fprintf(arquivo_dados,"%d;",dados);

    dados = shellSort(vetor,n);
    fprintf(arquivo_dados,"%d;",dados);

    dados = quickSort(vetor,0,5,0);
    fprintf(arquivo_dados,"%d;",dados);

    dados = stoogeSort(vetor,0,5,0);
    fprintf(arquivo_dados,"%d",dados);
    
    fclose(arquivo_dados);


    return 0;
}
