# 🧮 Calculadora Completa em C

> Projeto acadêmico desenvolvido em linguagem C com o objetivo de aplicar conceitos fundamentais de programação por meio da criação de uma calculadora com **20 operações matemáticas diferentes**.

---

## 👩‍💻 Identificação do Estudante

**Nome:** Anna Julia Santos Soares
**Curso:** Análise e Desenvolvimento de Sistemas (ADS)
**Instituição:** UDF – Centro Universitário do Distrito Federal 
**Disciplina:** Desenvolvimento de algoritmo e pensamento computacional
**Linguagem:** C

---

## 📌 Descrição do Projeto

Este projeto consiste no desenvolvimento de uma **calculadora completa em linguagem C**, permitindo que o usuário escolha diferentes operações matemáticas através de um menu interativo.

A aplicação foi desenvolvida com foco na utilização prática de conceitos fundamentais da programação, como:

* Variáveis e tipos de dados;
* Entrada e saída de dados;
* Funções;
* Modularização;
* Estruturas condicionais;
* Estruturas de repetição;
* Operadores matemáticos;
* Tratamento básico de erros;
* Utilização da biblioteca `math.h`;
* Organização e documentação de código.

O programa apresenta um menu com **20 operações matemáticas**, permitindo realizar cálculos básicos, funções matemáticas, conversões e cálculos geométricos.

---

## 🎯 Objetivo da Calculadora

O principal objetivo do projeto é desenvolver uma calculadora funcional utilizando a linguagem C e, ao mesmo tempo, demonstrar a aplicação integrada dos principais conceitos de programação.

Através do projeto, é possível praticar:

* Criação e utilização de funções;
* Passagem de parâmetros;
* Retorno de valores;
* Uso de variáveis do tipo `int` e `double`;
* Estruturas `if`, `else` e `switch...case`;
* Estruturas de repetição;
* Entrada de informações utilizando `scanf()`;
* Apresentação de resultados utilizando `printf()`;
* Utilização de funções matemáticas da biblioteca `math.h`;
* Tratamento de situações inválidas.

---

# ⚙️ Funcionalidades Implementadas

A calculadora possui **20 funções matemáticas**, acessíveis através de um menu numérico.

### 📋 Relação das 20 funções

| Nº | Função                 | Descrição                                      |
| -: | ---------------------- | ---------------------------------------------- |
| 01 | `somar()`              | Realiza a soma de dois números                 |
| 02 | `subtrair()`           | Realiza a subtração de dois números            |
| 03 | `multiplicar()`        | Realiza a multiplicação de dois números        |
| 04 | `dividir()`            | Realiza a divisão de dois números              |
| 05 | `potencia()`           | Calcula uma potência                           |
| 06 | `raizQuadrada()`       | Calcula a raiz quadrada                        |
| 07 | `raizCubica()`         | Calcula a raiz cúbica                          |
| 08 | `seno()`               | Calcula o seno de um ângulo                    |
| 09 | `cosseno()`            | Calcula o cosseno de um ângulo                 |
| 10 | `tangente()`           | Calcula a tangente de um ângulo                |
| 11 | `logaritmoNatural()`   | Calcula o logaritmo natural                    |
| 12 | `logaritmoBase10()`    | Calcula o logaritmo na base 10                 |
| 13 | `valorAbsoluto()`      | Retorna o valor absoluto de um número          |
| 14 | `porcentagem()`        | Calcula uma porcentagem                        |
| 15 | `mediaAritmetica()`    | Calcula a média aritmética de dois valores     |
| 16 | `grausParaRadianos()`  | Converte graus para radianos                   |
| 17 | `radianosParaGraus()`  | Converte radianos para graus                   |
| 18 | `areaCirculo()`        | Calcula a área de um círculo                   |
| 19 | `areaRetangulo()`      | Calcula a área de um retângulo                 |
| 20 | `calcularHipotenusa()` | Calcula a hipotenusa de um triângulo retângulo |

---

# 📚 Bibliotecas Utilizadas

O projeto utiliza duas bibliotecas principais:

### `stdio.h`

A biblioteca `stdio.h` é responsável pelas operações básicas de **entrada e saída de dados**.

Neste projeto, são utilizadas principalmente:

```c
#include <stdio.h>
```

A função `printf()` é utilizada para apresentar informações e resultados ao usuário.

Exemplo:

```c
printf("Resultado: %.2lf\n", resultado);
```

A função `scanf()` é utilizada para receber dados digitados pelo usuário.

Exemplo:

```c
scanf("%lf", &a);
```

---

### `math.h`

A biblioteca `math.h` fornece diversas funções matemáticas utilizadas no projeto.

```c
#include <math.h>
```

Entre as funções utilizadas estão:

