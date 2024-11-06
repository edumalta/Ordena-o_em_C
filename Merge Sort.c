#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mesclar duas metades do vetor
void merge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge(arr, left, mid); // Ordena a primeira metade
        merge(arr, mid + 1, right); // Ordena a segunda metade

        // Mescla as duas metades
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        // Copia os dados para os arrays temporários L[] e R[]
        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        // Mescla os arrays temporários de volta no vetor original
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copia os elementos restantes de L[], se houver
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copia os elementos restantes de R[], se houver
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
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

        // Medindo o tempo de execução do Merge Sort
        clock_t inicio, fim;
        double tempo_cpu;
        
        inicio = clock(); // Início da medição do tempo
        merge(arr, 0, n - 1); // Chamando o algoritmo de ordenação
        fim = clock(); // Fim da medição do tempo
        
        // Calcula o tempo de execução em segundos
        tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        
        printf("Tempo de execução do Merge Sort para %d elementos: %f segundos\n", n, tempo_cpu);
    }

    return 0;
}
