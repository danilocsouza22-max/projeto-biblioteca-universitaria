#include <stdio.h>
#include "../include/livros.h"
#include "../include/usuarios.h"

int main(void) {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];

    int totalLivros = 0;
    int totalUsuarios = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE BIBLIOTECA UNIVERSITARIA ===\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Cadastrar usuario\n");
        printf("4 - Listar usuarios\n");
        printf("5 - Buscar livro\n");
        printf("6 - Buscar usuario\n");
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

            case 3:
                cadastrarUsuario(usuarios, &totalUsuarios);
                break;

            case 4:
                listarUsuarios(usuarios, totalUsuarios);
                break;

            case 5:
                buscarLivro(livros, totalLivros);
                break;    

            case 6:
                buscarUsuario(usuarios, totalUsuarios);
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