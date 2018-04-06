#include <cstdio>

long long bin[100][100];

void gen_binomial() {
    for(int i = 0; i <= 50; i++) {
        bin[i][0] = 1;
        bin[i][i] = 1;
    }

    for(int i = 2; i <= 50; i++) {
        for(int j = 1; j < i; j++) {
            bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
        }
    }
}

void print_bin(char* a, char* b, int n) {
    if(n == 1) {
        printf("%s+%s", a, b);
    } else if(n == 2) {
        printf("%s^2+2*%s*%s+%s^2", a, a, b, b);
    } else {
        printf("%s^%d", a, n);
        printf("+%d*%s^%d*%s", n, a, n-1, b);

        for(int i = 2; i < n - 1; i++) {
            printf("+%lld*%s^%d*%s^%d", bin[n][i], a, n-i, b, i);
        }

        printf("+%d*%s*%s^%d", n, a, b, n-1);
        printf("+%s^%d", b, n);
    }
    puts("");
}

int main() {
    gen_binomial();
    int ts;
    scanf("%d\n", &ts);
    char a[110], b[110], c;
    int n, cnt;

    for(int t = 1; t <= ts; t++) {
        scanf("%*c");
        cnt = n = 0;
        while(scanf("%c", &c), c != '+') a[cnt++] = c;
        a[cnt] = '\0';
        cnt = 0;

        while(scanf("%c", &c), c != ')') b[cnt++] = c;
        b[cnt] = '\0';

        scanf("%*c");
        while(scanf("%c", &c) == 1 && c != '\n') n = n*10 + c - '0';

        printf("Case %d: ", t);
        print_bin(a, b, n);
    }
}
