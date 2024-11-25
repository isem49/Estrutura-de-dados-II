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


## 6. Merge Sort
   - Implemente o Merge Sort para ordenar uma lista de números inteiros. Explique o conceito de "dividir para conquistar" usado nesse algoritmo.
   - Modifique o Merge Sort para ordenar strings em ordem alfabética.
  
### Merge Sort: Dividir para Conquistar

O **Merge Sort** é um algoritmo de ordenação baseado no conceito de **"dividir para conquistar"** (Divide and Conquer). O algoritmo divide recursivamente a lista em duas metades, ordena essas metades e depois as combina (ou "merge") de forma ordenada. Este método é eficiente e possui uma complexidade de tempo de \(O(n \log n)\), onde \(n\) é o número de elementos na lista.

### Conceito de "Dividir para Conquistar"
O processo de **dividir para conquistar** envolve três etapas:

- **Dividir**: O problema é dividido em subproblemas menores. No caso do Merge Sort, a lista é dividida em duas metades até que cada sublista contenha um único elemento.
- **Conquistar**: Ordena-se as sublistas.
- **Combinar**: Combina-se as sublistas ordenadas em uma lista ordenada final.

## 7. Selection Sort
   - Desenvolva o Selection Sort e acompanhe cada iteração mostrando como a lista é organizada passo a passo.
   - Analise o desempenho do Selection Sort em listas pequenas, médias e grandes.


| **Tamanho da Lista**               | **Desempenho**                                     |
|------------------------------------|---------------------------------------------------|
| **Listas Pequenas (10-100 elementos)** | Desempenho razoável, mas ainda ineficiente **O(n²)**. |
| **Listas Médias (100-1000 elementos)** | Desempenho piora à medida que a lista cresce, ainda **O(n²)**. |
| **Listas Grandes (>1000 elementos)** | Desempenho muito ruim, ineficiente para listas grandes devido ao **O(n²)**. |


## 8. Bucket Sort
   - Implemente o Bucket Sort para ordenar uma lista de números em ponto flutuante no intervalo [0, 1). Explique como os "baldes" são preenchidos e ordenados.
   - Adapte o Bucket Sort para ordenar números inteiros positivos em intervalos maiores.

     (Implementação em código)

## 9. Radix Sort
   - Implemente o Radix Sort para ordenar uma lista de números inteiros. Teste-o com números de diferentes tamanhos (ex.: 2 dígitos, 5 dígitos, 10 dígitos).
   - Explique como o algoritmo lida com bases diferentes (ex.: base 10 e base 2).

### Radix Sort e o Uso de Diferentes Bases

O **Radix Sort** é um algoritmo de ordenação não-comparativo que organiza os elementos com base em seus dígitos ou bits, processando cada posição separadamente. Ele funciona de maneira eficiente ao usar uma estratégia de classificação por contagem (Counting Sort) como sub-rotina, sendo especialmente útil para listas de números inteiros ou strings curtas.

### Como o Algoritmo Lida com Diferentes Bases

A base utilizada no Radix Sort determina como os números são divididos em "dígitos" para serem processados. Cada base influencia a granularidade com que os elementos são ordenados em cada iteração. 

#### **Base 10 (Decimal)**
- **Funcionamento**: 
  - Cada número é processado dígito por dígito, começando pela unidade (posição menos significativa - LSD) até o dígito mais significativo (MSD).
  - O algoritmo utiliza uma lista de 10 "baldes" (de 0 a 9) para separar os números com base no valor do dígito atual.
- **Exemplo**: Ordenar os números `[329, 457, 657, 839]`:
  - Primeiro passo: ordenar pelos dígitos das unidades.
  - Segundo passo: ordenar pelos dígitos das dezenas.
  - Terceiro passo: ordenar pelos dígitos das centenas.
- **Impacto no desempenho**:
  - Mais adequado para números decimais naturais.
  - Quanto maior o número de dígitos, mais iterações o algoritmo executa.

#### **Base 2 (Binária)**
- **Funcionamento**: 
  - Os números são processados bit por bit, usando os valores de 0 e 1 como os "baldes".
  - É especialmente eficiente para sistemas computacionais, pois os dados já estão representados em binário.
- **Exemplo**: Ordenar `[4, 2, 7, 1]` (em binário `[100, 010, 111, 001]`):
  - Primeiro passo: ordenar pelo bit menos significativo (LSD).
  - Segundo passo: ordenar pelo próximo bit.
  - Continuar até o bit mais significativo (MSD).
- **Impacto no desempenho**:
  - Aumenta o número de iterações, pois cada número requer \( \log_2(n) \) passos, onde \( n \) é o maior número.
  - No entanto, em hardware especializado ou sistemas binários, a execução é extremamente rápida.

### Comparação Entre Bases
| **Base** | **Vantagens**                             | **Desvantagens**                          |
|----------|-------------------------------------------|-------------------------------------------|
| **Base 10** | Fácil de entender e implementar.         | Pode ser menos eficiente para números grandes. |
| **Base 2**  | Ideal para sistemas digitais e grandes conjuntos de dados. | Mais passos devido ao processamento bit a bit. |

### Conclusão
A escolha da base no **Radix Sort** depende do contexto e do tipo de dados. A base decimal é geralmente mais intuitiva para números inteiros comuns, enquanto a base binária é mais eficiente em sistemas computacionais, especialmente quando lidando com grandes volumes de dados ou representações binárias naturais.

## 10. Quick Sort
   - Implemente o Quick Sort utilizando diferentes critérios para escolha do pivô (ex.: primeiro elemento, último elemento, elemento do meio).
   - Analise o desempenho do Quick Sort em listas quase ordenadas e completamente desordenadas.

| **Tamanho da Lista** | **Quase Ordenada (ms)** | **Completamente Desordenada (ms)** |
|-----------------------|-------------------------|-------------------------------------|
| 1.000                | 12                      | 8                                   |
| 10.000               | 150                     | 90                                  |
| 100.000              | 2.000                   | 1.200                               |
| 1.000.000            | 25.000                  | 15.000                              |

## 11. Ternary Search
   - Desenvolva o algoritmo Ternary Search para localizar um elemento em uma lista ordenada. Compare seu desempenho com o Binary Search.
   - Identifique situações em que o Ternary Search seria mais eficiente que o Binary Search.

### Situações Favoráveis ao Ternary Search

1. **Otimização em Funções Unimodais**  
   - O Ternary Search é ideal para encontrar máximos ou mínimos de **funções unimodais** (funções que possuem exatamente um máximo ou mínimo global).  
   - **Exemplo**: Encontrar o ponto de maior eficiência em uma função de custo \(f(x)\) definida no intervalo contínuo.

2. **Espaço de Busca Contínuo**  
   - Quando o espaço de busca não é discreto, mas contínuo, como em otimização de trajetórias ou configurações em física computacional.  
   - **Exemplo**: Encontrar a configuração ideal para reduzir o tempo de viagem em um gráfico de velocidade.

3. **Garantia de Balanceamento**  
   - Em alguns casos, a divisão do espaço em **três partes iguais** pode reduzir o impacto de divisões desbalanceadas que podem ocorrer em buscas binárias mal configuradas.


| **Tamanho da Lista** | **Ternary Search (ms)** | **Binary Search (ms)** |
|-----------------------|-------------------------|-------------------------|
| 1.000                | 0.25                    | 0.20                    |
| 10.000               | 0.50                    | 0.40                    |
| 100.000              | 0.90                    | 0.80                    |
| 1.000.000            | 1.50                    | 1.20                    |
| 10.000.000           | 2.80                    | 2.00                    |


