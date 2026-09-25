#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#include "livros.h"
#include "usuarios.h"

#define MAX_EMPRESTIMOS 200

// Estrutura responsável por armazenar os dados de um empréstimo
typedef struct {
    char codigoLivro[MAX_CODIGO];
    char matriculaUsuario[MAX_MATRICULA];
    int ativo;
} Emprestimo;

// Realiza um empréstimo, verifica a existência do livro, do usuário e se há exemplares
void realizarEmprestimo(
    Livro livros[],
    int totalLivros,
    Usuario usuarios[],
    int totalUsuarios,
    Emprestimo emprestimos[],
    int *totalEmprestimos
);

// Registra a devolução de um livro e atualiza a quantidade disponível
void devolverLivro(
    Livro livros[],
    int totalLivros,
    Emprestimo emprestimos[],
    int totalEmprestimos
);

// Exibe todos os empréstimos registrados e seus status
void listarEmprestimos(
    const Emprestimo emprestimos[],
    int totalEmprestimos
);

#endif