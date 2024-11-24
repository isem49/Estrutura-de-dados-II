#include <stdio.h>

// Função para encontrar o valor máximo no array
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Função Counting Sort para ordenação crescente
void countingSortAsc(int array[], int n, int place) {
    int output[n];
    int count[10] = {0};

    // Conta a ocorrência de cada dígito na posição atual
    for (int i = 0; i < n; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }

    // Converte contagem para posição cumulativa para ordenar em ordem crescente
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída colocando os elementos na ordem crescente
    for (int i = n - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    // Copia os elementos ordenados de volta ao array original
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

// Função Counting Sort para ordenação decrescente
void countingSortDesc(int array[], int n, int place) {
    int output[n];
    int count[10] = {0};

    // Conta a ocorrência de cada dígito na posição atual
    for (int i = 0; i < n; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }

    // Converte contagem para posição cumulativa invertida para ordenar em ordem decrescente
    for (int i = 8; i >= 0; i--) {
        count[i] += count[i + 1];
    }

    // Constrói o array de saída colocando os elementos na ordem decrescente
    for (int i = n - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    // Copia os elementos ordenados de volta ao array original
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

// Função principal para Radix Sort em ordem crescente
void radixSortAsc(int array[], int n) {
    int maxElement = getMax(array, n);

    // Aplica Counting Sort para cada dígito, começando da unidade
    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSortAsc(array, n, place);
    }
}

// Função principal para Radix Sort em ordem decrescente
void radixSortDesc(int array[], int n) {
    int maxElement = getMax(array, n);

    // Aplica Counting Sort para cada dígito, começando da unidade
    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSortDesc(array, n, place);
    }
}

int main() {
    int data[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(data) / sizeof(data[0]);

    // Ordenação em ordem crescente
    printf("Array ordenado em ordem crescente:\n");
    radixSortAsc(data, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Redefine o array para a ordenação decrescente
    int dataDesc[] = {121, 432, 564, 23, 1, 45, 788};

    // Ordenação em ordem decrescente
    printf("Array ordenado em ordem decrescente:\n");
    radixSortDesc(dataDesc, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", dataDesc[i]);
    }
    printf("\n");

    return 0;
}