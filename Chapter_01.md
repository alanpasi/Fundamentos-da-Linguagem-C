Aqui está a tradução do documento para o português do Brasil:

---

### CAPÍTULO 1: Uma Introdução Tutorial

Vamos começar com uma rápida introdução à linguagem C. Nosso objetivo é mostrar os elementos essenciais da linguagem em programas reais, mas sem nos perdermos em detalhes, regras e exceções. Neste momento, não estamos tentando ser completos ou mesmo precisos (exceto que os exemplos devem estar corretos). Queremos levá-lo o mais rápido possível ao ponto em que você possa escrever programas úteis, e para isso precisamos nos concentrar nos fundamentos: variáveis e constantes, aritmética, fluxo de controle, funções e os rudimentos de entrada e saída. Estamos intencionalmente deixando de fora deste capítulo recursos do C que são importantes para escrever programas maiores. Isso inclui ponteiros, estruturas, a maior parte do rico conjunto de operadores do C, várias instruções de controle de fluxo e a biblioteca padrão.

Essa abordagem tem suas desvantagens. A mais notável é que a história completa sobre qualquer recurso específico da linguagem não é encontrada aqui, e o tutorial, por ser breve, também pode ser enganoso. E como os exemplos não usam todo o poder do C, eles não são tão concisos e elegantes quanto poderiam ser. Tentamos minimizar esses efeitos, mas fique avisado. Outra desvantagem é que capítulos posteriores necessariamente repetirão parte deste capítulo. Esperamos que a repetição ajude você mais do que o incomode.

De qualquer forma, programadores experientes devem ser capazes de extrapolar o material deste capítulo para suas próprias necessidades de programação. Iniciantes devem complementá-lo escrevendo pequenos programas semelhantes por conta própria. Ambos os grupos podem usá-lo como uma estrutura na qual pendurar as descrições mais detalhadas que começam no Capítulo 2.

#### 1.1 Começando

A única maneira de aprender uma nova linguagem de programação é escrevendo programas nela. O primeiro programa a ser escrito é o mesmo para todas as linguagens:

Imprima as palavras
**hello, world**

Este é o grande obstáculo; para superá-lo, você deve ser capaz de criar o programa...

---

### 6 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

...em algum lugar, compilá-lo com sucesso, carregá-lo, executá-lo e descobrir para onde foi sua saída. Com esses detalhes mecânicos dominados, tudo o mais é relativamente fácil.

Em C, o programa para imprimir “hello, world” é:

```c
#include <stdio.h>
main()
{
    printf("hello, world\n");
}
```

A maneira exata de executar esse programa depende do sistema que você está usando. Como um exemplo específico, no sistema operacional UNIX, você deve criar o programa em um arquivo cujo nome termina em “.c”, como `hello.c`, e então compilá-lo com o comando:

```bash
cc hello.c
```

Se você não cometeu nenhum erro, como omitir um caractere ou escrever algo errado, a compilação prosseguirá silenciosamente e criará um arquivo executável chamado `a.out`. Se você executar `a.out` digitando o comando:

```bash
a.out
```

ele imprimirá:

```
hello, world
```

Em outros sistemas, as regras serão diferentes; consulte um especialista local.

Agora, algumas explicações sobre o programa em si. Um programa em C, independentemente de seu tamanho, consiste em funções e variáveis. Uma função contém instruções que especificam as operações de computação a serem realizadas, e as variáveis armazenam valores usados durante a computação. As funções em C são como as sub-rotinas e funções do Fortran ou os procedimentos e funções do Pascal. Nosso exemplo é uma função chamada `main`. Normalmente, você tem liberdade para dar às funções os nomes que quiser, mas “main” é especial — seu programa começa a execução no início de `main`. Isso significa que todo programa deve ter uma `main` em algum lugar.

`main` geralmente chamará outras funções para ajudar a realizar seu trabalho, algumas que você escreveu e outras de bibliotecas fornecidas para você. A primeira linha do programa,

```c
#include <stdio.h>
```

diz ao compilador para incluir informações sobre a biblioteca padrão de entrada/saída; essa linha aparece no início de muitos arquivos fonte em C. A biblioteca padrão é descrita no Capítulo 7 e no Apêndice B.

Um método de comunicação de dados entre funções é a função chamadora fornecer uma lista de valores, chamados argumentos, para a função que ela chama. Os parênteses após o nome da função envolvem a lista de argumentos. Neste exemplo, `main` é definida como uma função que não espera argumentos, o que é indicado pela lista vazia `()`.

As instruções de uma função são colocadas entre chaves `{}`. A função `main` contém apenas uma instrução,

```c
printf("hello, world\n");
```

Uma função é chamada nomeando-a, seguida por uma lista de argumentos entre parênteses, então isso chama a função `printf` com o argumento `"hello, world\n"`. `printf` é uma função de biblioteca que imprime a saída, neste caso a sequência de caracteres entre as aspas.

Uma sequência de caracteres entre aspas duplas, como `"hello, world\n"`, é chamada de string de caracteres ou constante de string. Por enquanto, nosso único uso de strings de caracteres será como argumentos para `printf` e outras funções.

A sequência `\n` na string é a notação em C para o caractere de nova linha, que, quando impresso, avança a saída para a margem esquerda na próxima linha. Se você omitir o `\n` (um experimento que vale a pena), descobrirá que não há avanço de linha após a impressão da saída. Você deve usar `\n` para incluir um caractere de nova linha no argumento de `printf`; se você tentar algo como:

```c
printf("hello, world ");
```

o compilador C produzirá uma mensagem de erro.

`printf` nunca fornece uma nova linha automaticamente, então várias chamadas podem ser usadas para construir uma linha de saída em etapas. Nosso primeiro programa poderia ter sido escrito assim:

```c
#include <stdio.h>

main()
{
    printf("hello, ");
    printf("world");
    printf("\n");
}
```

para produzir a mesma saída.

Observe que `\n` representa apenas um único caractere. Uma sequência de escape como `\n` fornece um mecanismo geral e extensível para representar caracteres difíceis de digitar ou invisíveis. Entre os outros que o C fornece estão `\t` para tabulação, `\b` para retrocesso, `\"` para aspas duplas e `\\` para a própria barra invertida. Há uma lista completa na Seção 2.3.

**Exercício 1-1.** Execute o programa “hello, world” no seu sistema. Experimente omitir partes do programa para ver quais mensagens de erro você obtém. □

**Exercício 1-2.** Experimente para descobrir o que acontece quando o argumento de `printf` contém `\c`, onde `c` é algum caractere não listado acima. □

#### 1.2 Variáveis e Expressões Aritméticas

O próximo programa usa a fórmula `C = (5/9)(F−32)` para imprimir a seguinte tabela de temperaturas Fahrenheit e seus equivalentes em centígrados ou Celsius:

```
0   -17
20   -6
40    4
60   15
80   26
100   37
120   48
140   60
160   71
180   82
200   93
220  104
240  115
260  126
280  137
300  148
```

O programa em si ainda consiste na definição de uma única função chamada `main`. É mais longo do que aquele que imprimiu “hello, world”, mas não é complicado. Ele introduz várias novas ideias, incluindo comentários, declarações, variáveis, expressões aritméticas, loops e saída formatada.

---

### 9 SEÇÃO 1.2    VARIÁVEIS E EXPRESSÕES ARITMÉTICAS

