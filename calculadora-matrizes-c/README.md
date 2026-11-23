# Calculadora Interativa de Matrizes em C

Projeto desenvolvido em linguagem **C** (em arquivo único `calculadora_matrizes.c`, organizado de forma modularizada em funções) para cadastro, armazenamento, visualização e cálculo entre matrizes de dimensões `L` (linhas) por `C` (colunas), conforme proposto na atividade[cite: 1].

---

## Sumário

1. [Sobre o Projeto](#sobre-o-projeto)
2. [Funcionalidades e Fluxo do Menu](#funcionalidades-e-fluxo-do-menu)
3. [Modularização e Arquitetura do Código](#modularização-e-arquitetura-do-código)
4. [Regras Matemáticas e Tratamento de Erros](#regras-matemáticas-e-tratamento-de-erros)
5. [Estrutura do Repositório](#estrutura-do-repositório)
6. [Exemplo Prático de Uso](#exemplo-prático-de-uso)

---

## Sobre o Projeto

A **Calculadora Interativa de Matrizes em C** permite que o usuário defina uma quantidade de matrizes, informe as dimensões `L` (linhas) e `C` (colunas) e os valores de cada uma, armazene essas matrizes na memória durante a execução e aplique operações matemáticas com validação de compatibilidade[cite: 1].

O programa controla o estado da sessão para evitar passos fora de ordem — por exemplo, impede o cadastro das matrizes antes da escolha da quantidade e impede cálculos antes do cadastro completo das matrizes[cite: 1].

---

## Funcionalidades e Fluxo do Menu

Ao executar o programa, o menu principal oferece as seguintes opções:

- **`1` — Escolha a qtd de matrizes:** define quantas matrizes farão parte da sessão (respeitando o limite `MAX_MATRIZES`)[cite: 1]. Alterar a quantidade reinicia o estado de cadastro e de solução anterior para evitar inconsistências.
- **`2` — Informar matrizes (`L` linhas x `C` colunas):** disponível após definir a quantidade[cite: 1]. Para cada matriz, pede o número de linhas (`L`), o número de colunas (`C`) e cada elemento `[i][j]`, armazenando tudo no vetor de estruturas `Matriz`.
- **`3` — Soma de matrizes (código `1`):** solicita a confirmação do código `1`, pede os índices da 1ª e da 2ª matriz e calcula `A + B`[cite: 1].
- **`4` — Subtração de matrizes (código `2`):** solicita a confirmação do código `2`, pede os índices da 1ª e da 2ª matriz e calcula `A - B`[cite: 1].
- **`5` — Multiplicação de matrizes (código `3`):** solicita a confirmação do código `3`, pede os índices da 1ª e da 2ª matriz e calcula `A * B`[cite: 1].
- **`6` — Divisão de matrizes (código `4`):** solicita a confirmação do código `4`, pede os índices da 1ª matriz (`A`) e da 2ª matriz / divisora (`B`) e calcula `A * B^-1`[cite: 1].
- **`7` — Apresente a matriz `SOLUÇÃO` ao usuário:** exibe a matriz resultante da última operação válida executada[cite: 1].
- **`8` — Listar matrizes armazenadas:** mostra todas as matrizes cadastradas no momento, com suas respectivas dimensões `L x C` e elementos.
- **`0` — Sair:** encerra o programa com segurança.

---

## Modularização e Arquitetura do Código

Mesmo estando reunido em um único arquivo (`calculadora_matrizes.c`), o código é dividido em funções com responsabilidades bem definidas:

- **`Matriz` (`struct`) e constantes (`#define`):** agrupa `linhas` (`L`), `colunas` (`C`) e `dados[MAX_LINHAS][MAX_COLUNAS]` em um único tipo, facilitando a passagem por referência (`const Matriz *` e `Matriz *`).
- **Interface e entrada (`exibirMenu`, `limparBuffer`, `pausarTela`, `lerCodigoOperacao`, `selecionarOperandos`):** centralizam a leitura segura com `scanf`, limpeza de buffer do teclado e validação de índices e códigos.
- **Cadastro e exibição (`escolherQuantidadeMatrizes`, `informarMatrizes`, `exibirMatriz`, `listarMatrizesArmazenadas`):** cuidam da entrada dos dados e da formatação visual das matrizes na tela.
- **Operações (`somarMatrizes`, `subtrairMatrizes`, `multiplicarMatrizes`, `calcularInversa`, `dividirMatrizes`):** isolam a lógica matemática e retornam `1` (sucesso) ou `0` (falha), permitindo que `main` atualize ou não a matriz `SOLUÇÃO`[cite: 1].

---

## Regras Matemáticas e Tratamento de Erros

Quando uma operação não pode ser realizada, o programa exibe uma mensagem explicativa no terminal e **não** sobrescreve uma solução válida anterior com lixo de memória:

1. **Soma (`1`) e Subtração (`2`):**
   - **Regra:** exigem que ambas as matrizes tenham exatamente as mesmas dimensões (`L_A == L_B` e `C_A == C_B`).
   - **Erro tratado:** informa quando as dimensões são incompatíveis.

2. **Multiplicação (`3`):**
   - **Regra:** para multiplicar `A` (`L_A x C_A`) por `B` (`L_B x C_B`), é obrigatório que `C_A == L_B`. O resultado tem dimensão `L_A x C_B`.
   - **Erro tratado:** informa quando o número de colunas de `A` difere do número de linhas de `B`.

3. **Divisão (`4` — `A * B^-1`):**
   - **Regra:** como não há divisão direta de matrizes na álgebra matricial padrão, a operação é realizada multiplicando `A` pela inversa de `B` (`B^-1`), obtida por **eliminação de Gauss-Jordan com pivoteamento parcial** e matriz aumentada `[B | I]`. Além disso, `A` deve ser compatível com `B^-1` na multiplicação (`C_A == L_B`).
   - **Matriz divisora não quadrada:** se `L_B != C_B`, o sistema informa que a matriz divisora precisa ser quadrada.
   - **Matriz divisora singular:** durante o escalonamento, se o maior pivô em módulo for menor que `EPSILON` (`1e-9`), o sistema identifica que a matriz divisora é **singular** (determinante igual a zero) e, portanto, **não possui inversa**, bloqueando a operação e avisando o usuário.

---

## Estrutura do Repositório

```text
calculadora-matrizes-c/
├── README.md
└── calculadora_matrizes.c
```

- `calculadora_matrizes.c`: código-fonte completo e modularizado em C.
- `README.md`: documentação do projeto, regras e instruções de execução.

## Exemplo Prático de Uso

1. Escolha a opção **`1`** e informe **`2`** matrizes.
2. Escolha a opção **`2`** e cadastre:
   - **Matriz 1:** `L = 2`, `C = 2`, elementos `1, 2, 3, 4`.
   - **Matriz 2:** `L = 2`, `C = 2`, elementos `5, 6, 7, 8`.
3. Escolha a opção **`3`**, confirme digitando **`1`** (soma) e selecione a matriz `1` e a matriz `2`.
4. Escolha a opção **`7`** para visualizar a matriz **`SOLUÇÃO`** (`6.00 8.00` na 1ª linha e `10.00 12.00` na 2ª linha).
