## **Portfólio - Estrutura de Dados I - Atividade II**

## **Parte 2** – Implementação Individual dos Algoritmos (até 16/11) - via Github

Cada aluno deverá implementar três métodos de ordenação (Shellsort, Quicksort, Heapsort, RadixSort e/ou Mergesort) de forma independente, seguindo as diretrizes:

1. Escrever o Código: Implementar cada algoritmo em linguagem C, com todos os comentários de código pertinentes ao entendimento da atividade.
2. Analisar a Complexidade: Registrar a complexidade de tempo e espaço de cada algoritmo nos casos melhor, médio e pior.
3. Executar Testes: Testar os algoritmos com conjuntos de dados variados, analisando os resultados e a eficiência em cada caso.
Entrega: Cada aluno deverá entregar os códigos implementados, com análises de complexidade e resultados dos testes, via fork do github da disciplina.

## **2. Analisar a Complexidade** - MergeSort

Complexidade de Tempo
- Melhor caso: O(nlogn)
- Caso médio:  O(nlogn)
- Pior caso:   O(nlogn)

Complexidade de Espaço
- Melhor caso: O(n)
- Caso médio:  O(n)
- Pior caso:   O(n)


## **3. Executar Testes** - MergeSort
Array Aleatório: Neste caso, o Merge Sort deve funcionar de maneira eficiente, já que ele divide e mescla os elementos, o que leva O(nlog n) operações, independentemente da distribuição dos dados.

Array Já Ordenado: O Merge Sort sempre dividirá o array recursivamente e fará as comparações necessárias, resultando em uma complexidade de O(nlog n) também. Mesmo que o array já esteja ordenado, o algoritmo não se beneficia de otimizações como no Bubble Sort ou Insertion Sort (que poderiam ser mais rápidos no melhor caso).

Array em Ordem Reversa: No caso do array estar ordenado de forma inversa, o Merge Sort ainda terá a mesma performance, com complexidade O(nlog n), pois ele sempre dividirá e mesclará os elementos, sem importar a ordem inicial.

Arrays Muito Grandes: A performance do Merge Sort continua a ser O(n\log n), e ele pode lidar bem com arrays grandes. A desvantagem é o uso adicional de memória para as sublistas temporárias, o que pode ser um fator limitante em sistemas com pouca memória.
