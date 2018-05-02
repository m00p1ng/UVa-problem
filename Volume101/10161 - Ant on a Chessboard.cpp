#include <cstdio>
#include <cmath>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n, a, b;
    int prev_root, prev_sq, next_sq, half, remain;
    while(scanf("%d", &n), n) {
        prev_root = sqrt(n);
        next_sq = (prev_root+1)*(prev_root+1);
        prev_sq = prev_root*prev_root;
        half = (next_sq - prev_sq + 1)/2;
        remain = n - prev_sq;

        if(remain == 0) {
            a = prev_root;
            b = 1;
        } else if(remain < half) {
            a = prev_root + 1;
            b = remain;
        } else {
            a = 2*half - remain;
            b = prev_root + 1;
        }

        if(prev_root&1) swap(a, b);
        printf("%d %d\n", a, b);
    }
}
