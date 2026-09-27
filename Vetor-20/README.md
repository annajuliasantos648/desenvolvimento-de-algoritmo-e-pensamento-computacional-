# Programa de Análise de Vetor em C

## Identificação

**Estudante:** Anna Julia Santos Soares 

**Professora: Profa. Karla Sartin**

**Linguagem:** C

**Arquivo principal:** `vetor20.c`

## Objetivo

Desenvolver um programa em linguagem C para aplicar os conceitos de arrays (vetores), estruturas de repetição, estruturas condicionais, entrada de dados e operações matemáticas.

O programa recebe 20 números inteiros e realiza diferentes análises sobre os valores armazenados.

## Funcionalidades

O programa realiza as seguintes operações:

* Lê 20 números inteiros;
* Armazena os números em um vetor;
* Calcula a soma dos elementos múltiplos de 3;
* Calcula a média dos elementos pares;
* Informa a quantidade de números positivos;
* Informa a quantidade de números negativos;
* Identifica o maior valor do vetor;
* Identifica o menor valor do vetor;
* Exibe todos os elementos armazenados.

O número zero não é contabilizado como positivo ou negativo.

Além disso, o programa verifica se existem números pares antes de calcular a média, evitando uma divisão por zero.

## Lógica utilizada

Primeiramente, é criado um vetor de inteiros com 20 posições.

Um laço `for` é utilizado para solicitar ao usuário os 20 números e armazená-los no vetor.

Depois, outro laço `for` percorre todos os elementos para realizar as verificações:

* Para verificar múltiplos de 3, é utilizado o operador `%`;
* Para verificar números pares, é utilizado `numero % 2 == 0`;
* Para números positivos, é verificado se o valor é maior que zero;
* Para números negativos, é verificado se o valor é menor que zero;
* O maior e o menor valor são encontrados comparando cada elemento com os valores armazenados anteriormente.

A média dos números pares somente é calculada quando existe pelo menos um número par.

## Como compilar

### Windows

Caso o GCC esteja instalado, abra o terminal na pasta do projeto e execute:

```bash
gcc vetor20.c -o vetor20
```

Depois execute:

```bash
vetor20
```

### Linux

Compile com:

```bash
gcc vetor20.c -o vetor20
```

Execute com:

```bash
./vetor20
```

## Exemplo de entrada

```text
Digite o 1 numero: 1
Digite o 2 numero: 2
Digite o 3 numero: 3
Digite o 4 numero: 4
Digite o 5 numero: 5
Digite o 6 numero: 6
Digite o 7 numero: 7
Digite o 8 numero: 8
Digite o 9 numero: 9
Digite o 10 numero: 10
Digite o 11 numero: 11
Digite o 12 numero: 12
Digite o 13 numero: 13
Digite o 14 numero: 14
Digite o 15 numero: 15
Digite o 16 numero: 16
Digite o 17 numero: 17
Digite o 18 numero: 18
Digite o 19 numero: 19
Digite o 20 numero: 20
```

## Exemplo de saída

```text
========================================
           RESULTADOS
========================================
Soma dos multiplos de 3: 63
Media dos elementos pares: 11.00
Quantidade de positivos: 20
Quantidade de negativos: 0
Maior valor: 20
Menor valor: 1

========================================
       ELEMENTOS DO VETOR
========================================
vetor[0] = 1
vetor[1] = 2
vetor[2] = 3
vetor[3] = 4
vetor[4] = 5
vetor[5] = 6
vetor[6] = 7
vetor[7] = 8
vetor[8] = 9
vetor[9] = 10
vetor[10] = 11
vetor[11] = 12
vetor[12] = 13
vetor[13] = 14
vetor[14] = 15
vetor[15] = 16
vetor[16] = 17
vetor[17] = 18
vetor[18] = 19
vetor[19] = 20

========================================
Programa finalizado!
========================================
