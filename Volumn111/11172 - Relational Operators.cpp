#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);

    while(ts--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a - b > 0) puts(">");
        else if(a - b < 0) puts("<");
        else puts("=");
    }
}
