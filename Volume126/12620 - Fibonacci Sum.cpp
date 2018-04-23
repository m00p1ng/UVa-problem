#include <cstdio>
#define F300 14800ULL

typedef unsigned long long ull;
ull fibo[400], sum[400];

void gen_fibo() {
    fibo[0] = fibo[1] = 1;
    sum[0] = 1;
    sum[1] = 2;

    for(ull i = 2; i <= 300; i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 100;
        sum[i] = (sum[i-1] + fibo[i]);
    }
}

int main() {
    gen_fibo();
    int ts;
    ull n, m;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%lld %lld", &n, &m);
        m--, n--;
        ull km, kn, ans;
        ans = F300*(m/300-n/300) + sum[m%300] - sum[n%300] + fibo[n%300];
        printf("%lld\n", ans);
    }
}
