#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*  Descomente a função onde está comentada de "!!" para ver o processo de ordenação.  */

// Função para trocar os valores de duas variáveis
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Função para printar cada ordenação realizada no array
void print_array(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função para preencher o array com números aleatórios
void fill_array_with_random_numbers(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        array[i] = rand() % 100;
    }
}

// Função para particionar o array e retornar o índice do pivô
int partition(int array[], int low, int high) {
    int pivot = array[high];    // Escolher o último elemento como pivô
    int i = low - 1;            // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    // Aqui, imprimimos o array após cada partição
    printf("Array após particionamento: ");
    //print_array(array, high + 1);                         /*!!*/

    return i + 1;
}

// Função de ordenação QuickSort
void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quick_sort(array, low, pi - 1);     // Elementos à esquerda do pivô
        quick_sort(array, pi + 1, high);    // Elementos à direita do pivô
    }
}

// Função Principal
int main(void) {
    int array[50];
    
    // Configuração para gerar números aleatórios
    srand(time(NULL)); 
    fill_array_with_random_numbers(array, 50);

    // Printar na tela a sequência original
    printf("Antes da ordenação: ");
    print_array(array, 50);

    // Função para ordenação através do QuickSort
    printf("\nProcesso de ordenação:\n");
    quick_sort(array, 0, 49); // Ordenar o array inteiro

    // Printar na tela a sequência ordenada
    printf("\nDepois da ordenação: ");
    print_array(array, 50);

    return 0;
}
