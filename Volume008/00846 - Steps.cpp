#include <cstdio>
#include <cmath>

typedef long long ll;

ll step(ll n) {
    if(n <= 3) return n;
    ll a = ceil((-1 + sqrt(1+4*n))/2.0);
    return a + (n-1) / a;
}

int main() {
    int ts;
    ll a, b;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", step(b-a));
    }
}
