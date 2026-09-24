#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "livros.h"
#include "usuarios.h"
#include "emprestimos.h"

void carregarLivros(Livro livros[], int *totalLivros);
void salvarLivros(const Livro livros[], int totalLivros);

void carregarUsuarios(Usuario usuarios[], int *totalUsuarios);
void salvarUsuarios(const Usuario usuarios[], int totalUsuarios);

void carregarEmprestimos(
    Emprestimo emprestimos[],
    int *totalEmprestimos
);

void salvarEmprestimos(
    const Emprestimo emprestimos[],
    int totalEmprestimos
);

#endif