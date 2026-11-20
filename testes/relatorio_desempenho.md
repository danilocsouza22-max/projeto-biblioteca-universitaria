# Relatório de Análise de Desempenho

## 1. Introdução

Este relatório apresenta uma análise comparativa do desempenho dos algoritmos de busca e ordenação implementados no Sistema de Biblioteca Universitária, desenvolvido em linguagem C.

Foram analisados quatro algoritmos:

- Busca sequencial;
- Busca binária;
- Bubble Sort;
- Selection Sort.

O objetivo é observar o comportamento dos tempos de execução conforme aumenta a quantidade de livros processados.

## 2. Metodologia

Os testes foram realizados por meio do programa `testes/benchmark.c`, utilizando as funções originais implementadas em `src/livros.c`.

Foram gerados conjuntos de dados fictícios com 100, 500, 1.000 e 3.000 livros, sem modificar os registros reais da biblioteca.

A medição dos tempos foi realizada com a função `clock()`, disponível na biblioteca padrão `<time.h>` da linguagem C.

### 2.1. Testes de busca

Foram comparadas as funções:

- `encontrarLivroPorCodigo()`: busca sequencial;
- `buscarLivroBinaria()`: busca binária.

Para cada quantidade de livros, foram realizadas 100.000 buscas por um mesmo código inexistente, representando um caso desfavorável para a busca sequencial.

Antes da busca binária, os livros foram ordenados pelo código utilizando `ordenarLivrosPorCodigo()`.

O tempo dessa ordenação prévia não foi incluído no tempo medido da busca binária. Portanto, os resultados comparam apenas as operações de busca sobre suas respectivas estruturas de dados.

### 2.2. Testes de ordenação

Foram comparadas as funções:

- `ordenarLivrosBubbleSort()`: ordenação por título;
- `ordenarLivrosSelectionSort()`: ordenação por ano de publicação.

Cada algoritmo foi executado três vezes para cada tamanho de entrada. Os tempos apresentados correspondem à média dessas três execuções.

As ordenações utilizaram cópias independentes dos mesmos registros fictícios, evitando que a execução de um algoritmo alterasse os dados de entrada do outro.

Os registros foram gerados em ordem decrescente de título e ano.

Como as implementações ordenam por campos diferentes e utilizam operações de comparação distintas, os tempos permitem observar o desempenho das funções implementadas, mas não constituem uma comparação perfeitamente controlada entre os algoritmos.

## 3. Resultados

### 3.1. Algoritmos de busca

| Quantidade de livros | Busca sequencial (s) | Busca binária (s) |
|---|---:|---:|
| 100 | 0,044000 | 0,004000 |
| 500 | 0,218000 | 0,005000 |
| 1.000 | 0,458000 | 0,006000 |
| 3.000 | 1,308000 | 0,008000 |

### 3.2. Algoritmos de ordenação

| Quantidade de livros | Bubble Sort (s) | Selection Sort (s) |
|---|---:|---:|
| 100 | 0,000000 | 0,000000 |
| 500 | 0,004000 | 0,000667 |
| 1.000 | 0,017333 | 0,001333 |
| 3.000 | 0,160333 | 0,011000 |

Os valores apresentados foram obtidos na execução real do programa de testes.

Os tempos registrados como 0,000000 segundo indicam que a duração foi inferior à resolução observada na medição, não que a operação tenha sido instantânea.

## 4. Análise dos resultados

### 4.1. Busca sequencial e busca binária

A busca sequencial percorre os registros até encontrar o elemento procurado ou atingir o final da lista. Sua complexidade de tempo no pior caso é O(n).

A busca binária divide sucessivamente o intervalo de pesquisa pela metade. Sua complexidade de tempo é O(log n), desde que os dados estejam previamente ordenados.

Nos testes com 3.000 livros, foram registrados:

- Busca sequencial: 1,308000 segundos;
- Busca binária: 0,008000 segundos.

Nesse cenário, a busca binária apresentou um tempo aproximadamente 163,5 vezes menor que o da busca sequencial.

Entretanto, esse resultado considera apenas a execução das buscas. Em situações nas quais seja necessário ordenar os dados antes de cada pesquisa, o custo da ordenação também deve ser considerado.

### 4.2. Bubble Sort e Selection Sort

O Bubble Sort compara elementos adjacentes e realiza trocas quando estão fora da ordem desejada.

O Selection Sort procura o menor elemento da parte ainda não ordenada e o posiciona na posição correta.

As implementações utilizadas apresentam complexidade de tempo O(n²).

Nos testes com 3.000 livros, foram registrados:

- Bubble Sort: 0,160333 segundos;
- Selection Sort: 0,011000 segundos.

O Selection Sort apresentou menor tempo de execução nessa medição.

Essa diferença não deve ser interpretada como uma superioridade universal do Selection Sort, pois o desempenho depende da implementação, dos dados de entrada, das operações de comparação e do ambiente de execução.

## 5. Limitações dos testes

Os resultados representam uma execução específica do benchmark e podem variar conforme o computador, o compilador e a carga de processamento do sistema.

As medições de busca foram realizadas com 100.000 repetições, enquanto as medições de ordenação representam médias de três execuções.

Além disso, a comparação de ordenação envolve campos diferentes: título no Bubble Sort e ano no Selection Sort.

Por esses motivos, os valores devem ser interpretados como evidências experimentais do comportamento das funções do projeto, e não como medidas universais de desempenho.

## 6. Conclusão

A análise demonstrou que o aumento da quantidade de livros afeta diretamente o tempo de execução dos algoritmos.

A busca binária apresentou crescimento de tempo significativamente menor que a busca sequencial, confirmando a vantagem de pesquisar dados previamente ordenados em conjuntos maiores.

Nos testes de ordenação, o Selection Sort apresentou menores tempos que o Bubble Sort, embora ambos tenham complexidade quadrática e a comparação experimental apresente limitações.

Os resultados reforçam a importância da escolha de algoritmos adequados para melhorar a eficiência de sistemas que manipulam quantidades crescentes de registros.

## 7. Reprodução dos testes

Para compilar o programa de análise de desempenho, executar na pasta principal do projeto:

```powershell
gcc -Wall -Wextra -std=c11 testes/benchmark.c src/livros.c -o benchmark.exe
```

Para executar:

```powershell
.\benchmark.exe
```

O programa apresenta os tempos medidos para cada quantidade de livros.
