#include <stdio.h>
#include <math.h>

#define MAX_MATRIZES 10
#define MAX_LINHAS 10
#define MAX_COLUNAS 10
#define EPSILON 1e-9

typedef struct {
    int linhas;   /* L */
    int colunas;  /* C */
    double dados[MAX_LINHAS][MAX_COLUNAS];
} Matriz;

/* Assinaturas das funcoes (modularizacao) */
void limparBuffer(void);
void pausarTela(void);
void exibirMenu(void);
int escolherQuantidadeMatrizes(int *qtd);
int informarMatrizes(Matriz matrizes[], int qtd);
void exibirMatriz(const Matriz *m, const char *titulo);
void listarMatrizesArmazenadas(const Matriz matrizes[], int qtd);
int selecionarOperandos(int qtd, int *idxA, int *idxB);
int lerCodigoOperacao(int esperado, const char *nomeOperacao);
int somarMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao);
int subtrairMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao);
int multiplicarMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao);
static int calcularInversa(const Matriz *m, Matriz *inversa);
int dividirMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao);

int main(void) {
    Matriz matrizes[MAX_MATRIZES];
    Matriz solucao;

    int qtdMatrizes = 0;
    int qtdInformada = 0;
    int matrizesCadastradas = 0;
    int temSolucao = 0;
    int opcao;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("[ERRO] Digite um numero valido do menu.\n");
            pausarTela();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                if (escolherQuantidadeMatrizes(&qtdMatrizes)) {
                    qtdInformada = 1;
                    matrizesCadastradas = 0;
                    temSolucao = 0;
                }
                pausarTela();
                break;

            case 2:
                if (!qtdInformada) {
                    printf("[AVISO] Escolha primeiro a quantidade de matrizes na opcao 1.\n");
                } else if (informarMatrizes(matrizes, qtdMatrizes)) {
                    matrizesCadastradas = 1;
                    temSolucao = 0;
                }
                pausarTela();
                break;

            case 3:
            case 4:
            case 5:
            case 6: {
                if (!matrizesCadastradas) {
                    printf("[AVISO] Informe as matrizes na opcao 2 antes de realizar operacoes.\n");
                    pausarTela();
                    break;
                }

                int codigoEsperado = opcao - 2; /* 3->1, 4->2, 5->3, 6->4 */
                const char *nomes[] = {"soma", "subtracao", "multiplicacao", "divisao"};

                if (!lerCodigoOperacao(codigoEsperado, nomes[codigoEsperado - 1])) {
                    pausarTela();
                    break;
                }

                int idxA = 0, idxB = 0, sucesso = 0;
                if (!selecionarOperandos(qtdMatrizes, &idxA, &idxB)) {
                    pausarTela();
                    break;
                }

                if (codigoEsperado == 1) {
                    sucesso = somarMatrizes(&matrizes[idxA], &matrizes[idxB], &solucao);
                } else if (codigoEsperado == 2) {
                    sucesso = subtrairMatrizes(&matrizes[idxA], &matrizes[idxB], &solucao);
                } else if (codigoEsperado == 3) {
                    sucesso = multiplicarMatrizes(&matrizes[idxA], &matrizes[idxB], &solucao);
                } else if (codigoEsperado == 4) {
                    sucesso = dividirMatrizes(&matrizes[idxA], &matrizes[idxB], &solucao);
                }

                if (sucesso) {
                    temSolucao = 1;
                    printf("[OK] Operacao concluida! Selecione a opcao 7 para ver a matriz SOLUCAO.\n");
                }
                pausarTela();
                break;
            }

            case 7:
                if (!temSolucao) {
                    printf("[AVISO] Ainda nao ha uma matriz SOLUCAO valida gerada.\n");
                } else {
                    exibirMatriz(&solucao, "MATRIZ SOLUCAO");
                }
                pausarTela();
                break;

            case 8:
                if (!matrizesCadastradas) {
                    printf("[AVISO] Nenhuma matriz foi cadastrada ainda (use as opcoes 1 e 2).\n");
                } else {
                    listarMatrizesArmazenadas(matrizes, qtdMatrizes);
                }
                pausarTela();
                break;

            case 0:
                printf("\nEncerrando a calculadora de matrizes. Ate logo!\n");
                break;

            default:
                printf("[ERRO] Opcao invalida. Escolha uma opcao do menu.\n");
                pausarTela();
                break;
        }
    } while (opcao != 0);

    return 0;
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void pausarTela(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void exibirMenu(void) {
    printf("\n==============================================\n");
    printf("       CALCULADORA INTERATIVA DE MATRIZES     \n");
    printf("==============================================\n");
    printf("1 - Escolha a qtd de matrizes\n");
    printf("2 - Informar matrizes (L linhas x C colunas)\n");
    printf("3 - Digite 1 para soma de matrizes\n");
    printf("4 - Digite 2 para subtracao de matrizes\n");
    printf("5 - Digite 3 para multiplicacao\n");
    printf("6 - Digite 4 para divisao (A * B^-1)\n");
    printf("7 - Apresente a matriz SOLUCAO ao usuario\n");
    printf("8 - Listar matrizes armazenadas\n");
    printf("0 - Sair\n");
    printf("----------------------------------------------\n");
    printf("Escolha uma opcao: ");
}

int escolherQuantidadeMatrizes(int *qtd) {
    int valor;
    printf("\nInforme a quantidade de matrizes (2 a %d): ", MAX_MATRIZES);
    if (scanf("%d", &valor) != 1) {
        limparBuffer();
        printf("[ERRO] Entrada invalida. Digite um numero inteiro.\n");
        return 0;
    }
    limparBuffer();

    if (valor < 2 || valor > MAX_MATRIZES) {
        printf("[ERRO] Quantidade invalida. Escolha entre 2 e %d matrizes.\n", MAX_MATRIZES);
        return 0;
    }

    *qtd = valor;
    printf("[OK] Quantidade definida para %d matriz(es).\n", *qtd);
    return 1;
}

int informarMatrizes(Matriz matrizes[], int qtd) {
    for (int k = 0; k < qtd; k++) {
        int l = 0, c = 0;

        printf("\n--- Cadastro da Matriz %d de %d ---\n", k + 1, qtd);
        printf("Informe L (quantidade de linhas, 1 a %d): ", MAX_LINHAS);
        if (scanf("%d", &l) != 1 || l < 1 || l > MAX_LINHAS) {
            limparBuffer();
            printf("[ERRO] Quantidade de linhas (L) invalida.\n");
            return 0;
        }

        printf("Informe C (quantidade de colunas, 1 a %d): ", MAX_COLUNAS);
        if (scanf("%d", &c) != 1 || c < 1 || c > MAX_COLUNAS) {
            limparBuffer();
            printf("[ERRO] Quantidade de colunas (C) invalida.\n");
            return 0;
        }
        limparBuffer();

        matrizes[k].linhas = l;
        matrizes[k].colunas = c;

        printf("Digite os elementos da Matriz %d (%dx%d):\n", k + 1, l, c);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                printf("  Elemento [%d][%d]: ", i + 1, j + 1);
                if (scanf("%lf", &matrizes[k].dados[i][j]) != 1) {
                    limparBuffer();
                    printf("[ERRO] Valor numerico invalido no elemento [%d][%d].\n", i + 1, j + 1);
                    return 0;
                }
            }
        }
        limparBuffer();
        printf("[OK] Matriz %d (%dx%d) armazenada com sucesso.\n", k + 1, l, c);
    }
    return 1;
}

