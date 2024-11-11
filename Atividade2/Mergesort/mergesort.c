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
        array[i] = rand() % 100; // Gerar número de 0 a 99
    }
}

// Função para mesclar duas metades de um array de forma ordenada
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;


    int left_array[n1], right_array[n2];


    for (int i = 0; i < n1; i++) {
        left_array[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        right_array[i] = array[mid + 1 + i];
    }


    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        array[k] = left_array[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        array[k] = right_array[j];
        j++;
        k++;
    }
    
    printf(" ");
    //print_array(array, right + 1);                    /*!!*/
}

// Função de ordenação Merge Sort
void merge_sort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
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

    // Função para ordenação através do Merge Sort
    printf("\nProcesso de ordenação:\n");
    merge_sort(array, 0, 49); // Ordenar o array inteiro

    // Printar na tela a sequência ordenada
    printf("\nDepois da ordenação: ");
    print_array(array, 50);

    return 0;
}
