#include <stdio.h>

int main() {
    int N;
    double valor_esperado = 0.0;
    
    scanf("%d", &N);

    for (int X = 1; X <= N; X++) {
        double numerador = 0.0;
        double denominador = 0.0;

        for (int i = 1; i <= X; i++) {
            numerador += i;
        }

        for (int i = 1; i <= N; i++) {
            double temp_numerador = 0.0;

            for (int j = 1; j <= i; j++) {
                temp_numerador += j;
            }

            denominador += temp_numerador;
        }

        valor_esperado += (numerador / denominador) * X;
    }

    printf("%.2lf\n", valor_esperado);

    return 0;
}
