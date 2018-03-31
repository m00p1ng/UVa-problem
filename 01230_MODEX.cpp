#include <cstdio>

int bigmod(int x, int n, int y) {
    if(n == 0) return 1;

    if(n % 2 == 0) {
        int k = bigmod(x, n/2, y) % y;
        return (k*k)%y;
    } else {
        return (x*(bigmod(x, n-1, y) % y)) % y;
    }
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int x, n, y;
        scanf("%d %d %d", &x, &n, &y);

        printf("%d\n", bigmod(x, n, y));
    }
}
