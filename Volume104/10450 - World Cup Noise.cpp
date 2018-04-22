#include <cstdio>

long long fibo[100];
void gen_fibo() {
    fibo[1] = 2;
    fibo[2] = 3;
    for(int i = 3; i <= 51; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main() {
    gen_fibo();
    int ts, n;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d", &n);
        printf("Scenario #%d:\n", t);
        printf("%lld\n\n", fibo[n]);
    }
}
