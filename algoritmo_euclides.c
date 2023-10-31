#include <stdio.h>

int euclidean_gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return euclidean_gcd(b, a % b);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int result = euclidean_gcd(a, b);
        
        printf("MDC(%d,%d) = %d\n", a, b, result);
    }

    return 0;
}
