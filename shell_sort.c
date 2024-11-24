#include <stdio.h>
#include <time.h>

// Função para realizar o Shell Sort com a sequência de Shell
void shell_sort_shell(int lista[], int tamanho) {
    int intervalo, i, j, temp;
    for (intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < tamanho; i++) {
            temp = lista[i];
            j = i;
            while (j >= intervalo && lista[j - intervalo] > temp) {
                lista[j] = lista[j - intervalo];
                j -= intervalo;
            }
            lista[j] = temp;
        }
    }
}

// Função para realizar o Shell Sort com a sequência de Knuth
void shell_sort_knuth(int lista[], int tamanho) {
    int intervalo, i, j, temp;
    // Calcula os intervalos de Knuth
    int gaps[] = {1, 4, 13, 40, 121, 364, 1093}; // Exemplo de gaps baseados em 3^k - 1 / 2
    for (int k = 6; k >= 0; k--) {
        intervalo = gaps[k];
        for (i = intervalo; i < tamanho; i++) {
            temp = lista[i];
            j = i;
            while (j >= intervalo && lista[j - intervalo] > temp) {
                lista[j] = lista[j - intervalo];
                j -= intervalo;
            }
            lista[j] = temp;
        }
    }
}

// Função para realizar o Shell Sort com a sequência de Hibbard
void shell_sort_hibbard(int lista[], int tamanho) {
    int intervalo, i, j, temp;
    // Calcula os intervalos de Hibbard
    int gaps[] = {1, 3, 7, 15, 31, 63, 127}; // Exemplo de gaps baseados em 2^k - 1
    for (int k = 6; k >= 0; k--) {
        intervalo = gaps[k];
        for (i = intervalo; i < tamanho; i++) {
            temp = lista[i];
            j = i;
            while (j >= intervalo && lista[j - intervalo] > temp) {
                lista[j] = lista[j - intervalo];
                j -= intervalo;
            }
            lista[j] = temp;
        }
    }
}

// Função para comparar os tempos de execução
void comparar_tempos(int lista[], int tamanho) {
    clock_t inicio, fim;
    double tempo_shell, tempo_knuth, tempo_hibbard;

    // Tempo de execução do Shell Sort (Shell)
    int lista_shell[tamanho];
    for (int i = 0; i < tamanho; i++) lista_shell[i] = lista[i];
    inicio = clock();
    shell_sort_shell(lista_shell, tamanho);
    fim = clock();
    tempo_shell = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Tempo de execução do Shell Sort (Knuth)
    int lista_knuth[tamanho];
    for (int i = 0; i < tamanho; i++) lista_knuth[i] = lista[i];
    inicio = clock();
    shell_sort_knuth(lista_knuth, tamanho);
    fim = clock();
    tempo_knuth = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Tempo de execução do Shell Sort (Hibbard)
    int lista_hibbard[tamanho];
    for (int i = 0; i < tamanho; i++) lista_hibbard[i] = lista[i];
    inicio = clock();
    shell_sort_hibbard(lista_hibbard, tamanho);
    fim = clock();
    tempo_hibbard = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao do Shell Sort (Shell): %f segundos\n", tempo_shell);
    printf("Tempo de execucao do Shell Sort (Knuth): %f segundos\n", tempo_knuth);
    printf("Tempo de execucao do Shell Sort (Hibbard): %f segundos\n", tempo_hibbard);
}

int main() {
    // Lista de exemplo
    int lista[] = {12, 34, 54, 2, 3, 65, 32, 56, 78, 90};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    // Comparar os tempos de execução das três sequências
    comparar_tempos(lista, tamanho);

    return 0;
}
