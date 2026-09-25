#include <stdio.h>
#include <string.h>
#include "../include/livros.h"

void limparBuffer(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

// Procura um livro pelo código informado
int encontrarLivroPorCodigo(const Livro livros[], int total, const char codigo[]) {
    int i;

    for (i = 0; i < total; i++) {
        if (strcmp(livros[i].codigo, codigo) == 0) {
            return i;
        }
    }

    return -1;
}

void cadastrarLivro(Livro livros[], int *total) {
    Livro novoLivro;

    // Verifica se o limite de livros cadastrados foi atingido
    if (*total >= MAX_LIVROS) {
        printf("\nLimite de livros atingido.\n");
        return;
    }

    printf("\n=== CADASTRO DE LIVRO ===\n");

    printf("Codigo: ");
    fgets(novoLivro.codigo, MAX_CODIGO, stdin);
    novoLivro.codigo[strcspn(novoLivro.codigo, "\n")] = '\0';

    // Verifica se já existe um livro com o código informado
    if (encontrarLivroPorCodigo(livros, *total, novoLivro.codigo) != -1) {
        printf("Erro: ja existe um livro com esse codigo.\n");
        return;
    }

    printf("Titulo: ");
    fgets(novoLivro.titulo, MAX_TITULO, stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(novoLivro.autor, MAX_AUTOR, stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';

    printf("Ano de publicacao: ");
    scanf("%d", &novoLivro.ano);
    limparBuffer();

    printf("Quantidade disponivel: ");
    scanf("%d", &novoLivro.quantidade);
    limparBuffer();

    // Verifica se os valores informados são válidos
    if (novoLivro.ano < 0 || novoLivro.quantidade < 0) {
        printf("Erro: ano e quantidade nao podem ser negativos.\n");
        return;
    }

    // Adiciona o novo livro e atualiza o total de livros
    livros[*total] = novoLivro;
    (*total)++;

    printf("Livro cadastrado com sucesso!\n");
}

void listarLivros(const Livro livros[], int total) {
    int i;

    printf("\n=== LIVROS CADASTRADOS ===\n");

    if (total == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    // Percorre os livros cadastrados e exibe suas informações
    for (i = 0; i < total; i++) {
        printf("\nCodigo: %s\n", livros[i].codigo);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano: %d\n", livros[i].ano);
        printf("Quantidade disponivel: %d\n", livros[i].quantidade);
    }
}

void buscarLivro(const Livro livros[], int total) {
    int opcao;
    int i;
    int encontrou = 0;
    char termo[MAX_TITULO];

    printf("\n=== BUSCA DE LIVRO ===\n");
    printf("1 - Buscar por titulo\n");
    printf("2 - Buscar por autor\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();

    printf("Digite o termo da busca: ");
    fgets(termo, MAX_TITULO, stdin);
    termo[strcspn(termo, "\n")] = '\0';

    // Percorre os livros e verifica se correspondem ao termo pesquisado
    for (i = 0; i < total; i++) {
        if ((opcao == 1 && strstr(livros[i].titulo, termo) != NULL) ||
            (opcao == 2 && strstr(livros[i].autor, termo) != NULL)) {

            printf("\nCodigo: %s\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano: %d\n", livros[i].ano);
            printf("Quantidade disponivel: %d\n", livros[i].quantidade);

            encontrou = 1;
        }
    }

    if (opcao != 1 && opcao != 2) {
        printf("Opcao de busca invalida.\n");
    } else if (!encontrou) {
        printf("Nenhum livro encontrado.\n");
    }
}