#include <stdio.h>
#include <math.h>

#define MAX_MATRIZES 10
#define MAX_LINHAS 10
#define MAX_COLUNAS 10
#define EPSILON 1e-9

typedef struct {
    int linhas, colunas;
    double dados[MAX_LINHAS][MAX_COLUNAS];
} Matriz;

void limparBuffer(void);
void pausar(void);
int lerInteiro(const char *msg, int min, int max, int *out);
void exibirMenu(void);
int informarMatrizes(Matriz m[], int qtd);
void exibirMatriz(const Matriz *m, const char *titulo);
int selecionarOperandos(int qtd, int *a, int *b);
int somarOuSubtrair(const Matriz *a, const Matriz *b, Matriz *sol, int sinal);
int multiplicar(const Matriz *a, const Matriz *b, Matriz *sol);
int inverter(const Matriz *m, Matriz *inv);
int dividir(const Matriz *a, const Matriz *b, Matriz *sol);

int main(void) {
    Matriz m[MAX_MATRIZES], solucao;
    int qtd = 0, temQtd = 0, temMatrizes = 0, temSol = 0, op;
    const char *nomes[] = {"soma", "subtracao", "multiplicacao", "divisao"};

    do {
        exibirMenu();
        if (!lerInteiro("Escolha uma opcao: ", 0, 8, &op)) { pausar(); continue; }

        if (op == 1) {
            if (lerInteiro("\nQtd de matrizes (2 a 10): ", 2, MAX_MATRIZES, &qtd)) {
                temQtd = 1; temMatrizes = temSol = 0;
            }
        } else if (op == 2) {
            if (!temQtd) printf("[AVISO] Informe a qtd de matrizes na opcao 1.\n");
            else if (informarMatrizes(m, qtd)) { temMatrizes = 1; temSol = 0; }
        } else if (op >= 3 && op <= 6) {
            if (!temMatrizes) {
                printf("[AVISO] Informe as matrizes na opcao 2 primeiro.\n");
            } else {
                int codEsp = op - 2, codDig, idxA, idxB, ok = 0;
                char prompt[64];
                snprintf(prompt, sizeof(prompt), "Confirme digitando %d para %s: ", codEsp, nomes[codEsp - 1]);
                if (lerInteiro(prompt, 0, 99, &codDig)) {
                    if (codDig != codEsp) {
                        printf("[AVISO] Esperado codigo %d para %s.\n", codEsp, nomes[codEsp - 1]);
                    } else if (selecionarOperandos(qtd, &idxA, &idxB)) {
                        if (codEsp == 1) ok = somarOuSubtrair(&m[idxA], &m[idxB], &solucao, 1);
                        else if (codEsp == 2) ok = somarOuSubtrair(&m[idxA], &m[idxB], &solucao, -1);
                        else if (codEsp == 3) ok = multiplicar(&m[idxA], &m[idxB], &solucao);
                        else ok = dividir(&m[idxA], &m[idxB], &solucao);
                        if (ok) { temSol = 1; printf("[OK] Solucao pronta! Use a opcao 7.\n"); }
                    }
                }
            }
        } else if (op == 7) {
            if (!temSol) printf("[AVISO] Nenhuma SOLUCAO gerada ainda.\n");
            else exibirMatriz(&solucao, "MATRIZ SOLUCAO");
        } else if (op == 8) {
            if (!temMatrizes) printf("[AVISO] Nenhuma matriz cadastrada.\n");
            else for (int k = 0; k < qtd; k++) {
                char t[20]; snprintf(t, sizeof(t), "Matriz %d", k + 1);
                exibirMatriz(&m[k], t);
            }
        } else if (op == 0) {
            printf("\nEncerrando...\n");
            break;
        }
        pausar();
    } while (1);
    return 0;
}

void limparBuffer(void) { int c; while ((c = getchar()) != '\n' && c != EOF) {} }
void pausar(void) { printf("\nPressione ENTER..."); getchar(); }

int lerInteiro(const char *msg, int min, int max, int *out) {
    printf("%s", msg);
    if (scanf("%d", out) != 1 || *out < min || *out > max) {
        limparBuffer();
        printf("[ERRO] Valor invalido (%d a %d).\n", min, max);
        return 0;
    }
    limparBuffer();
    return 1;
}

