#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Fun��o de Insertion Sort para ordenar os n�meros dentro de cada balde
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

// Fun��o para realizar o Bucket Sort para n�meros inteiros
void bucket_sort(int arr[], int n, int intervalo) {
    // Encontrar o valor m�ximo do array para definir a quantidade de baldes necess�rios
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calcular o n�mero de baldes necess�rios
    int num_buckets = max_val / intervalo + 1;

    // Criar os baldes
    int **baldes = (int **)malloc(num_buckets * sizeof(int *));
    int *bucket_sizes = (int *)malloc(num_buckets * sizeof(int));

    for (int i = 0; i < num_buckets; i++) {
        baldes[i] = (int *)malloc(n * sizeof(int));  // Alocar mem�ria para cada balde
        bucket_sizes[i] = 0;  // Inicializar o tamanho de cada balde como 0
    }

    // Distribuir os elementos nos baldes
    for (int i = 0; i < n; i++) {
        int idx = arr[i] / intervalo;  // Calcular o �ndice do balde
        baldes[idx][bucket_sizes[idx]++] = arr[i];  // Coloca o n�mero no balde e aumenta o tamanho
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

    // Liberar a mem�ria alocada para os baldes
    for (int i = 0; i < num_buckets; i++) {
        free(baldes[i]);
    }
    free(baldes);
    free(bucket_sizes);
}

// Fun��o de Busca Bin�ria
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

// Fun��o de Interpolation Search
int busca_interpolacao(int lista[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim && valor >= lista[inicio] && valor <= lista[fim]) {
        // Calcular a posi��o usando interpola��o
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
    setlocale(LC_ALL, "portuguese");
    int notas[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(notas) / sizeof(notas[0]);
    int intervalo = 10;  // Intervalo para os baldes (por exemplo, 10 para notas entre 0 e 100)

    // Exibe a lista original de notas
    printf("Notas originais:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", notas[i]);
    }
    printf("\n");

    // Ordena as notas usando Bucket Sort
    bucket_sort(notas, n, intervalo);

    // Exibe a lista ordenada de notas
    printf("\nNotas ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", notas[i]);
    }
    printf("\n");

    // Valor a ser procurado (nota de um aluno espec�fico)
    int valor_procurado = 75;

    // Busca pela nota usando Busca Bin�ria
    int pos_binaria = busca_binaria(notas, n, valor_procurado);
    if (pos_binaria != -1) {
        printf("\nBusca Bin�ria: A nota %d foi encontrada na posi��o %d.\n", valor_procurado, pos_binaria);
    } else {
        printf("\nBusca Bin�ria: A nota %d n�o foi encontrada.\n", valor_procurado);
    }

    // Busca pela nota usando Interpolation Search
    int pos_interpolacao = busca_interpolacao(notas, n, valor_procurado);
    if (pos_interpolacao != -1) {
        printf("Busca por Interpola��o: A nota %d foi encontrada na posi��o %d.\n", valor_procurado, pos_interpolacao);
    } else {
        printf("Busca por Interpola��o: A nota %d n�o foi encontrada.\n", valor_procurado);
    }

    return 0;
}
