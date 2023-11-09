#include <stdio.h>

int MDC(int num1, int num2, int i)
{
    if (num1 == 1 || num2 == 1) {
        return 1;
    }

    if (num1 % i == 0 && num2 % i == 0)
    {
        num1 = num1 / i;
        num2 = num2 / i;
        
        return i * MDC(num1, num2, i);
    }
    else if (i <= num1 || i <= num2)
    {
        return MDC(num1, num2, i + 1);
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int numero1;
    int numero2;
    int i = 2;

    int retorno;

    scanf("%d", &numero1);
    scanf("%d", &numero2);

    if (numero1 <= 0 || numero2 <= 0) {
        printf("Os n�meros devem ser positivos e maiores que zero.\n");
        return -1;
    }

    retorno = MDC(numero1, numero2, i);

    printf("%d\n", retorno);

    return 0;
}
