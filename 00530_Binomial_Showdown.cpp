#include <cstdio>

typedef unsigned long long ull;

ull coeff(int n, int k) {
    ull ans = 1;

    if(k > n/2) k = n - k;

    for(int i = 0; i < k; i++) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

int main() {
    int n, k;

    while(scanf("%d %d", &n, &k), n || k) {
        printf("%lld\n", coeff(n, k));
    }
}
