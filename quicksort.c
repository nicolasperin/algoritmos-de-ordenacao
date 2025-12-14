#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50

void gerarAleatorio(long int * vetor, long int n){
    long int i;
    for(i=0; i< n; i++){
        vetor[i] = ( rand() % n) * ( rand() % n) + 1;
    }
}

void swap(long int *v, int i, int j){            
    long int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(long int *vetor, long int ini, long int fim){
    int pivo = vetor[fim];
    int i = ini;
    for (int j = ini; j < fim; j++){
        if (vetor[j] <= pivo){
            swap(vetor, i, j);
            i++;
        }
    }
    swap(vetor, i, fim);
    return i;
}

void quickSort(long int *vetor, long int ini, long int fim) {
    int pivo;
    if (ini < fim){
        pivo = particao(vetor, ini, fim);
        quickSort(vetor, ini, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

int main(){

    srand( (unsigned) time(NULL) );

    long int vetor[TAM];
    long int tamanho_vetor = TAM;
    gerarAleatorio(vetor, tamanho_vetor);

    quickSort(vetor, 0, tamanho_vetor-1);

    for(int i = 0; i < tamanho_vetor; i++){
        printf("%ld ", vetor[i]);
    }
    printf("\n");

    return 0;

}