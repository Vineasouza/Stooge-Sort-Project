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
