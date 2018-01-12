#include <cstdio>

int main() {
    int n;
    while(scanf("%d", &n), n) {
        if(n % 9 == 0) puts("9");
        else printf("%d\n", n % 9);
    }
}
