#include <cstdio>

int main() {
    int n, sum;
    while(scanf("%d", &n), n) {
        sum = 0;
        while(n/3 > 0) {
            sum += n/3;
            n = n/3 + n%3;
        }
        if(n == 2) sum++;
        printf("%d\n", sum);
    }
}

