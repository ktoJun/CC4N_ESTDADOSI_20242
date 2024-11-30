# Implementação de Árvores Binárias (BST e AVL)

Este repositório contém a implementação de duas estruturas de árvore binária: **Árvore Binária de Busca (BST)** e **Árvore AVL (Árvore de Busca Balanceada)**, com operações básicas como inserção, deleção e travessia em ordem (in-order).

## Índice

1. [Árvore Binária de Busca (BST)](https://github.com/ktoJun/CC4N_ESTDADOSI_20242/tree/main/AtividadeFinal/BST)
2. [Árvore AVL](https://github.com/ktoJun/CC4N_ESTDADOSI_20242/tree/main/AtividadeFinal/AVL)

 
---

## Árvore Binária de Busca (BST)

A **Árvore Binária de Busca** é uma árvore binária onde para cada nó:
- Os valores à esquerda são menores do que o valor do nó.
- Os valores à direita são maiores do que o valor do nó.

### Funções Implementadas

- **`createNode(int data)`**: Cria um novo nó com o valor fornecido.
- **`insert(Node* root, int data)`**: Insere um valor na árvore binária de busca, mantendo a propriedade da árvore.
- **`exists_in_tree(Node* root, int data)`**: Verifica se um valor já existe na árvore.
- **`findMin(Node* root)`**: Encontra o nó com o menor valor na árvore.
- **`delete(Node* root, int data)`**: Deleta um valor da árvore, ajustando os filhos conforme necessário para manter a estrutura da árvore.
- **`inorderTraversal(Node* root)`**: Realiza a travessia em ordem (in-order) e imprime os valores da árvore.
- **`fill_array_with_unique_random_numbers(int array[], int size, Node** root)`**: Preenche um array com números aleatórios e os insere na árvore, garantindo que não haja duplicatas.
- **`insert_into_array(int array[], int* size, int value, Node** root)`**: Insere um valor no array e na árvore, verificando se o valor já existe.
- **`delete_from_array(int array[], int* size, int value, Node** root)`**: Deleta um valor do array e da árvore, mantendo a árvore ajustada.

---

## Árvore AVL

A **Árvore AVL** é uma árvore binária de busca balanceada, onde a diferença entre as alturas das subárvores esquerda e direita de qualquer nó não é maior que 1. Essa propriedade é mantida por meio de rotações após cada inserção ou deleção.

### Funções Implementadas

- **`createNode(int data)`**: Cria um novo nó com o valor fornecido, com altura inicial de 1.
- **`height(Node* node)`**: Retorna a altura de um nó.
- **`getBalance(Node* node)`**: Calcula o fator de balanceamento de um nó (diferença entre a altura da subárvore esquerda e direita).
- **`updateHeight(Node* node)`**: Atualiza a altura de um nó com base nas alturas de suas subárvores.
- **`rotateRight(Node* y)`**: Realiza uma rotação à direita em torno de um nó.
- **`rotateLeft(Node* x)`**: Realiza uma rotação à esquerda em torno de um nó.
- **`insert(Node* node, int data)`**: Insere um valor na árvore AVL, realizando rotações conforme necessário para manter o balanceamento.
- **`findMin(Node* node)`**: Encontra o nó com o menor valor na árvore.
- **`delete(Node* root, int data)`**: Deleta um valor da árvore, realizando rotações conforme necessário para manter o balanceamento.
- **`inorderTraversal(Node* root)`**: Realiza a travessia em ordem (in-order) e imprime os valores da árvore.
- **`fill_array_with_unique_random_numbers(int array[], int size)`**: Preenche um array com números aleatórios e os insere na árvore AVL.
- **`insert_into_array_and_tree(int array[], int* size, int value, Node** root)`**: Insere um valor no array e na árvore AVL.
- **`delete_from_array_and_tree(int array[], int* size, int value, Node** root)`**: Deleta um valor do array e da árvore AVL, mantendo o balanceamento.



