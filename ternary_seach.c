#include <stdio.h>

int pesquisaTernaria(int lista[], int inicio, int fim, int valorProcurado) {
    if (fim >= inicio) {
        int meio1 = inicio + (fim - inicio) / 3;
        int meio2 = fim - (fim - inicio) / 3;

        if (lista[meio1] == valorProcurado)
            return meio1;

        if (lista[meio2] == valorProcurado)
            return meio2;

        if (valorProcurado < lista[meio1])
            return pesquisaTernaria(lista, inicio, meio1 - 1, valorProcurado);
        else if (valorProcurado > lista[meio2])
            return pesquisaTernaria(lista, meio2 + 1, fim, valorProcurado);
        else
            return pesquisaTernaria(lista, meio1 + 1, meio2 - 1, valorProcurado);
    }

    return -1;
}

int main() {
    int lista[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanhoLista = sizeof(lista) / sizeof(lista[0]);
    int valorProcurado = 5;
    int resultado = pesquisaTernaria(lista, 0, tamanhoLista - 1, valorProcurado);
    if (resultado != -1)
        printf("O valor %d foi encontrado no indice %d\n", valorProcurado, resultado);
    else
        printf("Valor nao encontrado\n");
    return 0;
}