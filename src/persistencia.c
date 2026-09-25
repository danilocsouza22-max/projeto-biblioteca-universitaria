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

void carregarLivros(Livro livros[], int *totalLivros) {
    FILE *arquivo;

    // Abre o arquivo de livros para carregar os dados
    arquivo = fopen("dados/livros.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    *totalLivros = 0;

    // Lê os livros armazenados no arquivo
    while (
        *totalLivros < MAX_LIVROS &&
        fscanf(
            arquivo,
            "%19[^|]|%119[^|]|%99[^|]|%d|%d\n",
            livros[*totalLivros].codigo,
            livros[*totalLivros].titulo,
            livros[*totalLivros].autor,
            &livros[*totalLivros].ano,
            &livros[*totalLivros].quantidade
        ) == 5
    ) {
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

void carregarUsuarios(Usuario usuarios[], int *totalUsuarios) {
    FILE *arquivo;

    // Abre o arquivo de usuários para carregar os dados
    arquivo = fopen("dados/usuarios.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    *totalUsuarios = 0;

    // Lê os usuários armazenados no arquivo
    while (
        *totalUsuarios < MAX_USUARIOS &&
        fscanf(
            arquivo,
            "%19[^|]|%99[^|]|%99[^\n]\n",
            usuarios[*totalUsuarios].matricula,
            usuarios[*totalUsuarios].nome,
            usuarios[*totalUsuarios].curso
        ) == 3
    ) {
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
    Emprestimo emprestimos[],
    int *totalEmprestimos
) {
    FILE *arquivo;

    // Abre o arquivo de empréstimos para carregar os dados
    arquivo = fopen("dados/emprestimos.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    *totalEmprestimos = 0;

    // Lê os empréstimos armazenados no arquivo
    while (
        *totalEmprestimos < MAX_EMPRESTIMOS &&
        fscanf(
            arquivo,
            "%19[^|]|%19[^|]|%d\n",
            emprestimos[*totalEmprestimos].codigoLivro,
            emprestimos[*totalEmprestimos].matriculaUsuario,
            &emprestimos[*totalEmprestimos].ativo
        ) == 3
    ) {
        (*totalEmprestimos)++;
    }

    fclose(arquivo);
}