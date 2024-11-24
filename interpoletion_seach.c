#include <stdio.h>

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

// Função de Interpolation Search
int busca_interpolacao(int lista[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim && valor >= lista[inicio] && valor <= lista[fim]) {
        // Calcular a posição usando interpolação
        int pos = inicio + ((valor - lista[inicio]) * (fim - inicio)) / (lista[fim] - lista[inicio]);

        if (lista[pos] == valor) {
            return pos;
        }

        if (lista[pos] < valor) {
            inicio = pos + 1;
        } else {
            fim = pos - 1;
        }
    }

    return -1;
}

int main() {
    int lista_uniforme[] = {10, 20, 30, 40, 50, 60, 70};
    int lista_nao_uniforme[] = {1, 2, 4, 8, 16, 32, 64};
    int valor_procurado = 32;

    int tamanho_uniforme = sizeof(lista_uniforme) / sizeof(lista_uniforme[0]);
    int tamanho_nao_uniforme = sizeof(lista_nao_uniforme) / sizeof(lista_nao_uniforme[0]);

    // Teste em lista uniforme
    printf("Teste em lista uniforme:\n");
    int pos_binaria = busca_binaria(lista_uniforme, tamanho_uniforme, valor_procurado);
    int pos_interpolacao = busca_interpolacao(lista_uniforme, tamanho_uniforme, valor_procurado);

    printf("Binary Search: ");
    if (pos_binaria != -1) {
        printf("O valor %d esta na posicao %d\n", valor_procurado, pos_binaria);
    } else {
        printf("Valor %d nao encontrado.\n", valor_procurado);
    }

    printf("Interpolation Search: ");
    if (pos_interpolacao != -1) {
        printf("O valor %d esta na posicao %d\n", valor_procurado, pos_interpolacao);
    } else {
        printf("Valor %d nao encontrado.\n", valor_procurado);
    }

    // Teste em lista não uniforme
    printf("\nTeste em lista nao uniforme:\n");
    pos_binaria = busca_binaria(lista_nao_uniforme, tamanho_nao_uniforme, valor_procurado);
    pos_interpolacao = busca_interpolacao(lista_nao_uniforme, tamanho_nao_uniforme, valor_procurado);

    printf("Binary Search: ");
    if (pos_binaria != -1) {
        printf("O valor %d esta na posicao %d\n", valor_procurado, pos_binaria);
    } else {
        printf("Valor %d nao encontrado.\n", valor_procurado);
    }

    printf("Interpolation Search: ");
    if (pos_interpolacao != -1) {
        printf("O valor %d esta na posicao %d\n", valor_procurado, pos_interpolacao);
    } else {
        printf("Valor %d nao encontrado.\n", valor_procurado);
    }

    return 0;
}
