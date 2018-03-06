#include <cstdio>

int main() {
    long long sz, p;
    while(scanf("%lld %lld", &sz, &p), sz != 0 && p != 0) {
        long long sq, max_sq, min_sq, x, y;
        long long remain, offset;
        int idx = 0;
        for(long long i = 0; p > (2*i+1)*(2*i+1); i++) {
            idx = i;
        }
        if(p != (2*idx+1)*(2*idx+1)) idx++;
        sq = 2*idx + 1;
       
        max_sq = sq*sq;
        min_sq = (sq-2)*(sq-2);
        
        offset = sq - 1;
        x = y = sz/2 + 1;
        remain = p - min_sq;
        if(p <= min_sq + offset) {
            x += idx - remain;
            y += idx;
        } else if(p <= min_sq + 2*offset) {
            x += -idx;
            y += idx - (remain - offset);
        } else if(p <= min_sq + 3*offset) {
            x += -idx + (remain - 2*offset);
            y += -idx;
        } else if(p <= max_sq) {
            x += idx;
            y += -idx + (remain - 3*offset);
        }

        printf("Line = %lld, column = %lld.\n", y, x);
    }
}

