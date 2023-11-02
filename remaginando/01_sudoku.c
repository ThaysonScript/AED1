#include <stdio.h>

int verificar_matriz_sudoku(int matriz[9][9]) {
    int linha[9];
    int coluna[9];
    int grade[9];

    for (int col = 0; col < 9; col++) {
        for (int ln = 0; ln < 9; ln++) {
            linha[ln] = 0;
            coluna[ln] = 0;
            grade[ln] = 0;
        }

        for (int ln = 0; ln < 9; ln++) {
            if (linha[matriz[col][ln] - 1] == 1) return 0;

            if (coluna[matriz[ln][col] - 1] == 1) return 0;

            linha[matriz[col][ln] - 1] = 1;

            coluna[matriz[ln][col] - 1] = 1;
        }
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            for (int k = 0; k < 9; k++) {
                grade[k] = 0;
            }
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if (grade[matriz[x][y] - 1] == 1) return 0;
                    grade[matriz[x][y] - 1] = 1;
                }
            }
        }
    }

    return 1;
}

int main(void) {
    int instancias;
    int matriz[9][9];
    int verificacao;

    scanf("%d", &instancias);

    for (int i = 0; i < instancias; i++) {

        for(int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++) {
                scanf("%d", &matriz[j][k]);
            }
        }

        verificacao = verificar_matriz_sudoku(matriz);

        printf("Instancia %d\n", i);
        if (verificacao) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");

    }

    // for (int i = 0; i < 9; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         printf("%d ", matriz[i][j]);
    //         if ((j + 1) % 3 == 0) {
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    //     if ((i + 1) % 3 == 0) {
    //         printf("\n");
    //     }
    // }

    return 0;
}