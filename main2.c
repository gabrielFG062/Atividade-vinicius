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

void executar(int tamanho, char nome[]) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    long long comparacoes = 0, movimentacoes = 0;
    clock_t inicio, fim;
    double tempo_ms;

    preencherDecrescente(vetor, tamanho);

    inicio = clock();

    if (nome[0] == 'B')
        bubbleSort(vetor, tamanho, &comparacoes, &movimentacoes);
    else
        selectionSort(vetor, tamanho, &comparacoes, &movimentacoes);

    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("%-15s %-10d %-12.2f %-15lld %-15lld\n",
           nome, tamanho, tempo_ms, comparacoes, movimentacoes);

    free(vetor);
}

int main() {

    printf("%-15s %-10s %-12s %-15s %-15s\n",
           "Algoritmo", "Tamanho", "Tempo (ms)", "Comparacoes", "Movimentacoes");

    executar(100, "Bubble Sort");
    executar(1000, "Bubble Sort");
    executar(10000, "Bubble Sort");

    executar(100, "Selection Sort");
    executar(1000, "Selection Sort");
    executar(10000, "Selection Sort");

    return 0;
}
