#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*  Descomente a função onde está comentada de "!!" para ver o processo de ordenação.  */

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
        array[i] = rand() % 100; // Gerar número de 0 a 99
    }
}

// Função para contar a ocorrência de cada dígito (0-9)
void counting_sort(int array[], int array_size, int exp) {
    int output[array_size];
    int count[10] = {0};

    // Contagem das ocorrências
    for (int i = 0; i < array_size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // Acumular a contagem
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir o array de saída
    for (int i = array_size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copiar o array ordenado de volta para o array original
    for (int i = 0; i < array_size; i++) {
        array[i] = output[i];
    }

    // Imprimir o array após a ordenação de um dígito
    printf("Array após ordenação no dígito de ordem %d: ", exp);
    print_array(array, array_size);
}

// Função principal do RadixSort
void radix_sort(int array[], int array_size) {
    // Encontrar o maior número para determinar o número de dígitos
    int max = array[0];
    for (int i = 1; i < array_size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Realizar a ordenação para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(array, array_size, exp); // Ordenar com base no dígito de ordem exp
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

    // Função para ordenação através do RadixSort
    printf("\nProcesso de ordenação:\n");
    radix_sort(array, 50); // Ordenar o array inteiro

    // Printar na tela a sequência ordenada
    printf("\nDepois da ordenação: ");
    print_array(array, 50);

    return 0;
}

