#include <cstdio>

long long fac[10001];

void gen_fac() {
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 10000; i++) {
        fac[i] = (fac[i-1]*i) % (int)1e7;

        while(fac[i] % 5 == 0) {
            fac[i] /= 10;
        }
    }
}

int main() {
    int n;
    gen_fac();
    while(scanf("%d", &n) == 1) {
        printf("%5d -> %lld\n", n, fac[n] % 10);
    }
}
