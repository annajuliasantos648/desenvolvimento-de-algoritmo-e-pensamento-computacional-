# Projeto de Monitoramento de Temperatura

## 1. Identificação

**Nome do aluno:** Anna Julia Santos Soares
**Disciplina:** Algoritmos e pensamento computacional  
**Professora:** Prof. Karla Sartin
**Título do projeto:** Sistema de Monitoramento de Temperatura

---

## 2. Objetivo

O objetivo deste projeto é desenvolver um programa em linguagem C capaz de realizar o monitoramento de temperaturas informadas pelo usuário.

O sistema permite definir um limite de temperatura, realizar diversas leituras, identificar temperaturas acima desse limite e controlar a quantidade de temperaturas consecutivas que ultrapassam o valor definido.

O monitoramento é encerrado automaticamente quando são registradas três temperaturas consecutivas acima do limite.

---

## 3. Funcionamento do programa

### Definição do limite

Inicialmente, o usuário informa o limite de temperatura que será utilizado durante o monitoramento.

O programa aceita valores entre -50 °C e 100 °C. Caso seja informado um valor fora desse intervalo, o programa apresenta uma mensagem de erro e solicita uma nova entrada.

### Realização das leituras

Após definir o limite, o usuário pode informar as temperaturas que serão monitoradas.

Cada temperatura é validada antes de ser utilizada nos cálculos. Somente valores entre -50 °C e 100 °C são considerados leituras válidas.

### Tratamento de valores inválidos

Quando uma temperatura está fora do intervalo permitido, o programa informa que o valor é inválido e solicita uma nova temperatura.

A leitura inválida não é contabilizada nos cálculos estatísticos.

### Identificação de temperaturas acima do limite

Quando uma temperatura válida é maior que o limite definido, o programa apresenta um alerta informando que a temperatura ultrapassou o limite.

Além disso, essa temperatura é contabilizada na quantidade de temperaturas acima do limite.

### Contagem de temperaturas consecutivas

O programa possui um contador para verificar quantas temperaturas consecutivas estão acima do limite.

Quando uma temperatura ultrapassa o limite, o contador é aumentado em 1.

Quando uma temperatura está dentro do limite, o contador é reiniciado para zero.

Se o contador atingir três temperaturas consecutivas acima do limite, o sistema encerra automaticamente o monitoramento.

### Encerramento do monitoramento

O monitoramento termina automaticamente quando são registradas três temperaturas consecutivas acima do limite.

Ao final, o programa apresenta um relatório contendo:

* Limite definido;
* Quantidade de leituras válidas;
* Maior temperatura;
* Menor temperatura;
* Média das temperaturas;
* Quantidade de temperaturas acima do limite;
* Percentual de temperaturas acima do limite.

---

## 4. Estruturas de repetição utilizadas

### do...while

A estrutura `do...while` foi utilizada na definição do limite de temperatura.

Ela permite que o programa solicite o limite pelo menos uma vez e continue solicitando enquanto o valor informado for inválido.

```c
do {
    printf("Digite o limite de temperatura: ");
    scanf("%f", &limite);
} while (limite < -50 || limite > 100);
```

Essa estrutura foi adequada porque a primeira solicitação de entrada precisa acontecer antes da verificação da condição.

### while

A estrutura `while` foi utilizada para controlar o monitoramento das temperaturas.

```c
while (continuar) {
    // leitura e processamento da temperatura
}
```

O `while` permite que o programa continue realizando leituras enquanto o monitoramento estiver ativo.

Quando três temperaturas consecutivas acima do limite são identificadas, a variável `continuar` recebe o valor `0`, encerrando o laço.

---

## 5. Como executar

Primeiramente, é necessário possuir um compilador C, como o GCC.

Para compilar o programa, utilize:

```bash
gcc monitoramento.c -o monitoramento
```

Depois, execute:

```bash
./monitoramento
```

No Windows, dependendo do ambiente utilizado, pode ser necessário executar:

```bash
monitoramento.exe
```

---

## 6. Testes realizados

### Teste 1 — Validação de entradas inválidas

Foi informado um limite fora do intervalo permitido e, posteriormente, uma temperatura inválida.

**Resultado esperado:** o programa apresenta uma mensagem informando que o valor é inválido e solicita uma nova entrada.

**Resultado obtido:** o programa rejeitou os valores inválidos e permitiu continuar o monitoramento somente após receber valores válidos.

**Evidência:** `evidencias/teste01.png`

---

### Teste 2 — Temperaturas acima do limite, porém não consecutivas

Foi definido um limite e foram inseridas temperaturas acima e dentro do limite de forma alternada.

Exemplo:

```text
Limite: 30 °C

32 °C
28 °C
35 °C
29 °C
```

**Resultado esperado:** as temperaturas acima do limite são contabilizadas, mas a contagem de temperaturas consecutivas é reiniciada sempre que uma temperatura dentro do limite é registrada.

**Resultado obtido:** o programa identificou corretamente as temperaturas acima do limite e reiniciou o contador quando uma temperatura abaixo ou igual ao limite foi informada.

**Evidência:** `evidencias/teste02.png`

---

### Teste 3 — Três temperaturas consecutivas acima do limite

Foi definido um limite e foram informadas três temperaturas consecutivas acima dele.

Exemplo:

```text
Limite: 30 °C

32 °C
35 °C
37 °C
```

**Resultado esperado:** o programa deve identificar três temperaturas consecutivas acima do limite e encerrar automaticamente o monitoramento.

**Resultado obtido:** o programa apresentou o alerta crítico e encerrou o monitoramento automaticamente após a terceira temperatura consecutiva acima do limite.

**Evidência:** `evidencias/teste03.png`

---

## 7. Questão final de reflexão

### Por que você escolheu while, do...while ou uma combinação das duas estruturas?

Foi escolhida uma combinação das estruturas `do...while` e `while` porque cada uma se adapta melhor a uma parte do algoritmo.

O `do...while` foi utilizado para validar o limite de temperatura, pois é necessário solicitar o valor ao usuário pelo menos uma vez e somente depois verificar se ele está dentro do intervalo permitido.

Já o `while` foi utilizado no monitoramento das temperaturas, pois o programa precisa continuar realizando leituras enquanto a condição de monitoramento estiver ativa.

A diferença entre testar a condição antes ou depois da execução foi importante principalmente na definição do limite. Nesse caso, o `do...while` garante que o usuário tenha a oportunidade de informar um valor antes que o programa verifique se ele é válido.

No monitoramento, o `while` permite verificar a condição antes de cada nova leitura e continuar o processo enquanto o sistema estiver ativo. Quando três temperaturas consecutivas acima do limite são identificadas, o programa altera a condição e encerra o laço.

