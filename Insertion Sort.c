#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função Insertion Sort
// Ordena o array usando o método de ordenação por inserção
void insertionSort(int arr[], int n) {
    // Percorre o array do segundo elemento até o final
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Guarda o elemento atual
        int j = i - 1;

        // Move os elementos de arr[0..i-1] que são maiores que a chave uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insere o elemento na posição correta
    }
}

// Função para preencher o array com números aleatórios
// Gera números aleatórios entre 0 e 999 para preencher o array
void preencherVetorAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Atribui ao array um número aleatório de 0 a 999
    }
}

int main() {
    // Define os diferentes tamanhos dos arrays a serem testados
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]); // Calcula o número de tamanhos

    // Inicializa a semente do gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Loop para realizar os testes para cada tamanho de array definido
    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i]; // Define o tamanho atual do array
        int arr[n]; // Declara o array com o tamanho atual
        
        // Preenche o array com números aleatórios
        preencherVetorAleatorio(arr, n);

        // Variáveis para medir o tempo de execução do Insertion Sort
        clock_t inicio, fim;
        double tempo_cpu;
        
        // Início da medição do tempo
        inicio = clock();
        
        // Chama a função de ordenação por inserção
        insertionSort(arr, n);
        
        // Fim da medição do tempo
        fim = clock();
        
        // Calcula o tempo de execução em segundos
        tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        
        // Exibe o tempo de execução para o tamanho atual do array
        printf("Tempo de execução do Insertion Sort para %d elementos: %f segundos\n", n, tempo_cpu);
    }

    return 0; // Indica que o programa terminou com sucesso
}
