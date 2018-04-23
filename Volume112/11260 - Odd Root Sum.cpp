#include <cstdio>
#define MOD 100000000
#define DEV 300000000

typedef long long ll;

// sn = 4n(n+1)(2n+1)/3 - n^2 + n
ll sn(ll n) {
    return ((4*n*(n+1)%DEV)*(2*n+1)/3) % MOD - (n*n + n) % MOD;
}

ll sum_sn(ll k) {
    ll ans, n;
    n = (k + 1)/2;
    ans = sn(n);
    if(k&1) ans -= (4*n*n) % MOD;

    return (DEV + ans) % MOD;
}

ll sqrt(ll n) {
    ll a = 0, b = 3037000499LL , ans;
    
    while(a <= b) {
        ll mid = (a + b)/2;

        if(mid*mid <= n) {
            a = mid + 1;
            ans = mid;
        } else {
            b = mid - 1;
        }
    }
    return ans;
}

ll root_sum(ll n) {
    ll sq_n,  diff;

    n -= (n & 1) == 0;
    sq_n = sqrt(n); 
    diff = (n - sq_n*sq_n)/2 + 1;

    return (sum_sn(sq_n-1) + sq_n*diff) % MOD;
}

int main() {
    ll n;

    while(scanf("%lld", &n), n) {
        printf("%lld\n", root_sum(n));
    }
}
