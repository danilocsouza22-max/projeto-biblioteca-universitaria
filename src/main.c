
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/livros.h"
#include "../include/usuarios.h"
#include "../include/emprestimos.h"
#include "../include/persistencia.h"

int main(void) {
    Livro *livros = NULL;
    Usuario *usuarios = NULL;
    Emprestimo *emprestimos = NULL;

    int capacidadeLivros = 0;
    int capacidadeUsuarios = 0;
    int capacidadeEmprestimos = 0;

    int totalLivros = 0;
    int totalUsuarios = 0;
    int totalEmprestimos = 0;
    int opcao;

    // Carrega os dados armazenados nos arquivos de texto
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
        printf("11 - Ordenar livros por ano (Selection Sort)\n");
        printf("12 - Buscar livro por codigo (Busca Binaria)\n");
        printf("13 - Historico de emprestimos por usuario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBuffer();

        // Executa a funcionalidade escolhida pelo usuario
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
                realizarEmprestimo(
                    livros, totalLivros,
                    usuarios, totalUsuarios,
                    &emprestimos, &totalEmprestimos,
                    &capacidadeEmprestimos
                );
                break;

            case 8:
                devolverLivro(
                    livros, totalLivros,
                    emprestimos, totalEmprestimos
                );
                break;

            case 9:
                listarEmprestimos(emprestimos, totalEmprestimos);
                break;

            case 10:
                ordenarLivrosBubbleSort(livros, totalLivros);
                printf("\nLivros ordenados por titulo com Bubble Sort!\n");
                break;

            case 11:
                ordenarLivrosSelectionSort(livros, totalLivros);
                printf("\nLivros ordenados por ano com Selection Sort!\n");
                break;

            case 12: {
                char codigoBusca[MAX_CODIGO];
                int indiceEncontrado;

                printf("\n=== BUSCA BINARIA DE LIVRO ===\n");
                printf("Digite o codigo do livro: ");

                fgets(codigoBusca, MAX_CODIGO, stdin);
                codigoBusca[strcspn(codigoBusca, "\n")] = '\0';

                // Ordena os livros por codigo antes da busca
                ordenarLivrosPorCodigo(livros, totalLivros);

                // Realiza a busca binaria
                indiceEncontrado = buscarLivroBinaria(
                    livros, totalLivros, codigoBusca
                );

                if (indiceEncontrado != -1) {
                    printf("\nLivro encontrado!\n");
                    printf("Codigo: %s\n", livros[indiceEncontrado].codigo);
                    printf("Titulo: %s\n", livros[indiceEncontrado].titulo);
                    printf("Autor: %s\n", livros[indiceEncontrado].autor);
                    printf("Ano: %d\n", livros[indiceEncontrado].ano);
                    printf("Quantidade disponivel: %d\n",
                           livros[indiceEncontrado].quantidade);
                } else {
                    printf("\nLivro nao encontrado.\n");
                }

                break;
            }
            case 13:
                historicoEmprestimosUsuario(
                    emprestimos,
                    totalEmprestimos,
                    livros,
                    totalLivros
                );
                break;

            case 0: {
                // Salva os dados em arquivos de texto
                salvarLivros(livros, totalLivros);
                salvarUsuarios(usuarios, totalUsuarios);
                salvarEmprestimos(emprestimos, totalEmprestimos);

                // Salva os dados em arquivos binarios
                int salvouLivros = salvarLivrosBinario(
                    livros, totalLivros
                );

                int salvouUsuarios = salvarUsuariosBinario(
                    usuarios, totalUsuarios
                );

                int salvouEmprestimos = salvarEmprestimosBinario(
                    emprestimos, totalEmprestimos
                );

                // Verifica se os tres salvamentos foram realizados
                if (salvouLivros && salvouUsuarios && salvouEmprestimos) {
                    printf("\nDados binarios salvos com sucesso!\n");
                } else {
                    printf("\nErro ao salvar algum arquivo binario.\n");
                }

                printf("\nPrograma encerrado.\n");
                break;
            }

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    // Libera a memoria alocada dinamicamente
    free(livros);
    free(usuarios);
    free(emprestimos);

    return 0;
}
