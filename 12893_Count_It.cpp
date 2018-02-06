#include <cstdio>

int main() {
    int ts;
    long long n;
    int cnt;
    scanf("%d", &ts);
    while(ts--) {
        cnt = 0;
        scanf("%lld", &n);
        while(n > 0) {
            cnt += n & 1;
            n >>= 1;
        }
        printf("%d\n", cnt);
    }
}
