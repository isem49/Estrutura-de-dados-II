#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int low, int high, int pivo_indice) {
    int pivot = arr[pivo_indice];
    swap(&arr[pivo_indice], &arr[high]); // Move o pivô para o final
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Escolha do pivô:
        // int pivo_indice = low; // Primeiro elemento
        // int pivo_indice = high; // Último elemento
        int pivo_indice = low + (high - low) / 2; // Elemento do meio

        int pi = particionar(arr, low, high, pivo_indice);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Array não ordenado: \n");
    printArray(data, n);

    quickSort(data, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(data, n);

    return 0;
}