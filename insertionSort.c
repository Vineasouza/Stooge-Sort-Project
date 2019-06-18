/* Funcao que implementa o Insertion Sort */
void insertionSort(int *vetor, int tamanho) {
    int i, j, k;
    
    for (i = 1; i < tamanho; ++i) {
        k = vetor[i];
        j = i - 1;

        while ((j >= 0) && (k < vetor[j])) {
            vetor[j + 1] = vetor[j];
            --j;
        }

        vetor[j + 1] = k;
    }
}