#include <stdio.h>

int euclidean_gcd(int a, int d) {
    if (d == 0) {
        return a;
    }
    return euclidean_gcd(d, a % d);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, d;
        scanf("%d %d", &a, &d);
        
        int result = euclidean_gcd(a, d);
        
        printf("MDC(%d,%d) = %d\n", a, d, result);
    }

    return 0;
}
