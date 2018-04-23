#include <cstdio>

int main() {
    int ts;
    long long an, n;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%lld", &an);
        n = (an + 1)/2;
        printf("%lld\n", 2*n*n - 2*n + 1);
    }
}
