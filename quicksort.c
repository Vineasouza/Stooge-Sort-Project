/*Funcao que troca os elementos*/
void swap(int*a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*Funcao que pega o ultimo elemento como pivot,
coloca o elemento pivot na posicao correta no
array sorted, e coloca todos os menores que o pivot
para a esquerda do pivot e todos os maiores a
direita do pivot*/

int partition (int* A, int low, int high) {
    int pivot = A[high];
    /*index do menor elemento*/
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {

        /*se o elemento atual e menor ou igual ao pivot*/
        if(A[j] <= pivot) {
            /*incrementa o index do menor elemento*/
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i+1], &A[high]);
    return (i+1);
}

/*funcao que implementa o quickSort, sendo low
o index inicial e high o index final*/

void quickSort(int* A, int low, int high) {

    if(low < high) {

        /*pi e a particao do index, A[p] e agora
        o lugar certo*/
        int pi = partition(A, low, high);

        /*separadamente sort os elementos antes de
        particionar e depois de particionar*/
        quickSort(A, low, pi-1);
        quickSort(A, pi+1, high);
    }
}
