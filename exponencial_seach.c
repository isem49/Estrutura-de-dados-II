#include <stdio.h>
#include <math.h>
#include <time.h>

// Função de Busca Binária
int busca_binaria(int lista[], int inicio, int fim, int valor) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista[meio] == valor) {
            return meio;
        } else if (lista[meio] > valor) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;  // Valor não encontrado
}

// Função de Exponential Search
int busca_exponencial(int lista[], int tamanho, int valor) {
    // Caso base: se o valor estiver na primeira posição
    if (lista[0] == valor) {
        return 0;
    }

    // Encontrando o intervalo que contém o valor
    int i = 1;
    while (i < tamanho && lista[i] <= valor) {
        i *= 2;  // Exponencialmente aumentamos o intervalo
    }

    // Fazendo a busca binária no intervalo encontrado
    return busca_binaria(lista, i / 2, fmin(i, tamanho - 1), valor);
}

// Função para comparar o tempo de execução
void comparar_tempos(int lista[], int tamanho, int valor) {
    clock_t inicio, fim;
    double tempo_binario, tempo_exponencial;

    // Tempo de execução do Binary Search
    inicio = clock();
    busca_binaria(lista, 0, tamanho - 1, valor);
    fim = clock();
    tempo_binario = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Tempo de execução do Exponential Search
    inicio = clock();
    busca_exponencial(lista, tamanho, valor);
    fim = clock();
    tempo_exponencial = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao do Binary Search: %f segundos\n", tempo_binario);
    printf("Tempo de execucao do Exponential Search: %f segundos\n", tempo_exponencial);
}

int main() {
    // Lista de exemplo ordenada
    int lista[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int valor_procurado = 10;

    // Busca de posição usando Exponential Search
    int posicao = busca_exponencial(lista, tamanho, valor_procurado);
    
    if (posicao != -1) {
        printf("O valor %d foi encontrado na posição %d.\n", valor_procurado, posicao);
    } else {
        printf("Valor %d não encontrado na lista.\n", valor_procurado);
    }

    // Comparar os tempos de execução
    comparar_tempos(lista, tamanho, valor_procurado);

    return 0;
}