```c
#include <stdio.h>

/* imprime a tabela Fahrenheit-Celsius para fahr = 0, 20, ..., 300 */
main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* limite inferior da tabela de temperatura */
    upper = 300;    /* limite superior */
    step = 20;    /* tamanho do passo */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

As duas linhas

```c
/* imprime a tabela Fahrenheit-Celsius para fahr = 0, 20, ..., 300 */
```

são um comentário, que neste caso explica brevemente o que o programa faz. Quaisquer caracteres entre `/*` e `*/` são ignorados pelo compilador; eles podem ser usados livremente para tornar um programa mais fácil de entender. Comentários podem aparecer em qualquer lugar onde um espaço em branco, tabulação ou nova linha possa.

Em C, todas as variáveis devem ser declaradas antes de serem usadas, geralmente no início da função antes de qualquer instrução executável. Uma declaração anuncia as propriedades das variáveis; consiste em um nome de tipo e uma lista de variáveis, como:

```c
int fahr, celsius;
int lower, upper, step;
```

O tipo `int` significa que as variáveis listadas são inteiros, em contraste com `float`, que significa ponto flutuante, ou seja, números que podem ter uma parte fracionária. A faixa de ambos `int` e `float` depende da máquina que você está usando; inteiros de 16 bits, que variam entre -32768 e +32767, são comuns, assim como inteiros de 32 bits. Um número `float` é tipicamente uma quantidade de 32 bits, com pelo menos seis dígitos significativos e magnitude geralmente entre cerca de \(10^{-38}\) e \(10^{+38}\).

O C fornece vários outros tipos de dados básicos além de `int` e `float`, incluindo:

- `char`    caractere — um único byte
- `short`    inteiro curto
- `long`    inteiro longo
- `double`    ponto flutuante de dupla precisão

---

### 10 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

Os tamanhos desses objetos também dependem da máquina. Há também arrays, estruturas e uniões desses tipos básicos, ponteiros para eles e funções que os retornam, todos os quais encontraremos no devido tempo.

A computação no programa de conversão de temperatura começa com as instruções de atribuição:

```c
lower = 0;
upper = 300;
step = 20;
fahr = lower;
```

que definem as variáveis para seus valores iniciais. Instruções individuais são terminadas por ponto e vírgula.

Cada linha da tabela é calculada da mesma maneira, então usamos um loop que se repete uma vez por linha de saída; esse é o propósito do loop `while`:

```c
while (fahr <= upper) {
    ...
}
```

O loop `while` opera da seguinte forma: a condição entre parênteses é testada. Se for verdadeira (`fahr` é menor ou igual a `upper`), o corpo do loop (as três instruções entre chaves) é executado. Então a condição é testada novamente, e se for verdadeira, o corpo é executado novamente. Quando o teste se torna falso (`fahr` excede `upper`), o loop termina e a execução continua na instrução que segue o loop. Não há mais instruções neste programa, então ele termina.

O corpo de um `while` pode ser uma ou mais instruções entre chaves, como no conversor de temperatura, ou uma única instrução sem chaves, como em:

```c
while (i < j)
    i = 2 * i;
```

Em ambos os casos, sempre indentaremos as instruções controladas pelo `while` por uma parada de tabulação (que mostramos como quatro espaços) para que você possa ver de relance quais instruções estão dentro do loop. A indentação enfatiza a estrutura lógica do programa. Embora os compiladores C não se importem com a aparência de um programa, a indentação e o espaçamento adequados são críticos para tornar os programas fáceis de ler para as pessoas. Recomendamos escrever apenas uma instrução por linha e usar espaços em branco ao redor dos operadores para esclarecer o agrupamento. A posição das chaves é menos importante, embora as pessoas tenham crenças apaixonadas. Escolhemos um dos vários estilos populares. Escolha um estilo que lhe agrade e use-o consistentemente.

A maior parte do trabalho é feita no corpo do loop. A temperatura Celsius é calculada e atribuída à variável `celsius` pela instrução:

```c
celsius = 5 * (fahr-32) / 9;
```

A razão para multiplicar por 5 e depois dividir por 9, em vez de apenas multiplicar por 5/9, é que em C, como em muitas outras linguagens, a divisão de inteiros trunca: qualquer parte fracionária é descartada. Como 5 e 9 são inteiros, 5/9 seria truncado para zero e, portanto, todas as temperaturas Celsius seriam relatadas como zero.

---

### 11 SEÇÃO 1.2    VARIÁVEIS E EXPRESSÕES ARITMÉTICAS

Este exemplo também mostra um pouco mais de como `printf` funciona. `printf` é uma função de formatação de saída de propósito geral, que descreveremos em detalhes no Capítulo 7. Seu primeiro argumento é uma string de caracteres a ser impressa, com cada `%` indicando onde um dos outros (segundo, terceiro, ...) argumentos deve ser substituído e em que forma deve ser impresso. Por exemplo, `%d` especifica um argumento inteiro, então a instrução:

```c
printf("%d\t%d\n", fahr, celsius);
```

faz com que os valores dos dois inteiros `fahr` e `celsius` sejam impressos, com uma tabulação (`\t`) entre eles.

Cada construção `%` no primeiro argumento de `printf` é emparelhada com o segundo, terceiro argumento, etc.; eles devem corresponder corretamente em número e tipo, ou você obterá respostas erradas.

A propósito, `printf` não faz parte da linguagem C; não há entrada ou saída definida no próprio C. `printf` é apenas uma função útil da biblioteca padrão de funções que normalmente são acessíveis a programas em C. O comportamento de `printf` é definido no padrão ANSI, no entanto, então suas propriedades devem ser as mesmas com qualquer compilador e biblioteca que esteja em conformidade com o padrão.

Para nos concentrarmos no C em si, não falaremos muito sobre entrada e saída até o Capítulo 7. Em particular, adiaremos a entrada formatada até então. Se você precisar inserir números, leia a discussão sobre a função `scanf` na Seção 7.4. `scanf` é como `printf`, exceto que lê a entrada em vez de escrever a saída.

Há alguns problemas com o programa de conversão de temperatura. O mais simples é que a saída não é muito bonita porque os números não estão justificados à direita. Isso é fácil de corrigir; se aumentarmos cada `%d` na instrução `printf` com uma largura, os números impressos serão justificados à direita em seus campos. Por exemplo, poderíamos dizer:

```c
printf("%3d %6d\n", fahr, celsius);
```

para imprimir o primeiro número de cada linha em um campo de três dígitos de largura e o segundo em um campo de seis dígitos de largura, assim:

```
  0    -17
 20     -6
 40      4
 60     15
 80     26
100     37
...
```

O problema mais sério é que, como usamos aritmética de inteiros, as temperaturas Celsius não são muito precisas; por exemplo, 0°F é na verdade cerca de \(-17.8°C\), não \(-17\). Para obter respostas mais precisas, devemos usar aritmética de ponto flutuante em vez de inteiros. Isso requer algumas mudanças no programa. Aqui está uma segunda versão:

---

### 12 SEÇÃO 1.2    VARIÁVEIS E EXPRESSÕES ARITMÉTICAS

```c
#include <stdio.h>

/* imprime a tabela Fahrenheit-Celsius
    para fahr = 0, 20, ..., 300; versão de ponto flutuante */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* limite inferior da tabela de temperatura */
    upper = 300;    /* limite superior */
    step = 20;    /* tamanho do passo */

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

Isso é muito semelhante ao anterior, exceto que `fahr` e `celsius` são declarados como `float`, e a fórmula de conversão é escrita de uma maneira mais natural. Não pudemos usar 5/9 na versão anterior porque a divisão de inteiros a truncaria para zero. Um ponto decimal em uma constante indica que ela é de ponto flutuante, no entanto, então 5.0/9.0 não é truncado porque é a razão de dois valores de ponto flutuante.

