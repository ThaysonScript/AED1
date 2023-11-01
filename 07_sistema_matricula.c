#include <stdio.h>
#include <string.h>

#define MAX_ESTUDANTES 100
#define MAX_MATERIAS 100

typedef struct {
    char id[31];
    char nomeCompleto[501];
    int anos;
    int genero;
    float notaEnem;
} Estudante;

typedef struct {
    char id[26];
    char titulo[101];
    int numEstudantes;
    char estudantesMatriculados[MAX_ESTUDANTES][501];
} Materia;

void ordenarMaterias(Materia materias[], int num) {
    int i, j;
    Materia temp;
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (strcmp(materias[j].titulo, materias[j + 1].titulo) > 0) {
                temp = materias[j];
                materias[j] = materias[j + 1];
                materias[j + 1] = temp;
            }
        }
    }
}

void ordenarNomesEstudantes(Materia materias[], int numMaterias) {
    for (int i = 0; i < numMaterias; i++) {
        int num = materias[i].numEstudantes;
        for (int j = 0; j < num - 1; j++) {
            for (int k = 0; k < num - j - 1; k++) {
                if (strcmp(materias[i].estudantesMatriculados[k], materias[i].estudantesMatriculados[k + 1]) > 0) {
                    char temp[501];
                    strcpy(temp, materias[i].estudantesMatriculados[k]);
                    strcpy(materias[i].estudantesMatriculados[k], materias[i].estudantesMatriculados[k + 1]);
                    strcpy(materias[i].estudantesMatriculados[k + 1], temp);
                }
            }
        }
    }
}

void matricularEstudante(Materia materias[], int numMaterias, Estudante estudantes[], int numEstudantes, char idEstudante[], char idMateria[]) {
    for (int i = 0; i < numEstudantes; i++) {
        if (strcmp(estudantes[i].id, idEstudante) == 0) {
            for (int j = 0; j < numMaterias; j++) {
                if (strcmp(materias[j].id, idMateria) == 0) {
                    strcpy(materias[j].estudantesMatriculados[materias[j].numEstudantes], estudantes[i].nomeCompleto);
                    materias[j].numEstudantes++;
                }
            }
        }
    }
}

int main() {
    int numEstudantes, numMaterias, p;
    int qtdMasculino = 0, qtdFeminino = 0;
    float somaIdades = 0, somaIdadesEnem = 0;
    int qtdIdadesEnem = 0;

    scanf("%d", &numEstudantes);
    Estudante estudantes[MAX_ESTUDANTES];
    for (int i = 0; i < numEstudantes; i++) {
        scanf("%s\n%[^\n]\n%d\n%d\n%f", estudantes[i].id, estudantes[i].nomeCompleto, &estudantes[i].anos, &estudantes[i].genero, &estudantes[i].notaEnem);
        if (estudantes[i].genero == 1) {
            qtdMasculino++;
        } else {
            qtdFeminino++;
        }
        somaIdades += estudantes[i].anos;
        if (estudantes[i].notaEnem > 7.5) {
            somaIdadesEnem += estudantes[i].anos;
            qtdIdadesEnem++;
        }
    }

    scanf("%d", &numMaterias);
    Materia materias[MAX_MATERIAS];
    for (int i = 0; i < numMaterias; i++) {
        scanf("%s\n%[^\n]", materias[i].id, materias[i].titulo);
        materias[i].numEstudantes = 0;
    }

    scanf("%d", &p);
    char idEstudante[31], idMateria[26];
    for (int i = 0; i < p; i++) {
        scanf("%s %s", idEstudante, idMateria);
        matricularEstudante(materias, numMaterias, estudantes, numEstudantes, idEstudante, idMateria);
    }

    printf("%d\n", qtdMasculino);
    printf("%d\n", qtdFeminino);
    printf("%.2f\n", somaIdades / numEstudantes);
    if (qtdIdadesEnem == 0) {
        printf("0.00\n");
    } else {
        printf("%.2f\n", somaIdadesEnem / qtdIdadesEnem);
    }

    ordenarMaterias(materias, numMaterias);
    ordenarNomesEstudantes(materias, numMaterias);

    for (int i = 0; i < numMaterias; i++) {
        printf("%s\n", materias[i].titulo);
        printf("%d\n", materias[i].numEstudantes);
        for (int j = 0; j < materias[i].numEstudantes; j++) {
            printf("%s\n", materias[i].estudantesMatriculados[j]);
        }
    }

    return 0;
}
