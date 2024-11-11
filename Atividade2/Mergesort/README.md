**Portfólio - Estrutura de Dados I - Atividade II**

---

## **Parte 2** – Implementação Individual dos Algoritmos (até 16/11) - via Github

Cada aluno deverá implementar três métodos de ordenação (Shellsort, Quicksort, Heapsort, RadixSort e/ou Mergesort) de forma independente, seguindo as diretrizes:

1. Escrever o Código: Implementar cada algoritmo em linguagem C, com todos os comentários de código pertinentes ao entendimento da atividade.
2. Analisar a Complexidade: Registrar a complexidade de tempo e espaço de cada algoritmo nos casos melhor, médio e pior.
3. Executar Testes: Testar os algoritmos com conjuntos de dados variados, analisando os resultados e a eficiência em cada caso.

Entrega: Cada aluno deverá entregar os códigos implementados, com análises de complexidade e resultados dos testes, via fork do github da disciplina.

---

## **2. Analisar a Complexidade** - MergeSort

### **Complexidade de Tempo**

- **Melhor caso (O(n log n)):**
  - O melhor caso ocorre quando o array está distribuído de forma equilibrada, permitindo que o MergeSort divida os dados de maneira eficiente. Como o MergeSort sempre divide o array ao meio e depois mescla as duas metades, sua complexidade de tempo é `O(n log n)` independentemente do estado do array.

- **Caso médio (O(n log n)):**
  - O caso médio do MergeSort também é `O(n log n)` porque ele sempre divide o array em duas partes e realiza as operações de mesclagem. Isso se aplica independentemente da distribuição dos dados, pois o MergeSort nunca perde o comportamento de divisão e mesclagem.

- **Pior caso (O(n log n)):**
  - O pior caso do MergeSort também é `O(n log n)` porque, mesmo que o array esteja ordenado de forma inversa ou em qualquer outra configuração desfavorável, ele sempre realiza as mesmas divisões e mesclagens, mantendo a complexidade consistente.

### **Complexidade de Espaço**

- **Melhor caso (O(n)):**
  - No melhor caso, o MergeSort usa `O(n)` espaço adicional para armazenar os arrays temporários criados durante as fases de mesclagem. Como o algoritmo divide o array ao meio e mescla as partes, ele requer espaço adicional proporcional ao tamanho do array.

- **Caso médio (O(n)):**
  - O caso médio também possui uma complexidade de espaço de `O(n)` porque, mesmo com dados distribuídos aleatoriamente, o MergeSort precisa de memória adicional para realizar as operações de mesclagem.

- **Pior caso (O(n)):**
  - No pior caso, o MergeSort continua a usar `O(n)` de espaço, uma vez que a estratégia de divisão e mesclagem não muda. A quantidade de memória necessária para armazenar as sublistas temporárias durante o processo de ordenação é sempre proporcional ao tamanho do array.

---

## **3. Executar Testes** - MergeSort

### **Array Aleatório:**
- **Descrição**: Quando o array contém valores aleatórios, o MergeSort divide o array recursivamente e mescla as sublistas ordenadas de forma eficiente. A complexidade de tempo é `O(n log n)`, o que torna o algoritmo adequado para trabalhar com arrays de tamanho médio a grande, mesmo com dados distribuídos aleatoriamente.
- **Comportamento esperado**: O MergeSort deve ordenar o array corretamente e de forma eficiente, mantendo a complexidade de tempo `O(n log n)`.

### **Array Já Ordenado:**
- **Descrição**: Quando o array já está ordenado, o MergeSort ainda realiza a divisão do array e mescla as sublistas, sem nenhuma otimização para detectar que o array já está ordenado. Isso resulta na mesma complexidade de tempo de `O(n log n)`, pois o algoritmo sempre segue as etapas de divisão e mesclagem, independentemente da ordem dos dados.
- **Comportamento esperado**: Mesmo com o array já ordenado, o MergeSort não melhora seu desempenho, pois sempre executa o processo completo de divisão e mesclagem.

### **Array em Ordem Reversa:**
- **Descrição**: No caso do array estar ordenado de forma inversa, o MergeSort ainda realiza a divisão e mesclagem das sublistas. O algoritmo mantém a complexidade de tempo de `O(n log n)` porque a ordem dos dados não afeta as operações internas do MergeSort.
- **Comportamento esperado**: O desempenho do MergeSort será o mesmo que no caso do array aleatório ou já ordenado, com complexidade de tempo de `O(n log n)`.

### **Arrays Muito Grandes:**
- **Descrição**: O MergeSort é eficiente para arrays muito grandes, pois mantém a complexidade de tempo de `O(n log n)` independentemente do estado do array. No entanto, como ele usa espaço adicional para as sublistas temporárias, o consumo de memória pode ser um fator limitante em sistemas com pouca memória.
- **Comportamento esperado**: O MergeSort deve lidar bem com arrays grandes, mas o uso adicional de memória pode ser um problema em sistemas com pouca capacidade de RAM.

---

### **Exemplo de Saída de Testes**:

Para um **array aleatório** de 10 elementos:

```
Antes da ordenação: 53 92 45 81 34 61 67 72 42 80
Processo de ordenação:
Divisão: 53 92 45 81 34 | 61 67 72 42 80
Divisão: 53 92 | 45 81 34 | 61 67 | 72 42 80
...
Depois da ordenação: 34 42 45 53 61 67 72 80 81 92
```

Para um **array já ordenado** de 10 elementos:

```
Antes da ordenação: 1 2 3 4 5 6 7 8 9 10
Processo de ordenação:
Divisão: 1 2 3 4 5 | 6 7 8 9 10
Divisão: 1 2 3 | 4 5 | 6 7 | 8 9 | 10
...
Depois da ordenação: 1 2 3 4 5 6 7 8 9 10
```

Para um **array em ordem inversa** de 10 elementos:

```
Antes da ordenação: 10 9 8 7 6 5 4 3 2 1
Processo de ordenação:
Divisão: 10 9 8 7 6 | 5 4 3 2 1
Divisão: 10 9 | 8 7 6 | 5 4 | 3 2 | 1
...
Depois da ordenação: 1 2 3 4 5 6 7 8 9 10
```

---

### **Resumo das Análises de Complexidade e Comportamento**:

- **Melhor, Caso Médio e Pior Caso**: O MergeSort possui uma complexidade de tempo de `O(n log n)` em todos os casos (melhor, médio e pior), o que o torna muito estável e eficiente para uma variedade de distribuições de dados.
- **Espaço**: A complexidade de espaço do MergeSort é `O(n)`, pois o algoritmo precisa de espaço adicional para armazenar as sublistas temporárias durante a divisão e mesclagem.

O MergeSort é eficiente para dados grandes e oferece um desempenho consistente, mas o uso de memória adicional pode ser uma limitação para sistemas com recursos limitados.

---

Agora o texto está adaptado para o **MergeSort**. Se precisar de mais alguma coisa, me avise!
