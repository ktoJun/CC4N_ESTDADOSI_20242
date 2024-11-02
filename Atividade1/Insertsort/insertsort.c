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

// Função para printar cada ordenação realizado no array
void print_array(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função de ordenação por inserção (Insert Sort)
void insertion_sort (int array[], int array_size) {
  int i, j;

  for (i = 1; i < array_size; i++) {
    j = i;
    while ((j > 0) && (array[j-1] > array[j])) {
      swap(&array[j-1], &array[j]);
      print_array(array, array_size);
      j--;
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
    insertion_sort(array, 50);

    // Printar na tela a sequência ordenada
    printf("\nDepois da ordenação: ");
    print_array(array, 50);

    return 0;
}
