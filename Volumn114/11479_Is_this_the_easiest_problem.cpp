#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    long long a, b, c;

    for(int t = 1; t <= ts; t++) {
        scanf("%lld %lld %lld", &a, &b, &c);

        printf("Case %d: ", t);
        if(a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b) {
            if(a == b && b == c) puts("Equilateral");
            else if(a == b || b == c || a == c) puts("Isosceles");
            else puts("Scalene");
        }
        else puts("Invalid");
    }
}
