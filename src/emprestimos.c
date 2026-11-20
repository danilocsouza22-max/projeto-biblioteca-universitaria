#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include "../include/emprestimos.h"

int expandirEmprestimos(Emprestimo **emprestimos, int *capacidade) {
    int novaCapacidade;
    Emprestimo *temporario;

    // Define a capacidade inicial ou dobra a capacidade atual
    if (*capacidade == 0) {
        novaCapacidade = 10;
    } else {
        if (*capacidade > INT_MAX / 2) {
            return 0;
        }
        novaCapacidade = (*capacidade) * 2;
    }

    // Verifica se a quantidade de memoria pode ser alocada
    if ((size_t)novaCapacidade > SIZE_MAX / sizeof(Emprestimo)) {
        return 0;
    }

    // Tenta aumentar o espaco reservado na memoria
    temporario = realloc(
        *emprestimos,
        (size_t)novaCapacidade * sizeof(Emprestimo)
    );

    if (temporario == NULL) {
        printf("Erro ao alocar memoria para emprestimos.\n");
        return 0;
    }

    // Atualiza o ponteiro e a capacidade disponivel
    *emprestimos = temporario;
    *capacidade = novaCapacidade;

    return 1;
}

void realizarEmprestimo(
    Livro livros[],
    int totalLivros,
    Usuario usuarios[],
    int totalUsuarios,
    Emprestimo **emprestimos,
    int *totalEmprestimos,
    int *capacidade
) {
    char codigoLivro[MAX_CODIGO];
char matriculaUsuario[MAX_MATRICULA];
int indiceLivro;
int indiceUsuario;
int i;

    printf("\n=== REALIZAR EMPRESTIMO ===\n");

    printf("Codigo do livro: ");
    fgets(codigoLivro, MAX_CODIGO, stdin);
    codigoLivro[strcspn(codigoLivro, "\n")] = '\0';

    // Verifica se o código informado não está vazio
    if (strlen(codigoLivro) == 0) {
        printf("Erro: o codigo do livro nao pode estar vazio.\n");
        return;
    }

    // Procura o livro informado entre os livros cadastrados
    indiceLivro = encontrarLivroPorCodigo(
        livros,
        totalLivros,
        codigoLivro
    );

    if (indiceLivro == -1) {
        printf("Erro: livro nao encontrado.\n");
        return;
    }

    // Verifica se o livro informado ainda está disponível para empréstimo
    if (livros[indiceLivro].quantidade <= 0) {
        printf("Erro: nao ha exemplares disponiveis.\n");
        return;
    }

    printf("Matricula do usuario: ");
    fgets(matriculaUsuario, MAX_MATRICULA, stdin);
    matriculaUsuario[strcspn(matriculaUsuario, "\n")] = '\0';

    // Verifica se a matrícula informada não está vazia
    if (strlen(matriculaUsuario) == 0) {
        printf("Erro: a matricula do usuario nao pode estar vazia.\n");
        return;
    }

    // Procura o usuário informado entre os usuários cadastrados
    indiceUsuario = encontrarUsuarioPorMatricula(
        usuarios,
        totalUsuarios,
        matriculaUsuario
    );

    if (indiceUsuario == -1) {
        printf("Erro: usuario nao encontrado.\n");
        return;
    }

    // Verifica se o usuário já possui este livro emprestado
    for (i = 0; i < *totalEmprestimos; i++) {
       if ((*emprestimos)[i].ativo &&
    strcmp((*emprestimos)[i].codigoLivro, codigoLivro) == 0 &&
    strcmp((*emprestimos)[i].matriculaUsuario, matriculaUsuario) == 0) {

            printf("Erro: este usuario ja possui este livro emprestado.\n");
            return;
        }
    }

    // Aumenta a capacidade quando nao houver espaco disponivel
if (*totalEmprestimos >= *capacidade) {
    if (!expandirEmprestimos(emprestimos, capacidade)) {
        printf("Erro ao expandir o armazenamento de emprestimos.\n");
        return;
    }
}

// Registra o novo emprestimo
strcpy((*emprestimos)[*totalEmprestimos].codigoLivro, codigoLivro);
strcpy((*emprestimos)[*totalEmprestimos].matriculaUsuario, matriculaUsuario);
(*emprestimos)[*totalEmprestimos].ativo = 1;

    // Atualiza a quantidade disponível do livro e o total de empréstimos
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

    if (strlen(codigoLivro) == 0) {
        printf("Erro: o codigo do livro nao pode estar vazio.\n");
        return;
    }

    printf("Matricula do usuario: ");
    fgets(matriculaUsuario, MAX_MATRICULA, stdin);
    matriculaUsuario[strcspn(matriculaUsuario, "\n")] = '\0';

    if (strlen(matriculaUsuario) == 0) {
        printf("Erro: a matricula do usuario nao pode estar vazia.\n");
        return;
    }

    // Procura o empréstimo ativo correspondente ao livro e ao usuário
    for (i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].ativo &&
            strcmp(emprestimos[i].codigoLivro, codigoLivro) == 0 &&
            strcmp(emprestimos[i].matriculaUsuario, matriculaUsuario) == 0) {

             // Marca o empréstimo como devolvido    
            emprestimos[i].ativo = 0;

            indiceLivro = encontrarLivroPorCodigo(
                livros,
                totalLivros,
                codigoLivro
            );
            // Devolve o exemplar ao estoque disponível
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

    // Percorre pelos empréstimos registrados e exibe seus dados
    for (i = 0; i < totalEmprestimos; i++) {
        printf("\nLivro: %s\n", emprestimos[i].codigoLivro);
        printf("Usuario: %s\n", emprestimos[i].matriculaUsuario);
        printf("Status: %s\n",
               emprestimos[i].ativo ? "Ativo" : "Devolvido");
    }
}

void historicoEmprestimosUsuario(
    const Emprestimo emprestimos[],
    int totalEmprestimos,
    const Livro livros[],
    int totalLivros
) {
    char matricula[MAX_MATRICULA];
    int encontrados = 0;

    printf("\n=== HISTORICO DE EMPRESTIMOS POR USUARIO ===\n");
    printf("Digite a matricula do usuario: ");

    fgets(matricula, MAX_MATRICULA, stdin);
    matricula[strcspn(matricula, "\n")] = '\0';

    // Verifica se a matricula foi informada
    if (strlen(matricula) == 0) {
        printf("Erro: a matricula nao pode estar vazia.\n");
        return;
    }

    // Percorre todos os emprestimos registrados
    for (int i = 0; i < totalEmprestimos; i++) {

        // Verifica se o emprestimo pertence ao usuario
        if (strcmp(emprestimos[i].matriculaUsuario, matricula) == 0) {
            encontrados++;

            printf("\nEmprestimo %d\n", encontrados);
            printf("Codigo do livro: %s\n", emprestimos[i].codigoLivro);

            // Procura o titulo do livro correspondente
            int indiceLivro = encontrarLivroPorCodigo(
                livros,
                totalLivros,
                emprestimos[i].codigoLivro
            );

            if (indiceLivro != -1) {
                printf("Titulo: %s\n", livros[indiceLivro].titulo);
            } else {
                printf("Titulo: livro nao encontrado no acervo.\n");
            }

            // Exibe a situacao do emprestimo
            printf("Status: %s\n",
                   emprestimos[i].ativo ? "Ativo" : "Devolvido");
        }
    }

    // Informa quando nao existem emprestimos para a matricula
    if (encontrados == 0) {
        printf("\nNenhum emprestimo encontrado para esta matricula.\n");
    } else {
        printf("\nTotal de emprestimos encontrados: %d\n", encontrados);
    }
}