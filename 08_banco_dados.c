#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idade;
    char nome[50];
    char sexo;
    char estado_civil;
    int amigos;
    int fotos_perfil;
} bd_usuario;

int main()
{
    int numero_cad;
    scanf("%d", &numero_cad);
    getchar();
    bd_usuario *cadastro = malloc(numero_cad * sizeof(bd_usuario));

    for (int i = 0; i < numero_cad; i++)
    {
        scanf("%d", &cadastro[i].idade);
        getchar();
        fgets(cadastro[i].nome, sizeof(cadastro[i].nome), stdin);
        cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = '\0';
        scanf(" %c %c %d %d", &cadastro[i].sexo, &cadastro[i].estado_civil, &cadastro[i].amigos, &cadastro[i].fotos_perfil);
    }

    for (int i = 0; i < numero_cad; i++)
    {
        printf("Idade: %d\nNome: %s\nSexo: %c\nEstado Civil: %c\nNumero de amigos: %d\nNumero de fotos: %d\n\n",
               cadastro[i].idade, cadastro[i].nome, cadastro[i].sexo, cadastro[i].estado_civil, cadastro[i].amigos, cadastro[i].fotos_perfil);
    }

    free(cadastro);

    return 0;
}
