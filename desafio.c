#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Funções de ordenação
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void counting_sort_for_radix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_for_radix(arr, n, exp);
}

void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Funções de busca
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int interpolation_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int jump_search(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[step - 1] < target && step < n) {
        prev = step;
        step += sqrt(n);
        if (step > n) step = n;
    }
    for (int i = prev; i < step; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int exponential_search(int arr[], int n, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2;
    }
    return binary_search(arr, i / 2, i < n ? target : arr[n-1]);
}

// Função para imprimir o array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int size;
    printf("Tamanho da lista: ");
    scanf("%d", &size);

    int *data = (int *)malloc(size * sizeof(int));
    srand(time(0));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 101;
    }

    printf("Lista original: ");
    print_array(data, size);

    int option;
    printf("Escolha uma opção:\n1. Ordenar lista\n2. Buscar elemento\n");
    scanf("%d", &option);

    if (option == 1) {
        int sort_choice;
        printf("Escolha um algoritmo de ordenação:\n1. Bubble Sort\n2. Selection Sort\n3. Merge Sort\n4. Quick Sort\n5. Radix Sort\n6. Shell Sort\n");
        scanf("%d", &sort_choice);

        clock_t start, end;
        switch (sort_choice) {
            case 1:
                start = clock();
                bubble_sort(data, size);
                end = clock();
                printf("Lista ordenada (Bubble Sort): ");
                break;
            case 2:
                start = clock();
                selection_sort(data, size);
                end = clock();
                printf("Lista ordenada (Selection Sort): ");
                break;
            case 3:
                start = clock();
                merge_sort(data, 0, size - 1);
                end = clock();
                printf("Lista ordenada (Merge Sort): ");
                break;
            case 4:
                start = clock();
                quick_sort(data, 0, size - 1);
                end = clock();
                printf("Lista ordenada (Quick Sort): ");
                break;
            case 5:
                start = clock();
                radix_sort(data, size);
                end = clock();
                printf("Lista ordenada (Radix Sort): ");
                break;
            case 6:
                start = clock();
                shell_sort(data, size);
                end = clock();
                printf("Lista ordenada (Shell Sort): ");
                break;
            default:
                printf("Opção inválida.\n");
                free(data);
                return 0;
        }
        print_array(data, size);
        printf("Tempo de execução: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    } else if (option == 2) {
        int target;
        printf("Informe o número a ser buscado: ");
        scanf("%d", &target);

        int search_choice;
        printf("Escolha um algoritmo de busca:\n1. Linear Search\n2. Binary Search\n3. Interpolation Search\n4. Jump Search\n5. Exponential Search\n");
        scanf("%d", &search_choice);

        clock_t start, end;
        int result;
        switch (search_choice) {
            case 1:
                start = clock();
                result = linear_search(data, size, target);
                end = clock();
                break;
            case 2:
                start = clock();
                result = binary_search(data, size, target);
                end = clock();
                break;
            case 3:
                start = clock();
                result = interpolation_search(data, size, target);
                end = clock();
                break;
            case 4:
                start = clock();
                result = jump_search(data, size, target);
                end = clock();
                break;
            case 5:
                start = clock();
                result = exponential_search(data, size, target);
                end = clock();
                break;
            default:
                printf("Opção inválida.\n");
                free(data);
                return 0;
        }

        if (result != -1) {
            printf("Elemento encontrado na posição %d\n", result);
        } else {
            printf("Elemento não encontrado.\n");
        }
        printf("Tempo de execução: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    } else {
        printf("Opção inválida.\n");
    }

    free(data);
    return 0;
}
