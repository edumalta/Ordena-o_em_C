#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar o heapify (manter a propriedade do heap)
void heapify(int arr[], int n, int i) {
    int maior = i; // Inicializa o maior como raiz
    int esq = 2 * i + 1; // Filho esquerdo
    int dir = 2 * i + 2; // Filho direito

    // Se o filho esquerdo for maior que a raiz
    if (esq < n && arr[esq] > arr[maior]) {
        maior = esq;
    }

    // Se o filho direito for maior que o maior até agora
    if (dir < n && arr[dir] > arr[maior]) {
        maior = dir;
    }

    // Se o maior não for a raiz, troque e continue heapificando
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        // Recursivamente heapifique a subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função para realizar o Heap Sort
void heapSort(int arr[], int n) {
    // Construa um heap máximo (reorganize o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Um a um, extraímos os elementos do heap
    for (int i = n - 1; i >= 1; i--) {
        // Troca a raiz (máximo) com o último elemento
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapifica a raiz
        heapify(arr, i, 0);
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

        // Medindo o tempo de execução do Heap Sort
        clock_t inicio, fim;
        double tempo_cpu;
        
        inicio = clock(); // Início da medição do tempo
        heapSort(arr, n); // Chamando o algoritmo de ordenação
        fim = clock(); // Fim da medição do tempo
        
        // Calcula o tempo de execução em segundos
        tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        
        printf("Tempo de execução do Heap Sort para %d elementos: %f segundos\n", n, tempo_cpu);
    }

    return 0;
}
