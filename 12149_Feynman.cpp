#include <cstdio>

int sq[110];
void gen_sq() {
    sq[1] = 1;
    for(int i = 2; i <= 100; i++) {
        sq[i] = sq[i-1] + i*i;
    }
}

int main() {
    gen_sq();
    int n;
    while(scanf("%d", &n), n) {
        printf("%d\n", sq[n]);
    }
}
