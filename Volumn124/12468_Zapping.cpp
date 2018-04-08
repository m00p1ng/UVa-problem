#include <cstdio>

int abs(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b), a != -1 || b != -1) {
        int x = abs(a-b);
        if(2*x < 100) printf("%d\n", x);
        else printf("%d\n", 100 - x);
    }
}
