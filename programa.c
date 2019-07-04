#include <stdio.h>
#include <stdlib.h>
#include "algoritmosordenacao.h"

int main(int argc, char const *argv[]) {

    
    //PONTEIRO PARA ARQUIVOS 
    FILE *arquivo_dados;
    FILE *arquivoVetor;
    FILE *arquivo_trocas;

    /*PARAMETRO PASSADOS AS FUNÇÕES PARA RECEBER O NÚMERO 
      DE COMPARAÇÃO DO ALGORITMOS DE ORDENAÇÃO
    */
    int numeroComparacao = 0;
    int *pontNumComp;
    pontNumComp = &numeroComparacao;

     /*PARAMETRO PASSADOS AS FUNÇÕES PARA RECEBER O NÚMERO 
      DE TROCAS DO ALGORITMOS DE ORDENAÇÃO
    */
    int numeroDeTrocas = 0;
    int *pontNumTroca;
    pontNumTroca = &numeroDeTrocas;

    //ARQUIVO QUE RECEBE OS DADOS 
    arquivo_dados = fopen("dadosComparacao.csv","w");
    arquivo_trocas = fopen("dadosTrocas.csv", "w");
    
    //>>>>>         TESTANDO INSERTION        <<<<<<
    //>>>>> ---- LENDO ARQUIVO ONDE ESTÁ O VETOR -------
 
    int *vet;
    int quantidade = 0;
    int inteiro = 0;
    
    arquivoVetor = fopen("vetor.csv", "r");//ARQUIVO ONDE ESTÁ O VETOR DESORDENADO

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

    //TESTANDO INSERTION E JOGANDO DADOS NO ARQUIVO
    insertionSort(vet,quantidade - 1,pontNumComp,pontNumTroca);
    //printf("Número de trocas >> %d \n", numeroDeTrocas);
    //printf("Número de comparacao >> %d \n",numeroComparacao);
    
    //for(int j = 0; j< quantidade; j++){
        //printf("|%d|, ",vet[j]);
    //}
    
    fprintf(arquivo_dados,"%d;",numeroComparacao);
    fprintf(arquivo_trocas,"%d;",numeroDeTrocas);
    //TA ORDENANDO DE ACORDO COM OS TESTES

    //----------------------------------------------------------------------------

    //-----------> TESTANDO SELECTION <----------

    //PEGANDO VETOR DESORDENADO NOVAMENTE
    arquivoVetor = fopen("vetor.csv", "r");

    inteiro = 0;
    quantidade = 0;

    while (!feof(arquivoVetor))
    {
        
        fscanf(arquivoVetor,"%d,", &inteiro);
        quantidade++;
        vet[quantidade - 1] = inteiro;
 
    }
    
    fclose(arquivoVetor);

    //TESTANDO PARA VER SE PEGOU O VETOR DESORDENADO
    //for(int i = 0; i< quantidade; i++){
        //printf("|%d|, ",vet[i]);
    //}
    numeroComparacao = 0;
    numeroDeTrocas = 0;
    selectionSort(vet,quantidade - 1,pontNumComp,pontNumTroca);
    fprintf(arquivo_dados,"%d;", numeroComparacao);
    fprintf(arquivo_trocas,"%d;", numeroDeTrocas);

    //printf("Números de comparações >>> %d \n", numeroComparacao);
    //printf("Números de trocas >> %d \n", numeroDeTrocas);

    //TESTANDO PARA VER SE ORDENOU
    //for(int i = 0; i< quantidade; i++){
        //printf("|%d|, ",vet[i]);
    

    //ESTÁ ORDENANDO


//------------------------------------------------------------


//---------->>>     TESTANDO BUBLE SORT <<<< -----------------------------

    arquivoVetor = fopen("vetor.csv", "r");

    inteiro = 0;
    quantidade = 0;

    while (!feof(arquivoVetor))
    {
        
        fscanf(arquivoVetor,"%d,", &inteiro);
        quantidade++;
        vet[quantidade - 1] = inteiro;

    }
    
    fclose(arquivoVetor);

    /*  TESTE PARA VER SE PEGOU VETOR DESORDENADO 
    for(int i = 0; i<quantidade; i++){
        printf("|%d| ", vet[i]);
    }
    */
    
    numeroComparacao = 0;
    numeroDeTrocas = 0;

    bubbleSort(vet,quantidade - 1,pontNumComp,pontNumTroca);
    fprintf(arquivo_dados,"%d;",numeroComparacao);
    fprintf(arquivo_trocas,"%d;",numeroDeTrocas);
    
    //TESTE PARA VER SE O VETOR ORDENOU 
    /* for(int i = 0; i<quantidade; i++){
        printf("|%d| ", vet[i]);
    */

    

//--------------------------------------------------------------
   
//----------------->>> TESTANDO SHELLSORT <<---------------------

//PEGANDO VETOR DESORDENADO
 arquivoVetor = fopen("vetor.csv", "r");

    inteiro = 0;
    quantidade = 0;

    while (!feof(arquivoVetor))
    {
        
        fscanf(arquivoVetor,"%d,", &inteiro);
        quantidade++;
        vet[quantidade - 1] = inteiro;

    }
    
    fclose(arquivoVetor);

    /* for(int i = 0; i<quantidade; i++){
        printf("|%d|", vet[i]);
    }

    */

    numeroComparacao = 0;
    numeroDeTrocas = 0;

    shellSort(vet,quantidade - 1,pontNumComp,pontNumTroca);
    fprintf(arquivo_dados,"%d;",numeroComparacao);
    fprintf(arquivo_trocas,"%d;",numeroDeTrocas);
    
    //printf("Número de comparaçao >> %d \n", numeroComparacao);
    //printf("Número de trocas>> %d \n", numeroDeTrocas);

    //for(int i = 0; i<quantidade; i++){
        //printf("|%d|", vet[i]);
    //}
    

    //SHELL ESTÁ RODANDO

//----------------------------------------------------------------

//-------- >>> TESTANDO QUICKSORT <<< -----------------------------------

arquivoVetor = fopen("vetor.csv", "r");

    inteiro = 0;
    quantidade = 0;

    while (!feof(arquivoVetor))
    {
        
        fscanf(arquivoVetor,"%d,", &inteiro);
        quantidade++;
        vet[quantidade - 1] = inteiro;

    }
    
    fclose(arquivoVetor);

    /* TESTE PARA VER SE É VETOR DESORDENADO
    for(int i = 0; i<quantidade; i++){
        printf("|%d|", vet[i]);
    }
    */
   
    numeroComparacao = 0;
    numeroDeTrocas = 0;
    quickSort(vet,0,quantidade - 1,pontNumComp,pontNumTroca);
    fprintf(arquivo_dados,"%d;", *pontNumComp);
    fprintf(arquivo_trocas,"%d;", numeroDeTrocas);

    /* TESTE PARA VER SE ORDENOU

    for(int i = 0; i<quantidade; i++){
        printf("|%d|", vet[i]);
    }

    */
  

//------------------------------------------------------------------

//----------------->>>> TESTANDO MERGERSORT <<<-----------------------

arquivoVetor = fopen("vetor.csv", "r");

    inteiro = 0;
    quantidade = 0;

    while (!feof(arquivoVetor))
    {
        
        fscanf(arquivoVetor,"%d,", &inteiro);
        quantidade++;
        vet[quantidade - 1] = inteiro;

    }
    
    fclose(arquivoVetor);

    numeroComparacao = 0;
    numeroDeTrocas = 0;
    mergeSort(vet,0,quantidade - 1,pontNumComp,pontNumTroca);
    fprintf(arquivo_dados,"%d;",numeroComparacao);
    fprintf(arquivo_trocas,"%d;",numeroDeTrocas);
    /*
    for(int i = 0; i<quantidade; i++){
        printf("|%d| ", vet[i]);
    }

    */

//------------------------------------------------------------------------

//----------------->>> STOOGE SORT <<<-----------------------------------

arquivoVetor = fopen("vetor.csv", "r");

    inteiro = 0;
    quantidade = 0;

    while (!feof(arquivoVetor))
    {
        
        fscanf(arquivoVetor,"%d,", &inteiro);
        quantidade++;
        vet[quantidade - 1] = inteiro;

    }
    
    fclose(arquivoVetor);

    numeroComparacao = 0;
    numeroDeTrocas = 0;

    stoogeSort(vet,0,quantidade - 1,pontNumComp,pontNumTroca);
    fprintf(arquivo_dados,"%d", numeroComparacao);
    fprintf(arquivo_trocas,"%d",numeroDeTrocas);
   


    //stooge ta rodando
//----------------------------------------------------------------------

    //FECHANDO ARQUIVO ONDE CONTEM OS DADOS
    fclose(arquivo_dados);
    fclose(arquivo_trocas);

    //Desalocando memória
    free(vet);

    return 0;
}
