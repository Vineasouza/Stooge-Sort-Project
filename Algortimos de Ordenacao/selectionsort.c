/**
 * Funcao auxiliar da funcao principal utilizada 
 * para trocar dois valores entre si
 */
void swap(int *xp, int *yp) {
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/**
 * O algoritmo Selection Sort baseia-se na ideia
 * de encontrar o menor elemento do array e coloca-lo na primeira posicao,
 * depois na segunda, terceira, etc. Tambem se trabalha a ideia de sub-array,
 * onde e criado um sub-array para cada iteracao do loop interno, em que se busca
 * encontrar o menor elemento do sub-array 
 */ 
void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 

    // Mover um por um o limite do sub-array desordenado
    for (i = 0; i < n-1; i++) { 
        // Encontrar o menor elemento do array desordenado
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Trocar o menor elemento encontrado pelo primeiro elemento 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 