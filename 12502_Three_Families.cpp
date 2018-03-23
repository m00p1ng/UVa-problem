#include <cstdio>

int main() {
    int ts, a, b, c;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", (2*a-b)*c/(a+b));
    }
}
