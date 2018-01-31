#include <cstdio>
#include <cmath>

int main() {
    long long n, k;
    while(scanf("%lld %lld", &n, &k) == 2) {
        long double digit = 0;
        for(int i = 0; i < k; i++) {
            digit += log10(n-i) - log10(i+1);
        }
        printf("%d\n", (int)floor(digit)+1);
    }
}