Se um operador aritmético tiver operandos inteiros, uma operação inteira é realizada. Se um operador aritmético tiver um operando de ponto flutuante e um operando inteiro, no entanto, o inteiro será convertido para ponto flutuante antes que a operação seja feita. Se tivéssemos escrito `fahr-32`, o 32 seria automaticamente convertido para ponto flutuante. No entanto, escrever constantes de ponto flutuante com pontos decimais explícitos, mesmo quando têm valores integrais, enfatiza sua natureza de ponto flutuante para leitores humanos.

As regras detalhadas para quando inteiros são convertidos para ponto flutuante estão no Capítulo 2. Por enquanto, observe que a atribuição:

```c
fahr = lower;
```

e o teste:

```c
while (fahr <= upper)
```

também funcionam da maneira natural — o `int` é convertido para `float` antes que a operação seja feita.

A especificação de conversão `%3.0f` em `printf` diz que um número de ponto flutuante (aqui `fahr`) deve ser impresso com pelo menos três caracteres de largura, sem ponto decimal e sem dígitos fracionários. `%6.1f` descreve outro número (`celsius`) que deve ser impresso com pelo menos seis caracteres de largura, com 1 dígito após o ponto decimal. A saída se parece com isso:

```
  0   -17.8
 20    -6.7
 40     4.4
...
```

---

### 13 SEÇÃO 1.3    A INSTRUÇÃO FOR

Largura e precisão podem ser omitidas de uma especificação: `%6f` diz que o número deve ter pelo menos seis caracteres de largura; `%.2f` especifica dois caracteres após o ponto decimal, mas a largura não é restrita; e `%f` apenas diz para imprimir o número como ponto flutuante.

- `%d`    imprime como inteiro decimal
- `%6d`    imprime como inteiro decimal, com pelo menos 6 caracteres de largura
- `%f`    imprime como ponto flutuante
- `%6f`    imprime como ponto flutuante, com pelo menos 6 caracteres de largura
- `%.2f`    imprime como ponto flutuante, com 2 caracteres após o ponto decimal
- `%6.2f`    imprime como ponto flutuante, com pelo menos 6 de largura e 2 após o ponto decimal

Entre outros, `printf` também reconhece `%o` para octal, `%x` para hexadecimal, `%c` para caractere, `%s` para string de caracteres e `%%` para o próprio `%`.

**Exercício 1-3.** Modifique o programa de conversão de temperatura para imprimir um cabeçalho acima da tabela. □

**Exercício 1-4.** Escreva um programa para imprimir a tabela correspondente de Celsius para Fahrenheit. □

#### 1.3 A Instrução For

Há muitas maneiras diferentes de escrever um programa para uma tarefa específica. Vamos tentar uma variação no conversor de temperatura.

```c
#include <stdio.h>

/* imprime a tabela Fahrenheit-Celsius */
main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

Isso produz as mesmas respostas, mas certamente parece diferente. Uma grande mudança é a eliminação da maioria das variáveis; apenas `fahr` permanece, e a tornamos um `int`. Os limites inferior e superior e o tamanho do passo aparecem apenas como constantes na instrução `for`, que é uma nova construção, e a expressão que calcula a temperatura Celsius agora aparece como o terceiro argumento de `printf` em vez de como uma instrução de atribuição separada.

Essa última mudança é um exemplo de uma regra geral — em qualquer contexto onde é permitido usar o valor de uma variável de algum tipo, você pode usar uma expressão mais complicada desse tipo. Como o terceiro argumento de `printf` deve ser um valor de ponto flutuante para corresponder a `%6.1f`, qualquer expressão de ponto flutuante pode ocorrer lá.

A instrução `for` é um loop, uma generalização do `while`. Se você compará-la ao `while` anterior, sua operação deve ficar clara. Dentro dos parênteses, há três partes, separadas por ponto e vírgula. A primeira parte, a inicialização:

```c
fahr = 0
```

é feita uma vez, antes que o loop propriamente dito seja iniciado. A segunda parte é o teste ou condição que controla o loop:

```c
fahr <= 300
```

Essa condição é avaliada; se for verdadeira, o corpo do loop (aqui uma única instrução `printf`) é executado. Então o passo de incremento:

```c
fahr = fahr + 20
```

é executado, e a condição é reavaliada. O loop termina se a condição se tornar falsa. Como no `while`, o corpo do loop pode ser uma única instrução ou um grupo de instruções entre chaves. A inicialização, condição e incremento podem ser quaisquer expressões.

A escolha entre `while` e `for` é arbitrária, baseada em qual parece mais clara. O `for` geralmente é apropriado para loops em que a inicialização e o incremento são instruções únicas e logicamente relacionadas, pois é mais compacto que o `while` e mantém as instruções de controle do loop juntas em um só lugar.

**Exercício 1-5.** Modifique o programa de conversão de temperatura para imprimir a tabela em ordem inversa, ou seja, de 300 graus a 0. □

#### 1.4 Constantes Simbólicas

Uma observação final antes de deixarmos a conversão de temperatura para sempre. É uma má prática enterrar “números mágicos” como 300 e 20 em um programa; eles transmitem pouca informação para alguém que possa ter que ler o programa mais tarde, e são difíceis de mudar de forma sistemática. Uma maneira de lidar com números mágicos é dar-lhes nomes significativos. Uma linha `#define` define um nome simbólico ou constante simbólica para ser uma determinada sequência de caracteres:

```c
#define nome texto_de_substituição
```

A partir de então, qualquer ocorrência de `nome` (não entre aspas e não parte de outro nome) será substituída pelo texto de substituição correspondente. O nome tem a mesma forma de um nome de variável: uma sequência de letras e dígitos que começa com uma letra. O texto de substituição pode ser qualquer sequência de caracteres; não se limita a números.

---

### 14 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

```c
#include <stdio.h>
#define LOWER 0    /* limite inferior da tabela */
#define UPPER 300    /* limite superior */
#define STEP 20    /* tamanho do passo */

/* imprime a tabela Fahrenheit-Celsius */
main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

As quantidades `LOWER`, `UPPER` e `STEP` são constantes simbólicas, não variáveis, então elas não aparecem em declarações. Os nomes de constantes simbólicas são convencionalmente escritos em maiúsculas para que possam ser facilmente distinguidos dos nomes de variáveis em minúsculas. Observe que não há ponto e vírgula no final de uma linha `#define`.

#### 1.5 Entrada e Saída de Caracteres

Agora vamos considerar uma família de programas relacionados para processar dados de caracteres. Você descobrirá que muitos programas são apenas versões expandidas dos protótipos que discutiremos aqui.

O modelo de entrada e saída suportado pela biblioteca padrão é muito simples. A entrada ou saída de texto, independentemente de onde se origina ou para onde vai, é tratada como fluxos de caracteres. Um fluxo de texto é uma sequência de caracteres dividida em linhas; cada linha consiste em zero ou mais caracteres seguidos por um caractere de nova linha. É responsabilidade da biblioteca fazer com que cada fluxo de entrada ou saída se conforme a esse modelo; o programador C que usa a biblioteca não precisa se preocupar com como as linhas são representadas fora do programa.

A biblioteca padrão fornece várias funções para ler ou escrever um caractere por vez, das quais `getchar` e `putchar` são as mais simples. Cada vez que é chamada, `getchar` lê o próximo caractere de entrada de um fluxo de texto e retorna esse valor. Ou seja, após:

```c
c = getchar();
```

a variável `c` contém o próximo caractere de entrada. Os caracteres normalmente vêm do teclado; a entrada de arquivos é discutida no Capítulo 7.

A função `putchar` imprime um caractere cada vez que é chamada:

