#include <cstdio>

typedef long long ll;

ll tri[1000010];

void gen_tri() {
    int cnt = 3;
    tri[cnt++] = 0;
    tri[cnt++] = 1;

    for(ll i = 2; cnt <= 1000000; i++) {
        tri[cnt] = tri[cnt-1] + i*i-i;
        tri[cnt+1] = tri[cnt] + i*i;
        cnt += 2;
    }
}

int main() {
    gen_tri(); 
    int n;
    while(scanf("%d", &n), n > 2) {
        printf("%lld\n", tri[n]);
    }
}
