#include <cstdio>
#include <cmath>

typedef unsigned long long ull;
typedef long long ll;

int find_n(int k, int d) {
    int i = 1;
    while(1) {
        int sum = d*(i*(i+1)/2);
        if(k <= sum) {
            return i;
        }
        i++;
    }
}

ull sum(ll co[], int degree, int n) {
    ull val = 0;
    for(int i = 0; i <= degree; i++) {
        val += co[i]*pow(n, i);
    }
    return val;
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        ll co[30];
        int degree, k, d;
        scanf("%d", &degree);
        for(int i = 0; i <= degree; i++) {
            scanf("%lld", &co[i]);
        }
        scanf("%d", &d);
        scanf("%d", &k);
        printf("%lld\n", sum(co, degree, find_n(k, d)));
    }
}

