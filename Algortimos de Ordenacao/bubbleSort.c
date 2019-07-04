/**
 * Funcao auxiliar do algoritmo Bubble Sort,
 * responsavel pela entre dois elementos do vetor
 */
void swap(int *xp, int *yp) {
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/**
 * Implementacao do algoritmo de ordenacao Bubble Sort
 * Este algoritmo trabalha com a ideia de passagens, ou passes, 
 * que eh simplemente o que ocorre quando escaneamos um vetor da esq para dir
 * Para cada 1 pass, o algortimo empurra para a direita o maior elemento do vetor
 * Este algoritmo foi otimizado atraves de uma variavel flag e, para cada pass,
 * pode-se notar que ele nao percorre a parte que ja esta ordenada do vetor
 * Tudo isso ajuda a diminuir os passos computacionais do algortimo
 */


void bubbleSort(int arr[], int n) { 
    int i, k, flag;

    // garante que serao feitas n passagens (n passes) e o vetor sera ordenado corretamente
    for (k = 0; k < n; k++) {
        flag = 0;
        // faz uma passagem (1 pass) pelo subvetor
        // vai de 0 ate n-k-1 pois assim garantimos que ele nao ira perder tempo com a parte do vetor que ja esta ordenado 
        for (i = 0; i < n-k-1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                flag = 1;
            }
        }

        // A fim de otimizar ainda mais o codigo, add uma variavel flag,
        // se ao final de 1 pass, ou 1 passagem ele ainda valer 0, eh porque
        // ao fazer o pass, nao foi feita nenhuma TROCA, se nao foi feita nenhuma troca,
        // quer dizer que nao eh necessario mais fazer mais loops (ou passagens)
        if (flag == 0) break;
    }
} 