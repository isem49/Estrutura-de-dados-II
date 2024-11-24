#include <stdio.h>
#include <math.h>
#include <time.h>

// Função de Busca Binária
int busca_binaria(int lista[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

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

    return -1;
}

// Função para retornar o menor valor entre dois
int minimo(int a, int b) {
    return (a < b) ? a : b;
}

// Função de Jump Search
int busca_jump(int lista[], int tamanho, int valor) {
    // Calcula o salto ideal
    int salto = (int)sqrt(tamanho);
    int inicio = 0;

    // Procura pelo bloco onde o valor pode estar
    while (lista[minimo(inicio + salto, tamanho) - 1] < valor) {
        inicio += salto;
        if (inicio >= tamanho) {
            return -1;  // O valor não foi encontrado
        }
    }

    // Faz uma busca linear dentro do bloco
    for (int i = inicio; i < minimo(inicio + salto, tamanho); i++) {
        if (lista[i] == valor) {
            return i;  // Retorna a posição do valor
        }
    }

    return -1;  // Valor não encontrado
}

// Função para comparar o tempo de execução
void comparar_tempos(int lista[], int tamanho, int valor) {
    clock_t inicio, fim;
    double tempo_binario, tempo_jump;

    // Tempo de execução do Binary Search
    inicio = clock();
    busca_binaria(lista, tamanho, valor);
    fim = clock();
    tempo_binario = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Tempo de execução do Jump Search
    inicio = clock();
    busca_jump(lista, tamanho, valor);
    fim = clock();
    tempo_jump = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao do Binary Search: %f segundos\n", tempo_binario);
    printf("Tempo de execucao do Jump Search: %f segundos\n", tempo_jump);
}

int main() {
    // Lista de exemplo ordenada
    int lista[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int valor_procurado = 10;

    // Busca de posição usando Jump Search
    int posicao = busca_jump(lista, tamanho, valor_procurado);
    
    if (posicao != -1) {
        printf("O valor %d foi encontrado na posicao %d.\n", valor_procurado, posicao);
    } else {
        printf("Valor %d não encontrado na lista.\n", valor_procurado);
    }

    // Comparar os tempos de execução
    comparar_tempos(lista, tamanho, valor_procurado);

    return 0;
}
