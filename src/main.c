#include <stdio.h>
#include "../include/livros.h"
#include "../include/usuarios.h"
#include "../include/emprestimos.h"
#include "../include/persistencia.h"
#include <stdlib.h>

int main(void) {
    Livro *livros = NULL;

int capacidadeLivros = 0;
    Usuario *usuarios = NULL;

int capacidadeUsuarios = 0;
   Emprestimo *emprestimos = NULL;
   
int capacidadeEmprestimos = 0;

    int totalLivros = 0;
    int totalUsuarios = 0;
    int totalEmprestimos = 0;
    int opcao;

    // Carrega os dados armazenados nos arquivos ao iniciar o sistema
    carregarLivros(&livros, &totalLivros, &capacidadeLivros);
    carregarUsuarios(&usuarios, &totalUsuarios, &capacidadeUsuarios);
    carregarEmprestimos(&emprestimos, &totalEmprestimos, &capacidadeEmprestimos);

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
        printf("10 - Ordenar livros por titulo (Bubble Sort)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        // Executa a funcionalidade escolhida pelo usuário
        switch (opcao) {
            case 1:
                cadastrarLivro(&livros, &totalLivros, &capacidadeLivros);
                break;

            case 2:
                listarLivros(livros, totalLivros);
                break;

            case 3:
               cadastrarUsuario(&usuarios, &totalUsuarios, &capacidadeUsuarios);
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
               realizarEmprestimo(livros, totalLivros, usuarios, totalUsuarios,
                  &emprestimos, &totalEmprestimos, &capacidadeEmprestimos);
                break;

            case 8:
                devolverLivro(livros, totalLivros, emprestimos, totalEmprestimos);
                break;

            case 9:
                listarEmprestimos(emprestimos, totalEmprestimos);
                break;

            case 10:
                ordenarLivrosBubbleSort(livros, totalLivros);
                printf("\nLivros ordenados por titulo com Bubble Sort!\n");
                break;

            case 0:
            // Salva os dados antes de encerrar o programa
            salvarLivros(livros, totalLivros);
            salvarUsuarios(usuarios, totalUsuarios);
            salvarEmprestimos(emprestimos, totalEmprestimos);

            printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

free(livros);
free(usuarios);
free(emprestimos);

return 0;
}