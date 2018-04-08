#include <cstdio>

long long catalan[30];

void gen_catalan() {
    catalan[0] = 1;
    catalan[1] = 1;
    for(int i = 2; i < 30; i++) {
        catalan[i] = 0;
        for(int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
}

int main() {
    gen_catalan();
    long long n;
    while(scanf("%lld", &n) == 1) {
        int i;
        for(i = 1; i < 30; i++) {
            if(n == catalan[i]) break;
        }
        printf("%d\n", i);
    }
}

