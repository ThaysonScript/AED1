/*
    Escreva uma função recursiva chamada ContaDigitosPares que receba como entrada um número e retorne a quantidade de dígitos pares que o compõem.

    Ex: 234 tem 3 dígitos, mas apenas 2 são pares

    Formato de entrada

    Um número inteiro

    Formato de saída

    Um número inteiro
*/

#include <stdio.h>

int ContaDigitosPares(int numero) {
    int qtd_digitos_pares;
    int pegar_ultimo_numero;
    pegar_ultimo_numero = numero % 10;

    if (numero <= 0) {
        return 0;
    }
    else if (pegar_ultimo_numero % 2 == 0) {
        return 1 + ContaDigitosPares(numero / 10);
    } else {
        return ContaDigitosPares(numero / 10);
    }

    return qtd_digitos_pares;
}

int main(void) {
    int numero;

    scanf("%d", &numero);

    printf("%d\n", ContaDigitosPares(numero));

    return 0;
}