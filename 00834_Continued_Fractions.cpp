#include <cstdio>

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
        printf("[%d", n/k);
        int temp = k;
        k = n % k;
        n = temp;

        if(k) putchar(';');
        while(k) {
            printf("%d", n/k);
            temp = k;
            k = n % k;
            n = temp;
            if(k) putchar(',');
        }
        puts("]");
    }
}