```c
pow()
sqrt()
cbrt()
sin()
cos()
tan()
log()
log10()
fabs()
hypot()
```

A constante `M_PI` também é utilizada nos cálculos envolvendo graus, radianos e área do círculo.

---

# 🧩 Organização do Código

O código foi organizado de forma **modular**, separando cada operação matemática em uma função específica.

Por exemplo:

```c
double somar(double a, double b) {
    return a + b;
}
```

E:

```c
double potencia(double base, double expoente) {
    return pow(base, expoente);
}
```

Essa organização facilita a leitura, manutenção e compreensão do programa.

A estrutura geral do código pode ser representada da seguinte maneira:

```text
Calculadora
│
├── Bibliotecas
│   ├── stdio.h
│   └── math.h
│
├── Funções matemáticas
│   ├── Soma
│   ├── Subtração
│   ├── Multiplicação
│   ├── Divisão
│   ├── Potenciação
│   ├── Raiz quadrada
│   ├── Raiz cúbica
│   ├── Seno
│   ├── Cosseno
│   ├── Tangente
│   ├── Logaritmo natural
│   ├── Logaritmo base 10
│   ├── Valor absoluto
│   ├── Porcentagem
│   ├── Média
│   ├── Graus → Radianos
│   ├── Radianos → Graus
│   ├── Área do círculo
│   ├── Área do retângulo
│   └── Hipotenusa
│
└── main()
    ├── Exibe o menu
    ├── Recebe a opção
    ├── Executa a função escolhida
    ├── Exibe o resultado
    └── Repete até escolher "0"
```

---

# 🧠 Conceitos de Programação Utilizados

## 🔹 1. Variáveis e tipos de dados

O programa utiliza diferentes tipos de dados para armazenar informações.

O tipo `int` é utilizado para armazenar a opção escolhida no menu:

```c
int opcao;
```

O tipo `double` é utilizado para armazenar números que podem possuir casas decimais:

```c
double a, b, resultado;
```

---

## 🔹 2. Funções

Cada operação matemática possui uma função específica.

Por exemplo:

```c
double multiplicar(double a, double b) {
    return a * b;
}
```

As funções recebem valores através de parâmetros e retornam o resultado da operação.

Essa abordagem torna o programa mais organizado e facilita sua manutenção.

---

## 🔹 3. Estruturas condicionais

O programa utiliza estruturas condicionais para verificar situações que podem gerar erros.

Um exemplo é a divisão por zero:

```c
if (b == 0) {
    printf("ERRO: nao e possivel dividir por zero!\n");
} else {
    resultado = dividir(a, b);
}
```

Também são utilizadas condições para impedir operações matemáticas inválidas, como calcular o logaritmo de um número menor ou igual a zero.

---

## 🔹 4. Estrutura `switch...case`

A estrutura `switch...case` é utilizada para identificar qual operação o usuário selecionou.

Exemplo:

```c
switch (opcao) {

    case 1:
        // Soma
        break;

    case 2:
        // Subtração
        break;

    case 3:
        // Multiplicação
        break;

    default:
        printf("Opcao invalida!\n");
}
```

Dessa forma, cada número do menu está associado a uma operação específica.

---

## 🔹 5. Estrutura de repetição

Para permitir que o usuário realize vários cálculos sem precisar reiniciar o programa, foi utilizada a estrutura `do...while`.

```c
do {

    // Menu e operações

} while (opcao != 0);
```

O programa continua executando enquanto a opção escolhida for diferente de `0`.

A opção `0` encerra a calculadora.

---

## 🔹 6. Entrada e saída de dados

A entrada de dados é realizada através da função `scanf()`.

Exemplo:

```c
printf("Digite o primeiro numero: ");
scanf("%lf", &a);
```

A saída de informações é realizada através da função `printf()`.

Exemplo:

```c
printf("Resultado: %.2lf\n", resultado);
```

---

## 🔹 7. Biblioteca `math.h`

A biblioteca `math.h` é fundamental para a realização das operações matemáticas mais avançadas.

Por exemplo, para calcular uma potência:

```c
pow(base, expoente);
```

Para calcular uma raiz quadrada:

```c
sqrt(numero);
```

Para calcular uma hipotenusa:

```c
hypot(catetoA, catetoB);
```

---

# 🛡️ Tratamento de Erros

O programa possui tratamentos básicos para evitar resultados matematicamente inválidos.

### Divisão por zero

```text
ERRO: nao e possivel dividir por zero!
```

### Raiz quadrada de número negativo

```text
ERRO: nao existe raiz quadrada real de numero negativo.
```

### Logaritmo inválido

O programa verifica se o número é maior que zero antes de calcular o logaritmo.

```text
ERRO: o logaritmo exige numero maior que zero.
```

### Área com valores negativos

O programa impede que valores negativos sejam utilizados como raio, base ou altura.

