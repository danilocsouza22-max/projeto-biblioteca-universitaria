#ifndef LIVROS_H
#define LIVROS_H

#define MAX_CODIGO 20
#define MAX_TITULO 120
#define MAX_AUTOR 100
#define MAX_LIVROS 100

// Responsável por armazenar os dados de um livro
typedef struct {
    char codigo[MAX_CODIGO];
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
    int quantidade;
} Livro;

void cadastrarLivro(Livro livros[], int *total);        // Cadastra um novo livro
void listarLivros(const Livro livros[], int total);     // Exibe os livros cadastrados
void buscarLivro(const Livro livros[], int total);      // Busca os livros por título ou autor
int encontrarLivroPorCodigo(const Livro livros[], int total, const char codigo[]); // Procura um livro pelo código
void limparBuffer(void);

#endif