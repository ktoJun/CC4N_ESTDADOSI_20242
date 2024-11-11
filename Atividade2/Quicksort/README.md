**Portfólio - Estrutura de Dados I - Atividade II**

---

## **Parte 2** – Implementação Individual dos Algoritmos (até 16/11) - via Github

Cada aluno deverá implementar três métodos de ordenação (Shellsort, Quicksort, Heapsort, RadixSort e/ou Mergesort) de forma independente, seguindo as diretrizes:

1. Escrever o Código: Implementar cada algoritmo em linguagem C, com todos os comentários de código pertinentes ao entendimento da atividade.
2. Analisar a Complexidade: Registrar a complexidade de tempo e espaço de cada algoritmo nos casos melhor, médio e pior.
3. Executar Testes: Testar os algoritmos com conjuntos de dados variados, analisando os resultados e a eficiência em cada caso.

Entrega: Cada aluno deverá entregar os códigos implementados, com análises de complexidade e resultados dos testes, via fork do github da disciplina.

---

## **2. Analisar a Complexidade** - QuickSort

### **Complexidade de Tempo**

- **Melhor caso (O(n log n)):**
  - O melhor caso ocorre quando o pivô escolhido divide o array de forma aproximadamente igual a cada particionamento. Isso faz com que a altura da árvore de recursão seja logarítmica e a quantidade de comparações e trocas seja proporcional a `n log n`.

- **Caso médio (O(n log n)):**
  - O caso médio também é `O(n log n)` quando os pivôs escolhidos tendem a dividir o array de forma relativamente equilibrada. Em termos práticos, QuickSort tem uma boa média de desempenho mesmo quando os dados não estão perfeitamente equilibrados.

- **Pior caso (O(n²)):**
  - O pior caso ocorre quando o pivô escolhido é o menor ou maior elemento do array a cada chamada recursiva. Isso faz com que a árvore de recursão se torne uma lista ligada, resultando em uma complexidade de tempo quadrática `O(n²)`. Isso pode ocorrer, por exemplo, quando o array já está ordenado ou em ordem inversa, e o pivô escolhido é sempre o primeiro ou o último elemento.

### **Complexidade de Espaço**

- **Melhor caso (O(log n)):**
  - No melhor caso, QuickSort usa `O(log n)` espaço adicional devido à profundidade da pilha de recursão. Isso ocorre porque a árvore de recursão tem altura logarítmica.

- **Caso médio (O(log n)):**
  - Em média, o QuickSort também usa `O(log n)` de espaço, uma vez que o número de chamadas recursivas é logarítmico quando o pivô divide o array de maneira equilibrada.

- **Pior caso (O(n)):**
  - No pior caso, o QuickSort pode usar até `O(n)` de espaço devido à profundidade da pilha de recursão, caso o pivô não divida bem o array e o algoritmo se comporte como uma lista ligada.

---

## **3. Executar Testes** - QuickSort

### **Array Aleatório:**
- **Descrição**: Quando o array contém valores aleatórios, o QuickSort geralmente funciona de forma eficiente com complexidade de tempo `O(n log n)`. O algoritmo divide o array em duas metades com base no pivô e faz a ordenação de maneira eficiente mesmo para dados distribuídos aleatoriamente.
- **Comportamento esperado**: O QuickSort deve realizar divisões rápidas e eficientes e produzir um array ordenado após a execução.

### **Array Já Ordenado:**
- **Descrição**: No caso de o array já estar ordenado, o QuickSort pode sofrer uma degradação de performance se o pivô escolhido for sempre o primeiro ou o último elemento do array, o que causaria uma divisão desigual. Isso leva a um comportamento de pior caso com complexidade `O(n²)`. No entanto, se a estratégia de escolha do pivô for otimizada (como o pivô sendo o elemento central ou um pivô aleatório), o desempenho pode ser mais eficiente.
- **Comportamento esperado**: Em seu pior comportamento (se o pivô for mal escolhido), o algoritmo pode ter complexidade `O(n²)`, mas, com uma escolha adequada de pivô, o desempenho deve ser em torno de `O(n log n)`.

### **Array em Ordem Reversa:**
- **Descrição**: Quando o array está ordenado de forma inversa, o QuickSort pode sofrer a mesma degradação de desempenho observada no caso do array já ordenado, caso o pivô escolhido seja sempre o primeiro ou o último elemento. Isso também resulta em uma complexidade de tempo de `O(n²)`.
- **Comportamento esperado**: Como no caso de array já ordenado, o desempenho do QuickSort pode ser pior no caso de escolha de pivô ruim, com complexidade `O(n²)`.

### **Arrays Muito Grandes:**
- **Descrição**: Para arrays muito grandes, o QuickSort ainda mantém a complexidade média de `O(n log n)`, o que torna o algoritmo bastante eficiente. No entanto, o QuickSort pode ter problemas de stack overflow em recursões profundas se o espaço de pilha não for bem gerenciado, o que pode ser um limite para arrays extremamente grandes.
- **Comportamento esperado**: O QuickSort deve lidar bem com grandes volumes de dados, mas a escolha de um bom pivô e o controle da profundidade da recursão (evitar o pior caso) são importantes para garantir boa performance. Em casos extremos de arrays muito grandes, a eficiência do algoritmo pode ser afetada pela profundidade da recursão.

---

### **Exemplo de Saída de Testes**:

Para um **array aleatório** de 10 elementos:

```
Antes da ordenação: 53 92 45 81 34 61 67 72 42 80
Processo de ordenação:
Array após particionamento: 53 45 42 34 61 67 72 81 80 92
...

Depois da ordenação: 34 42 45 53 61 67 72 80 81 92
```

Para um **array já ordenado** de 10 elementos (com pivô ruim):

```
Antes da ordenação: 1 2 3 4 5 6 7 8 9 10
Processo de ordenação:
Array após particionamento: 1 2 3 4 5 6 7 8 9 10
...

Depois da ordenação: 1 2 3 4 5 6 7 8 9 10
```

Para um **array em ordem inversa** de 10 elementos (com pivô ruim):

```
Antes da ordenação: 10 9 8 7 6 5 4 3 2 1
Processo de ordenação:
Array após particionamento: 1 2 3 4 5 6 7 8 9 10
...

Depois da ordenação: 1 2 3 4 5 6 7 8 9 10
```

---

### **Resumo das Análises de Complexidade e Comportamento**:

- **Melhor e Caso Médio**: O QuickSort possui uma complexidade de tempo de `O(n log n)` tanto no melhor quanto no caso médio, o que o torna eficiente para a maioria das distribuições de dados.
- **Pior Caso**: No pior caso, como quando o pivô é mal escolhido (exemplo: array já ordenado ou em ordem inversa), a complexidade de tempo pode chegar a `O(n²)`.
- **Espaço**: A complexidade de espaço do QuickSort é `O(log n)` na média, mas pode chegar a `O(n)` no pior caso devido à profundidade da pilha de recursão.

Esse comportamento faz do QuickSort um algoritmo bastante eficiente em termos de tempo para a maioria dos casos, mas a escolha do pivô e o controle da recursão são fundamentais para evitar o pior caso.

---
