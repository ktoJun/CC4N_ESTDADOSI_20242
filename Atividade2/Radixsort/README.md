**Portfólio - Estrutura de Dados I - Atividade II**

---

## **Parte 2** – Implementação Individual dos Algoritmos (até 16/11) - via Github

Cada aluno deverá implementar três métodos de ordenação (Shellsort, Quicksort, Heapsort, RadixSort e/ou Mergesort) de forma independente, seguindo as diretrizes:

1. Escrever o Código: Implementar cada algoritmo em linguagem C, com todos os comentários de código pertinentes ao entendimento da atividade.
2. Analisar a Complexidade: Registrar a complexidade de tempo e espaço de cada algoritmo nos casos melhor, médio e pior.
3. Executar Testes: Testar os algoritmos com conjuntos de dados variados, analisando os resultados e a eficiência em cada caso.

Entrega: Cada aluno deverá entregar os códigos implementados, com análises de complexidade e resultados dos testes, via fork do github da disciplina.

---

## **Análise de Complexidade - Radix Sort**

### **Complexidade de Tempo**

1. **Melhor Caso (O(nk))**:  
   O Radix Sort possui um desempenho de O(nk) no melhor caso, onde:
   - **n** é o número de elementos no array.
   - **k** é o número de dígitos (ou posições) do maior número no array (isto é, o número de passes que o algoritmo realiza sobre os dados).
   
   No caso ideal, o Radix Sort realiza um número fixo de passes sobre os dados, onde a distribuição dos elementos nos "buckets" é eficiente e a ordenação de cada "bucket" é feita rapidamente. Como não depende da distribuição dos dados, o tempo é linear em relação ao número de elementos.

2. **Caso Médio (O(nk))**:  
   No caso médio, o Radix Sort também tem complexidade O(nk), pois o número de passes e a distribuição dos dados continuam a depender do número de dígitos. Como o algoritmo não compara diretamente os elementos, a complexidade depende principalmente da base de números e do número de passes necessários.

3. **Pior Caso (O(nk))**:  
   No pior caso, o Radix Sort também possui O(nk) de complexidade. Isso ocorre porque, independentemente da distribuição dos dados, o algoritmo realiza k passes sobre os dados, e o tempo por passagem é proporcional ao número de elementos (n).

### **Complexidade de Espaço**

1. **Melhor Caso (O(n))**:  
   O espaço utilizado é proporcional ao número de elementos, pois o Radix Sort precisa de uma estrutura extra (como um array ou fila) para armazenar os "buckets". O espaço utilizado é O(n), já que são necessários **n** espaços para armazenar os dados durante a ordenação.

2. **Caso Médio (O(n))**:  
   No caso médio, o espaço adicional usado pelo Radix Sort também é O(n). A complexidade de espaço é dominada pelo armazenamento temporário para a distribuição dos elementos durante o processo de ordenação.

3. **Pior Caso (O(n))**:  
   No pior caso, o espaço adicional é O(n), pois a estrutura de armazenamento dos elementos continua a ser de tamanho proporcional ao número de elementos.

---

## **Execução de Testes - Radix Sort**

### **Testes e Expectativas de Comportamento**

1. **Array Aleatório**:
   - **Descrição**: Para um array com elementos aleatórios, o Radix Sort deve funcionar de forma eficiente, com tempo de execução de O(nk), sendo o valor de k o número de dígitos dos números. Para inteiros de tamanho fixo, o desempenho tende a ser muito bom.
   - **Comportamento Esperado**: O Radix Sort irá ordenar os elementos em tempo linear com relação ao número de elementos e ao número de dígitos. Para arrays de tamanho razoável e números com poucos dígitos, o tempo de execução será eficiente.

   **Exemplo de Saída de Testes**:
   - **Antes da ordenação**: 53, 92, 45, 81, 34, 61, 67, 72, 42, 80  
   - **Depois da ordenação**: 34, 42, 45, 53, 61, 67, 72, 80, 81, 92

2. **Array Já Ordenado**:
   - **Descrição**: Mesmo que o array já esteja ordenado, o Radix Sort ainda realiza o mesmo número de passes para ordenar os dados. Isso ocorre porque o algoritmo não realiza comparações diretas entre os elementos, mas sim distribui os números em "buckets" com base nos seus dígitos.  
   - **Comportamento Esperado**: O Radix Sort manterá a mesma complexidade O(nk) independentemente de o array estar ou não ordenado.

   **Exemplo de Saída de Testes**:
   - **Antes da ordenação**: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10  
   - **Depois da ordenação**: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

3. **Array em Ordem Reversa**:
   - **Descrição**: Para arrays em ordem inversa, o Radix Sort ainda irá ordenar os elementos de forma eficiente, já que ele não depende da ordem atual dos elementos. O tempo de execução será O(nk), e o algoritmo continuará a realizar a ordenação de maneira estável, sem depender da ordem original dos dados.  
   - **Comportamento Esperado**: A ordem reversa não impacta o desempenho, que continua sendo O(nk).

   **Exemplo de Saída de Testes**:
   - **Antes da ordenação**: 10, 9, 8, 7, 6, 5, 4, 3, 2, 1  
   - **Depois da ordenação**: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

4. **Arrays Muito Grandes**:
   - **Descrição**: Para arrays muito grandes, o Radix Sort ainda mantém a complexidade de O(nk). O desempenho é eficiente em termos de tempo, mas pode ser afetado pela quantidade de dígitos que os números possuem. Para números muito grandes (com muitos dígitos), o valor de k aumenta, o que pode resultar em maior tempo de execução.
   - **Comportamento Esperado**: O Radix Sort lida bem com grandes quantidades de dados, desde que o número de dígitos não seja excessivamente grande. Se os números forem de tamanho razoável, o algoritmo deve continuar sendo eficiente.

   **Exemplo de Saída de Testes** (em um array muito grande de 1.000.000 de elementos):
   - **Antes da ordenação**: Uma sequência de números aleatórios.
   - **Depois da ordenação**: Uma sequência de números ordenados do menor para o maior.

---

## **Resumo das Análises de Complexidade e Comportamento**

- **Melhor e Caso Médio**: O Radix Sort possui uma complexidade de tempo de O(nk) em ambos os casos, o que o torna eficiente quando o número de dígitos **k** não é muito grande.
- **Pior Caso**: Mesmo no pior caso, a complexidade permanece O(nk), já que o algoritmo sempre realiza o mesmo número de passes e distribuições sobre os dados.
- **Espaço**: A complexidade de espaço é O(n), pois o algoritmo usa espaço adicional para armazenar os dados enquanto realiza a ordenação.

Esse comportamento faz do **Radix Sort** um algoritmo altamente eficiente para dados com números inteiros de tamanho limitado e quando a quantidade de dígitos (k) é pequena. Em arrays com números muito grandes (em termos de dígitos), a eficiência do algoritmo pode ser reduzida devido ao aumento de **k**.

---

Se precisar de algum código ou mais detalhes sobre a implementação do Radix Sort, é só avisar!
