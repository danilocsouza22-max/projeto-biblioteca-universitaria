#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "livros.h"
#include "usuarios.h"
#include "emprestimos.h"

void carregarLivros(Livro **livros, int *totalLivros, int *capacidade);  // Carrega os livros armazenados no arquivo de dados
void salvarLivros(const Livro livros[], int totalLivros); // Salva os livros cadastrados no arquivo de dados

void carregarUsuarios(Usuario **usuarios, int *totalUsuarios, int *capacidade);
void salvarUsuarios(const Usuario usuarios[], int totalUsuarios);  // Salva os usuários cadastrados no arquivo de dados

// Carrega os empréstimos armazenados no arquivo de dados
void carregarEmprestimos(
    Emprestimo **emprestimos,
    int *totalEmprestimos,
    int *capacidade
);

// Salva os empréstimos registrados no arquivo de dados
void salvarEmprestimos(
    const Emprestimo emprestimos[],
    int totalEmprestimos
);
// Salva os dados dos livros em arquivo binario
int salvarLivrosBinario(const Livro livros[], int totalLivros);

// Carrega os dados dos livros de arquivo binario
int carregarLivrosBinario(Livro **livros, int *totalLivros, int *capacidade);

// Salva os dados dos usuarios em arquivo binario
int salvarUsuariosBinario(const Usuario usuarios[], int totalUsuarios);

// Carrega os dados dos usuarios de arquivo binario
int carregarUsuariosBinario(Usuario **usuarios, int *totalUsuarios, int *capacidade);

// Salva os dados dos emprestimos em arquivo binario
int salvarEmprestimosBinario(const Emprestimo emprestimos[], int totalEmprestimos);

// Carrega os dados dos emprestimos de arquivo binario
int carregarEmprestimosBinario(Emprestimo **emprestimos, int *totalEmprestimos, int *capacidade);
#endif