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

void cadastrarLivro(Livro **livros, int *total, int *capacidade);
void listarLivros(const Livro livros[], int total);
void buscarLivro(const Livro livros[], int total);
int encontrarLivroPorCodigo(const Livro livros[], int total, const char codigo[]);
void limparBuffer(void);

// Aumenta a capacidade de armazenamento dos livros
int expandirLivros(Livro **livros, int *capacidade);

// Ordena os livros alfabeticamente pelo titulo usando Bubble Sort
void ordenarLivrosBubbleSort(Livro livros[], int total);

// Ordena os livros por ano de publicacao usando Selection Sort
void ordenarLivrosSelectionSort(Livro livros[], int total);

#endif