#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50

int gerarGap(int tam_vetor){
    int gap = (tam_vetor * 10)/13;
    return gap;
}

void gerarAleatorio(long int * vetor, long int n){
    long int i;
    for(i=0; i< n; i++){
        vetor[i] = ( rand() % n) * ( rand() % n) + 1;
    }
}

void swap(long int *v, int i){            
    int aux = v[i];
    v[i] = v[i+1];
    v[i+1] = aux;
}

void bubbleSort(long int *vetor, long int tam_vetor) {
    int i, j, atual;
    int troca = 1;
    int gap = tam_vetor;
    int qtd_trocas = 0;
    while (troca && (gap > 1)){
        troca = 0;
        gap = gerarGap(gap);
        for (i = 0; i < tam_vetor - gap; i++){ 
            atual = vetor[i];
            if (atual > vetor[i + 1]){
                swap(vetor, i);
                troca = 1;
                qtd_trocas++;
            }
        }    
    }
    printf("Trocas: %d", qtd_trocas);
}

int main(){

    srand( (unsigned) time(NULL) );

    long int vetor[TAM];
    long int tamanho_vetor = TAM;
    gerarAleatorio(vetor, tamanho_vetor);

    bubbleSort(vetor, tamanho_vetor);


    return 0;

}