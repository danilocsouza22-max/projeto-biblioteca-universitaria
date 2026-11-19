#include <stdio.h>
#include <string.h>
#include "../include/persistencia.h"

void salvarLivros(const Livro livros[], int totalLivros) {
    FILE *arquivo;
    int i;

    // Abre o arquivo de livros para salvar os dados
    arquivo = fopen("dados/livros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    // Percorre os livros e grava seus dados no arquivo
    for (i = 0; i < totalLivros; i++) {
        fprintf(
            arquivo,
            "%s|%s|%s|%d|%d\n",
            livros[i].codigo,
            livros[i].titulo,
            livros[i].autor,
            livros[i].ano,
            livros[i].quantidade
        );
    }

    fclose(arquivo);
}


void carregarLivros(Livro **livros, int *totalLivros, int *capacidade) {
    FILE *arquivo;
    Livro livroTemporario;

    // Abre o arquivo de livros para carregar os dados
    arquivo = fopen("dados/livros.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    *totalLivros = 0;

    // Le os livros armazenados no arquivo
    while (fscanf(
        arquivo,
        " %19[^|]|%119[^|]|%99[^|]|%d|%d",
        livroTemporario.codigo,
        livroTemporario.titulo,
        livroTemporario.autor,
        &livroTemporario.ano,
        &livroTemporario.quantidade
    ) == 5) {

        // Aumenta a memoria quando necessario
        if (*totalLivros >= *capacidade) {
            if (!expandirLivros(livros, capacidade)) {
                printf("Erro ao carregar livros: memoria insuficiente.\n");
                break;
            }
        }

        // Armazena o livro carregado
        (*livros)[*totalLivros] = livroTemporario;
        (*totalLivros)++;
    }

    fclose(arquivo);
}

void salvarUsuarios(const Usuario usuarios[], int totalUsuarios) {
    FILE *arquivo;
    int i;

    // Abre o arquivo de usuários para salvar os dados
    arquivo = fopen("dados/usuarios.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    // Percorre os usuários e grava seus dados no arquivo
    for (i = 0; i < totalUsuarios; i++) {
        fprintf(
            arquivo,
            "%s|%s|%s\n",
            usuarios[i].matricula,
            usuarios[i].nome,
            usuarios[i].curso
        );
    }

    fclose(arquivo);
}

void carregarUsuarios(Usuario **usuarios, int *totalUsuarios, int *capacidade) {
    FILE *arquivo;
    Usuario usuarioTemporario;

    // Abre o arquivo de usuarios para carregar os dados
    arquivo = fopen("dados/usuarios.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    *totalUsuarios = 0;

    // Le os usuarios armazenados no arquivo
    while (fscanf(
        arquivo,
        " %19[^|]|%99[^|]|%99[^\n]",
        usuarioTemporario.matricula,
        usuarioTemporario.nome,
        usuarioTemporario.curso
    ) == 3) {

        // Aumenta a memoria quando necessario
        if (*totalUsuarios >= *capacidade) {
            if (!expandirUsuarios(usuarios, capacidade)) {
                printf("Erro ao carregar usuarios: memoria insuficiente.\n");
                break;
            }
        }

        // Armazena o usuario carregado
        (*usuarios)[*totalUsuarios] = usuarioTemporario;
        (*totalUsuarios)++;
    }

    fclose(arquivo);
}

void salvarEmprestimos(
    const Emprestimo emprestimos[],
    int totalEmprestimos
) {
    FILE *arquivo;
    int i;

    // Abre o arquivo de empréstimos para salvar os dados
    arquivo = fopen("dados/emprestimos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de emprestimos.\n");
        return;
    }

    // Percorre os empréstimos e grava seus dados no arquivo
    for (i = 0; i < totalEmprestimos; i++) {
        fprintf(
            arquivo,
            "%s|%s|%d\n",
            emprestimos[i].codigoLivro,
            emprestimos[i].matriculaUsuario,
            emprestimos[i].ativo
        );
    }

    fclose(arquivo);
}


void carregarEmprestimos(
    Emprestimo **emprestimos,
    int *totalEmprestimos,
    int *capacidade
) {
    FILE *arquivo;
    Emprestimo emprestimoTemporario;

    // Abre o arquivo de emprestimos para carregar os dados
    arquivo = fopen("dados/emprestimos.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    *totalEmprestimos = 0;

    // Le os emprestimos armazenados no arquivo
    while (fscanf(
        arquivo,
        " %19[^|]|%19[^|]|%d",
        emprestimoTemporario.codigoLivro,
        emprestimoTemporario.matriculaUsuario,
        &emprestimoTemporario.ativo
    ) == 3) {

        // Aumenta a memoria quando necessario
        if (*totalEmprestimos >= *capacidade) {
            if (!expandirEmprestimos(emprestimos, capacidade)) {
                printf("Erro ao carregar emprestimos: memoria insuficiente.\n");
                break;
            }
        }

        // Armazena o emprestimo carregado
        (*emprestimos)[*totalEmprestimos] = emprestimoTemporario;
        (*totalEmprestimos)++;
    }

    fclose(arquivo);
}