#include <stdio.h>

int main() {
    float limite, temperatura;
    float soma = 0, maior = 0, menor = 0;
    int quantidade = 0;
    int acimaLimite = 0;
    int consecutivas = 0;
    int continuar = 1;

    // Leitura e validação do limite de temperatura
    do {
        printf("Digite o limite de temperatura (entre -50 e 100): ");
        scanf("%f", &limite);

        if (limite < -50 || limite > 100) {
            printf("Valor invalido! Digite um limite entre -50 e 100.\n");
        }
    } while (limite < -50 || limite > 100);

    printf("\n--- INICIO DO MONITORAMENTO ---\n");

    // Realiza as leituras enquanto o monitoramento estiver ativo
    while (continuar) {
        printf("\nDigite a temperatura (-50 a 100): ");
        scanf("%f", &temperatura);

        // Validação da temperatura
        if (temperatura < -50 || temperatura > 100) {
            printf("Temperatura invalida! Digite um valor entre -50 e 100.\n");
            continue;
        }

        // Primeira leitura define maior e menor
        if (quantidade == 0) {
            maior = temperatura;
            menor = temperatura;
        }

        // Atualiza maior e menor temperatura
        if (temperatura > maior) {
            maior = temperatura;
        }

        if (temperatura < menor) {
            menor = temperatura;
        }

        soma += temperatura;
        quantidade++;

        // Verifica se a temperatura ultrapassou o limite
        if (temperatura > limite) {
            acimaLimite++;
            consecutivas++;

            printf("ALERTA: temperatura acima do limite!\n");
            printf("Temperaturas consecutivas acima do limite: %d\n",
                   consecutivas);

            // Encerra após três temperaturas consecutivas acima do limite
            if (consecutivas == 3) {
                printf("\n*** ALERTA CRITICO ***\n");
                printf("Tres temperaturas consecutivas acima do limite.\n");
                printf("Monitoramento encerrado automaticamente.\n");
                continuar = 0;
            }
        } else {
            // Reinicia a contagem quando a temperatura volta ao limite
            consecutivas = 0;
            printf("Temperatura dentro do limite.\n");
        }
    }

    // Relatorio final
    printf("\n====================================\n");
    printf("       RELATORIO FINAL\n");
    printf("====================================\n");

    printf("Limite definido: %.2f °C\n", limite);
    printf("Quantidade de leituras validas: %d\n", quantidade);
    printf("Maior temperatura: %.2f °C\n", maior);
    printf("Menor temperatura: %.2f °C\n", menor);
    printf("Media das temperaturas: %.2f °C\n", soma / quantidade);
    printf("Temperaturas acima do limite: %d\n", acimaLimite);
    printf("Percentual acima do limite: %.2f%%\n",
           (acimaLimite * 100.0) / quantidade);

    printf("====================================\n");

    return 0;
}
