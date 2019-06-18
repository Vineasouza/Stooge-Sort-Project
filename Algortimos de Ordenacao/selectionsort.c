/* Funcao que implementa o Selection Sort */
void selectionSort(int *vetor, int tamanho) {
    int i, j, min;

    for (i = 0; i < tamanho - 1; i++) {
        min = i;
        for (j = i + 1; j < tamanho; j++)
            if (vetor[j] < vetor[min])
                min = j;

        trocar(&vetor[i], &vetor[min]);
    }
}

/* Funcao auxiliar do Selection Sort */
void trocar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}