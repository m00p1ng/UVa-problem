#include <cstdio>

int main() {
    int ts;
    long long a, b;

    scanf("%d", &ts);
    while(ts--) {
        scanf("%lld %lld", &a, &b);
        if(a < b || (a+b)%2 == 1) {
            puts("impossible");
        } else{
            printf("%lld %lld\n", (a+b)/2, (a-b)/2);
        }
    }
}
