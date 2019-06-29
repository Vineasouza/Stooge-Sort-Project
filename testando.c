#include <stdio.h>
#include <stdlib.h>
#include "algoritmosordenacao.h"

int main(int argc, char const *argv[]) {

    int vetor[] = {10,3,5,9,7};
    int n = 5;
    int dados;
    
    FILE *arquivo_dados;
    FILE *arquivoVetor;
    //ARQUIVO QUE RECEBE OS DtesADOS 
    arquivo_dados =fopen("dadosComparacao.csv","w");
    arquivoVetor = fopen("vetor.csv", "r");
    
    //>>>>> LENDO ARQUIVO ONDE ESTÁ O VETOR
 
    int *vet;
    int quantidade = 0;
    int inteiro = 0;
    
    while (!feof(arquivoVetor))
    {

        fscanf(arquivoVetor,"%d,",&inteiro);
        quantidade++;
        
        if(quantidade == 1){
            vet = (int*) malloc(sizeof(int)*quantidade);
        }else{
            vet = (int*)realloc(vet,sizeof(int)*quantidade);
        }

        vet[quantidade - 1] = inteiro;

    
    }

    fclose(arquivoVetor);
    //-----------------------------------------------

    //TESTE PARA VER SE O VETOR DEU CERTO
    printf("tamanho vetor >> %d \n", quantidade);
    for(int i = 0; i<quantidade; i++){
        printf("|%d| ", vet[i]);
    }
    
   
    //TESTANDO EM RALAÇÃO AO NÚMERO DE COMPARAÇÕES
    int numeroCom = 0;
    int *ponteiroNumComp;
    ponteiroNumComp = &numeroCom;
    int numTroca = 0;
    int *ponteiroNumTroca;
    ponteiroNumTroca = &numTroca;

    // SE COND = 0 retorna número de comparações, SE COND = 1 retorna número de trocas
    
    dados = selectionSort(vet,quantidade - 1,0);
    printf("%d, ", dados);

    dados = shellSort(vet,quantidade - 1,0);
    printf("%d, ", dados);

    dados = insertionSort(vet,quantidade - 1,0);
    printf("%d, ", dados);

    dados = bubbleSort(vet,quantidade - 1,0);
    printf("%d, ", dados);

    dados = quickSort(vet,0,quantidade - 1, ponteiroNumComp, ponteiroNumTroca,0);
    printf("%d, ", dados);
    numeroCom = 0;
    numTroca = 0;

    dados = mergeSort(vet,0,quantidade - 1,ponteiroNumComp, ponteiroNumTroca, 0);
    printf("%d, ", dados);
    numeroCom = 0;
    numTroca = 0;

    dados = stoogeSort(vet,0,quantidade - 1,ponteiroNumComp,ponteiroNumTroca,0);
    printf("%d.", dados);
    numeroCom = 0;
    numTroca = 0;
    
    //TESTANDO EM RELAÇÃO AO NÚMERO DE TROCAS
    
    
    dados = selectionSort(vet,quantidade - 1,1);
    printf("\n %d, ", dados);

    dados = shellSort(vet,quantidade - 1,1);
    printf("%d, ", dados);

    dados = insertionSort(vet,quantidade - 1,1);
    printf("%d, ", dados);

    dados = bubbleSort(vet,quantidade - 1,1);
    printf("%d, ", dados);

    dados = quickSort(vet,0,quantidade - 1, ponteiroNumComp, ponteiroNumTroca,1);
    printf("%d, ", dados);
    numeroCom = 0;
    numTroca = 0;

    dados = mergeSort(vet,0,quantidade - 1,ponteiroNumComp, ponteiroNumTroca, 1);
    printf("%d, ", dados);
    numeroCom = 0;
    numTroca = 0;

    dados = stoogeSort(vet,0,quantidade - 1,ponteiroNumComp,ponteiroNumTroca,1);
    printf("%d.", dados);
    numeroCom = 0;
    numTroca = 0;


    //GRAVANDO DADOS

    dados = insertionSort(vet,(quantidade - 1),0);
    fprintf(arquivo_dados,"%d;",dados);

    dados = selectionSort(vet,(quantidade - 1),0);
    fprintf(arquivo_dados,"%d;",dados);

    dados = mergeSort(vet,0,(quantidade - 1),ponteiroNumComp,ponteiroNumTroca,0);
    fprintf(arquivo_dados,"%d;",dados);
    numeroCom = 0;
    numTroca = 0;

    dados = bubbleSort(vet,(quantidade - 1),0);
    fprintf(arquivo_dados,"%d;",dados);

    dados = shellSort(vetor,(quantidade - 1),0);
    fprintf(arquivo_dados,"%d;",dados);

    dados = quickSort(vetor,0,(quantidade - 1),ponteiroNumComp,ponteiroNumTroca,0);
    fprintf(arquivo_dados,"%d;",dados);
    numeroCom = 0;
    numTroca = 0;

    dados = stoogeSort(vetor,0,(quantidade - 1),ponteiroNumComp,ponteiroNumTroca,0);
    fprintf(arquivo_dados,"%d",dados);
    numeroCom = 0;
    numTroca = 0;

    fputs("Ta gravando", arquivo_dados);

    fclose(arquivo_dados);
    
    //Desalocando memória
    free(vet);

    return 0;
}
