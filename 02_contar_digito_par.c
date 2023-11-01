#include <stdio.h>

int ContaDigitosPares(int numero) {
    if (numero <= 0) {
        return 0;
    } else {
        int resto_numero = numero % 10;

        if (resto_numero % 2 == 0) {
            return 1 + ContaDigitosPares(numero / 10);
        } else {
            return ContaDigitosPares(numero / 10);
        }
    }
}

int main(void) {
    int num;

    scanf("%d", &num);

    int quantidadeDigitosPares = ContaDigitosPares(num);

    printf("%d\n", quantidadeDigitosPares);

    return 0;
}
