#include <cstdio>
#include <cmath>

int main() {
    int n;
    while(scanf("%d", &n), n) {
        int sum = 0;
        int cnt = floor(log2(n));

        printf("The parity of ");
        while(cnt >= 0) {
            printf("%d", (n>>cnt)&1);
            sum += (n>>cnt)&1;
            cnt--;
        }
        printf(" is %d (mod 2).\n", sum);
    }
}
