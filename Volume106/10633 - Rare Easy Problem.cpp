#include <cstdio>

int main() {
    long long n;
    while(scanf("%lld", &n), n) {
        if(n % 9 == 0) {
            long long nn = n/9 - 1;
            printf("%lld ", 10*(nn) + (n-9*nn));
        }
        printf("%lld\n", 10*(n/9) + n%9);
    }
}
