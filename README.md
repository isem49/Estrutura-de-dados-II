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

  ### Shell Sort e as Sequências de Intervalo

#### O que é o Shell Sort?
O **Shell Sort** é um algoritmo de ordenação que melhora o **Insertion Sort** (ordenando elementos próximos) ao permitir que elementos distantes sejam trocados mais rapidamente. Ele trabalha com intervalos (também conhecidos como "gap" ou "hops") para comparar e ordenar elementos que não estão imediatamente próximos, o que reduz o número de movimentações de elementos e melhora o desempenho comparado ao **Insertion Sort** convencional.

#### Sequências de Intervalos:
O desempenho do **Shell Sort** depende diretamente da **sequência de intervalos** escolhida. O algoritmo começa com um intervalo maior e, progressivamente, diminui até alcançar 1 (última iteração, onde o algoritmo se comporta como o Insertion Sort).

Aqui estão três das sequências de intervalo mais comuns:

### 1. Sequência de Shell:
- **Descrição**: A sequência de Shell é simples: comece com um intervalo que seja aproximadamente metade do tamanho da lista e depois vá diminuindo o intervalo pela metade a cada iteração.
- **Exemplo**: Para uma lista de 10 elementos, a sequência seria 5, 2, 1.
- **Desempenho**: A sequência de Shell tem desempenho melhor que o **Insertion Sort**, mas o desempenho ainda não é ótimo para listas grandes. A complexidade do tempo pode ser algo entre \(O(n^{3/2})\) e \(O(n^{2})}\), dependendo da lista.

### 2. Sequência de Knuth:
- **Descrição**: A sequência de Knuth foi proposta por Donald Knuth. Ela usa a fórmula \( h = 3^k - 1 \), onde \( h \) é o intervalo e \( k \) é um número inteiro tal que \( h \leq n \).
- **Exemplo**: Para uma lista de 100 elementos, os intervalos seriam 1, 4, 13, 40, 121, etc.
- **Desempenho**: A sequência de Knuth oferece uma melhoria significativa em comparação com a sequência de Shell, com um tempo de execução \(O(n^{3/2})\) ou melhor. Ela é mais eficiente, especialmente para listas maiores, devido ao intervalo mais "denso", que permite uma melhor ordenação no início.

### 3. Sequência de Hibbard:
- **Descrição**: A sequência de Hibbard é definida pela fórmula \( h = 2^k - 1 \), onde \( k \) é um número inteiro tal que \( h \leq n \). Essa sequência é mais agressiva do que a de Knuth, com saltos maiores, resultando em menos comparações em algumas situações.
- **Exemplo**: Para uma lista de 100 elementos, os intervalos seriam 1, 3, 7, 15, 31, 63, etc.
- **Desempenho**: A sequência de Hibbard tem melhor desempenho do que a de Shell em listas grandes. A complexidade pode atingir \(O(n^{3/2})\), mas tende a ser mais eficiente, já que há menos iterações no processo final de ordenação.

### Comparação de Desempenho das Sequências de Intervalo:

| **Sequência de Intervalo** | **Descrição**                         | **Complexidade de Tempo** | **Desempenho para Listas Pequenas** | **Desempenho para Listas Grandes** |
|----------------------------|---------------------------------------|---------------------------|-------------------------------------|------------------------------------|
| **Shell (Diminui pela metade)** | Simples, usa intervalos \(n/2, n/4, \dots\) | \(O(n^{3/2})\) a \(O(n^2)\) | Moderado                           | Ruim a Moderado                   |
| **Knuth**                   | Baseado em \(3^k - 1\)                | \(O(n^{3/2})\)             | Bom                                 | Muito bom                         |
| **Hibbard**                 | Baseado em \(2^k - 1\)                | \(O(n^{3/2})\)             | Muito bom                           | Excelente                         |

### Impacto da Sequência de Intervalos no Desempenho:

1. **Desempenho em Listas Grandes**:
   - Para listas grandes, a escolha de uma boa sequência é crítica. A **sequência de Knuth** e **Hibbard** oferecem melhor desempenho para listas grandes porque os intervalos diminuem mais rapidamente, permitindo que o algoritmo se aproxime de um **Insertion Sort** muito eficiente para as últimas passagens.

2. **Desempenho em Listas Pequenas**:
   - Em listas pequenas, as diferenças de desempenho entre as sequências podem ser menos notáveis. O **Shell** ainda pode ser uma boa escolha em casos simples, mas em listas moderadas ou grandes, as sequências **Knuth** e **Hibbard** são superiores.



