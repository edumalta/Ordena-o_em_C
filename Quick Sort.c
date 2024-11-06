#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para particionar o array para o Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // O último elemento é o pivô
    int i = low - 1; // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // Se o elemento atual for menor ou igual ao pivô
            i++;
            // Troca arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Troca o pivô com o elemento em arr[i + 1]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Função recursiva do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array
        int pi = partition(arr, low, high);

        // Ordena as duas metades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

        // Medindo o tempo de execução do Quick Sort
        clock_t inicio, fim;
        double tempo_cpu;
        
        inicio = clock(); // Início da medição do tempo
        quickSort(arr, 0, n - 1); // Chamando o algoritmo de ordenação
        fim = clock(); // Fim da medição do tempo
        
        // Calcula o tempo de execução em segundos
        tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        
        printf("Tempo de execução do Quick Sort para %d elementos: %f segundos\n", n, tempo_cpu);
    }

    return 0;
}
