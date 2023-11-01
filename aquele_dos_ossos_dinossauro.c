#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dino {
    char nome[101];
    int tamanho;
    struct Dino* prox;
} Dinossauro;

Dinossauro* criaDinossauro(char* nome, int tamanho) {
    Dinossauro* novo = (Dinossauro*) malloc(sizeof(Dinossauro));
    strcpy(novo->nome, nome);
    novo->tamanho = tamanho;
    novo->prox = NULL;
    return novo;
}

Dinossauro* insere(Dinossauro* lista, char* nome, int tamanho) {
    Dinossauro* novo = criaDinossauro(nome, tamanho);

    if (lista == NULL || strcmp(lista->nome, nome) >= 0) {
        novo->prox = lista;
        return novo;
    }

    Dinossauro* p = lista;
    while (p->prox != NULL && strcmp(p->prox->nome, nome) < 0) {
        p = p->prox;
    }

    novo->prox = p->prox;
    p->prox = novo;

    return lista;
}

void imprime(Dinossauro* lista) {
    printf("[");
    for (Dinossauro* p = lista; p != NULL; p = p->prox) {
        for(int i=0; i<p->tamanho; i++) {
            printf("%s", p->nome);
            if(!(p->prox == NULL && i == p->tamanho - 1)) {
                printf(", ");
            } else if (i != p->tamanho - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

int main() {
    Dinossauro* lista = NULL;
    char nome[101];
    int tamanho;

    while(scanf("%d %s", &tamanho, nome) != EOF) {
        lista = insere(lista, nome, tamanho);
    }

    imprime(lista);

    return 0;
}
