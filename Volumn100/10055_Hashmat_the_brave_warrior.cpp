#include <cstdio>

long long abs(long long n) {
    return n > 0 ? n : -n;
}

int main() {
    long long a, b;
    while(scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", abs(a-b));
    }
}
