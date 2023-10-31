#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int senha;
    char mensalidade;
} Cliente;

int main(void)
{
    Cliente novoCliente[100];
    int senhaAcesso;
    int i;

    for (i = 1; i <= 100; i++)
    {
        fgets(novoCliente[i].nome, 50, stdin);
        novoCliente[i].nome[strcspn(novoCliente[i].nome, "\n")] = 0;

        if (strcmp(novoCliente[i].nome, "SAIR") == 0)
        {
            break;
        }
        scanf("%d", &novoCliente[i].senha);
        getchar();

        scanf("%c", &novoCliente[i].mensalidade);
        getchar();
    }

    while (1)
    {
        scanf("%d", &senhaAcesso);

        if (senhaAcesso == -1)
        {
            break;
        }
        int encontrado = 0;
        for (int j = 0; j < i; j++)
        {
            if (novoCliente[j].senha == senhaAcesso)
            {
                encontrado = 1;
                if (novoCliente[j].mensalidade == 'P')
                {
                    printf("%s, seja bem-vindo(a)!\n", novoCliente[j].nome);
                }
                else
                {
                    printf("N�o est� esquecendo de algo, %s? Procure a recep��o!\n", novoCliente[j].nome);
                }
            }
        }

        if (!encontrado)
        {
            printf("Seja bem-vindo(a)! Procure a recep��o!\n");
        }
    }
    return 0;
}
