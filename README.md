# Sistema de Biblioteca Universitária

## 1. Sobre o projeto

Este projeto consiste no desenvolvimento de um sistema de gerenciamento de uma biblioteca universitária utilizando a linguagem de programação C.

O sistema foi desenvolvido com o objetivo de aplicar conceitos fundamentais de programação estruturada, estruturas de dados, modularização, manipulação de strings, vetores, funções, estruturas (`struct`), busca sequencial, manipulação de arquivos e tratamento básico de erros.

O sistema permite o gerenciamento de livros e usuários, além do controle de empréstimos e devoluções.

Os dados utilizados pelo sistema são armazenados em arquivos de texto (`.txt`), permitindo que as informações cadastradas permaneçam salvas mesmo após o encerramento do programa.

---

## 2. Objetivos

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

---

## 3. Funcionalidades

### 3.1 Cadastro de livros

O sistema permite cadastrar livros informando:

- Código;
- Título;
- Autor;
- Ano de publicação;
- Quantidade disponível.

O código do livro funciona como identificador e não pode ser repetido.

Também existem verificações para impedir o cadastro de valores negativos para ano e quantidade.

---

### 3.2 Listagem de livros

A opção de listagem apresenta todos os livros cadastrados e suas respectivas informações.

São exibidos:

- Código;
- Título;
- Autor;
- Ano;
- Quantidade disponível.

Caso não existam livros cadastrados, o sistema informa que o acervo está vazio.

---

### 3.3 Cadastro de usuários

O sistema permite cadastrar usuários informando:

- Matrícula;
- Nome;
- Curso.

A matrícula funciona como identificador do usuário e não pode ser repetida.

---

### 3.4 Listagem de usuários

Através dessa funcionalidade é possível visualizar todos os usuários cadastrados, apresentando:

- Matrícula;
- Nome;
- Curso.

---

### 3.5 Busca de livros

O sistema possui busca sequencial de livros.

É possível realizar buscas utilizando:

- Título;
- Autor.

A busca percorre os livros cadastrados e verifica quais registros correspondem ao termo informado.

A busca por título ou autor também permite localizar ocorrências dentro de textos maiores.

---

### 3.6 Busca de usuários

Os usuários podem ser localizados através de sua matrícula.

O sistema percorre os usuários cadastrados até encontrar uma matrícula correspondente.

---

### 3.7 Empréstimo de livros

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

---

### 3.8 Devolução de livros

Para realizar uma devolução são informados:

- Código do livro;
- Matrícula do usuário.

O sistema procura um empréstimo ativo correspondente.

Quando o empréstimo é encontrado:

1. O status do empréstimo é alterado para devolvido;
2. A quantidade disponível do livro é aumentada em uma unidade;
3. O sistema informa que a devolução foi realizada com sucesso.

Caso o empréstimo não seja encontrado, uma mensagem de erro é apresentada.

---

### 3.9 Listagem de empréstimos

O sistema permite visualizar todos os empréstimos registrados.

Para cada empréstimo são apresentados:

- Código do livro;
- Matrícula do usuário;
- Status do empréstimo.

O status pode ser:

- Ativo;
- Devolvido.

Dessa forma, os registros de empréstimos anteriores permanecem armazenados mesmo depois que o livro é devolvido.

---

## 4. Tratamento de erros

O sistema possui verificações para evitar situações inválidas durante sua utilização.

Entre os casos tratados estão:

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

---

# 5. Organização do projeto

O projeto foi dividido em módulos para separar as responsabilidades de cada parte do sistema.

```text
projeto-biblioteca-universitaria/
│
├── include/
│   ├── livros.h
│   ├── usuarios.h
│   ├── emprestimos.h
│   └── persistencia.h
│
├── src/
│   ├── main.c
│   ├── livros.c
│   ├── usuarios.c
│   ├── emprestimos.c
│   └── persistencia.c
│
├── dados/
│   ├── livros.txt
│   ├── usuarios.txt
│   └── emprestimos.txt
│
└── README.md