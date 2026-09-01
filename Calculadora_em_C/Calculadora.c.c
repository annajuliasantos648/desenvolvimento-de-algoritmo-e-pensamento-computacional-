#include <stdio.h>
#include <math.h>

// ======================================================
// CALCULADORA COMPLETA EM C
// 20 operações matemáticas
// ======================================================

// 1. Soma
double somar(double a, double b) {
    return a + b;
}

// 2. Subtração
double subtrair(double a, double b) {
    return a - b;
}

// 3. Multiplicação
double multiplicar(double a, double b) {
    return a * b;
}

// 4. Divisão
double dividir(double a, double b) {
    return a / b;
}

// 5. Potenciação
double potencia(double base, double expoente) {
    return pow(base, expoente);
}

// 6. Raiz quadrada
double raizQuadrada(double numero) {
    return sqrt(numero);
}

// 7. Raiz cúbica
double raizCubica(double numero) {
    return cbrt(numero);
}

// 8. Seno
double seno(double angulo) {
    return sin(angulo);
}

// 9. Cosseno
double cosseno(double angulo) {
    return cos(angulo);
}

// 10. Tangente
double tangente(double angulo) {
    return tan(angulo);
}

// 11. Logaritmo natural
double logaritmoNatural(double numero) {
    return log(numero);
}

// 12. Logaritmo na base 10
double logaritmoBase10(double numero) {
    return log10(numero);
}

// 13. Valor absoluto
double valorAbsoluto(double numero) {
    return fabs(numero);
}

// 14. Porcentagem
double porcentagem(double valor, double percentual) {
    return valor * percentual / 100.0;
}

// 15. Média aritmética
double mediaAritmetica(double a, double b) {
    return (a + b) / 2.0;
}

// 16. Graus para radianos
double grausParaRadianos(double graus) {
    return graus * M_PI / 180.0;
}

// 17. Radianos para graus
double radianosParaGraus(double radianos) {
    return radianos * 180.0 / M_PI;
}

// 18. Área do círculo
double areaCirculo(double raio) {
    return M_PI * raio * raio;
}

// 19. Área do retângulo
double areaRetangulo(double base, double altura) {
    return base * altura;
}

// 20. Hipotenusa
double calcularHipotenusa(double catetoA, double catetoB) {
    return hypot(catetoA, catetoB);
}


// ======================================================
// FUNÇÃO PRINCIPAL
// ======================================================

