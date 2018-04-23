#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, max_divisor, prev;
    while(scanf("%d", &prev), prev) {
        scanf("%d", &n);
        max_divisor = abs(prev - n);
        prev = n;

        while(scanf("%d", &n), n) {
            max_divisor = gcd(max_divisor, abs(prev - n));
            prev = n;
        }
        printf("%d\n", max_divisor);
    }
}
