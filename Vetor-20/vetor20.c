#include <stdio.h>

#define TAMANHO 20

int main() {
    int vetor[TAMANHO];
    int somaMultiplos3 = 0;
    int somaPares = 0;
    int quantidadePares = 0;
    int quantidadePositivos = 0;
    int quantidadeNegativos = 0;
    int maior, menor;
    int i;

    // Entrada dos 20 números
    printf("=== CADASTRO DE 20 NUMEROS ===\n\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Inicializa maior e menor com o primeiro elemento
    maior = vetor[0];
    menor = vetor[0];

    // Percorre o vetor para realizar os calculos
    for (i = 0; i < TAMANHO; i++) {

        // Soma dos elementos multiplos de 3
        if (vetor[i] % 3 == 0) {
            somaMultiplos3 += vetor[i];
        }

        // Calcula a soma e quantidade dos elementos pares
        if (vetor[i] % 2 == 0) {
            somaPares += vetor[i];
            quantidadePares++;
        }

        // Conta numeros positivos e negativos
        if (vetor[i] > 0) {
            quantidadePositivos++;
        } else if (vetor[i] < 0) {
            quantidadeNegativos++;
        }

        // Verifica o maior valor
        if (vetor[i] > maior) {
            maior = vetor[i];
        }

        // Verifica o menor valor
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    // Apresentacao dos resultados
    printf("\n========================================\n");
    printf("           RESULTADOS\n");
    printf("========================================\n");

    printf("Soma dos multiplos de 3: %d\n", somaMultiplos3);

    // Evita divisao por zero caso nao existam numeros pares
    if (quantidadePares > 0) {
        float mediaPares = (float)somaPares / quantidadePares;
        printf("Media dos elementos pares: %.2f\n", mediaPares);
    } else {
        printf("Media dos elementos pares: Nao existem numeros pares.\n");
    }

    printf("Quantidade de positivos: %d\n", quantidadePositivos);
    printf("Quantidade de negativos: %d\n", quantidadeNegativos);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    // Exibe todos os elementos armazenados
    printf("\n========================================\n");
    printf("       ELEMENTOS DO VETOR\n");
    printf("========================================\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf("\n========================================\n");
    printf("Programa finalizado!\n");
    printf("========================================\n");

    return 0;
}
