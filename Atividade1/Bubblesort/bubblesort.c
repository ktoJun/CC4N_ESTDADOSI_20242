#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar os valores de duas variáveis
void swap(int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

// Função de ordenação por bolha (Bubble Sort)
void bubble_sort(int array[], int array_size) {
    int i, j;

    for (i = 0; i < array_size - 1; i++) {
        for (j = array_size - 1; j >= i + 1; j--) {
            if (array[j] < array[j - 1]) { swap(&array[j], &array[j - 1]); }
        }
    }
}

// Função para preencher o array com números aleatórios
void fill_array_with_random_numbers(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) { array[i] = rand() % 100; /*Gerar num de 0 a 99*/}
}


// Função Principal
int main(void) {
    int array[50];
    int i;
    
    // Configuração para gerar números aleatórios
    srand(time(NULL)); 
    fill_array_with_random_numbers(array, 50);

    // Printar na tela a sequência original
    printf("Antes da ordenação: ");
    for (i = 0; i < 50; i++) { printf("%d ", array[i]); }
    printf("\n");

    // Função para ordenação através de bubble_sort
    bubble_sort(array, 50);

    // Printar na tela a sequência ordenada
    printf("Depois da ordenação: ");
    for (i = 0; i < 50; i++) { printf("%d ", array[i]); }
    printf("\n");

    return 0;
}
