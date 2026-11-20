#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "livros.h"
#include "usuarios.h"
#include "emprestimos.h"

// Exporta um relatorio consolidado da biblioteca para arquivo de texto
int exportarRelatorio(
    const Livro livros[],
    int totalLivros,
    const Usuario usuarios[],
    int totalUsuarios,
    const Emprestimo emprestimos[],
    int totalEmprestimos
);

#endif