#include <cstdio>

int collatz(long long a, int limit) {
    if(a == 1) return 1;
    if(a > limit) return 0;

    if(a % 2 == 0) return collatz(a/2, limit) + 1;
    return collatz(3*a+1, limit) + 1;
}

int main() {
    long long a;
    int limit;
    int cs = 1;
    while(scanf("%lld %d", &a, &limit), a > 0 || limit > 0) {
        int count = collatz(a, limit);
        printf("Case %d: A = %lld, limit = %d, number of terms = %d\n", cs++, a, limit, count);
    }
}

