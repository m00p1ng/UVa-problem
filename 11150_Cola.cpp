#include <cstdio>

int main() {
    int n, sum;
    while(scanf("%d", &n) == 1) {
        sum = n;
        while(n/3 > 0) {
            sum += n/3;
            n = n/3 + n%3;
        }
        if(n == 2) sum++;
        printf("%d\n", sum);
    }
}

