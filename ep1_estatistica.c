#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função auxiliar para comparar elementos
int comparar(const void *a, const void *b) {
    double diff = *(double*)a - *(double*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int main() {
    int n;

    printf("Quantos números na sua série (N): ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("A quantidade de elementos deve ser maior que 1.\n");
        return 1;
    }

    double *numeros = (double*) malloc(n * sizeof(double));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("\nEntre com números:\n\n");
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        printf("> ");
        scanf("%lf", &numeros[i]);
        soma += numeros[i];
    }

    // Cálculo da média
    double media = soma / n;

    // Ordenação do vetor para encontrar Mínimo, Máximo e Mediana
    qsort(numeros, n, sizeof(double), comparar);

    double min = numeros[0];
    double max = numeros[n - 1];

    // Cálculo da Mediana
    double mediana;
    if (n % 2 == 0) {
        mediana = (numeros[n / 2 - 1] + numeros[n / 2]) / 2.0;
    } else {
        mediana = numeros[n / 2];
    }

    // Cálculo da soma dos quadrados das diferenças
    double soma_quadrados = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = numeros[i] - media;
        soma_quadrados += diff * diff;
    }

    // Cálculo do Desvio Padrão Amostral
    double desvio_padrao = sqrt(soma_quadrados / (n - 1));

    // Exibição dos resultados
    printf("\nValor mínimo: %g\n", min);
    printf("Valor Máximo: %g\n", max);
    printf("Média: %.2f\n", media);
    printf("Mediana: %g\n", mediana);
    printf("Desvio padrão: %.14f\n", desvio_padrao);

    free(numeros);
    return 0;
}