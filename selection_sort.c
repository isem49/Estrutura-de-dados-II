#include <stdio.h>

// Função para trocar dois elementos de lugar
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função Selection Sort
void selection_sort(int lista[], int tamanho) {
    // Passa por cada posição da lista
    for (int i = 0; i < tamanho - 1; i++) {
        int indice_minimo = i;
        
        // Encontra o menor elemento na lista não ordenada
        for (int j = i + 1; j < tamanho; j++) {
            if (lista[j] < lista[indice_minimo]) {
                indice_minimo = j;
            }
        }

        // Troca o elemento encontrado com o primeiro elemento não ordenado
        if (indice_minimo != i) {
            trocar(&lista[i], &lista[indice_minimo]);
        }

        // Exibe a lista após cada iteração
        printf("Passo %d: ", i + 1);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", lista[k]);
        }
        printf("\n");
    }
}

int main() {
    int lista[] = {64, 25, 12, 22, 11};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Lista original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n\n");

    // Ordena a lista e acompanha as iterações
    selection_sort(lista, tamanho);

    printf("\nLista ordenada:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    return 0;
}
