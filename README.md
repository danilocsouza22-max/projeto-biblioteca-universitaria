
# Sistema de Biblioteca Universitária

## 1. Introdução

Este projeto consiste no desenvolvimento de um sistema de gerenciamento de biblioteca universitária utilizando a linguagem de programação C.

O sistema foi desenvolvido com o objetivo de aplicar os conceitos estudados na disciplina de Programação Estruturada, incluindo estruturas de dados, funções, ponteiros, alocação dinâmica de memória, algoritmos de busca e ordenação e manipulação de arquivos.

O programa permite gerenciar livros, usuários, empréstimos e devoluções. Também oferece consultas ao histórico de empréstimos, exportação de relatórios e armazenamento persistente dos dados.

O desenvolvimento foi dividido em duas partes, com a implementação inicial das funcionalidades básicas e a posterior ampliação dos recursos do sistema.

## 2. Objetivos

O sistema possui como principais objetivos:

- Cadastrar e listar livros;
- Cadastrar e listar usuários;
- Buscar livros por título, autor e código;
- Buscar usuários por matrícula;
- Realizar empréstimos e registrar devoluções;
- Controlar a quantidade disponível de cada livro;
- Consultar o histórico de empréstimos por usuário;
- Ordenar livros por título e ano de publicação;
- Exportar relatórios com informações da biblioteca;
- Armazenar dados em arquivos de texto e binários;
- Utilizar vetores dinâmicos para armazenar os registros;
- Comparar o desempenho dos algoritmos de busca e ordenação;
- Organizar o código em módulos separados.

## 3. Funcionalidades

### 3.1. Cadastro de livros

O sistema permite cadastrar livros informando:

- Código;
- Título;
- Autor;
- Ano de publicação;
- Quantidade disponível.

O código funciona como identificador do livro e não pode ser repetido.

### 3.2. Listagem de livros

A listagem apresenta os livros cadastrados com código, título, autor, ano de publicação e quantidade disponível.

Caso não existam livros cadastrados, o sistema informa que o acervo está vazio.

### 3.3. Cadastro de usuários

O cadastro de usuários solicita:

- Matrícula;
- Nome;
- Curso.

A matrícula funciona como identificador do usuário e não pode ser repetida.

### 3.4. Listagem de usuários

A listagem apresenta a matrícula, o nome e o curso dos usuários cadastrados.

### 3.5. Busca sequencial de livros

O sistema permite pesquisar livros por título ou autor.

A busca percorre os registros cadastrados e verifica quais correspondem ao termo informado.

Também existe uma função de busca sequencial por código, utilizada na implementação do sistema e na análise de desempenho.

### 3.6. Busca de usuários

Os usuários podem ser localizados por meio da matrícula cadastrada.

### 3.7. Empréstimo de livros

Para realizar um empréstimo, são informados o código do livro e a matrícula do usuário.

Antes de registrar a operação, o sistema verifica:

- Se o livro existe;
- Se o usuário está cadastrado;
- Se existem exemplares disponíveis;
- Se o usuário já possui um empréstimo ativo daquele livro;
- Se existe capacidade de armazenamento para o novo registro.

Quando o empréstimo é realizado, a quantidade disponível do livro é reduzida em uma unidade.

### 3.8. Devolução de livros

Para registrar uma devolução, são informados o código do livro e a matrícula do usuário.

O sistema procura um empréstimo ativo correspondente. Quando encontrado:

1. O status do empréstimo é alterado para devolvido;
2. A quantidade disponível do livro aumenta em uma unidade;
3. Uma mensagem confirma a devolução.

O registro permanece armazenado para consultas posteriores.

### 3.9. Listagem de empréstimos

O sistema permite visualizar os empréstimos registrados, apresentando:

- Código do livro;
- Matrícula do usuário;
- Status do empréstimo.

Os status possíveis são ativo e devolvido.

### 3.10. Alocação dinâmica de memória

Na segunda parte do projeto, os registros passaram a ser armazenados em vetores dinâmicos.

A memória é alocada e expandida conforme a necessidade, utilizando funções da biblioteca padrão da linguagem C, como `malloc()` e `realloc()`.

O sistema possui funções específicas para expandir o armazenamento de livros, usuários e empréstimos.

