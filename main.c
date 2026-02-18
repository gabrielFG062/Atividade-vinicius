#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void bubbleSort(int vetor[], int tamanho, long long *comparacoes, long long *movimentacoes) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*movimentacoes)++;
            }
        }
    }
}

void selectionSort(int vetor[], int tamanho, long long *comparacoes, long long *movimentacoes) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = vetor[i];
            vetor[i] = vetor[minIndex];
            vetor[minIndex] = temp;
            (*movimentacoes)++;
        }
    }
}

void testarAlgoritmo(int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    clock_t inicio, fim;
    double tempo_ms;
    long long comparacoes, movimentacoes;

    // -------- Bubble Sort --------
    preencherDecrescente(vetor, tamanho);
    comparacoes = 0;
    movimentacoes = 0;

    inicio = clock();
    bubbleSort(vetor, tamanho, &comparacoes, &movimentacoes);
    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("Bubble Sort\t%d\t%.2f\t%lld\t%lld\n",
           tamanho, tempo_ms, comparacoes, movimentacoes);

    // -------- Selection Sort --------
    preencherDecrescente(vetor, tamanho);
    comparacoes = 0;
    movimentacoes = 0;

    inicio = clock();
    selectionSort(vetor, tamanho, &comparacoes, &movimentacoes);
    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("Selection Sort\t%d\t%.2f\t%lld\t%lld\n",
           tamanho, tempo_ms, comparacoes, movimentacoes);

    free(vetor);
}

int main() {

    printf("Algoritmo\tTamanho\tTempo(ms)\tComparacoes\tMovimentacoes\n");

    testarAlgoritmo(100);
    testarAlgoritmo(1000);
    testarAlgoritmo(10000);

    return 0;
}
