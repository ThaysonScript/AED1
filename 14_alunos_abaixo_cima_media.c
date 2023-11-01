#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    int matricula;
    char nome[50];
    float nota;
};

int compareAluno(const void *a, const void *b) {
    struct Aluno *alunoA = (struct Aluno *)a;
    struct Aluno *alunoB = (struct Aluno *)b;

    if (alunoA->nota != alunoB->nota) {
        return alunoA->nota < alunoB->nota ? -1 : 1;
    } else {
        return alunoA->matricula - alunoB->matricula;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    struct Aluno *alunos = (struct Aluno *)malloc(N * sizeof(struct Aluno));
    if (alunos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    float somaNotas = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d-", &alunos[i].matricula);
        scanf("%[^-]-%f", alunos[i].nome, &alunos[i].nota);
        somaNotas += alunos[i].nota;
    }

    float media = somaNotas / N;

    qsort(alunos, N, sizeof(struct Aluno), compareAluno);

    printf("Alunos abaixo da media:\n");
    for (int i = 0; i < N; i++) {
        if (alunos[i].nota < media) {
            printf("Matricula: %d Nome: %s Nota: %.1f\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota);
        }
    }

    printf("Alunos iguais ou acima da media:\n");
    for (int i = 0; i < N; i++) {
        if (alunos[i].nota >= media) {
            printf("Matricula: %d Nome: %s Nota: %.1f\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota);
        }
    }

    printf("Media = %.2f\n", media);

    free(alunos);

    return 0;
}
