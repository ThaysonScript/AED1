/*

Atenção : Use Recursividade

O algoritmo de euclides é muito antigo, foi criado como meio de calcular o MDC de dois números,esse algoritmo é mais eficiente que fazer o mdc por fatoração,sabemos que a divisão inteira é feita do seguinte modo:

A=D*Q + R

onde:
A é o numero a ser dividido
D é o dividendo
Q é o quociente da divisão inteira de A por D e R é o mod ou resto da divisão inteira.

digamos que queremos calcular o mdc(36,24).

36=24*1+12

perceba que 12 é divisor de 36 e 24

portanto o mdc(36,24)=mdc(24,12)

24=12*2 + 0

como o resto é 0 sabemos que 12 divide 24

mdc(36,24)=mdc(24,12)=12

em geral, o que o algoritmo de euclides faz é: 

    Escolha os dois numeros para tirar mdc(A,D)
    Divida A por D, se o resto não for zero divida D pelo resto até achar o resto 0
    Quando achar uma divisão com resto 0 o "D" dessa divisão será o MDC de A e D originais.

Formato de entrada

Dado o numero de casos N, a cada caso leia 2 numeros e tire o MDC dos dois

N

N1 N1'

N2 N2'...

NN NN'

Todos os números são inteiros.

Formato de saída

para cada caso:

MDC(a,b) = R

onde a e b são os numeros para tirar o mdc na ordem em que foram dados e R o resultado.

não esqueça da quebra de linha  no final da cada caso e fique atento com os espaçamentos.

*/

#include <stdio.h>

int mdc_euclides(int num1, int num2) {
    if (num2 != 0) {
        return mdc_euclides(num2, num1 % num2);
    } else {
        return num1;
    }
}

int main() {
    int casosN;
    int num1, num2;
    int mdc;

    scanf("%d", &casosN);

    for (int i = 0; i < casosN; i++) {
        scanf("%d %d", &num1, &num2);
        mdc = mdc_euclides(num1, num2);

        printf("MDC(%d,%d) = %d\n", num1, num2, mdc);
    }

    return 0;
}