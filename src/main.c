#include <stdio.h>
#include "../include/livros.h"

int main(void) {
    Livro livros[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE BIBLIOTECA UNIVERSITARIA ===\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrarLivro(livros, &totalLivros);
                break;

            case 2:
                listarLivros(livros, totalLivros);
                break;

            case 0:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}