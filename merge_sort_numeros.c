#include <stdio.h>

// Função para combinar duas sublistas ordenadas
void merge(int lista[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    // Criar listas temporárias
    int esquerda_temp[n1], direita_temp[n2];
    
    // Copiar os dados para as listas temporárias
    for (int i = 0; i < n1; i++)
        esquerda_temp[i] = lista[esquerda + i];
    for (int j = 0; j < n2; j++)
        direita_temp[j] = lista[meio + 1 + j];
    
    int i = 0, j = 0, k = esquerda;
    
    // Combina as duas sublistas temporárias
    while (i < n1 && j < n2) {
        if (esquerda_temp[i] <= direita_temp[j]) {
            lista[k] = esquerda_temp[i];
            i++;
        } else {
            lista[k] = direita_temp[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes, se houver algum
    while (i < n1) {
        lista[k] = esquerda_temp[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        lista[k] = direita_temp[j];
        j++;
        k++;
    }
}

// Função principal de ordenação Merge Sort
void merge_sort(int lista[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Ordena as duas metades
        merge_sort(lista, esquerda, meio);
        merge_sort(lista, meio + 1, direita);
        
        // Combina as duas metades ordenadas
        merge(lista, esquerda, meio, direita);
    }
}

int main() {
    int lista[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    
    merge_sort(lista, 0, tamanho - 1);
    
    printf("Lista ordenada: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    return 0;
}
