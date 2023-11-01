#include <stdio.h>

int main() {
    int portugues, matematica;
    int aprovados = 0;
    float redacao;

    while (1) {
        scanf("%d", &portugues);
        
        if (portugues < 0 || matematica < 0 || redacao < 0) {
            break;
        }
        
        scanf("%d", &matematica);
        
        scanf("%f", &redacao);
        
        if (portugues >= 40 && matematica >= 21 && redacao >= 7.0) {
            aprovados++;
        }
    }
    
    printf("%d\n", aprovados);
    
    return 0;
}
