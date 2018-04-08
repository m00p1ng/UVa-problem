#include <cstdio>
#include <cmath>

double digit[10000001];

void gen_digit() {
    digit[1] = 0;
    for(int i = 2; i <= 1e7; i++) {
        digit[i] = digit[i-1] + log10(i);
    }
    digit[1] = 1;
}

int main() {
    int ts, n;
    gen_digit();
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d\n", &n);
        printf("%.0lf\n", ceil(digit[n]));
    }
}