Ao encerrar a execução, a memória utilizada é liberada com `free()`.

### 3.11. Ordenação com Bubble Sort

O sistema utiliza o algoritmo Bubble Sort para organizar os livros em ordem alfabética de título.

O algoritmo compara elementos adjacentes e realiza trocas quando necessário.

A implementação está disponível na função `ordenarLivrosBubbleSort()`.

### 3.12. Ordenação com Selection Sort

O algoritmo Selection Sort é utilizado para organizar os livros em ordem crescente de ano de publicação.

A implementação está disponível na função `ordenarLivrosSelectionSort()`.

O projeto também utiliza uma ordenação por código para preparar os registros antes da busca binária.

### 3.13. Busca binária

A busca binária permite localizar um livro por seu código.

Antes da pesquisa, os livros são organizados por código, pois o algoritmo exige que os dados estejam ordenados.

A função responsável pela pesquisa é `buscarLivroBinaria()`.

### 3.14. Histórico de empréstimos por usuário

O sistema permite consultar os empréstimos registrados para uma matrícula específica.

A consulta apresenta os livros associados ao usuário e informa se cada empréstimo está ativo ou foi devolvido.

Ao final, é apresentada a quantidade de empréstimos encontrados.

### 3.15. Exportação de relatório

O sistema permite gerar um relatório consolidado da biblioteca em arquivo de texto.

O arquivo é criado no caminho:

`dados/relatorio_biblioteca.txt`

O relatório apresenta:

- Quantidade de livros cadastrados;
- Quantidade de usuários cadastrados;
- Total de empréstimos registrados;
- Quantidade de empréstimos ativos;
- Quantidade de empréstimos devolvidos;
- Informações dos livros;
- Informações dos usuários;
- Registros dos empréstimos.

A exportação pode ser realizada pela opção 14 do menu principal.

## 4. Persistência dos dados

O sistema utiliza arquivos para manter os registros após o encerramento do programa.

### 4.1. Arquivos de texto

Os arquivos utilizados são:

- `dados/livros.txt`;
- `dados/usuarios.txt`;
- `dados/emprestimos.txt`.

Esses arquivos são carregados na inicialização e atualizados no encerramento do sistema.

### 4.2. Arquivos binários

Na segunda parte do projeto, foram implementadas funções de gravação e leitura de arquivos binários.

Os arquivos utilizados são:

- `dados/livros.dat`;
- `dados/usuarios.dat`;
- `dados/emprestimos.dat`.

A gravação utiliza `fwrite()` e a leitura utiliza `fread()`.

Na versão atual, o programa principal carrega os dados dos arquivos de texto na inicialização e salva os dados nos formatos de texto e binário ao encerrar.

As funções de leitura binária foram implementadas e testadas separadamente.

## 5. Tratamento de erros

O sistema possui verificações para evitar operações inválidas, incluindo:

- Código de livro duplicado;
- Matrícula de usuário duplicada;
- Livro inexistente;
- Usuário inexistente;
- Livro sem exemplares disponíveis;
- Tentativa de realizar um empréstimo duplicado;
- Tentativa de devolver um empréstimo inexistente;
- Ano de publicação negativo;
- Quantidade de livros negativa;
- Falha na alocação de memória;
- Falha na abertura de arquivos;
- Opções inválidas no menu.

## 6. Estrutura do projeto

### 6.1. Pasta `include/`

Contém os arquivos de cabeçalho responsáveis pelas declarações de estruturas e funções utilizadas pelos módulos.

Entre eles estão:

- `livros.h`;
- `usuarios.h`;
- `emprestimos.h`;
- `persistencia.h`;
- `relatorios.h`.

### 6.2. Pasta `src/`

Contém os arquivos de implementação do sistema:

- `main.c`: menu principal e integração das funcionalidades;
- `livros.c`: cadastro, listagem, busca e ordenação de livros;
- `usuarios.c`: cadastro, listagem e busca de usuários;
- `emprestimos.c`: empréstimos, devoluções e histórico;
- `persistencia.c`: leitura e gravação dos arquivos;
- `relatorios.c`: exportação do relatório consolidado.

### 6.3. Pasta `dados/`

Contém os arquivos utilizados para armazenar os registros de livros, usuários e empréstimos.

