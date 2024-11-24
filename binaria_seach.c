/*A ordenação é essencial porque garante que possamos eliminar metades da lista de maneira confiável, já que os elementos seguem uma sequência lógica. Isso torna possível prever onde um determinado valor pode estar.*/

#include <stdio.h>

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

int main() {
    int lista_ordenada[] = {2, 4, 9, 11, 21, 132};
    int valor_procurado = 4;
    int tamanho = sizeof(lista_ordenada) / sizeof(lista_ordenada[0]);

    int pos = busca_binaria(lista_ordenada, tamanho, valor_procurado);

    if (pos != -1) {
        printf("O valor %d esta na posicao %d do vetor", valor_procurado, pos);
    } else {
        printf("Valor %d nao encontrado na lista.\n", valor_procurado);
    }

    return 0;
}