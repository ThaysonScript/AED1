#include <stdio.h>
#include <string.h>

int encontrarMaiorPar(int *lista, int tamanho)
{
    int maiorPar = -1;
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] % 2 == 0 && lista[i] > maiorPar)
        {
            maiorPar = lista[i];
        }
    }

    return maiorPar;
}

int main()
{
    char entrada[100];
    int numeros[100], i = 0, tamanho;
    char *token;
    int menorPar;

    fgets(entrada, sizeof(entrada), stdin);
    entrada[strlen(entrada) - 1] = '\0';

    token = strtok(entrada, ",");
    while (token != NULL)
    {
        numeros[i++] = atoi(token);
        token = strtok(NULL, ",");
    }
    tamanho = i;

    if (tamanho > 0)
    {
        menorPar = encontrarMaiorPar(numeros, tamanho);
        printf("%d\n", menorPar);
    }

    return 0;
}
