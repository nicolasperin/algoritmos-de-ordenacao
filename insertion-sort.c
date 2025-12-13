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

void insertionSort(long int *vetor, long int tam_vetor) {
    int i, j, atual;
    //int trocas = 0;
    for (i = 1; i < tam_vetor; i++){ // i = 1, pois no insertion sort, o primeiro elemento a ser ordenado é o elemento na segunda posição do array
        atual = vetor[i];
        j = i - 1;
        while ((j >= 0) && (vetor[j] > atual)){
            vetor[j + 1] = vetor[j];
            j--;
            //trocas++;
        }
        vetor[j + 1] = atual;
    }    
    //printf("Trocas: %d", trocas);
}

int main(){

    srand( (unsigned) time(NULL) );

    long int vetor[TAM];
    long int tamanho_vetor = TAM;
    gerarAleatorio(vetor, tamanho_vetor);

    insertionSort(vetor, tamanho_vetor);


    return 0;

}