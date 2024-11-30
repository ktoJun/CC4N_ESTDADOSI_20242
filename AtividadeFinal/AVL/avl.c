#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Inicializando altura do nó
    return newNode;
}

// Função para obter a altura de um nó
int height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

// Função para calcular o fator de balanceamento
int getBalance(Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Função para atualizar a altura do nó
void updateHeight(Node* node) {
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
}

// Função para rotação à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Função para rotação à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Função para inserir um valor na árvore AVL
Node* insert(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node; // Não permite valores duplicados
    }

    updateHeight(node);

    // Verificação do fator de balanceamento
    int balance = getBalance(node);

    // Caso 1: Rotação simples à direita
    if (balance > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    // Caso 2: Rotação simples à esquerda
    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    // Caso 3: Rotação dupla à esquerda-direita
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso 4: Rotação dupla à direita-esquerda
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Função para encontrar o menor nó
Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Função para deletar um nó da árvore AVL
Node* delete(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    if (root == NULL) return root;

    updateHeight(root);

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Função para exibir a árvore em ordem (in-order)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Função para preencher o array com números aleatórios únicos
void fill_array_with_unique_random_numbers(int array[], int size) {
    int num, i, unique;
    for (i = 0; i < size; i++) {
        do {
            num = rand() % 100;
            unique = 1;
            for (int j = 0; j < i; j++) {
                if (array[j] == num) {
                    unique = 0;
                    break;
                }
            }
        } while (!unique);
        array[i] = num;
    }
}

// Função para inserir um número no array e na árvore AVL
void insert_into_array_and_tree(int array[], int* size, int value, Node** root) {
    array[*size] = value;
    (*size)++;
    *root = insert(*root, value);
}

// Função para deletar um número do array e da árvore AVL
int delete_from_array_and_tree(int array[], int* size, int value, Node** root) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (array[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) return 0; // Número não encontrado

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
    fill_array_with_unique_random_numbers(array, size);

    printf("Array inicial:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        root = insert(root, array[i]);
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
                continue;
            }

            // Verificar se o número já existe
            int exists = 0;
            for (int i = 0; i < size; i++) {
                if (array[i] == value) {
                    exists = 1;
                    break;
                }
            }

            if (exists) {
                printf("Erro: número já existe no array.\n");
            } else {
                insert_into_array_and_tree(array, &size, value, &root);
                printf("Número inserido com sucesso.\n");
            }

        } else if (choice == 2) {
            printf("Digite o número para deletar: ");
            scanf("%d", &value);

            if (delete_from_array_and_tree(array, &size, value, &root)) {
                printf("Número deletado com sucesso.\n");
            } else {
                printf("Erro: número não encontrado no array.\n");
            }

        } else if (choice == 3) {
            printf("Saindo do programa.\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

        printf("\nÁrvore em ordem após a operação:\n");
        inorderTraversal(root);
    }

    return 0;
}
