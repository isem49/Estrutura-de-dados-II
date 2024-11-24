#include <stdio.h>
#include <stdlib.h>

// Função de Insertion Sort para ordenar os números dentro de cada balde
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// Função para realizar o Bucket Sort para números inteiros
void bucket_sort(int arr[], int n, int intervalo) {
    // Encontrar o valor máximo do array para definir a quantidade de baldes necessários
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calcular o número de baldes necessários
    int num_buckets = max_val / intervalo + 1;

    // Criar os baldes
    int **baldes = (int **)malloc(num_buckets * sizeof(int *));
    int *bucket_sizes = (int *)malloc(num_buckets * sizeof(int));

    for (int i = 0; i < num_buckets; i++) {
        baldes[i] = (int *)malloc(n * sizeof(int));  // Alocar memória para cada balde
        bucket_sizes[i] = 0;  // Inicializar o tamanho de cada balde como 0
    }

    // Distribuir os elementos nos baldes
    for (int i = 0; i < n; i++) {
        int idx = arr[i] / intervalo;  // Calcular o índice do balde
        baldes[idx][bucket_sizes[idx]++] = arr[i];  // Coloca o número no balde e aumenta o tamanho
    }

    // Ordenar cada balde usando Insertion Sort
    for (int i = 0; i < num_buckets; i++) {
        if (bucket_sizes[i] > 0) {
            insertion_sort(baldes[i], bucket_sizes[i]);
        }
    }

    // Reunir os baldes ordenados na lista original
    int idx = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[idx++] = baldes[i][j];  // Copia os elementos do balde de volta para o array original
        }
    }

    // Liberar a memória alocada para os baldes
    for (int i = 0; i < num_buckets; i++) {
        free(baldes[i]);
    }
    free(baldes);
    free(bucket_sizes);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Define o intervalo para os baldes (ex: intervalo de 10)
    bucket_sort(arr, n, 10);  // Chama a função de Bucket Sort

    printf("\nLista ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
