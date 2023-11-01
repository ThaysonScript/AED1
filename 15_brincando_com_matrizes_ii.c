#include <stdio.h>

int main() {
    int matriz[3][3];
    int menor_numero;
    int delta;
    int soma_sem_diagonal = 0;
    int contar_posicao = 0;
    float media = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    menor_numero = matriz[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] > 0) {
                media += matriz[i][j];
                contar_posicao++;
            }
            if (matriz[i][j] < menor_numero) {
                menor_numero = matriz[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                soma_sem_diagonal += matriz[i][j];
            }
        }
    }
    
    if (contar_posicao > 0) {
        media = media / contar_posicao;
    } else {
        media = 0;
    }
    
    if (menor_numero % 2 == 0) {
        delta = 1;
    } else {
        delta = 0;
    }

    printf("%.2f %d %d %d", media, menor_numero, delta, soma_sem_diagonal);

    return 0;
}
