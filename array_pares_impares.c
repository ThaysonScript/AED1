#include <stdio.h>

int main() {
    int entrada[15];
    int impares[5];
    int pares[5];

    for (int i = 0; i < 15; i++) {
        scanf("%d", &entrada[i]);
    }

    int contImpares = 0;
    int contPares = 0;

    for (int i = 0; i < 15; i++) {
        if (entrada[i] % 2 != 0) {
            impares[contImpares] = entrada[i];
            contImpares++;
        } else {
            pares[contPares] = entrada[i];
            contPares++;
        }

        if (contImpares == 5) {
            for (int j = 0; j < 5; j++) {
                printf("impar[%d] = %d\n", j, impares[j]);
            }
            contImpares = 0;
        }

        if (contPares == 5) {
            for (int j = 0; j < 5; j++) {
                printf("par[%d] = %d\n", j, pares[j]);
            }
            contPares = 0;
        }
    }

    for (int j = 0; j < contImpares; j++) {
        printf("impar[%d] = %d\n", j, impares[j]);
    }

    for (int j = 0; j < contPares; j++) {
        printf("par[%d] = %d\n", j, pares[j]);
    }

    return 0;
}
