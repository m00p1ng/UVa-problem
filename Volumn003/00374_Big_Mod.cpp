#include <cstdio>

int bigmod(int b, int p, int m) {
    if(p == 0) return 1;

    if(p & 1) {
        return ((b%m)*bigmod(b, p-1, m)) % m; 
    } else {
        int c = bigmod(b, p/2, m);
        return ((c%m)*(c%m)) % m;
    }
}

int main() {
    int b, p, m;

    while(scanf("%d %d %d", &b, &p, &m) == 3) {
        int c = bigmod(b, p, m);
        printf("%d\n", c);
    }
}
