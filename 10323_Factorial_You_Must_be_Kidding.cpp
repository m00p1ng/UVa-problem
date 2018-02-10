#include <cstdio>

long long fac[20];

void gen_fac() {
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 13; i++) {
        fac[i] = fac[i-1]*i;
    }
}

int main() {
    gen_fac();
    
    int n;
    bool is_neg;
    while(scanf("%d", &n) == 1) {
        is_neg = (n >> 31) & 1;
        
        if((!is_neg && n < 8) || (is_neg && ~(-n)&1)) puts("Underflow!");
        else if(n > 13 || (is_neg && (-n)&1)) puts("Overflow!");
        else printf("%lld\n", fac[n]); 

    }
}
