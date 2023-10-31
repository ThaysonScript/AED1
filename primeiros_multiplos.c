#include <stdio.h>

int main(void) {
    int valor;

    scanf("%d", &valor);
    
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", valor * i);
    }
    
    return 0;
}
