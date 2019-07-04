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
