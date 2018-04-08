#include <cstdio>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    while(scanf("%d", &n), n) {
        int g = 0;
        for(int i = 1; i < n; i++) {
            for(int j = i+1; j<= n; j++) {
                g += gcd(i, j);
            }
        }
        printf("%d\n", g);
    }
}
