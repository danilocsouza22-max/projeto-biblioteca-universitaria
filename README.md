# Sistema de Biblioteca Universitária

Este projeto consiste no desenvolvimento de um sistema de gerenciamento de uma biblioteca universitária utilizando a linguagem de programação C. O sistema foi desenvolvido com o objetivo de aplicar conceitos fundamentais vistos nas aulas de Programação Estruturada. O sistema permite o gerenciamento de livros e usuários, além do controle de empréstimos e devoluções. Os dados utilizados pelo sistema são armazenados em arquivos de texto (`.txt`), permitindo que as informações cadastradas permaneçam salvas mesmo após o encerramento do programa.

# 2.Objetivos

O sistema possui como principais objetivos:

- Cadastrar livros;
- Listar os livros cadastrados;
- Cadastrar usuários;
- Listar os usuários cadastrados;
- Buscar livros por título;
- Buscar livros por autor;
- Buscar usuários por matrícula;
- Realizar empréstimos;
- Registrar devoluções;
- Controlar a quantidade disponível de cada livro;
- Listar os empréstimos registrados;
- Armazenar os dados de forma persistente em arquivos `.txt`;
- Separar as funcionalidades do sistema em diferentes módulos;
- Aplicar boas práticas de organização de código em C.

# 3.Funcionalidades

## 3.1Cadastro de livros

O sistema permite cadastrar livros informando:

- Código;
- Título;
- Autor;
- Ano de publicação;
- Quantidade disponível.

O código do livro funciona como identificador e não pode ser repetido.

## 3.2 Listagem de livros

A opção de listagem apresenta todos os livros cadastrados e suas respectivas informações.

São exibidos:

- Código;
- Título;
- Autor;
- Ano;
- Quantidade disponível.

Caso não existam livros cadastrados, o sistema informa que o acervo está vazio.

## 3.3 Cadastro de usuários

O sistema permite cadastrar usuários informando:

- Matrícula;
- Nome;
- Curso.

A matrícula funciona como identificador do usuário e não pode ser repetida.

## 3.4 Listagem de usuários

Através dessa funcionalidade é possível visualizar todos os usuários cadastrados, apresentando:

- Matrícula;
- Nome;
- Curso.

## 3.5 Busca de livros

O sistema possui busca sequencial de livros, sendo realizanodo, portanto, buscando por:

- Título;
- Autor.

A busca percorre os livros cadastrados e verifica quais registros correspondem ao termo informado.

## 3.6 Busca de usuários

Os usuários podem ser localizados através de sua matrícula.

## 3.7 Empréstimo de livros

Para realizar um empréstimo são informados:

- Código do livro;
- Matrícula do usuário.

Antes de registrar o empréstimo, o sistema verifica:

- Se o livro existe;
- Se existem exemplares disponíveis;
- Se o usuário existe;
- Se o usuário já possui aquele mesmo livro emprestado;
- Se ainda existe espaço para registrar novos empréstimos.

Quando o empréstimo é realizado, a quantidade disponível do livro é reduzida em uma unidade.

O empréstimo também recebe um status, que indica se ele está ativo ou se já foi devolvido.

## 3.8 Devolução de livros

Para realizar uma devolução são informados:

- Código do livro;
- Matrícula do usuário.

O sistema procura um empréstimo ativo correspondente.

Quando o empréstimo é encontrado:

1. O status do empréstimo é alterado para devolvido;
2. A quantidade disponível do livro é aumentada em uma unidade;
3. O sistema informa que a devolução foi realizada com sucesso.

Caso o empréstimo não seja encontrado, uma mensagem de erro é apresentada.

## 3.9 Listagem de empréstimos

O sistema permite visualizar todos os empréstimos registrados.

Para cada empréstimo são apresentados:

- Código do livro;
- Matrícula do usuário;
- Status do empréstimo.

O status pode ser:

- Ativo;
- Devolvido.

Os registros de empréstimos anteriores permanecem armazenados mesmo depois que o livro é devolvido.

## 4.0 Tratamento de erros

O sistema possui verificações para evitar situações inválidas, como nos seguintes casos:

- Código de livro vazio;
- Matrícula de usuário vazia;
- Livro inexistente;
- Usuário inexistente;
- Livro sem exemplares disponíveis;
- Matrícula de usuário duplicada;
- Código de livro duplicado;
- Tentativa de realizar o mesmo empréstimo duas vezes;
- Tentativa de devolver um empréstimo inexistente;
- Quantidade negativa de livros;
- Ano de publicação negativo;
- Limite máximo de livros atingido;
- Limite máximo de usuários atingido;
- Limite máximo de empréstimos atingido;
- Opções inválidas no menu.

# 5. Estrutura de Pastas

## `include/`

A pasta `include/` contém os arquivos de cabeçalho (`.h`) do projeto, os quais definem as estruturas de dados das funções utilizadas pelos diferentes módulos do sistema. A separação dos cabeçalhos contribui para a organização do código.

## `src/`

A pasta `src/` contém os arquivos de implementação (`.c`) do projeto. Nela estão as funções responsáveis pelo funcionamento do sistema, incluindo o cadastro e a busca de livros e usuários, o controle de empréstimos e devoluções, a persistência dos dados e o arquivo principal responsável pela execução e menu do programa.

## `dados/`

A pasta `dados/` contém os arquivos de texto utilizados para armazenar os dados do sistema. Os arquivos `livros.txt`, `usuarios.txt` e `emprestimos.txt` permitem manter os registros cadastrados mesmo após o encerramento do programa, sendo utilizados pelas funções de persistência para salvar e carregar as informações.