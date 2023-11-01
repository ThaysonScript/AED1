#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    char livro_nome[n][100];

    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", livro_nome[i]);
    }

    char livro_citado[100];
    scanf(" %[^\n]", livro_citado);

    int citado = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(livro_nome[i], livro_citado) == 0) {
            citado = 1;
            break;
        }
    }

    if (citado == 1) {
        printf("Sim\n");
    } else {
        printf("N�o\n");
    }

    return 0;
}
