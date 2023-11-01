#include <stdio.h>

int verificaSudoku(int matriz[9][9]) {
    int linha[9], coluna[9], regiao[9];
    int i, j, k;

    for (i = 0; i < 9; i++) {
        for (k = 0; k < 9; k++) {
            linha[k] = 0;
            coluna[k] = 0;
            regiao[k] = 0;
        }
        for (j = 0; j < 9; j++) {
            if (linha[matriz[i][j] - 1] == 1) return 0;
            if (coluna[matriz[j][i] - 1] == 1) return 0;
            linha[matriz[i][j] - 1] = 1;
            coluna[matriz[j][i] - 1] = 1;
        }
    }

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            for (k = 0; k < 9; k++) {
                regiao[k] = 0;
            }
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if (regiao[matriz[x][y] - 1] == 1) return 0;
                    regiao[matriz[x][y] - 1] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int matriz[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int resultado = verificaSudoku(matriz);

        printf("Instancia %d\n", instancia);
        if (resultado) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