Também recebe o relatório gerado pela funcionalidade de exportação.

### 6.4. Pasta `testes/`

Contém os arquivos relacionados à análise de desempenho:

- `benchmark.c`: programa utilizado para medir os tempos de execução;
- `relatorio_desempenho.md`: documentação dos testes e resultados obtidos.

## 7. Compilação e execução

O projeto foi desenvolvido em linguagem C e pode ser compilado utilizando o GCC.

Os comandos abaixo devem ser executados na pasta principal do projeto.

### 7.1. Compilar o sistema

No terminal:

```powershell
gcc -Wall -Wextra -std=c11 src/*.c -o biblioteca.exe
```

### 7.2. Executar o sistema

No Windows, utilizando PowerShell:

```powershell
.\biblioteca.exe
```

O programa apresenta um menu com as opções disponíveis para gerenciamento da biblioteca.

### 7.3. Compilar o benchmark

```powershell
gcc -Wall -Wextra -std=c11 testes/benchmark.c src/livros.c -o benchmark.exe
```

### 7.4. Executar o benchmark

```powershell
.\benchmark.exe
```

## 8. Análise de desempenho

Foi desenvolvido um programa de testes para comparar os algoritmos de busca e ordenação utilizados no sistema.

Os testes foram realizados com conjuntos de 100, 500, 1.000 e 3.000 livros fictícios.

Foram comparados:

- Busca sequencial e busca binária;
- Bubble Sort e Selection Sort.

As medições foram realizadas utilizando a função `clock()`, da biblioteca padrão `<time.h>`.

As buscas foram repetidas 100.000 vezes para cada tamanho de entrada. Os tempos das ordenações correspondem à média de três execuções.

### 8.1. Resultados das buscas

| Livros | Busca sequencial (s) | Busca binária (s) |
|---|---:|---:|
| 100 | 0,044000 | 0,004000 |
| 500 | 0,218000 | 0,005000 |
| 1.000 | 0,458000 | 0,006000 |
| 3.000 | 1,308000 | 0,008000 |

### 8.2. Resultados das ordenações

| Livros | Bubble Sort (s) | Selection Sort (s) |
|---|---:|---:|
| 100 | 0,000000 | 0,000000 |
| 500 | 0,004000 | 0,000667 |
| 1.000 | 0,017333 | 0,001333 |
| 3.000 | 0,160333 | 0,011000 |

Os resultados indicaram menor crescimento do tempo de busca binária em relação à busca sequencial.

Nos testes realizados, o Selection Sort apresentou menores tempos de execução que o Bubble Sort.

Entretanto, os algoritmos de ordenação utilizam campos diferentes: o Bubble Sort ordena por título e o Selection Sort por ano. Essa diferença limita a comparação direta entre seus tempos.

O relatório completo, incluindo metodologia, análise e limitações dos testes, está disponível em:

`testes/relatorio_desempenho.md`

## 9. Considerações finais

O desenvolvimento do Sistema de Biblioteca Universitária permitiu colocar em prática diversos conceitos estudados na disciplina de Programação Estruturada, por meio da construção de um programa capaz de gerenciar livros, usuários, empréstimos e devoluções. A organização do código em diferentes módulos contribuiu para facilitar a implementação e a manutenção das funcionalidades, enquanto a utilização de arquivos possibilitou o armazenamento dos registros entre as execuções do sistema.

Na segunda parte do projeto, a implementação de vetores dinâmicos, algoritmos de busca e ordenação e operações com arquivos binários ampliou os recursos do programa e proporcionou uma compreensão mais aprofundada sobre o gerenciamento de memória e o processamento de dados em linguagem C. Além disso, a inclusão do histórico de empréstimos e da exportação de relatórios tornou o sistema mais completo. Os testes de desempenho também permitiram observar, na prática, como diferentes algoritmos se comportam diante do aumento da quantidade de registros.

Dessa forma, o projeto contribuiu para consolidar os conhecimentos adquiridos ao longo da disciplina, especialmente em relação ao uso de funções, ponteiros, estruturas de dados, manipulação de arquivos e organização de programas. A experiência também demonstrou a importância de realizar testes, identificar possíveis erros e aprimorar gradualmente uma aplicação durante seu desenvolvimento.