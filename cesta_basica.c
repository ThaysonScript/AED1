#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    float precos[] = {5.50, 6.0, 7.50, 1.99, 4.00, 6.70, 1.20, 2.80, 5.30, 5.00, 3.00, 2.00, 3.50, 0.80, 1.00, 0.80, 5.40, 1.90, 5.00, 10.00, 0.50, 0.50, 5.00, 4.50, 1.99, 2.90, 0.30};
    int n = sizeof(precos) / sizeof(precos[0]);

    char input[500];
    fgets(input, sizeof(input), stdin);

    float valorDoacao;
    scanf("%f", &valorDoacao);

    int quantidades[n];
    char *token = strtok(input, ",");
    for (int i = 0; i < n; i++) {
        quantidades[i] = atoi(token);
        token = strtok(NULL, ",");
    }

    float valorCesta = 0;
    for (int i = 0; i < n; i++) {
        valorCesta += quantidades[i] * precos[i];
    }

    int quantidadeCestas = valorDoacao / valorCesta;

    printf("O valor da cesta b�sica ficou em: R$%.2f\n", valorCesta);
    printf("Com o valor doado pode ser comprada %d cestas b�sicas\n", quantidadeCestas);

    return 0;
}
