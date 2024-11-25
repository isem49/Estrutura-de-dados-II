#include <stdio.h>
#include <string.h>

// Função para trocar duas palavras
void swap(char* a, char* b) {
    char temp[100];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Função para particionar o array de strings
int particionar(char arr[][100], int low, int high, int pivo_indice) {
    char pivot[100];
    strcpy(pivot, arr[pivo_indice]);
    swap(arr[pivo_indice], arr[high]); // Move o pivô para o final
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) { // Comparar as strings
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Função de ordenação Quick Sort
void quickSort(char arr[][100], int low, int high) {
    if (low < high) {
        int pivo_indice = low + (high - low) / 2; // Escolhe o elemento do meio
        int pi = particionar(arr, low, high, pivo_indice);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array de strings
void printArray(char arr[][100], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

// Função de busca binária
int binarySearch(char arr[][100], int low, int high, char* palavra) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = strcmp(arr[mid], palavra);

        if (res == 0) {
            return mid; // Palavra encontrada
        }
        if (res < 0) {
            low = mid + 1; // A palavra está na metade superior
        } else {
            high = mid - 1; // A palavra está na metade inferior
        }
    }
    return -1; // Palavra não encontrada
}

int main() {
    char palavras[][100] = {"laranja", "banana", "maca", "uva", "kiwi", "abacaxi"};
    int n = sizeof(palavras) / sizeof(palavras[0]);

    printf("Lista nao ordenada de palavras: \n");
    printArray(palavras, n);

    // Ordenando as palavras
    quickSort(palavras, 0, n - 1);

    printf("Lista ordenada de palavras: \n");
    printArray(palavras, n);

    // Exemplo de busca binária
    char palavraProcurada[] = "kiwi";
    int resultado = binarySearch(palavras, 0, n - 1, palavraProcurada);

    if (resultado != -1) {
        printf("Palavra '%s' encontrada na posicao %d.\n", palavraProcurada, resultado);
    } else {
        printf("Palavra '%s' nao encontrada.\n", palavraProcurada);
    }

    return 0;
}
