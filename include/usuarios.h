#ifndef USUARIOS_H
#define USUARIOS_H

#define MAX_MATRICULA 20
#define MAX_NOME 100
#define MAX_CURSO 100
#define MAX_USUARIOS 100

// Responsável por armazenar os dados de um usuário
typedef struct {
    char matricula[MAX_MATRICULA];
    char nome[MAX_NOME];
    char curso[MAX_CURSO];
} Usuario;

void cadastrarUsuario(Usuario usuarios[], int *total);
void listarUsuarios(const Usuario usuarios[], int total);
int encontrarUsuarioPorMatricula(const Usuario usuarios[], int total, const char matricula[]);
void buscarUsuario(const Usuario usuarios[], int total);

#endif