void exibirMenu(void) {
    printf("\n=== CALCULADORA DE MATRIZES ===\n"
           "1 - Escolha a qtd de matrizes\n"
           "2 - Informar matrizes (L x C)\n"
           "3 - Digite 1 para soma\n"
           "4 - Digite 2 para subtracao\n"
           "5 - Digite 3 para multiplicacao\n"
           "6 - Digite 4 para divisao (A * B^-1)\n"
           "7 - Apresente a matriz SOLUCAO\n"
           "8 - Listar matrizes\n0 - Sair\n");
}

int informarMatrizes(Matriz m[], int qtd) {
    for (int k = 0; k < qtd; k++) {
        printf("\n--- Matriz %d ---\n", k + 1);
        if (!lerInteiro("L (linhas, 1 a 10): ", 1, MAX_LINHAS, &m[k].linhas) ||
            !lerInteiro("C (colunas, 1 a 10): ", 1, MAX_COLUNAS, &m[k].colunas)) return 0;
        for (int i = 0; i < m[k].linhas; i++) {
            for (int j = 0; j < m[k].colunas; j++) {
                printf("  [%d][%d]: ", i + 1, j + 1);
                if (scanf("%lf", &m[k].dados[i][j]) != 1) {
                    limparBuffer(); printf("[ERRO] Numero invalido.\n"); return 0;
                }
            }
        }
        limparBuffer();
    }
    return 1;
}

void exibirMatriz(const Matriz *m, const char *titulo) {
    printf("\n--- %s (%dx%d) ---\n", titulo, m->linhas, m->colunas);
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) printf("%8.2f ", m->dados[i][j]);
        printf("\n");
    }
}

int selecionarOperandos(int qtd, int *a, int *b) {
    return lerInteiro("1a matriz: ", 1, qtd, a) &&
           lerInteiro("2a matriz / divisora: ", 1, qtd, b) && ((*a)--, (*b)--, 1);
}

int somarOuSubtrair(const Matriz *a, const Matriz *b, Matriz *sol, int sinal) {
    if (a->linhas != b->linhas || a->colunas != b->colunas) {
        printf("[IMPOSSIVEL] Dimensoes diferentes (%dx%d vs %dx%d).\n",
               a->linhas, a->colunas, b->linhas, b->colunas);
        return 0;
    }
    sol->linhas = a->linhas; sol->colunas = a->colunas;
    for (int i = 0; i < a->linhas; i++)
        for (int j = 0; j < a->colunas; j++)
            sol->dados[i][j] = a->dados[i][j] + sinal * b->dados[i][j];
    return 1;
}

int multiplicar(const Matriz *a, const Matriz *b, Matriz *sol) {
    if (a->colunas != b->linhas) {
        printf("[IMPOSSIVEL] Colunas de A (%d) != linhas de B (%d).\n", a->colunas, b->linhas);
        return 0;
    }
    sol->linhas = a->linhas; sol->colunas = b->colunas;
    for (int i = 0; i < sol->linhas; i++)
        for (int j = 0; j < sol->colunas; j++) {
            double s = 0;
            for (int k = 0; k < a->colunas; k++) s += a->dados[i][k] * b->dados[k][j];
            sol->dados[i][j] = s;
        }
    return 1;
}

int inverter(const Matriz *m, Matriz *inv) {
    int n = m->linhas;
    if (n != m->colunas) {
        printf("[IMPOSSIVEL] Matriz divisora precisa ser quadrada (%dx%d).\n", n, m->colunas);
        return 0;
    }
    double aug[MAX_LINHAS][MAX_COLUNAS * 2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) { aug[i][j] = m->dados[i][j]; aug[i][j + n] = (i == j); }

    for (int col = 0; col < n; col++) {
        int piv = col;
        for (int i = col + 1; i < n; i++) if (fabs(aug[i][col]) > fabs(aug[piv][col])) piv = i;
        if (fabs(aug[piv][col]) < EPSILON) {
            printf("[IMPOSSIVEL] Matriz divisora SINGULAR (sem inversa).\n"); return 0;
        }
        for (int j = 0; j < 2 * n; j++) { double t = aug[col][j]; aug[col][j] = aug[piv][j]; aug[piv][j] = t; }
        double p = aug[col][col];
        for (int j = 0; j < 2 * n; j++) aug[col][j] /= p;
        for (int i = 0; i < n; i++) if (i != col) {
            double f = aug[i][col];
            for (int j = 0; j < 2 * n; j++) aug[i][j] -= f * aug[col][j];
        }
    }
    inv->linhas = inv->colunas = n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) inv->dados[i][j] = aug[i][j + n];
    return 1;
}

int dividir(const Matriz *a, const Matriz *b, Matriz *sol) {
    Matriz invB;
    return inverter(b, &invB) && multiplicar(a, &invB, sol);
}