```c
putchar(c);
```

imprime o conteúdo da variável inteira `c` como um caractere, geralmente na tela. Chamadas para `putchar` e `printf` podem ser intercaladas; a saída aparecerá na ordem em que as chamadas são feitas.

---

### 16 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

#### 1.5.1 Cópia de Arquivo

Dadas `getchar` e `putchar`, você pode escrever uma quantidade surpreendente de código útil sem saber mais nada sobre entrada e saída. O exemplo mais simples é um programa que copia sua entrada para sua saída, um caractere por vez:

```
leia um caractere
enquanto (o caractere não for o indicador de fim de arquivo)
    imprima o caractere lido
    leia um caractere
```

Convertendo isso para C, temos:

```c
#include <stdio.h>

/* copia a entrada para a saída; 1ª versão */
main()
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```

O operador relacional `!=` significa "não igual a".

O que parece ser um caractere no teclado ou na tela é, é claro, como tudo o mais, armazenado internamente apenas como um padrão de bits. O tipo `char` é especificamente destinado a armazenar dados de caracteres, mas qualquer tipo inteiro pode ser usado. Usamos `int` por uma razão sutil, mas importante.

O problema é distinguir o fim da entrada dos dados válidos. A solução é que `getchar` retorna um valor distinto quando não há mais entrada, um valor que não pode ser confundido com nenhum caractere real. Esse valor é chamado `EOF`, para "fim de arquivo". Devemos declarar `c` como um tipo grande o suficiente para conter qualquer valor que `getchar` retorne. Não podemos usar `char` porque `c` deve ser grande o suficiente para conter `EOF` além de qualquer possível `char`. Portanto, usamos `int`.

`EOF` é um inteiro definido em `<stdio.h>`, mas o valor numérico específico não importa, desde que não seja o mesmo que qualquer valor `char`. Ao usar a constante simbólica, temos a garantia de que nada no programa depende do valor numérico específico.

O programa de cópia seria escrito de forma mais concisa por programadores C experientes. Em C, qualquer atribuição, como:

```c
c = getchar();
```

---

### 17 SEÇÃO 1.5    ENTRADA E SAÍDA DE CARACTERES

é uma expressão e tem um valor, que é o valor do lado esquerdo após a atribuição. Isso significa que uma atribuição pode aparecer como parte de uma expressão maior. Se a atribuição de um caractere a `c` for colocada dentro da parte de teste de um loop `while`, o programa de cópia pode ser escrito assim:

```c
#include <stdio.h>

/* copia a entrada para a saída; 2ª versão */
main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}
```

O `while` obtém um caractere, atribui-o a `c` e então testa se o caractere era o sinal de fim de arquivo. Se não fosse, o corpo do `while` é executado, imprimindo o caractere. O `while` então se repete. Quando o fim da entrada é finalmente alcançado, o `while` termina e `main` também.

Esta versão centraliza a entrada — agora há apenas uma referência a `getchar` — e reduz o programa. O programa resultante é mais compacto e, uma vez que o idioma é dominado, mais fácil de ler. Você verá esse estilo com frequência. (É possível exagerar e criar código impenetrável, no entanto, uma tendência que tentaremos conter.)

Os parênteses em torno da atribuição dentro da condição são necessários. A precedência de `!=` é maior que a de `=`, o que significa que na ausência de parênteses o teste relacional `!=` seria feito antes da atribuição `=`. Portanto, a instrução:

```c
c = getchar() != EOF
```

é equivalente a:

```c
c = (getchar() != EOF)
```

Isso tem o efeito indesejado de definir `c` como 0 ou 1, dependendo se a chamada de `getchar` encontrou o fim do arquivo ou não. (Mais sobre isso no Capítulo 2.)

**Exercício 1-6.** Verifique que a expressão `getchar() != EOF` é 0 ou 1. □

**Exercício 1-7.** Escreva um programa para imprimir o valor de `EOF`. □

#### 1.5.2 Contagem de Caracteres

O próximo programa conta caracteres; é semelhante ao programa de cópia.

---

### 18 SEÇÃO 1.5    ENTRADA E SAÍDA DE CARACTERES

```c
#include <stdio.h>

/* conta caracteres na entrada; 1ª versão */
main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
```

A instrução:

```c
++nc;
```

apresenta um novo operador, `++`, que significa incrementar em um. Você poderia escrever `nc = nc + 1`, mas `++nc` é mais conciso e frequentemente mais eficiente. Há um operador correspondente `--` para decrementar em 1. Os operadores `++` e `--` podem ser prefixados (`++nc`) ou pós-fixados (`nc++`); essas duas formas têm valores diferentes em expressões, como será mostrado no Capítulo 2, mas `++nc` e `nc++` ambos incrementam `nc`. Por enquanto, vamos nos ater à forma prefixada.

O programa de contagem de caracteres acumula sua contagem em uma variável `long` em vez de um `int`. Inteiros `long` têm pelo menos 32 bits. Embora em algumas máquinas, `int` e `long` tenham o mesmo tamanho, em outras um `int` tem 16 bits, com um valor máximo de 32767, e levaria relativamente pouca entrada para estourar um contador `int`. A especificação de conversão `%ld` diz a `printf` que o argumento correspondente é um inteiro longo.

Pode ser possível lidar com números ainda maiores usando um `double` (ponto flutuante de dupla precisão). Também usaremos uma instrução `for` em vez de um `while`, para ilustrar outra maneira de escrever o loop.

```c
#include <stdio.h>

/* conta caracteres na entrada; 2ª versão */
main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
```

`printf` usa `%f` para ambos `float` e `double`; `%.0f` suprime a impressão do ponto decimal e da parte fracionária, que é zero.

O corpo deste loop `for` está vazio, porque todo o trabalho é feito nas partes de teste e incremento. Mas as regras gramaticais do C exigem que uma instrução `for` tenha um corpo. O ponto e vírgula isolado, chamado de instrução nula, está lá para satisfazer essa exigência. Colocamos em uma linha separada para torná-lo visível.

Antes de deixarmos o programa de contagem de caracteres, observe que se a entrada não contiver caracteres, o teste `while` ou `for` falha na primeira chamada para `getchar`, e o programa produz zero, a resposta correta. Isso é importante. Uma das coisas boas sobre `while` e `for` é que eles testam no topo do loop, antes de prosseguir com o corpo. Se não houver nada a fazer, nada é feito, mesmo que isso signifique nunca passar pelo corpo do loop. Os programas devem agir de forma inteligente quando recebem entrada de comprimento zero. As instruções `while` e `for` ajudam a garantir que os programas façam coisas razoáveis com condições de limite.

---

### 19 SEÇÃO 1.5    ENTRADA E SAÍDA DE CARACTERES

#### 1.5.3 Contagem de Linhas

O próximo programa conta linhas de entrada. Como mencionamos acima, a biblioteca padrão garante que um fluxo de texto de entrada apareça como uma sequência de linhas, cada uma terminada por uma nova linha. Portanto, contar linhas é apenas contar novas linhas:

```c
#include <stdio.h>

/* conta linhas na entrada */
main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```

O corpo do `while` agora consiste em um `if`, que por sua vez controla o incremento `++nl`. A instrução `if` testa a condição entre parênteses e, se a condição for verdadeira, executa a instrução (ou grupo de instruções entre chaves) que a segue. Novamente, indentamos para mostrar o que é controlado por quê.

