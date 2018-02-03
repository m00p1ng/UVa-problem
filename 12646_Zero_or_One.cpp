#include <cstdio>

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) == 3) {
        if(a == b && a != c) puts("C");
        else if(a == c && a != b) puts("B");
        else if(b == c && b != a) puts("A");
        else puts("*");
    }
}
