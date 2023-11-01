#include <stdio.h>

int main()
{

    int numero, contagem = 0;
    scanf("%d", &numero);

    if (numero == 0)
    {
        contagem = 1;
        return printf("%d", contagem);
    }
    else if (numero < 0)
    {
        numero = -numero;
    }
    while (numero > 0)
    {
        contagem++;
        numero = numero / 10;
    }

    printf("%d", contagem);

    return 0;
}
