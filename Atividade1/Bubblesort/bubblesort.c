#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Para manter o seu olho bem, o print do processo da ordenação está comentada.
//Descomente a função onde está comentada de "!!" para ver o processo de ordenação.

// Função para trocar os valores de duas variáveis
void swap(int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

// Função para printar cada ordenação realizado no array
void print_array(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função de ordenação por bolha (Bubble Sort)
void bubble_sort(int array[], int array_size) {
    int i, j;

    for (i = 0; i < array_size - 1; i++) {
        for (j = array_size - 1; j >= i + 1; j--) {
            if (array[j] < array[j - 1]) { 
                swap(&array[j], &array[j - 1]);
                //print_array(array, array_size); /*!!*/
            }
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
    print_array(array, 50);

    // Função para ordenação através de insert_sort
    printf("\nProcesso de ordenação:\n");
    bubble_sort(array, 50);

    // Printar na tela a sequência ordenada
    printf("\nDepois da ordenação: ");
    print_array(array, 50);

    return 0;
}
