#include <cstdio>

unsigned long long coeff[101][101];
void gen_coeff() {
    coeff[0][0] = coeff[1][0] = coeff[1][1] = 1;

    for(int i = 2; i <= 100; i++) {
        coeff[i][0] = coeff[i][i] = 1;
        for(int j = 0; j <= i; j++) {
            coeff[i][j] = coeff[i-1][j-1] + coeff[i-1][j];
        }
    }
}

int main() {
    gen_coeff();
    int n, k;

    while(scanf("%d %d", &n, &k), n || k) {
        printf("%d things taken %d at a time is %lld exactly.\n", n, k, coeff[n][k]);
    }
}
