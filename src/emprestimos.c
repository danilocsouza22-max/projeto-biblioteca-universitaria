#include <stdio.h>
#include <string.h>
#include "../include/emprestimos.h"

void realizarEmprestimo(
    Livro livros[],
    int totalLivros,
    Usuario usuarios[],
    int totalUsuarios,
    Emprestimo emprestimos[],
    int *totalEmprestimos
) {
    char codigoLivro[MAX_CODIGO];
    char matriculaUsuario[MAX_MATRICULA];
    int indiceLivro;
    int indiceUsuario;
    int i;

    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("\nLimite de emprestimos atingido.\n");
        return;
    }

    printf("\n=== REALIZAR EMPRESTIMO ===\n");

    printf("Codigo do livro: ");
    fgets(codigoLivro, MAX_CODIGO, stdin);
    codigoLivro[strcspn(codigoLivro, "\n")] = '\0';

    indiceLivro = encontrarLivroPorCodigo(
        livros,
        totalLivros,
        codigoLivro
    );

    if (indiceLivro == -1) {
        printf("Erro: livro nao encontrado.\n");
        return;
    }

    if (livros[indiceLivro].quantidade <= 0) {
        printf("Erro: nao ha exemplares disponiveis.\n");
        return;
    }

    printf("Matricula do usuario: ");
    fgets(matriculaUsuario, MAX_MATRICULA, stdin);
    matriculaUsuario[strcspn(matriculaUsuario, "\n")] = '\0';

    indiceUsuario = encontrarUsuarioPorMatricula(
        usuarios,
        totalUsuarios,
        matriculaUsuario
    );

    if (indiceUsuario == -1) {
        printf("Erro: usuario nao encontrado.\n");
        return;
    }

    for (i = 0; i < *totalEmprestimos; i++) {
        if (emprestimos[i].ativo &&
            strcmp(emprestimos[i].codigoLivro, codigoLivro) == 0 &&
            strcmp(emprestimos[i].matriculaUsuario, matriculaUsuario) == 0) {

            printf("Erro: este usuario ja possui este livro emprestado.\n");
            return;
        }
    }

    strcpy(emprestimos[*totalEmprestimos].codigoLivro, codigoLivro);
    strcpy(emprestimos[*totalEmprestimos].matriculaUsuario, matriculaUsuario);
    emprestimos[*totalEmprestimos].ativo = 1;

    livros[indiceLivro].quantidade--;
    (*totalEmprestimos)++;

    printf("Emprestimo realizado com sucesso!\n");
}

void devolverLivro(
    Livro livros[],
    int totalLivros,
    Emprestimo emprestimos[],
    int totalEmprestimos
) {
    char codigoLivro[MAX_CODIGO];
    char matriculaUsuario[MAX_MATRICULA];
    int i;
    int indiceLivro;

    printf("\n=== DEVOLVER LIVRO ===\n");

    printf("Codigo do livro: ");
    fgets(codigoLivro, MAX_CODIGO, stdin);
    codigoLivro[strcspn(codigoLivro, "\n")] = '\0';

    printf("Matricula do usuario: ");
    fgets(matriculaUsuario, MAX_MATRICULA, stdin);
    matriculaUsuario[strcspn(matriculaUsuario, "\n")] = '\0';

    for (i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].ativo &&
            strcmp(emprestimos[i].codigoLivro, codigoLivro) == 0 &&
            strcmp(emprestimos[i].matriculaUsuario, matriculaUsuario) == 0) {

            emprestimos[i].ativo = 0;

            indiceLivro = encontrarLivroPorCodigo(
                livros,
                totalLivros,
                codigoLivro
            );

            if (indiceLivro != -1) {
                livros[indiceLivro].quantidade++;
            }

            printf("Devolucao realizada com sucesso!\n");
            return;
        }
    }

    printf("Erro: emprestimo ativo nao encontrado.\n");
}

void listarEmprestimos(
    const Emprestimo emprestimos[],
    int totalEmprestimos
) {
    int i;

    printf("\n=== EMPRESTIMOS ===\n");

    if (totalEmprestimos == 0) {
        printf("Nenhum emprestimo registrado.\n");
        return;
    }

    for (i = 0; i < totalEmprestimos; i++) {
        printf("\nLivro: %s\n", emprestimos[i].codigoLivro);
        printf("Usuario: %s\n", emprestimos[i].matriculaUsuario);
        printf("Status: %s\n",
               emprestimos[i].ativo ? "Ativo" : "Devolvido");
    }
}