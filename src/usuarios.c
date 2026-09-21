#include <stdio.h>
#include <string.h>
#include "../include/usuarios.h"

void cadastrarUsuario(Usuario usuarios[], int *total) {
    Usuario novoUsuario;

    if (*total >= MAX_USUARIOS) {
        printf("\nLimite de usuarios atingido.\n");
        return;
    }

    printf("\n=== CADASTRO DE USUARIO ===\n");

    printf("Matricula: ");
    fgets(novoUsuario.matricula, MAX_MATRICULA, stdin);
    novoUsuario.matricula[strcspn(novoUsuario.matricula, "\n")] = '\0';

    if (encontrarUsuarioPorMatricula(usuarios, *total, novoUsuario.matricula) != -1) {
        printf("Erro: ja existe um usuario com essa matricula.\n");
        return;
    }

    printf("Nome: ");
    fgets(novoUsuario.nome, MAX_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    printf("Curso: ");
    fgets(novoUsuario.curso, MAX_CURSO, stdin);
    novoUsuario.curso[strcspn(novoUsuario.curso, "\n")] = '\0';

    usuarios[*total] = novoUsuario;
    (*total)++;

    printf("Usuario cadastrado com sucesso!\n");
}

void listarUsuarios(const Usuario usuarios[], int total) {
    int i;

    printf("\n=== USUARIOS CADASTRADOS ===\n");

    if (total == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("\nMatricula: %s\n", usuarios[i].matricula);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Curso: %s\n", usuarios[i].curso);
    }
}

int encontrarUsuarioPorMatricula(
    const Usuario usuarios[],
    int total,
    const char matricula[]
) {
    int i;

    for (i = 0; i < total; i++) {
        if (strcmp(usuarios[i].matricula, matricula) == 0) {
            return i;
        }
    }

    return -1;
}