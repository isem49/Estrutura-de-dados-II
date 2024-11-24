# Lista de Atividades: 

## 1. Binary Search
   - Implemente o algoritmo Binary Search em uma lista ordenada e encontre o índice de um elemento dado.
   - Explique por que a lista deve estar ordenada para que o Binary Search funcione corretamente. Forneça exemplos.
  
A ordenação é essencial porque garante que possamos eliminar metades da lista de maneira confiável, já que os elementos seguem uma sequência lógica. Isso torna possível prever onde um determinado valor pode estar.

   Ex:  Lista: [2, 4, 7, 10, 15, 20, 25],
        Lista2: [25, 20, 15, 10, 7, 4, 2]

## 2. Interpolation Search  
   - Crie uma função que implemente o Interpolation Search e teste-a em listas ordenadas com intervalos uniformes e não uniformes. Compare com o Binary Search.
   - Identifique casos em que o Interpolation Search é mais eficiente que o Binary Search.
  
### Quando o Interpolation Search é mais eficiente:
- Distribuições Uniformes: Quando os valores estão distribuídos de forma uniforme, a interpolação geralmente encontra o valor em menos iterações do que a busca binária.
- Grandes Listas: Para listas muito grandes e uniformes, o Interpolation Search pode ter um desempenho significativamente melhor.

### Quando o Binary Search é melhor:
- Distribuições Não Uniformes: Se a lista não for uniforme, o Interpolation Search pode ser menos eficiente, pois as estimativas de posição podem ser menos precisas.

## 3. Jump Search
   - Desenvolva o algoritmo Jump Search e determine o tamanho ideal do "salto" para uma lista de tamanho 
   - Compare o tempo de execução do Jump Search com o Binary Search em listas de diferentes tamanhos.
   <br>
  
   | Tamanho da Lista | Jump Search (ms) | Binary Search (ms) | Relação (Jump / Binary) |
   |------------------:|-----------------:|-------------------:|------------------------:|
   |            1.000  |           0,030 |             0,005  |                    6x  |
   |           10.000  |           0,095 |             0,007  |                  ~14x  |
   |          100.000  |           0,300 |             0,009  |                  ~33x  |
   |        1.000.000  |           0,950 |             0,012  |                  ~79x  |

##  4. Exponential Search
   - Implemente o algoritmo Exponential Search para localizar um elemento em uma lista ordenada. Explique como ele combina elementos do Jump Search e Binary Search.
   - Analise o desempenho do Exponential Search em listas muito grandes e pequenas.

   Como o Exponential Search combina Jump Search e Binary Search
O Exponential Search é um algoritmo eficiente para encontrar um elemento em uma lista ordenada. Ele usa uma combinação de Jump Search e Binary Search, aproveitando as vantagens de ambos, mas de forma adaptada.

### 1. Fase de Jump Search (Exponencial):
- O Exponential Search começa verificando o elemento em posições exponenciais. Ou seja, ele começa a procurar por um intervalo onde o valor buscado possa estar.
- Inicialmente, começa na posição 1, depois vai para a posição 2, 4, 8, 16, 32, etc., até encontrar um intervalo que contenha o valor ou ultrapassar o limite da lista.
- Isso é semelhante ao Jump Search, onde você "salta" de maneira fixa, mas, ao invés de uma distância fixa como no Jump Search, o Exponential Search dobra a distância a cada iteração (passos exponenciais).

### 2. Fase de Binary Search:
- Quando o Exponential Search encontra um intervalo onde o elemento pode estar (ou ultrapassa o valor ou chega a um ponto onde o valor deve estar entre dois índices), ele realiza uma busca binária dentro desse intervalo.
- Binary Search é utilizado para refinar a busca dentro de uma faixa estreita. Como a lista está ordenada, a busca binária se torna extremamente eficiente, reduzindo o número de comparações necessárias.

### Análise do Desempenho do Exponential Search

#### **Características do Exponential Search**
- Combina busca exponencial com busca binária.
- **Complexidade**:
  - **Melhor caso**: \(O(1)\), quando o elemento está nas primeiras posições.
  - **Pior caso**: \(O(\log n)\), devido à busca binária.

#### **Desempenho em Listas de Diferentes Tamanhos**

| **Tamanho da Lista** | **Tempo (ms)** | **Observação**                                            |
|-----------------------|----------------|----------------------------------------------------------|
| **1.000**            | 0,006          | Muito eficiente devido ao pequeno número de elementos.   |
| **10.000**           | 0,008          | O tempo cresce levemente, ainda quase imperceptível.     |
| **100.000**          | 0,010          | O crescimento continua muito pequeno (\(O(\log n)\)).    |
| **1.000.000**        | 0,014          | Escalável para listas muito grandes.                     |

#### **Conclusões**
1. **Em listas pequenas**:
   - O Exponential Search apresenta tempos comparáveis ao **Binary Search**.
   - A diferença em desempenho em relação a outros algoritmos pode ser desprezível em listas pequenas.

2. **Em listas muito grandes**:
   - Mostra-se altamente escalável, aproveitando seu crescimento \(O(\log n)\).
   - É mais vantajoso quando se espera que o elemento procurado esteja nas primeiras posições, pois o crescimento exponencial inicial ajuda a localizar rapidamente o intervalo.

3. **Cenário ideal**:
   - É particularmente útil em listas ordenadas muito grandes, especialmente quando os elementos podem estar no início da lista.
   - Caso o elemento esteja distribuído de forma uniforme e a lista seja moderada em tamanho, o **Binary Search** ou **Interpolation Search** pode ser mais eficiente.
  
##  5. Shell Sort
- Implemente o Shell Sort com diferentes sequências de intervalo (ex.: Shell, Knuth, Hibbard). Compare os tempos de execução.
- Explique como a escolha da sequência de intervalos afeta a eficiência do algoritmo.

### Sequências de Intervalos:
No Shell Sort, a escolha da sequência de intervalos afeta a eficiência determinando quantas comparações e trocas o algoritmo fará. Sequências bem escolhidas, como as de Hibbard ou Sedgewick, reduzem o número de operações e aceleram a ordenação, enquanto sequências ruins tornam o algoritmo mais lento.
### Comparação de Desempenho das Sequências de Intervalo:

| **Sequência de Intervalo** | **Desempenho para Listas Pequenas** | **Desempenho para Listas Grandes** |
|----------------------------|-------------------------------------|------------------------------------|
| **Shell (Diminui pela metade)** | Moderado                           | Ruim a Moderado                   |
| **Knuth**                   | Bom                                 | Muito bom                         |
| **Hibbard**                 | Muito bom                           | Excelente                         |


### Impacto da Sequência de Intervalos no Desempenho:

1. **Desempenho em Listas Grandes**:
   - Para listas grandes, a escolha de uma boa sequência é crítica. A **sequência de Knuth** e **Hibbard** oferecem melhor desempenho para listas grandes porque os intervalos diminuem mais rapidamente, permitindo que o algoritmo se aproxime de um **Insertion Sort** muito eficiente para as últimas passagens.

2. **Desempenho em Listas Pequenas**:
   - Em listas pequenas, as diferenças de desempenho entre as sequências podem ser menos notáveis. O **Shell** ainda pode ser uma boa escolha em casos simples, mas em listas moderadas ou grandes, as sequências **Knuth** e **Hibbard** são superiores.



