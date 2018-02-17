#include <cstdio>

long long bee[50];

void gen_bee() {
    bee[0] = 0;
    bee[1] = 1;
    for(int i = 2; i < 50; i++) {
        bee[i] = bee[i-1] + bee[i-2] + 1;
    }
}

int main() {
    int n;
    gen_bee();
    while(scanf("%d", &n), n != -1) {
        printf("%lld %lld\n", bee[n], bee[n+1]);
    }
}
