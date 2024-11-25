#include <stdio.h>

typedef struct {
    int isbn;
    char titulo[100];
} Livro;

int busca_binaria(Livro lista[], int tamanho, int valor_isbn) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista[meio].isbn == valor_isbn) {
            return meio;
        } else if (lista[meio].isbn > valor_isbn) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

int main() {
    // Lista de livros ordenada por ISBN
    Livro lista_ordenada[] = {
        {123, "Livro A"},
        {456, "Livro B"},
        {789, "Livro C"},
        {1011, "Livro D"},
        {1321, "Livro E"}
    };

    int valor_isbn = 789;
    int tamanho = sizeof(lista_ordenada) / sizeof(lista_ordenada[0]);

    int pos = busca_binaria(lista_ordenada, tamanho, valor_isbn);

    if (pos != -1) {
        printf("O livro com ISBN %d e '%s' e esta na posicao %d.\n", valor_isbn, lista_ordenada[pos].titulo, pos);
    } else {
        printf("Livro com ISBN %d nao encontrado.\n", valor_isbn);
    }

    return 0;
}
