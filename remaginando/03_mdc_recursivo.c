/*

    Dois números naturais sempre têm divisores comuns. Por exemplo: os divisores comuns de 12 e 18 são 1,2,3 e 6. Dentre eles, 6 é o maior. Então chamamos o 6 de máximo divisor comum de 12 e 18 e indicamos m.d.c.(12,18) = 6.

    Desenvolva uma função recursiva para calcular o m.d.c de dois inteiros.

    Formato de entrada

    Dois inteiros positivos.

    Formato de saída

    Um inteiro positivo.

*/

#include <stdio.h>

int MDC(int numero1, int numero2, int divisor_comum) {
    if (numero1 % divisor_comum == 0 && numero2 % divisor_comum == 0) {
        numero1 = numero1 / divisor_comum;
        numero2 = numero2 / divisor_comum;

        return divisor_comum * MDC(numero1, numero2, divisor_comum);

    } else if (divisor_comum <= numero1 || divisor_comum <= numero2) {
        return MDC(numero1, numero2, divisor_comum + 1);
    } else {
        return 1;
    }
}

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    printf("%d\n", MDC(num1, num2, 2));

    return 0;
}