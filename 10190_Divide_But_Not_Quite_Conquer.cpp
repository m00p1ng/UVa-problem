#include <cstdio>

int main() {
    int n, m;
    int out[100];
    int cnt;
    while(scanf("%d %d", &n, &m) == 2) {
        if(n < 2 || m < 2 || m > n) {
            puts("Boring!");
            continue;
        }

        bool is_valid = true;
        out[0] = n;
        cnt = 1;

        while(n > 1) {
            if(n % m != 0) {
                is_valid = false;
                break;
            } else {
                out[cnt++] = n / m;
                n /= m;
            }
        }

        if(!is_valid) {
            puts("Boring!");
            continue;
        }

        printf("%d", out[0]);
        for(int i = 1; i < cnt; i++) {
            printf(" %d", out[i]);
        }
        puts("");
    }
}
