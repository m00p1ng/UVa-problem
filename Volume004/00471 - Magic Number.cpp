#include <cstdio>

bool is_frac_valid(long long temp) {
    int check = 0;
    while(temp) {
        int t = temp % 10;
        if((check >> t) & 1) return false;
        check |= 1<<t;
        temp /= 10;
    }
    return true;
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        long long number, i;
        scanf("%lld", &number);
        for(i = 1; i <= 9876543210L/number; i++) {
            if(is_frac_valid(i) && is_frac_valid(i*number)) {
                printf("%lld / %lld = %lld\n", i*number, i, number);
            }
        }
        if(ts) puts("");
    }
}

