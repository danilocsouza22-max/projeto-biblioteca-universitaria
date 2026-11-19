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

#endif