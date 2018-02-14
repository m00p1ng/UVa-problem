#include <cstdio>

int main() {
    long long n, l;
    while(scanf("%lld", &n) == 1) {
        l = (n+1)/2;
        printf("%lld\n", 6*l*l-9);
    }
}
