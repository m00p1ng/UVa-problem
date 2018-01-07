#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        int n;
        scanf("%d", &n);

        long long sum = 0;
        while(n--) {
            long long a, b;
            scanf("%lld %*d %lld", &a, &b);
            sum += a*b;
        }

        printf("%lld\n", sum);
    }
}