O sinal de igual duplo `==` é a notação em C para "é igual a" (como o único `=` do Pascal ou o `.EQ.` do Fortran). Esse símbolo é usado para distinguir o teste de igualdade do único `=` que o C usa para atribuição. Uma palavra de cautela: recém-chegados ao C ocasionalmente escrevem `=` quando querem dizer `==`. Como veremos no Capítulo 2, o resultado geralmente é uma expressão legal, então você não receberá nenhum aviso.

Um caractere escrito entre aspas simples representa um valor inteiro igual ao valor numérico do caractere no conjunto de caracteres da máquina. Isso é chamado de constante de caractere, embora seja apenas outra maneira de escrever um pequeno inteiro. Então, por exemplo, `'A'` é uma constante de caractere; no conjunto de caracteres ASCII, seu valor é 65, a representação interna do caractere A. Claro, `'A'` é preferível a 65: seu significado é óbvio e é independente de um conjunto de caracteres específico.

As sequências de escape usadas em constantes de string também são legais em constantes de caractere, então `'\n'` representa o valor do caractere de nova linha, que é 10 em ASCII. Você deve notar cuidadosamente que `'\n'` é um único caractere e, em expressões, é apenas um inteiro; por outro lado, `"\n"` é uma constante de string que por acaso contém apenas um caractere. O tópico de strings versus caracteres é discutido mais adiante no Capítulo 2.

**Exercício 1-8.** Escreva um programa para contar espaços em branco, tabulações e novas linhas. □

**Exercício 1-9.** Escreva um programa para copiar sua entrada para sua saída, substituindo cada sequência de um ou mais espaços em branco por um único espaço. □

**Exercício 1-10.** Escreva um programa para copiar sua entrada para sua saída, substituindo cada tabulação por `\t`, cada retrocesso por `\b` e cada barra invertida por `\\`. Isso torna as tabulações e retrocessos visíveis de forma inequívoca. □

---

### 20 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

#### 1.5.4 Contagem de Palavras

O quarto em nossa série de programas úteis conta linhas, palavras e caracteres, com a definição solta de que uma palavra é qualquer sequência de caracteres que não contenha um espaço em branco, tabulação ou nova linha. Esta é uma versão básica do programa UNIX `wc`.

```c
#include <stdio.h>

#define IN 1    /* dentro de uma palavra */
#define OUT 0    /* fora de uma palavra */

/* conta linhas, palavras e caracteres na entrada */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```

Toda vez que o programa encontra o primeiro caractere de uma palavra, ele conta mais uma palavra. A variável `state` registra se o programa está atualmente em uma palavra ou não; inicialmente, ele está "fora de uma palavra", o que é atribuído ao valor `OUT`. Preferimos as constantes simbólicas `IN` e `OUT` aos valores literais 1 e 0 porque tornam o programa mais legível. Em um programa tão pequeno quanto este, faz pouca diferença, mas em programas maiores, o aumento na clareza vale bem o esforço extra modesto para escrevê-lo dessa forma desde o início. Você também descobrirá que é mais fácil fazer alterações extensas em programas onde números mágicos aparecem apenas como constantes simbólicas.

A linha:

```c
nl = nw = nc = 0;
```

define todas as três variáveis como zero. Isso não é um caso especial, mas uma consequência do fato de que uma atribuição é uma expressão com um valor e as atribuições associam da direita para a esquerda. É como se tivéssemos escrito:

```c
nl = (nw = (nc = 0));
```

O operador `||` significa OU, então a linha:

```c
if (c == ' ' || c == '\n' || c == '\t')
```

diz "se `c` é um espaço em branco ou `c` é uma nova linha ou `c` é uma tabulação". (Lembre-se de que a sequência de escape `\t` é uma representação visível do caractere de tabulação.) Há um operador correspondente `&&` para E; sua precedência é um pouco maior que `||`. Expressões conectadas por `&&` ou `||` são avaliadas da esquerda para a direita, e é garantido que a avaliação parará assim que a verdade ou falsidade for conhecida. Se `c` for um espaço em branco, não há necessidade de testar se é uma nova linha ou tabulação, então esses testes não são feitos. Isso não é particularmente importante aqui, mas é significativo em situações mais complicadas, como veremos em breve.

O exemplo também mostra um `else`, que especifica uma ação alternativa se a parte da condição de uma instrução `if` for falsa. A forma geral é:

```c
if (expressão)
    instrução_1
else
    instrução_2
```

Uma e apenas uma das duas instruções associadas a um `if-else` é executada. Se a expressão for verdadeira, `instrução_1` é executada; se não, `instrução_2` é executada. Cada instrução pode ser uma única instrução ou várias entre chaves. No programa de contagem de palavras, a instrução após o `else` é um `if` que controla duas instruções entre chaves.

**Exercício 1-11.** Como você testaria o programa de contagem de palavras? Que tipos de entrada são mais propensos a revelar bugs, se houver algum? □

**Exercício 1-12.** Escreva um programa que imprima sua entrada, uma palavra por linha. □

---

### 22 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

#### 1.6 Arrays

Vamos escrever um programa para contar o número de ocorrências de cada dígito, de caracteres de espaço em branco (espaço, tabulação, nova linha) e de todos os outros caracteres. Isso é artificial, mas nos permite ilustrar vários aspectos do C em um único programa.

Há doze categorias de entrada, então é conveniente usar um array para armazenar o número de ocorrências de cada dígito, em vez de dez variáveis individuais. Aqui está uma versão do programa:

```c
#include <stdio.h>

/* conta dígitos, espaços em branco, outros */
main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("dígitos =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", espaços em branco = %d, outros = %d\n",
        nwhite, nother);
}
```

A saída deste programa em si é:

```
dígitos = 9 3 0 0 0 0 0 0 1, espaços em branco = 123, outros = 345
```

A declaração:

```c
int ndigit[10];
```

declara `ndigit` como um array de 10 inteiros. Os índices de array sempre começam em zero em C, então os elementos são `ndigit[0]`, `ndigit[1]`, ..., `ndigit[9]`. Isso é refletido nos loops `for` que inicializam e imprimem o array.

Um índice pode ser qualquer expressão inteira, o que inclui variáveis inteiras como `i` e constantes inteiras.

Este programa em particular depende das propriedades da representação de caracteres dos dígitos. Por exemplo, o teste:

```c
if (c >= '0' && c <= '9') ...
```

determina se o caractere em `c` é um dígito. Se for, o valor numérico desse dígito é:

```c
c - '0'
```

Isso só funciona se `'0'`, `'1'`, ..., `'9'` tiverem valores consecutivos crescentes. Felizmente, isso é verdadeiro para todos os conjuntos de caracteres.

Por definição, `chars` são apenas pequenos inteiros, então variáveis e constantes `char` são idênticas a `ints` em expressões aritméticas. Isso é natural e conveniente; por exemplo, `c - '0'` é uma expressão inteira com um valor entre 0 e 9 correspondente ao caractere `'0'` a `'9'` armazenado em `c`, e é, portanto, um índice válido para o array `ndigit`.

A decisão sobre se um caractere é um dígito, espaço em branco ou outra coisa é feita com a sequência:

```c
if (c >= '0' && c <= '9')
    ++ndigit[c-'0'];
else if (c == ' ' || c == '\n' || c == '\t')
    ++nwhite;
else
    ++nother;
```

O padrão:

```c
if (condição_1)
    instrução_1
else if (condição_2)
    instrução_2
...
else
    instrução_n
```

ocorre frequentemente em programas como uma maneira de expressar uma decisão de múltiplas vias. As condições são avaliadas em ordem a partir do topo até que alguma condição seja satisfeita; nesse ponto, a parte correspondente da instrução é executada, e toda a construção é finalizada. (Qualquer instrução pode ser várias instruções entre chaves.) Se nenhuma das condições for satisfeita, a instrução após o `else` final é executada, se estiver presente. Se o `else` final e a instrução forem omitidos, como no programa de contagem de palavras, nenhuma ação ocorre. Pode haver qualquer número de grupos:

