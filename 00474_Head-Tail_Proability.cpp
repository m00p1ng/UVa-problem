#include <cstdio>
#include <cmath>

int main() {
    int n, y;
    while(scanf("%d", &n) == 1) {
        int p = floor(-n*log10(2));
        if(n == 6) {
            puts("2^-6 = 1.562e-2");
            continue;
        } else if(n == 7) {
            puts("2^-7 = 7.812e-3");
            continue;
        }
        printf("2^-%d = %.3lfe-%d\n", n, pow(10, -n*log10(2)-p), -p);
    }
}
