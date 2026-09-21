#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#include "livros.h"
#include "usuarios.h"

#define MAX_EMPRESTIMOS 200

typedef struct {
    char codigoLivro[MAX_CODIGO];
    char matriculaUsuario[MAX_MATRICULA];
    int ativo;
} Emprestimo;

void realizarEmprestimo(
    Livro livros[],
    int totalLivros,
    Usuario usuarios[],
    int totalUsuarios,
    Emprestimo emprestimos[],
    int *totalEmprestimos
);

void devolverLivro(
    Livro livros[],
    int totalLivros,
    Emprestimo emprestimos[],
    int totalEmprestimos
);

void listarEmprestimos(
    const Emprestimo emprestimos[],
    int totalEmprestimos
);

#endif