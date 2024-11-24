#include <stdio.h>
#include <string.h>

// Função para combinar duas sublistas ordenadas de strings
void merge_strings(char *lista[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    // Criar listas temporárias para armazenar as sublistas
    char *esquerda_temp[n1], *direita_temp[n2];
    
    // Copiar os dados para as listas temporárias
    for (int i = 0; i < n1; i++)
        esquerda_temp[i] = lista[esquerda + i];
    for (int j = 0; j < n2; j++)
        direita_temp[j] = lista[meio + 1 + j];
    
    int i = 0, j = 0, k = esquerda;
    
    // Combina as duas sublistas temporárias
    while (i < n1 && j < n2) {
        // Comparação sem distinguir maiúsculas de minúsculas
        if (strcasecmp(esquerda_temp[i], direita_temp[j]) <= 0) {
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

// Função principal de ordenação Merge Sort para strings
void merge_sort_strings(char *lista[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Ordena as duas metades
        merge_sort_strings(lista, esquerda, meio);
        merge_sort_strings(lista, meio + 1, direita);
        
        // Combina as duas metades ordenadas
        merge_strings(lista, esquerda, meio, direita);
    }
}

int main() {
    char *lista[] = {"Zebra", "cachorro", "gato", "maca", "marrom","Zelda","pokemon","Seila","Junior","ricardo","Cicero","pao","pc","acabou"};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    
    merge_sort_strings(lista, 0, tamanho - 1);
    
    printf("Lista ordenada de strings: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", lista[i]);
    }
    return 0;
}
