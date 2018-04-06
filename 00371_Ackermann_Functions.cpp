#include <cstdio>
int acker[1000000000] = {0};

typedef long long ll;
int gen_acker(ll n) {
    int cnt = 0;
    do {
        if(n & 1) {
            n = 3*n + 1;
        } else {
            n >>= 1;
        }
        cnt++;
    } while(n != 1);
    return cnt;
}

int main() {
    ll l, h;
    while(scanf("%lld %lld", &l, &h), h || l) {
        if(l > h) {
            int k = h;
            h = l;
            l = k;
        }
        int mn = 0, ml = 0, temp;
        for(ll i = l; i <= h; i++) {
            if(acker[i] != 0) {
                temp = acker[i];
            } else {
                temp = gen_acker(i);
                acker[i] = temp;
            }
            if(temp > ml) {
                ml = temp;
                mn = i;
            }
        }
        printf("Between %lld and %lld, %d generates the longest sequence of %d values.\n", l, h, mn, ml);
    }
}
