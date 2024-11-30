#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função para verificar se um número já existe na BST
int exists_in_tree(Node* root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    if (data < root->data) return exists_in_tree(root->left, data);
    return exists_in_tree(root->right, data);
}

// Função para encontrar o menor valor na subárvore
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Função para deletar um valor na BST
Node* delete(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Função para exibir a BST em ordem
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Função para preencher um array com números aleatórios sem duplicados
void fill_array_with_unique_random_numbers(int array[], int size, Node** root) {
    for (int i = 0; i < size; ) {
        int value = rand() % 100;
        if (!exists_in_tree(*root, value)) {
            array[i] = value;
            *root = insert(*root, value);
            i++;
        }
    }
}

// Função para inserir um elemento no array
int insert_into_array(int array[], int* size, int value, Node** root) {
    if (exists_in_tree(*root, value)) {
        return 0; // Número já existe
    }

    array[*size] = value;
    (*size)++;
    *root = insert(*root, value);
    return 1; // Sucesso
}

// Função para deletar um elemento do array
int delete_from_array(int array[], int* size, int value, Node** root) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (array[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return 0; // Elemento não encontrado
    }

    for (int i = index; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
    *root = delete(*root, value);
    return 1; // Sucesso
}

// Função principal
int main() {
    Node* root = NULL;
    int array[50];
    int size = 20;
    int choice, value;

    srand(time(NULL));
    fill_array_with_unique_random_numbers(array, size, &root);

    printf("Array inicial:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\nÁrvore inicial em ordem:\n");
    inorderTraversal(root);

    while (1) {
        printf("\n\nEscolha uma opção:\n");
        printf("1. Inserir um número\n");
        printf("2. Deletar um número\n");
        printf("3. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Digite o número para inserir (entre 0 e 99): ");
            scanf("%d", &value);

            if (value < 0 || value > 99) {
                printf("Erro: número fora do intervalo permitido (0 a 99).\n");
                continue; // Volta ao menu
            }

            if (insert_into_array(array, &size, value, &root)) {
                printf("Número inserido com sucesso.\n");
            } else {
                printf("Erro: número %d já existe no array.\n", value);
            }

        } else if (choice == 2) {
            printf("Digite o número para deletar: ");
            scanf("%d", &value);
            if (delete_from_array(array, &size, value, &root)) {
                printf("Número deletado com sucesso.\n");
            } else {
                printf("Erro: número %d não encontrado no array.\n", value);
            }

        } else if (choice == 3) {
            printf("Encerrando o programa.\n");
            break;

        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

        printf("\nArray atualizado:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\nÁrvore atualizada em ordem:\n");
        inorderTraversal(root);
    }

    return 0;
}
