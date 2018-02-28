#include <cstdio>

int main() {
    int a, b, c ,d;
    int sum, diff;
    while(scanf("%d %d %d %d", &a, &b, &c, &d), a || b || c || d) {
        sum = 1080 + 9*(a - 2*b + 2*c - d);

        if(a < b) sum += 360;
        if(c < b) sum += 360;
        if(c < d) sum += 360;
        printf("%d\n", sum);
    }
}

