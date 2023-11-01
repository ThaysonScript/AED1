#include <stdio.h>
#include <stdlib.h>

float CalculaMedia(int falta, float *nota) {
    float media;

    for(int i = 0; i < 5; i++) {
        media += *(nota + i);
    }

    media = media / 5;

    return media;
}

int main(void) {
    int faltas;
    float *notas;
    float resultado_media;
    int alocar = 5;

    notas = (float *) malloc(alocar * sizeof(float));

    scanf("%d", &faltas);

    for (int i = 0; i < 5; i++) {
        scanf("%f", (notas + i));
    }

    resultado_media = CalculaMedia(faltas, notas);

    if (resultado_media >= 7.0 && faltas <= 5) {
        printf("APROVADO\n");
    } else {
        printf("REPROVADO\n");
    }

    free(notas);

    return 0;
}