```c
else if (condição)
    instrução
```

entre o `if` inicial e o `else` final.

Como uma questão de estilo, é aconselhável formatar essa construção como mostramos; se cada `if` fosse indentado além do `else` anterior, uma longa sequência de decisões marcharia para fora do lado direito da página.

---

### 24 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

A instrução `switch`, a ser discutida no Capítulo 3, fornece outra maneira de escrever uma ramificação de múltiplas vias que é particularmente adequada quando a condição é se alguma expressão inteira ou de caractere corresponde a um de um conjunto de constantes. Para contraste, apresentaremos uma versão `switch` deste programa na Seção 3.4.

**Exercício 1-13.** Escreva um programa para imprimir um histograma dos comprimentos das palavras em sua entrada. É fácil desenhar o histograma com as barras horizontais; uma orientação vertical é mais desafiadora. □

**Exercício 1-14.** Escreva um programa para imprimir um histograma das frequências de diferentes caracteres em sua entrada. □

#### 1.7 Funções

Em C, uma função é equivalente a uma sub-rotina ou função em Fortran, ou a um procedimento ou função em Pascal. Uma função fornece uma maneira conveniente de encapsular algum cálculo, que pode então ser usado sem se preocupar com sua implementação. Com funções bem projetadas, é possível ignorar como um trabalho é feito; saber o que é feito é suficiente. O C torna o uso de funções fácil, conveniente e eficiente; você verá frequentemente uma função curta definida e chamada apenas uma vez, apenas porque esclarece alguma parte do código.

Até agora, usamos apenas funções como `printf`, `getchar` e `putchar` que foram fornecidas para nós; agora é hora de escrever algumas das nossas. Como o C não tem um operador de exponenciação como o `**` do Fortran, vamos ilustrar a mecânica da definição de funções escrevendo uma função `power(m,n)` para elevar um inteiro `m` a uma potência inteira positiva `n`. Ou seja, o valor de `power(2,5)` é 32. Esta função não é uma rotina de exponenciação prática, pois lida apenas com potências positivas de inteiros pequenos, mas é boa o suficiente para ilustração. (A biblioteca padrão contém uma função `pow(x,y)` que calcula \(x^y\)).

Aqui está a função `power` e um programa principal para exercitá-la, para que você possa ver toda a estrutura de uma vez.

```c
#include <stdio.h>

int power(int m, int n);

/* testa a função power */
main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    return 0;
}

/* power: eleva base à n-ésima potência; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
```

Uma definição de função tem esta forma:

```c
tipo_de_retorno nome_da_função(declarações_de_parâmetros, se houver)
{
    declarações
    instruções
}
```

As definições de funções podem aparecer em qualquer ordem e em um arquivo fonte ou vários, embora nenhuma função possa ser dividida entre arquivos. Se o programa fonte aparecer em vários arquivos, você pode ter que dizer mais para compilá-lo e carregá-lo do que se tudo aparecer em um, mas isso é uma questão do sistema operacional, não um atributo da linguagem. Por enquanto, vamos assumir que ambas as funções estão no mesmo arquivo, então o que você aprendeu sobre a execução de programas em C ainda funcionará.

A função `power` é chamada duas vezes por `main`, na linha:

```c
printf("%d %d %d\n", i, power(2,i), power(-3,i));
```

Cada chamada passa dois argumentos para `power`, que cada vez retorna um inteiro a ser formatado e impresso. Em uma expressão, `power(2,i)` é um inteiro, assim como 2 e `i` são. (Nem todas as funções produzem um valor inteiro; abordaremos isso no Capítulo 4.)

A primeira linha de `power` em si,

```c
int power(int base, int n)
```

declara os tipos e nomes dos parâmetros e o tipo do resultado que a função retorna. Os nomes usados por `power` para seus parâmetros são locais para `power` e não são visíveis para nenhuma outra função: outras rotinas podem usar os mesmos nomes sem conflito. Isso também é verdadeiro para as variáveis `i` e `p`: o `i` em `power` não está relacionado ao `i` em `main`.

Geralmente usaremos o termo **parâmetro** para uma variável nomeada na lista entre parênteses em uma definição de função, e **argumento** para o valor usado em uma chamada da função. Os termos **argumento formal** e **argumento real** são às vezes usados para a mesma distinção.

O valor que `power` calcula é retornado a `main` pela instrução `return`. Qualquer expressão pode seguir `return`:

```c
return expressão;
```

---

### 26 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

Uma função não precisa retornar um valor; uma instrução `return` sem expressão faz com que o controle, mas nenhum valor útil, seja retornado ao chamador, assim como "cair no final" de uma função ao atingir a chave direita de fechamento. E a função chamadora pode ignorar um valor retornado por uma função.

Você pode ter notado que há uma instrução `return` no final de `main`. Como `main` é uma função como qualquer outra, ela pode retornar um valor ao seu chamador, que é efetivamente o ambiente no qual o programa foi executado. Normalmente, um valor de retorno zero implica terminação normal; valores diferentes de zero sinalizam condições de terminação incomuns ou errôneas. No interesse da simplicidade, omitimos instruções `return` de nossas funções `main` até agora, mas as incluiremos daqui para frente, como um lembrete de que os programas devem retornar status ao seu ambiente.

A declaração:

```c
int power(int m, int n);
```

logo antes de `main` diz que `power` é uma função que espera dois argumentos `int` e retorna um `int`. Esta declaração, chamada de **protótipo de função**, deve concordar com a definição e os usos de `power`. É um erro se a definição de uma função ou qualquer uso dela não concordar com seu protótipo.

Os nomes dos parâmetros não precisam concordar. De fato, os nomes dos parâmetros são opcionais em um protótipo de função, então para o protótipo poderíamos ter escrito:

```c
int power(int, int);
```

Nomes bem escolhidos são uma boa documentação, no entanto, então frequentemente os usaremos.

Uma nota histórica: A maior mudança entre o ANSI C e versões anteriores é como as funções são declaradas e definidas. Na definição original de C, a função `power` teria sido escrita assim:

```c
/* power: eleva base à n-ésima potência; n >= 0 */
/* (versão antiga) */
power(base, n)
int base, n;
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
```

Os parâmetros são nomeados entre os parênteses, e seus tipos são declarados antes da chave esquerda de abertura; parâmetros não declarados são considerados `int`. (O corpo da função é o mesmo de antes.)

A declaração de `power` no início do programa teria sido assim:

```c
int power();
```

Nenhuma lista de parâmetros era permitida, então o compilador não poderia verificar facilmente se `power` estava sendo chamada corretamente. De fato, como por padrão `power` seria assumida como retornando um `int`, toda a declaração poderia muito bem ter sido omitida.

A nova sintaxe de protótipos de função torna muito mais fácil para um compilador detectar erros no número de argumentos ou seus tipos. O estilo antigo de declaração e definição ainda funciona no ANSI C, pelo menos durante um período de transição, mas recomendamos fortemente que você use a nova forma quando tiver um compilador que a suporte.

**Exercício 1-15.** Reescreva o programa de conversão de temperatura da Seção 1.2 para usar uma função para conversão. □

#### 1.8 Argumentos — Chamada por Valor