int main() {

    int opcao;
    double a, b, resultado;

    do {

        printf("\n============================================\n");
        printf("        CALCULADORA COMPLETA EM C\n");
        printf("============================================\n");
        printf(" 1  - Soma\n");
        printf(" 2  - Subtracao\n");
        printf(" 3  - Multiplicacao\n");
        printf(" 4  - Divisao\n");
        printf(" 5  - Potenciacao\n");
        printf(" 6  - Raiz quadrada\n");
        printf(" 7  - Raiz cubica\n");
        printf(" 8  - Seno\n");
        printf(" 9  - Cosseno\n");
        printf("10  - Tangente\n");
        printf("11  - Logaritmo natural\n");
        printf("12  - Logaritmo base 10\n");
        printf("13  - Valor absoluto\n");
        printf("14  - Porcentagem\n");
        printf("15  - Media aritmetica\n");
        printf("16  - Graus para radianos\n");
        printf("17  - Radianos para graus\n");
        printf("18  - Area do circulo\n");
        printf("19  - Area do retangulo\n");
        printf("20  - Hipotenusa\n");
        printf(" 0  - Encerrar programa\n");
        printf("============================================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        printf("\n");

        switch (opcao) {

            // 1 - Soma
            case 1:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);

                printf("Digite o segundo numero: ");
                scanf("%lf", &b);

                resultado = somar(a, b);

                printf("Resultado: %.2lf\n", resultado);
                break;


            // 2 - Subtração
            case 2:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);

                printf("Digite o segundo numero: ");
                scanf("%lf", &b);

                resultado = subtrair(a, b);

                printf("Resultado: %.2lf\n", resultado);
                break;


            // 3 - Multiplicação
            case 3:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);

                printf("Digite o segundo numero: ");
                scanf("%lf", &b);

                resultado = multiplicar(a, b);

                printf("Resultado: %.2lf\n", resultado);
                break;


            // 4 - Divisão
            case 4:
                printf("Digite o dividendo: ");
                scanf("%lf", &a);

                printf("Digite o divisor: ");
                scanf("%lf", &b);

                if (b == 0) {
                    printf("ERRO: nao e possivel dividir por zero!\n");
                } else {
                    resultado = dividir(a, b);
                    printf("Resultado: %.2lf\n", resultado);
                }
                break;


            // 5 - Potenciação
            case 5:
                printf("Digite a base: ");
                scanf("%lf", &a);

                printf("Digite o expoente: ");
                scanf("%lf", &b);

                resultado = potencia(a, b);

                printf("Resultado: %.2lf\n", resultado);
                break;


            // 6 - Raiz quadrada
            case 6:
                printf("Digite um numero: ");
                scanf("%lf", &a);

                if (a < 0) {
                    printf("ERRO: nao existe raiz quadrada real de numero negativo.\n");
                } else {
                    resultado = raizQuadrada(a);
                    printf("Resultado: %.2lf\n", resultado);
                }
                break;


            // 7 - Raiz cúbica
            case 7:
                printf("Digite um numero: ");
                scanf("%lf", &a);

                resultado = raizCubica(a);

                printf("Resultado: %.2lf\n", resultado);
                break;


            // 8 - Seno
            case 8:
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &a);

                resultado = seno(a);

                printf("Seno: %.4lf\n", resultado);
                break;


            // 9 - Cosseno
            case 9:
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &a);

                resultado = cosseno(a);

                printf("Cosseno: %.4lf\n", resultado);
                break;


            // 10 - Tangente
            case 10:
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &a);

                // Verifica se o cosseno está próximo de zero
                if (fabs(cos(a)) < 1e-10) {
                    printf("ERRO: tangente indefinida para este angulo.\n");
                } else {
                    resultado = tangente(a);
                    printf("Tangente: %.4lf\n", resultado);
                }
                break;


            // 11 - Logaritmo natural
            case 11:
                printf("Digite um numero positivo: ");
                scanf("%lf", &a);

                if (a <= 0) {
                    printf("ERRO: o logaritmo natural exige numero maior que zero.\n");
                } else {
                    resultado = logaritmoNatural(a);
                    printf("Resultado: %.4lf\n", resultado);
                }
                break;


            // 12 - Logaritmo base 10
            case 12:
                printf("Digite um numero positivo: ");
                scanf("%lf", &a);

                if (a <= 0) {
                    printf("ERRO: o logaritmo exige numero maior que zero.\n");
                } else {
                    resultado = logaritmoBase10(a);
                    printf("Resultado: %.4lf\n", resultado);
                }
                break;


            // 13 - Valor absoluto
            case 13:
                printf("Digite um numero: ");
                scanf("%lf", &a);

                resultado = valorAbsoluto(a);

                printf("Valor absoluto: %.2lf\n", resultado);
                break;


            // 14 - Porcentagem
            case 14:
                printf("Digite o valor: ");
                scanf("%lf", &a);

                printf("Digite a porcentagem: ");
                scanf("%lf", &b);

                resultado = porcentagem(a, b);

                printf("%.2lf%% de %.2lf = %.2lf\n",
                       b, a, resultado);
                break;


            // 15 - Média aritmética
            case 15:
                printf("Digite a primeira nota/valor: ");
                scanf("%lf", &a);

                printf("Digite a segunda nota/valor: ");
                scanf("%lf", &b);

                resultado = mediaAritmetica(a, b);

                printf("Media aritmetica: %.2lf\n", resultado);
                break;


            // 16 - Graus para radianos
            case 16:
                printf("Digite o valor em graus: ");
                scanf("%lf", &a);

                resultado = grausParaRadianos(a);

                printf("%.2lf graus = %.4lf radianos\n",
                       a, resultado);
                break;


            // 17 - Radianos para graus
            case 17:
                printf("Digite o valor em radianos: ");
                scanf("%lf", &a);

                resultado = radianosParaGraus(a);

                printf("%.4lf radianos = %.2lf graus\n",
                       a, resultado);
                break;


            // 18 - Área do círculo
            case 18:
                printf("Digite o raio do circulo: ");
                scanf("%lf", &a);

                if (a < 0) {
                    printf("ERRO: o raio nao pode ser negativo.\n");
                } else {
                    resultado = areaCirculo(a);
                    printf("Area do circulo: %.2lf\n", resultado);
                }
                break;


            // 19 - Área do retângulo
            case 19:
                printf("Digite a base do retangulo: ");
                scanf("%lf", &a);

                printf("Digite a altura do retangulo: ");
                scanf("%lf", &b);

                if (a < 0 || b < 0) {
                    printf("ERRO: base e altura nao podem ser negativas.\n");
                } else {
                    resultado = areaRetangulo(a, b);
                    printf("Area do retangulo: %.2lf\n", resultado);
                }
                break;


            // 20 - Hipotenusa
            case 20:
                printf("Digite o primeiro cateto: ");
                scanf("%lf", &a);

                printf("Digite o segundo cateto: ");
                scanf("%lf", &b);

                if (a < 0 || b < 0) {
                    printf("ERRO: os catetos nao podem ser negativos.\n");
                } else {
                    resultado = calcularHipotenusa(a, b);
                    printf("Hipotenusa: %.2lf\n", resultado);
                }
                break;


            // Encerramento
            case 0:
                printf("Programa encerrado. Obrigado por usar a calculadora!\n");
                break;


            // Opção inválida
            default:
                printf("ERRO: opcao invalida! Escolha uma opcao de 0 a 20.\n");
        }

    } while (opcao != 0);

    return 0;
}