void exibirMatriz(const Matriz *m, const char *titulo) {
    printf("\n--- %s (L=%d x C=%d) ---\n", titulo, m->linhas, m->colunas);
    for (int i = 0; i < m->linhas; i++) {
        printf("| ");
        for (int j = 0; j < m->colunas; j++) {
            printf("%8.2f ", m->dados[i][j]);
        }
        printf("|\n");
    }
}

void listarMatrizesArmazenadas(const Matriz matrizes[], int qtd) {
    printf("\n=== MATRIZES ARMAZENADAS ===\n");
    for (int k = 0; k < qtd; k++) {
        char rotulo[32];
        snprintf(rotulo, sizeof(rotulo), "Matriz %d", k + 1);
        exibirMatriz(&matrizes[k], rotulo);
    }
}

int selecionarOperandos(int qtd, int *idxA, int *idxB) {
    printf("\nEscolha o indice da 1a matriz (1 a %d): ", qtd);
    if (scanf("%d", idxA) != 1 || *idxA < 1 || *idxA > qtd) {
        limparBuffer();
        printf("[ERRO] Indice invalido para a 1a matriz.\n");
        return 0;
    }

    printf("Escolha o indice da 2a matriz / divisora (1 a %d): ", qtd);
    if (scanf("%d", idxB) != 1 || *idxB < 1 || *idxB > qtd) {
        limparBuffer();
        printf("[ERRO] Indice invalido para a 2a matriz.\n");
        return 0;
    }
    limparBuffer();

    (*idxA)--;
    (*idxB)--;
    return 1;
}

