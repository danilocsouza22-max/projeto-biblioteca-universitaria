
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/livros.h"

#define REPETICOES_BUSCA 100000
#define REPETICOES_ORDENACAO 3

// Impede que os resultados das buscas sejam descartados
volatile long resultadoBuscas = 0;

// Preenche livros ficticios para os testes
void gerarLivros(Livro livros[], int total) {
    for (int i = 0; i < total; i++) {
        int numero = total - i;

        snprintf(livros[i].codigo, MAX_CODIGO, "L%06d", numero);
        snprintf(livros[i].titulo, MAX_TITULO, "LIVRO %06d", numero);
        snprintf(livros[i].autor, MAX_AUTOR, "AUTOR TESTE");

        livros[i].ano = 1900 + numero;
        livros[i].quantidade = 1;
    }
}

// Compara os algoritmos de busca pelo mesmo codigo
void testarBuscas(Livro livros[], int total) {
    clock_t inicio;
    double sequencial, binaria;
    char codigo[MAX_CODIGO];

    // Procura um codigo inexistente, exercitando o pior caso
    snprintf(codigo, sizeof(codigo), "Z999999");

    inicio = clock();

    for (int i = 0; i < REPETICOES_BUSCA; i++) {
        resultadoBuscas += encontrarLivroPorCodigo(
            livros, total, codigo
        );
    }

    sequencial = (double)(clock() - inicio) / CLOCKS_PER_SEC;

    // A busca binaria exige os livros ordenados por codigo
    ordenarLivrosPorCodigo(livros, total);

    inicio = clock();

    for (int i = 0; i < REPETICOES_BUSCA; i++) {
        resultadoBuscas += buscarLivroBinaria(
            livros, total, codigo
        );
    }

    binaria = (double)(clock() - inicio) / CLOCKS_PER_SEC;

    printf("Busca sequencial: %.6f segundos\n", sequencial);
    printf("Busca binaria:    %.6f segundos\n", binaria);
}

// Compara os algoritmos de ordenacao
void testarOrdenacoes(const Livro originais[], int total) {
    Livro *copia = malloc((size_t)total * sizeof(Livro));
    double tempoBubble = 0.0;
    double tempoSelection = 0.0;

    if (copia == NULL) {
        printf("Erro ao alocar memoria para ordenacao.\n");
        return;
    }

    for (int r = 0; r < REPETICOES_ORDENACAO; r++) {
        clock_t inicio;

        memcpy(copia, originais, (size_t)total * sizeof(Livro));

        inicio = clock();
        ordenarLivrosBubbleSort(copia, total);
        tempoBubble += (double)(clock() - inicio) / CLOCKS_PER_SEC;

        memcpy(copia, originais, (size_t)total * sizeof(Livro));

        inicio = clock();
        ordenarLivrosSelectionSort(copia, total);
        tempoSelection += (double)(clock() - inicio) / CLOCKS_PER_SEC;
    }

    printf("Bubble Sort:     %.6f segundos (media)\n",
           tempoBubble / REPETICOES_ORDENACAO);
    printf("Selection Sort:  %.6f segundos (media)\n",
           tempoSelection / REPETICOES_ORDENACAO);

    free(copia);
}

int main(void) {
    int tamanhos[] = {100, 500, 1000, 3000};
    int quantidade = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== ANALISE DE DESEMPENHO ===\n");

    for (int i = 0; i < quantidade; i++) {
        int total = tamanhos[i];

        Livro *livros = malloc((size_t)total * sizeof(Livro));

        if (livros == NULL) {
            printf("Erro ao alocar memoria.\n");
            return 1;
        }

        gerarLivros(livros, total);

        printf("\n=== TESTE COM %d LIVROS ===\n", total);

        testarOrdenacoes(livros, total);
        testarBuscas(livros, total);

        free(livros);
    }

    return 0;
}
