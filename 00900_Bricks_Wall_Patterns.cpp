#include <cstdio>

long long fibo[100];

void gen_fibo() {
    fibo[1] = 1;
    fibo[2] = 2;

    for(int i = 3; i <= 50; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main() {
    int n;
    gen_fibo();
    while(scanf("%d", &n), n) {
        printf("%lld\n", fibo[n]);
    }
}