Um aspecto das funções em C pode ser desconhecido para programadores acostumados com outras linguagens, particularmente Fortran. Em C, todos os argumentos de função são passados "por valor". Isso significa que a função chamada recebe os valores de seus argumentos em variáveis temporárias, em vez dos originais. Isso leva a algumas propriedades diferentes das vistas em linguagens de "chamada por referência" como Fortran ou com parâmetros `var` em Pascal, nas quais a rotina chamada tem acesso ao argumento original, não a uma cópia local.

A principal distinção é que em C a função chamada não pode alterar diretamente uma variável na função chamadora; ela só pode alterar sua cópia privada e temporária. A chamada por valor é um recurso, no entanto, não uma limitação. Geralmente leva a programas mais compactos com menos variáveis extras, porque os parâmetros podem ser tratados como variáveis locais convenientemente inicializadas na rotina chamada. Por exemplo, aqui está uma versão de `power` que faz uso dessa propriedade.

```c
/* power: eleva base à n-ésima potência; n>=0; versão 2 */
int power(int base, int n)
{
    int p;
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```

O parâmetro `n` é usado como uma variável temporária e é decrementado (um loop `for` que funciona para trás) até se tornar zero; não há mais necessidade da variável `i`. O que quer que seja feito com `n` dentro de `power` não tem efeito sobre o argumento com o qual `power` foi originalmente chamada.

Quando necessário, é possível arranjar para que uma função modifique uma variável em uma rotina chamadora. O chamador deve fornecer o endereço da variável a ser definida (tecnicamente um ponteiro para a variável), e a função chamada deve declarar o parâmetro como um ponteiro e acessar a variável indiretamente através dele. Cobriremos ponteiros no Capítulo 5.

A história é diferente para arrays. Quando o nome de um array é usado como argumento, o valor passado para a função é a localização ou endereço do início do array — não há cópia dos elementos do array. Ao indexar esse valor, a função pode acessar e alterar qualquer elemento do array. Este é o tópico da próxima seção.

---

### 28 UMA INTRODUÇÃO TUTORIAL    CAPÍTULO 1

#### 1.9 Arrays de Caracteres

O tipo mais comum de array em C é o array de caracteres. Para ilustrar o uso de arrays de caracteres e funções para manipulá-los, vamos escrever um programa que lê um conjunto de linhas de texto e imprime a mais longa. O esboço é simples o suficiente:

```
enquanto (há outra linha)
    se (ela for mais longa que a mais longa anterior)
        salve-a
        salve seu comprimento
    imprima a linha mais longa
```

Este esboço deixa claro que o programa se divide naturalmente em partes. Uma parte obtém uma nova linha, outra a testa, outra a salva e o restante controla o processo.

Como as coisas se dividem tão bem, seria bom escrevê-las dessa forma também. Assim, vamos primeiro escrever uma função separada `getline` para buscar a próxima linha de entrada. Vamos tentar tornar a função útil em outros contextos. No mínimo, `getline` deve retornar um sinal sobre o possível fim do arquivo; um design mais útil seria retornar o comprimento da linha ou zero se o fim do arquivo for encontrado. Zero é um retorno aceitável para o fim do arquivo porque nunca é um comprimento de linha válido. Toda linha de texto tem pelo menos um caractere; mesmo uma linha contendo apenas uma nova linha tem comprimento 1.

Quando encontramos uma linha que é mais longa que a linha mais longa anterior, ela deve ser salva em algum lugar. Isso sugere uma segunda função, `copy`, para copiar a nova linha para um local seguro.

Finalmente, precisamos de um programa principal para controlar `getline` e `copy`. Aqui está o resultado.

---

### 29 SEÇÃO 1.9    ARRAYS DE CARACTERES

```c
#include <stdio.h>
#define MAXLINE 1000    /* comprimento máximo de uma linha de entrada */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* imprime a linha de entrada mais longa */
main()
{
    int len;    /* comprimento atual da linha */
    int max;    /* comprimento máximo visto até agora */
    char line[MAXLINE];    /* linha de entrada atual */
    char longest[MAXLINE];    /* linha mais longa salva aqui */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* havia uma linha */
        printf("%s", longest);
    return 0;
}

/* getline: lê uma linha em s, retorna o comprimento */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copia 'from' para 'to'; assume que to é grande o suficiente */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
```

As funções `getline` e `copy` são declaradas no início do programa, que assumimos estar contido em um arquivo. `main` e `getline` se comunicam através de um par de argumentos e um valor retornado. Em `getline`, os argumentos são declarados pela linha:

```c
int getline(char s[], int lim)
```

que especifica que o primeiro argumento, `s`, é um array, e o segundo, `lim`, é um inteiro. O propósito de fornecer o tamanho de um array em uma declaração é reservar armazenamento. O comprimento do array `s` não é necessário em `getline`, pois seu tamanho é definido em `main`. `getline` usa `return` para enviar um valor de volta ao chamador, assim como a função `power` fez. Esta linha também declara que `getline` retorna um `int`; como `int` é o tipo de retorno padrão, ele poderia ser omitido. Algumas funções retornam um valor útil; outras, como `copy`, são usadas apenas para seu efeito e não retornam valor. O tipo de retorno de `copy` é `void`, que declara explicitamente que nenhum valor é retornado.

`getline` coloca o caractere `'\0'` (o caractere nulo, cujo valor é zero) no final do array que está criando, para marcar o fim da string de caracteres. Essa convenção também é usada pela linguagem C: quando uma constante de string como `"hello\n"` aparece em um programa C, ela é armazenada como um array de caracteres contendo os caracteres da string e terminada com um `'\0'` para marcar o fim.

```
h   e   l   l   o   \n   \0
```

A especificação de formato `%s` em `printf` espera que o argumento correspondente seja uma string representada dessa forma. `copy` também depende do fato de que seu argumento de entrada é terminado por `'\0'`, e copia esse caractere no argumento de saída. (Tudo isso implica que `'\0'` não faz parte do texto normal.)

Vale a pena mencionar de passagem que mesmo um programa tão pequeno quanto este apresenta alguns problemas de design complicados. Por exemplo, o que `main` deve fazer se encontrar uma linha que seja maior que seu limite? `getline` funciona com segurança, pois para de coletar quando o array está cheio, mesmo que nenhuma nova linha tenha sido vista. Ao testar o comprimento e o último caractere retornado, `main` pode determinar se a linha era muito longa e então lidar com isso como desejar. No interesse da brevidade, ignoramos a questão. Não há como um usuário de `getline` saber de antemão o quão longa uma linha de entrada pode ser, então `getline` verifica o estouro. Por outro lado, o usuário de `copy` já sabe (ou pode descobrir) o quão grandes são as strings, então escolhemos não adicionar verificação de erro a ela.

**Exercício 1-16.** Revise a rotina principal do programa da linha mais longa para que ela imprima corretamente o comprimento de linhas de entrada arbitrariamente longas e o máximo possível do texto. □

**Exercício 1-17.** Escreva um programa para imprimir todas as linhas de entrada que tenham mais de 80 caracteres. □

**Exercício 1-18.** Escreva um programa para remover espaços em branco e tabulações à direita de cada linha de entrada e para excluir linhas inteiramente em branco. □

**Exercício 1-19.** Escreva uma função `reverse(s)` que inverta a string de caracteres `s`. Use-a para escrever um programa que inverta sua entrada uma linha por vez. □

---

### 31 SEÇÃO 1.10    VARIÁVEIS EXTERNAS E ESCOPO

#### 1.10 Variáveis Externas e Escopo

