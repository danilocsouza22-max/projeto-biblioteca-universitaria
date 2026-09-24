#include <stdio.h>
#include "../include/livros.h"
#include "../include/usuarios.h"
#include "../include/emprestimos.h"
#include "../include/persistencia.h"

int main(void) {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    Emprestimo emprestimos[MAX_EMPRESTIMOS];

    int totalLivros = 0;
    int totalUsuarios = 0;
    int totalEmprestimos = 0;
    int opcao;

    carregarLivros(livros, &totalLivros);
    carregarUsuarios(usuarios, &totalUsuarios);
    carregarEmprestimos(emprestimos, &totalEmprestimos);

    do {
        printf("\n=== SISTEMA DE BIBLIOTECA UNIVERSITARIA ===\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Cadastrar usuario\n");
        printf("4 - Listar usuarios\n");
        printf("5 - Buscar livro\n");
        printf("6 - Buscar usuario\n");
        printf("7 - Realizar emprestimo\n");
        printf("8 - Devolver livro\n");
        printf("9 - Listar emprestimos\n");
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

            case 7:
                realizarEmprestimo(livros, totalLivros, usuarios, totalUsuarios, emprestimos, &totalEmprestimos);
                break;

            case 8:
                devolverLivro(livros, totalLivros, emprestimos, totalEmprestimos);
                break;

            case 9:
                listarEmprestimos(emprestimos, totalEmprestimos);
                break;    

            case 0:
            salvarLivros(livros, totalLivros);
            salvarUsuarios(usuarios, totalUsuarios);
            salvarEmprestimos(emprestimos, totalEmprestimos);

            printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}