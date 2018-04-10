#include <cstdio>

int number[20] = {0};

void gen_ans() {
    int fac[20];
    int an[20][20];
    fac[0] = fac[1] = 1;

    for(int i = 2; i <= 11; i++) {
        fac[i] = fac[i-1]*i;
    }
    for(int i = 1; i <= 11; i++) {
        an[i][i] = an[i][1] = 1;
    }

    number[1] = 1;
    for(int i = 2; i <= 11; i++) {
        number[i] = 1 + fac[i];
        for(int j = 2; j < i; j++) {
            an[i][j] = an[i-1][j]*j + an[i-1][j-1];
            number[i] += an[i][j]*fac[j];
        }
    }
}

int main() {
    int ts, n;
    gen_ans();
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        printf("%d\n", number[n]);
    }
}
