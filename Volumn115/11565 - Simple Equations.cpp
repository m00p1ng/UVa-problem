#include <cstdio>

typedef long long ll;

void swap(ll& a, ll& b) {
    ll temp = a;
    a = b;
    b = temp;
}

void print_ans(ll x, ll y, ll z) {
    ll temp;
    if(x > y) swap(x, y);
    if(x > z) swap(x, z);
    if(y > z) swap(y, z);
    printf("%lld %lld %lld\n", x, y, z);
}

int  main() {
    int ts;
    ll a, b, c;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        bool found = false;
        for(ll x = -22; x <= 22 && !found; x++) {
            if(x*x <= c) {
                for(ll y = -100; y <= 100 && !found; y++) {
                    if (y != x && x * x + y * y <= c) {
                        for(ll z = -100; z <= 100 && !found; z++) {
                            if (z != x && z != y && x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
                                print_ans(x, y, z);
                                found  = true;
                            }
                        }
                    }
                }
            }
        }
        if(!found) puts("No solution.");
    }
}
