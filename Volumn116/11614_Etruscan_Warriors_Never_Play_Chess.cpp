#include <cstdio>
#include <cmath>

int main() {
    int ts;
    long long n;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%lld", &n);
        printf("%lld\n", (long long)floor((-1+sqrt(1+8*n))/2));
    }
}
