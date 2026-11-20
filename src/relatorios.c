
#include <stdio.h>
#include "../include/relatorios.h"

int exportarRelatorio(
    const Livro livros[],
    int totalLivros,
    const Usuario usuarios[],
    int totalUsuarios,
    const Emprestimo emprestimos[],
    int totalEmprestimos
) {
    FILE *arquivo;
    int ativos = 0;
    int devolvidos = 0;

    // Cria o arquivo de relatorio na pasta dados
    arquivo = fopen("dados/relatorio_biblioteca.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de relatorio.\n");
        return 0;
    }

    fprintf(arquivo, "=== RELATORIO DA BIBLIOTECA UNIVERSITARIA ===\n\n");

    // Apresenta os totais gerais
    fprintf(arquivo, "=== RESUMO GERAL ===\n");
    fprintf(arquivo, "Total de livros cadastrados: %d\n", totalLivros);
    fprintf(arquivo, "Total de usuarios cadastrados: %d\n", totalUsuarios);
    fprintf(arquivo, "Total de emprestimos registrados: %d\n",
            totalEmprestimos);

    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].ativo) {
            ativos++;
        } else {
            devolvidos++;
        }
    }

    fprintf(arquivo, "Emprestimos ativos: %d\n", ativos);
    fprintf(arquivo, "Emprestimos devolvidos: %d\n\n", devolvidos);

    // Exporta os livros cadastrados
    fprintf(arquivo, "=== LIVROS CADASTRADOS ===\n");

    if (totalLivros == 0) {
        fprintf(arquivo, "Nenhum livro cadastrado.\n");
    }

    for (int i = 0; i < totalLivros; i++) {
        fprintf(arquivo, "\nCodigo: %s\n", livros[i].codigo);
        fprintf(arquivo, "Titulo: %s\n", livros[i].titulo);
        fprintf(arquivo, "Autor: %s\n", livros[i].autor);
        fprintf(arquivo, "Ano: %d\n", livros[i].ano);
        fprintf(arquivo, "Quantidade disponivel: %d\n",
                livros[i].quantidade);
    }

    // Exporta os usuarios cadastrados
    fprintf(arquivo, "\n=== USUARIOS CADASTRADOS ===\n");

    if (totalUsuarios == 0) {
        fprintf(arquivo, "Nenhum usuario cadastrado.\n");
    }

    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(arquivo, "\nMatricula: %s\n", usuarios[i].matricula);
        fprintf(arquivo, "Nome: %s\n", usuarios[i].nome);
        fprintf(arquivo, "Curso: %s\n", usuarios[i].curso);
    }

    // Exporta os emprestimos registrados
    fprintf(arquivo, "\n=== EMPRESTIMOS REGISTRADOS ===\n");

    if (totalEmprestimos == 0) {
        fprintf(arquivo, "Nenhum emprestimo registrado.\n");
    }

    for (int i = 0; i < totalEmprestimos; i++) {
        fprintf(arquivo, "\nCodigo do livro: %s\n",
                emprestimos[i].codigoLivro);
        fprintf(arquivo, "Matricula do usuario: %s\n",
                emprestimos[i].matriculaUsuario);
        fprintf(arquivo, "Status: %s\n",
                emprestimos[i].ativo ? "Ativo" : "Devolvido");
    }

    // Verifica se o arquivo foi gravado corretamente
    if (ferror(arquivo)) {
        fclose(arquivo);
        printf("Erro durante a escrita do relatorio.\n");
        return 0;
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao finalizar o arquivo de relatorio.\n");
        return 0;
    }

    printf("\nRelatorio exportado com sucesso!\n");
    printf("Arquivo: dados/relatorio_biblioteca.txt\n");

    return 1;
}