int lerCodigoOperacao(int esperado, const char *nomeOperacao) {
    int codigo;
    printf("Confirme digitando %d para %s: ", esperado, nomeOperacao);
    if (scanf("%d", &codigo) != 1) {
        limparBuffer();
        printf("[ERRO] Entrada invalida.\n");
        return 0;
    }
    limparBuffer();

    if (codigo != esperado) {
        printf("[AVISO] Voce digitou %d, mas esta opcao espera o codigo %d para %s.\n",
               codigo, esperado, nomeOperacao);
        return 0;
    }
    return 1;
}

int somarMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao) {
    if (a->linhas != b->linhas || a->colunas != b->colunas) {
        printf("[OPERACAO IMPOSSIVEL] Soma exige mesmas dimensoes: "
               "Matriz A (%dx%d) != Matriz B (%dx%d).\n",
               a->linhas, a->colunas, b->linhas, b->colunas);
        return 0;
    }

    solucao->linhas = a->linhas;
    solucao->colunas = a->colunas;

    for (int i = 0; i < a->linhas; i++) {
        for (int j = 0; j < a->colunas; j++) {
            solucao->dados[i][j] = a->dados[i][j] + b->dados[i][j];
        }
    }
    return 1;
}

int subtrairMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao) {
    if (a->linhas != b->linhas || a->colunas != b->colunas) {
        printf("[OPERACAO IMPOSSIVEL] Subtracao exige mesmas dimensoes: "
               "Matriz A (%dx%d) != Matriz B (%dx%d).\n",
               a->linhas, a->colunas, b->linhas, b->colunas);
        return 0;
    }

    solucao->linhas = a->linhas;
    solucao->colunas = a->colunas;

    for (int i = 0; i < a->linhas; i++) {
        for (int j = 0; j < a->colunas; j++) {
            solucao->dados[i][j] = a->dados[i][j] - b->dados[i][j];
        }
    }
    return 1;
}

int multiplicarMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao) {
    if (a->colunas != b->linhas) {
        printf("[OPERACAO IMPOSSIVEL] Multiplicacao exige C_A (%d) == L_B (%d).\n",
               a->colunas, b->linhas);
        return 0;
    }

    solucao->linhas = a->linhas;
    solucao->colunas = b->colunas;

    for (int i = 0; i < solucao->linhas; i++) {
        for (int j = 0; j < solucao->colunas; j++) {
            double soma = 0.0;
            for (int k = 0; k < a->colunas; k++) {
                soma += a->dados[i][k] * b->dados[k][j];
            }
            solucao->dados[i][j] = soma;
        }
    }
    return 1;
}

static int calcularInversa(const Matriz *m, Matriz *inversa) {
    int n = m->linhas;

    if (m->linhas != m->colunas) {
        printf("[OPERACAO IMPOSSIVEL] A matriz divisora precisa ser quadrada (L == C). "
               "Recebida: %dx%d.\n", m->linhas, m->colunas);
        return 0;
    }

    double aug[MAX_LINHAS][MAX_COLUNAS * 2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = m->dados[i][j];
            aug[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int col = 0; col < n; col++) {
        int linhaPivo = col;
        for (int i = col + 1; i < n; i++) {
            if (fabs(aug[i][col]) > fabs(aug[linhaPivo][col])) {
                linhaPivo = i;
            }
        }

        if (fabs(aug[linhaPivo][col]) < EPSILON) {
            printf("[OPERACAO IMPOSSIVEL] A matriz divisora e SINGULAR (determinante = 0) "
                   "e nao possui inversa.\n");
            return 0;
        }

        if (linhaPivo != col) {
            for (int j = 0; j < 2 * n; j++) {
                double temp = aug[col][j];
                aug[col][j] = aug[linhaPivo][j];
                aug[linhaPivo][j] = temp;
            }
        }

        double pivo = aug[col][col];
        for (int j = 0; j < 2 * n; j++) {
            aug[col][j] /= pivo;
        }

        for (int i = 0; i < n; i++) {
            if (i != col) {
                double fator = aug[i][col];
                for (int j = 0; j < 2 * n; j++) {
                    aug[i][j] -= fator * aug[col][j];
                }
            }
        }
    }

    inversa->linhas = n;
    inversa->colunas = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inversa->dados[i][j] = aug[i][j + n];
        }
    }
    return 1;
}

int dividirMatrizes(const Matriz *a, const Matriz *b, Matriz *solucao) {
    Matriz inversaB;

    if (!calcularInversa(b, &inversaB)) {
        return 0;
    }

    if (a->colunas != inversaB.linhas) {
        printf("[OPERACAO IMPOSSIVEL] Divisao (A * B^-1) exige C_A (%d) == L_B (%d).\n",
               a->colunas, inversaB.linhas);
        return 0;
    }

    return multiplicarMatrizes(a, &inversaB, solucao);
}
