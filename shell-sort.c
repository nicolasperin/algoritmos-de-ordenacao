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

void shellSort(long int *vetor, long int tam_vetor) {
    int gap, i, j, atual;
    for (gap = tam_vetor/2; gap > 0; gap /= 2){
        for (i = gap; i < tam_vetor; i++){
            atual = vetor[i];
            j = i - 1;
            while ((j >=0) && (vetor[j] > atual)){
                vetor[j + 1] = vetor[j];
                j--; 
            }
            vetor[j + 1] = atual;
        }
    }
}

int main(){

    srand( (unsigned) time(NULL) );

    long int vetor[TAM];
    long int tamanho_vetor = TAM;
    gerarAleatorio(vetor, tamanho_vetor);

    shellSort(vetor, tamanho_vetor);

    printf("Vetor ordenado:\n");
    for(int i = 0; i < tamanho_vetor; i++){
        printf("%ld ", vetor[i]);
    }
    printf("\n");

    return 0;

}