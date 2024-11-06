#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função Selection Sort
// Ordena o array usando o método de ordenação por seleção
void selectionSort(int arr[], int n) {
    // Percorre o array até o penúltimo elemento
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Define o índice do menor elemento como o índice atual
        // Busca o menor elemento no restante do array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Atualiza o índice do menor elemento
            }
        }
        // Troca o menor elemento encontrado com o elemento na posição i
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Função para preencher o array com números aleatórios
// Gera números aleatórios entre 0 e 999 para preencher o array
void preencherVetorAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Gera números aleatórios de 0 a 999
    }
}

int main() {
    // Define os diferentes tamanhos de arrays a serem testados
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]); // Calcula o número de tamanhos

    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));

    // Loop para realizar os testes para cada tamanho de array
    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i]; // Define o tamanho atual do array
        int arr[n]; // Declara o array com o tamanho atual

        // Preenche o array com números aleatórios
        preencherVetorAleatorio(arr, n);

        // Variáveis para medir o tempo de execução do Selection Sort
        clock_t inicio, fim;
        double tempo_cpu;
        
        // Início da medição do tempo
        inicio = clock();
        
        // Chama a função de ordenação por seleção
        selectionSort(arr, n);
        
        // Fim da medição do tempo
        fim = clock();
        
        // Calcula o tempo de execução em segundos
        tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        
        // Exibe o tempo de execução para o tamanho atual do array
        printf("Tempo de execução do Selection Sort para %d elementos: %f segundos\n", n, tempo_cpu);
    }

    return 0; // Indica que o programa terminou com sucesso
}
