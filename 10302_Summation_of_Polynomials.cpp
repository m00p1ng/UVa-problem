#include <cstdio>

int main() {
    long long n;
    long long sum;
    while(scanf("%lld", &n) == 1) {
        sum = ((n*(n+1))/2)*((n*(n+1))/2);
        printf("%lld\n", sum);
    }
}
