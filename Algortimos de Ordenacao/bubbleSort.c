/* Funcao que implementa o Bubble Sort */
void bubbleSort(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < (tamanho - 1); i++)
        for (j = 0; j < (tamanho - (i + 1)); j++)
            if (vetor[j] > vetor[j + 1])
                trocar(&vetor[j], &vetor[j + 1]);
}

/* Funcao auxiliar do Bubble Sort */
void trocar(int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}