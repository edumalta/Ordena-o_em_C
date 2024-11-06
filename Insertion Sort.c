#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move os elementos do arr[0..i-1] que são maiores que a chave para uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para preencher o array com números aleatórios
void preencherVetorAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Números entre 0 e 999 para simplificar
    }
}

int main() {
    // Definindo os tamanhos dos arrays a serem testados
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    // Semente para gerar números aleatórios
    srand(time(NULL));

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        int arr[n];
        
        // Preenche o vetor com números aleatórios
        preencherVetorAleatorio(arr, n);

        // Medindo o tempo de execução do Insertion Sort
        clock_t inicio, fim;
        double tempo_cpu;
        
        inicio = clock(); // Início da medição do tempo
        insertionSort(arr, n); // Chamando o algoritmo de ordenação
        fim = clock(); // Fim da medição do tempo
        
        // Calcula o tempo de execução em segundos
        tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        
        printf("Tempo de execução do Insertion Sort para %d elementos: %f segundos\n", n, tempo_cpu);
    }

    return 0;
}