As variáveis em `main`, como `line`, `longest`, etc., são privadas ou locais para `main`. Como elas são declaradas dentro de `main`, nenhuma outra função pode ter acesso direto a elas. O mesmo é verdadeiro para as variáveis em outras funções; por exemplo, a variável `i` em `getline` não está relacionada ao `i` em `copy`. Cada variável local em uma função passa a existir apenas quando a função é chamada e desaparece quando a função é encerrada. É por isso que essas variáveis são geralmente conhecidas como **variáveis automáticas**, seguindo a terminologia de outras linguagens. Usaremos o termo **automático** daqui em diante para nos referirmos a essas variáveis locais. (O Capítulo 4 discute a classe de armazenamento `static`, na qual as variáveis locais retêm seus valores entre chamadas.)

Como as variáveis automáticas vêm e vão com a invocação da função, elas não retêm seus valores de uma chamada para a próxima e devem ser explicitamente definidas a cada entrada. Se não forem definidas, conterão lixo.

Como alternativa às variáveis automáticas, é possível definir variáveis que são externas a todas as funções, ou seja, variáveis que podem ser acessadas por nome por qualquer função. (Esse mecanismo é semelhante ao `COMMON` do Fortran ou às variáveis declaradas no bloco mais externo do Pascal.) Como as variáveis externas são globalmente acessíveis, elas podem ser usadas em vez de listas de argumentos para comunicar dados entre funções. Além disso, como as variáveis externas permanecem em existência permanentemente, em vez de aparecerem e desaparecerem conforme as funções são chamadas e encerradas, elas retêm seus valores mesmo após as funções que as definiram retornarem.

Uma variável externa deve ser definida, exatamente uma vez, fora de qualquer função; isso reserva armazenamento para ela. A variável também deve ser declarada em cada função que deseja acessá-la; isso declara o tipo da variável. A declaração pode ser uma instrução `extern` explícita ou pode ser implícita a partir do contexto. Para tornar a discussão concreta, vamos reescrever o programa da linha mais longa com `line`, `longest` e `max` como variáveis externas. Isso requer mudanças nas chamadas, declarações e corpos de todas as três funções.

---

### 32 SEÇÃO 1.10    VARIÁVEIS EXTERNAS E ESCOPO

```c
#include <stdio.h>

#define MAXLINE 1000    /* comprimento máximo de uma linha de entrada */

int max;    /* comprimento máximo visto até agora */
char line[MAXLINE];    /* linha de entrada atual */
char longest[MAXLINE];    /* linha mais longa salva aqui */

int getline(void);
void copy(void);

/* imprime a linha de entrada mais longa; versão especializada */
main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0) /* havia uma linha */
        printf("%s", longest);
    return 0;
}

/* getline: versão especializada */
int getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1
        && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: versão especializada */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
```

As variáveis externas em `main`, `getline` e `copy` são definidas pelas primeiras linhas do exemplo acima, que declaram seus tipos e fazem com que o armazenamento seja alocado para elas. Sintaticamente, as definições externas são como as definições de variáveis locais, mas como ocorrem fora de funções, as variáveis são externas. Antes que uma função possa usar uma variável externa, o nome da variável deve ser conhecido pela função. Uma maneira de fazer isso é escrever uma declaração `extern` na função; a declaração é a mesma de antes, exceto pela adição da palavra-chave `extern`.

Em certas circunstâncias, a declaração `extern` pode ser omitida. Se a definição de uma variável externa ocorrer no arquivo fonte antes de seu uso em uma função específica, então não há necessidade de uma declaração `extern` na função. As declarações `extern` em `main`, `getline` e `copy` são, portanto, redundantes. Na verdade, a prática comum é colocar as definições de todas as variáveis externas no início do arquivo fonte e, em seguida, omitir todas as declarações `extern`.

Se o programa estiver em vários arquivos fonte e uma variável for definida em `file1` e usada em `file2` e `file3`, então declarações `extern` serão necessárias em `file2` e `file3` para conectar as ocorrências da variável. A prática usual é coletar declarações `extern` de variáveis e funções em um arquivo separado, historicamente chamado de **cabeçalho**, que é incluído por `#include` no início de cada arquivo fonte. O sufixo `.h` é convencional para nomes de cabeçalhos. As funções da biblioteca padrão, por exemplo, são declaradas em cabeçalhos como `<stdio.h>`. Esse tópico é discutido em detalhes no Capítulo 4, e a própria biblioteca é discutida no Capítulo 7 e no Apêndice B.

Como as versões especializadas de `getline` e `copy` não têm argumentos, a lógica sugere que seus protótipos no início do arquivo deveriam ser `getline()` e `copy()`. Mas, para compatibilidade com programas C mais antigos, o padrão considera uma lista vazia como uma declaração de estilo antigo e desativa toda a verificação de lista de argumentos; a palavra `void` deve ser usada para uma lista explicitamente vazia. Discutiremos isso mais adiante no Capítulo 4.

Você deve notar que estamos usando as palavras **definição** e **declaração** com cuidado ao nos referirmos a variáveis externas nesta seção. "Definição" refere-se ao local onde a variável é criada ou o armazenamento é atribuído; "declaração" refere-se a locais onde a natureza da variável é declarada, mas nenhum armazenamento é alocado.

A propósito, há uma tendência a tornar tudo o que está à vista uma variável `extern` porque parece simplificar as comunicações — as listas de argumentos são curtas e as variáveis estão sempre lá quando você as quer. Mas as variáveis externas estão sempre lá, mesmo quando você não as quer. Confiar demais em variáveis externas é repleto de perigos, pois leva a programas cujas conexões de dados não são nada óbvias — as variáveis podem ser alteradas de maneiras inesperadas e até inadvertidas, e o programa é difícil de modificar. A segunda versão do programa da linha mais longa é inferior à primeira, em parte por essas razões e em parte porque destrói a generalidade de duas funções úteis ao conectar nelas os nomes das variáveis que manipulam.

Neste ponto, cobrimos o que poderia ser chamado de núcleo convencional do C. Com esse punhado de blocos de construção, é possível escrever programas úteis de tamanho considerável, e provavelmente seria uma boa ideia se você pausasse o suficiente para fazê-lo. Esses exercícios sugerem programas de complexidade um pouco maior do que os anteriores neste capítulo.

**Exercício 1-20.** Escreva um programa `detab` que substitua tabulações na entrada pelo número apropriado de espaços em branco para avançar até a próxima parada de tabulação. Suponha um conjunto fixo de paradas de tabulação, digamos a cada \( n \) colunas. \( n \) deve ser uma variável ou um parâmetro simbólico? □

**Exercício 1-21.** Escreva um programa `entab` que substitua sequências de espaços em branco pelo número mínimo de tabulações e espaços para alcançar o mesmo espaçamento. Use as mesmas paradas de tabulação que para `detab`. Quando uma tabulação ou um único espaço em branco seria suficiente para alcançar uma parada de tabulação, qual deve ser preferido? □

**Exercício 1-22.** Escreva um programa para "dobrar" longas linhas de entrada em duas ou mais linhas mais curtas após o último caractere não branco que ocorre antes da \( n \)-ésima coluna de entrada. Certifique-se de que seu programa faça algo inteligente com linhas muito longas e se não houver espaços ou tabulações antes da coluna especificada. □

**Exercício 1-23.** Escreva um programa para remover todos os comentários de um programa C. Não se esqueça de lidar corretamente com strings entre aspas e constantes de caractere. Comentários em C não se aninham. □

**Exercício 1-24.** Escreva um programa para verificar um programa C em busca de erros de sintaxe rudimentares, como parênteses, colchetes e chaves desbalanceados. Não se esqueça de aspas, tanto simples quanto duplas, sequências de escape e comentários. (Este programa é difícil se você fizer isso em geral.) □

---

Espero que esta tradução seja útil! Se precisar de mais alguma coisa, estou à disposição.
