#include <cstdio>

int main() {
    long long n;
    while(scanf("%lld", &n), n >= 0) {
        printf("%lld\n", 1+n*(n+1)/2);
    }
}