### Tangente indefinida

Antes de calcular a tangente, o programa verifica se o cosseno do ângulo está próximo de zero.

### Opção inválida

Caso o usuário escolha uma opção que não esteja no menu:

```text
ERRO: opcao invalida! Escolha uma opcao de 0 a 20.
```

---

# 💻 Menu da Calculadora

Ao executar o programa, o usuário encontrará o seguinte menu:

```text
============================================
        CALCULADORA COMPLETA EM C
============================================
 1  - Soma
 2  - Subtracao
 3  - Multiplicacao
 4  - Divisao
 5  - Potenciacao
 6  - Raiz quadrada
 7  - Raiz cubica
 8  - Seno
 9  - Cosseno
10  - Tangente
11  - Logaritmo natural
12  - Logaritmo base 10
13  - Valor absoluto
14  - Porcentagem
15  - Media aritmetica
16  - Graus para radianos
17  - Radianos para graus
18  - Area do circulo
19  - Area do retangulo
20  - Hipotenusa
 0  - Encerrar programa
============================================
Escolha uma opcao:
```

---

# ▶️ Compilação e Execução

## Pré-requisitos

Para executar o projeto, é necessário possuir um compilador da linguagem C instalado.

Uma opção é utilizar o **GCC**.

---

## 📥 1. Clonar o repositório

No terminal, utilize:

```bash
git clone URL_DO_SEU_REPOSITORIO
```

Depois entre na pasta:

```bash
cd NOME_DO_REPOSITORIO
```

---

## 🔨 2. Compilar o programa

Utilizando o GCC:

```bash
gcc calculadora.c -o calculadora -lm
```

O parâmetro `-lm` é utilizado para realizar a ligação com a biblioteca matemática.

---

## ▶️ 3. Executar

### Windows

```bash
calculadora.exe
```

### Linux/macOS

```bash
./calculadora
```

---

# 🧪 Exemplos de Uso

## Exemplo 1 — Soma

```text
Escolha uma opcao: 1

Digite o primeiro numero: 10
Digite o segundo numero: 5

Resultado: 15.00
```

---

## Exemplo 2 — Potenciação

```text
Escolha uma opcao: 5

Digite a base: 2
Digite o expoente: 3

Resultado: 8.00
```

---

## Exemplo 3 — Área do círculo

```text
Escolha uma opcao: 18

Digite o raio do circulo: 5

Area do circulo: 78.54
```

---

## Exemplo 4 — Hipotenusa

```text
Escolha uma opcao: 20

Digite o primeiro cateto: 3
Digite o segundo cateto: 4

Hipotenusa: 5.00
```

---

## Exemplo 5 — Tratamento de erro

```text
Escolha uma opcao: 4

Digite o dividendo: 10
Digite o divisor: 0

ERRO: nao e possivel dividir por zero!
```
---

# 📊 Resumo dos Conceitos Aplicados

| Conceito            | Aplicação no projeto                |
| ------------------- | ----------------------------------- |
| Variáveis           | Armazenamento dos valores e opções  |
| `int`               | Opção selecionada no menu           |
| `double`            | Valores matemáticos                 |
| `scanf()`           | Entrada de dados                    |
| `printf()`          | Saída de dados                      |
| Funções             | Implementação das 20 operações      |
| Parâmetros          | Passagem de valores para as funções |
| `return`            | Retorno dos resultados              |
| `if/else`           | Tratamento de condições e erros     |
| `switch/case`       | Seleção das operações               |
| `do/while`          | Repetição do programa               |
| `math.h`            | Operações matemáticas avançadas     |
| Modularização       | Separação das operações em funções  |
| Tratamento de erros | Prevenção de operações inválidas    |

---

# 🎓 Conclusão

O desenvolvimento desta calculadora possibilitou aplicar, de maneira integrada, diversos fundamentos da linguagem C.

A utilização de **funções e modularização** permitiu organizar cada operação matemática individualmente, enquanto as estruturas **condicionais** possibilitaram controlar situações específicas e tratar erros.

A estrutura **`do...while`** permitiu que a calculadora continuasse disponível para novas operações até que o usuário escolhesse encerrar o programa.

Além disso, a utilização das bibliotecas **`stdio.h`** e **`math.h`** possibilitou, respectivamente, realizar a comunicação com o usuário e executar cálculos matemáticos mais avançados.

Dessa forma, o projeto atende à proposta de desenvolver uma calculadora com **20 funções diferentes**, demonstrando a aplicação prática dos principais conceitos estudados em programação em linguagem C.

---

## 👩‍💻 Desenvolvido por

**Anna Julia Santos Soares**

**Curso:** Análise e Desenvolvimento de Sistemas — ADS
**Instituição:** UDF – Centro Universitário do Distrito Federal 


