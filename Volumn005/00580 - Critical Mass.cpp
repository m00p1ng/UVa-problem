#include <cstdio>

typedef long long ll;
ll tribo[64], ans[64];

void gen_tribo() {
    tribo[0] = 1;
    tribo[1] = 2;
    tribo[2] = 4;
    for(int i = 3; i < 64; i++) {
        tribo[i] = tribo[i-3] + tribo[i-2] + tribo[i-1];
        ans[i] = (1LL<<i) - tribo[i];
    }
}

int main() {
    gen_tribo();
    int n;
    while(scanf("%d", &n), n) {
        printf("%lld\n", ans[n]);
    }
}
